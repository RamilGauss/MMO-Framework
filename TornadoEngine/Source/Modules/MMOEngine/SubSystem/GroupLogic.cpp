/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GroupLogic.h"
#include "Components.h"
#include "Events.h"
#include "ScenarioRecommutationClient.h"
#include "Base.h"
#include "ControlScenario.h"

using namespace nsMMOEngine;

TGroupLogic::TGroupLogic( TBase* p ) : TBaseMasterLogic( p )
{

}
//-------------------------------------------------------------------------------------------
bool TGroupLogic::TryCreateGroup( std::list<unsigned int>& clientKeyList, unsigned int& groupID )
{
  TClientIdentityComponent clientIdentity;
  for ( unsigned int clientKey : clientKeyList )
  {
    // Клиент может и не существовать в системе 
    // спросить состоит ли клиент в группе
    clientIdentity.v = clientKey;
    auto clientEntity = mEntMng->GetByUnique<TClientIdentityComponent>( clientIdentity );
    if ( clientEntity == nsECSFramework::None )
    {
      AddError( CreateGroup_ClientNotExist );
      return false;
    }
    auto groupID = mEntMng->ViewComponent<TGroupIDComponent>( clientEntity )->v;
    if ( groupID != 0 )// уже состоит в какой-то группе
    {
      AddError( CreateGroup_ClientInGroup );
      return false;
    }
  }
  // оценка ситуации на Slave
  return EvalCreateGroupNow( clientKeyList, groupID );
}
//-------------------------------------------------------------------------------------------
void TGroupLogic::DestroyGroup( unsigned int groupID )
{
  TGroupIdentityComponent groupIdentityComponent;
  groupIdentityComponent.v = groupID;
  auto groupEntity = mEntMng->GetByUnique( groupIdentityComponent );
  if ( groupEntity == nsECSFramework::None )
    return;// нет такой группы

  TGroupIDComponent groupIDComponent;
  groupIDComponent.v = groupID;
  auto clients = mEntMng->GetByValue( groupIDComponent );
  groupIDComponent.v = 0;
  TSlaveSessionByClientComponent slaveSessionByClientComponent;
  if ( clients != nullptr )
    for ( auto clientEntity : *clients )
    {
      mEntMng->SetComponent( clientEntity, groupIDComponent );
      mEntMng->SetComponent( clientEntity, slaveSessionByClientComponent );// обнулить информацию о Slave
    }

  mEntMng->DestroyEntity( groupEntity );

  //unsigned int slaveSessionID;
  //if ( mMngGroup->FindSessionByID( groupID, slaveSessionID ) == false )
  //  return;
  //mStatisticaClientInGroup->DeleteBySlaveSession( slaveSessionID );
  //mMngGroup->DeleteByID( groupID );
}
//-------------------------------------------------------------------------------------------
void TGroupLogic::LeaveGroup( unsigned int clientKey )
{
  TClientIdentityComponent clientIdentityComponent;
  auto clientEntity = mEntMng->GetByUnique( clientIdentityComponent );
  if ( clientEntity == nsECSFramework::None )
    return;
  TGroupIDComponent groupIDComponent;
  mEntMng->SetComponent( clientEntity, groupIDComponent );


  //unsigned int groupID;
  //if ( mMngGroup->FindIDByClientKey( clientKey, groupID ) == false )
  //  return;

  //unsigned int slaveSessionID;
  //if ( mMngGroup->FindSessionByID( groupID, slaveSessionID ) )
  //  mStatisticaClientInGroup->DeleteByClientKey( slaveSessionID, clientKey );

  //mMngGroup->DeleteClientKey( clientKey );
}
//-------------------------------------------------------------------------------------------
void TGroupLogic::GetListForGroup( unsigned int groupID, std::list<unsigned int>& clientKeyList )
{
  clientKeyList.clear();

  TGroupIDComponent groupIDComponent;
  groupIDComponent.v = groupID;
  auto clients = mEntMng->GetByValue( groupIDComponent );
  if ( clients == nullptr )
    return;
  groupIDComponent.v = 0;
  for ( auto clientEntity : *clients )
  {
    auto clientId = mEntMng->ViewComponent<TClientIdentityComponent>( clientEntity )->v;
    clientKeyList.push_back( clientId );
  }
}
//-------------------------------------------------------------------------------------------
bool TGroupLogic::FindSlaveSessionByGroup( unsigned int groupID, unsigned int& sessionID )
{
  TGroupIdentityComponent groupIdentityComponent;
  groupIdentityComponent.v = groupID;
  auto groupEntity = mEntMng->GetByUnique( groupIdentityComponent );
  if ( groupEntity == nsECSFramework::None )
    return false;// нет такой группы

  sessionID = mEntMng->ViewComponent<TSlaveSessionByGroupComponent>( groupEntity )->v;
  return true;
}
//-------------------------------------------------------------------------------------------
bool TGroupLogic::EvalCreateGroupNow( std::list<unsigned int>& clientKeyList, unsigned int& groupID )
{
  // считается какой вклад вносят группы в нагрузку на Slave и вносится в map
  // load / clientCountOnSlave - сколько процентов от нагрузки несет каждый клиент
  // умножаем на кол-во клиентов в группах - получаем нагрузку приходящуюся на клиентов в группах
  std::map<int, nsECSFramework::TEntityID> loadSlaveEntityMap;
  CalculateLoadMap( loadSlaveEntityMap );

  // ищем Slave, который содержит минимум Клиентов, состоящих в группе
  // ищем до последнего Slave, процессоры могут быть разными, поэтому в случае
  // неудачи пробовать следующего Slave
  for ( auto loadSlaveEntityPair : loadSlaveEntityMap )// sorted
  {
    auto slaveEntity = loadSlaveEntityPair.second;
    auto slaveSession = mEntMng->ViewComponent<TSlaveSessionIdentityComponent>( slaveEntity )->v;

    // искать только тех, кто onSlave
    std::list<nsECSFramework::TEntityID> clientEntityWithoutGroupList;
    GetClientWithoutGroup( slaveSession, clientEntityWithoutGroupList );

    auto clientCountNotOnSlave = CalculateClientCountNotOnSlave( slaveEntity, clientKeyList );
    auto addedClientCount = clientCountNotOnSlave - clientEntityWithoutGroupList.size();
    if ( addedClientCount < 0 )
      addedClientCount = 0;

    auto loadAfterAdd = CalculateFutureLoadOnSlave( slaveEntity, addedClientCount );
    if ( loadAfterAdd < LimitLoadPercentOnSlaveForAdd_ClientInGroup )
    {
      groupID = CreateGroup( slaveSession, clientKeyList );
      // перекинуть клиент с других Slave на этот, в обмен надо отдать своих
      AddClientsInGroup( groupID, clientKeyList );
      ExchangeClients( slaveSession, clientKeyList, clientEntityWithoutGroupList );
    }
  }
  /*
  // ищем минимум Slave, который содержит минимум Клиентов, состоящих в группе
  unsigned int slaveSessionID;
  if ( mStatisticaClientInGroup->FindSlaveSessionByMinimumClient( slaveSessionID ) == false )
    return false;
  // определить нагрузку, которая будет в будущем на Slave, если будет меньше допустимого значения, то можно создать
  if ( LoadInFutureLessLimit( slaveSessionID, clientKeyList ) == false )
    return false;
  // создать группу
  groupID = mMngGroup->AddGroup( slaveSessionID );

  // занести в статистику
  mStatisticaClientInGroup->AddSlave( slaveSessionID );
  // все те Клиенты, которые активны и стали внутри Группы, поместить в Статистику
  for ( unsigned int clientKey : clientKeyList )
  {
    // если присутствует в системе
    if ( mMngContextClient->FindContextByClientKey( clientKey ) )
      mStatisticaClientInGroup->AddBySlaveSessionClientKey( slaveSessionID, clientKey );
    // заполнить клиентами независимо от того существуют ли они в системе
    mMngGroup->AddClientKey( groupID, clientKey );
  }
  //================================================================================
  // определить кто встанет на место этого Клиента на старом Slave
  // и заодно перенаправить этого Клиента на новый Slave
  for ( unsigned int clientKey : clientKeyList )
  {
    TContainerContextSc* pC = mMngContextClient->FindContextByClientKey( clientKey );
    if ( pC == nullptr )
    {
      unsigned int id_session_client = INVALID_HANDLE_SESSION;
      mMngContextClientLogining->FindSessionByClientKey( clientKey, id_session_client );
      pC = mMngContextClientLogining->FindContextBySession( id_session_client );
      if ( pC == nullptr )
        continue;
    }
    SolveExchangeClient( clientKey, pC, slaveSessionID );
  }
  */
  return true;
}
//-------------------------------------------------------------------------------------------
void TGroupLogic::CalculateLoadMap( std::map<int, nsECSFramework::TEntityID>& loadSlaveEntityMap )
{
  auto slaves = mEntMng->GetByHas<TSlaveSessionIdentityComponent>();
  if ( slaves == nullptr )
    return;

  for ( auto slaveEntity : *slaves )
  {
    auto sessionID = mEntMng->ViewComponent<TSlaveSessionIdentityComponent>( slaveEntity )->v;
    TSlaveLoadInfoComponent slaveLoadComponent;
    mEntMng->GetComponent( slaveEntity, slaveLoadComponent );

    TSlaveSessionByClientComponent slaveSessionByClientComponent;
    slaveSessionByClientComponent.v = sessionID;
    TClientStateComponent clientStateComponent;
    clientStateComponent.v = TClientStateComponent::OnSlave;
    auto clientOnSlaves = mEntMng->GetByValue( slaveSessionByClientComponent, clientStateComponent );
    auto clientOnSlaveCount = clientOnSlaves == nullptr ? 0 : clientOnSlaves->size();

    int clientCountInGroup = 0;

    TSlaveSessionByGroupComponent slaveSessionByGroupComponent;
    slaveSessionByGroupComponent.v = sessionID;
    auto groups = mEntMng->GetByValue( slaveSessionByGroupComponent );

    if ( groups != nullptr )
      for ( auto groupEntity : *groups )
      {
        auto groupId = mEntMng->ViewComponent<TGroupIdentityComponent>( groupEntity )->v;

        TGroupIDComponent groupIDComponent;
        groupIDComponent.v = groupId;
        auto clientInGroups = mEntMng->GetByValue( groupIDComponent );
        if ( clientInGroups == nullptr )
          continue;

        clientCountInGroup += clientInGroups->size();
      }

    int loadByGroup = 0;
    if ( clientOnSlaveCount > 0 )
      loadByGroup = (int)( ( slaveLoadComponent.v / clientOnSlaveCount ) * clientCountInGroup );

    loadSlaveEntityMap.insert( {loadByGroup, slaveEntity} );
  }
}
//-------------------------------------------------------------------------------------------
int TGroupLogic::CalculateClientCountNotOnSlave( unsigned int slaveSession,
  std::list<unsigned int>& clientKeyList )
{
  int result = 0;

  std::list<nsECSFramework::TEntityID> clientEntityList;// зачем?
  GetClientWithoutGroup( slaveSession, clientEntityList );

  for ( auto clientKey : clientKeyList )
  {
    TClientIdentityComponent clientIdentityComponent;
    clientIdentityComponent.v = clientKey;
    auto clientEntity = mEntMng->GetByUnique( clientIdentityComponent );
    if ( clientEntity == nsECSFramework::None )
      continue;

    TSlaveSessionByClientComponent slaveSessionByClientComponent;
    auto slaveSessionId = mEntMng->ViewComponent<TSlaveSessionByClientComponent>( clientEntity )->v;
    if ( slaveSessionId == slaveSession )
      continue;

    result++;
  }
  return result;
}
//-------------------------------------------------------------------------    
unsigned int TGroupLogic::CreateGroup( unsigned int slaveSession, std::list<unsigned int>& clientKeyList )
{
  unsigned int groupID = GetNewID();

  auto groupEntity = mEntMng->CreateEntity();

  TGroupIdentityComponent groupIdentityComponent;
  groupIdentityComponent.v = groupID;
  mEntMng->SetComponent( groupEntity, groupIdentityComponent );

  TSlaveSessionByGroupComponent slaveSessionByGroupComponent;
  slaveSessionByGroupComponent.v = slaveSession;
  mEntMng->SetComponent( groupEntity, slaveSessionByGroupComponent );

  for ( auto clientKey : clientKeyList )
  {
    TClientIdentityComponent clientIdentityComponent;
    clientIdentityComponent.v = clientKey;
    auto clientEntity = mEntMng->GetByUnique( clientIdentityComponent );
    if ( clientEntity == nsECSFramework::None )
      continue;

    TGroupIDComponent groupIDComponent;
    groupIDComponent.v = groupID;
    mEntMng->SetComponent( clientEntity, groupIDComponent );
  }

  return groupID;
}
//-------------------------------------------------------------------------    
void TGroupLogic::AddClientsInGroup( unsigned int groupID, std::list<unsigned int>& clientKeyList )
{
  for ( auto clientKey : clientKeyList )
  {
    // найти клиента
    TClientIdentityComponent clientIdentityComponent;
    auto clientEntity = mEntMng->GetByUnique( clientIdentityComponent );
    if ( clientEntity == nsECSFramework::None )
      continue;

    TGroupIDComponent groupIDComponent;
    groupIDComponent.v = groupID;
    mEntMng->SetComponent( clientEntity, groupIDComponent );
  }
}
//-------------------------------------------------------------------------    
void TGroupLogic::ExchangeClients( unsigned int slaveSession,
  std::list<unsigned int>& clientKeyList,
  std::list<nsECSFramework::TEntityID>& clientEntityWithoutGroupList )
{
  for ( auto clientKey : clientKeyList )
  {
    // найти клиента
    TClientIdentityComponent clientIdentityComponent;
    auto clientEntity = mEntMng->GetByUnique( clientIdentityComponent );
    if ( clientEntity == nsECSFramework::None )
      continue;

    if ( mEntMng->ViewComponent<TSlaveSessionByClientComponent>( clientEntity )->v == slaveSession )
      continue;

    StartRcm( clientEntity, slaveSession );

    if ( clientEntityWithoutGroupList.size() == 0 )
      continue;

    clientEntity = clientEntityWithoutGroupList.front();
    clientEntityWithoutGroupList.pop_front();

    StartRcm( clientEntity, slaveSession );
  }
}
//-------------------------------------------------------------------------    
void TGroupLogic::StartRcm( nsECSFramework::TEntityID clientEntity, unsigned int slaveSession )
{
  auto pContext = mEntMng->ViewComponent<TContextContainerComponent>( clientEntity )->v;
  auto pCRCM = &( pContext->mRcm );

  TClientIdentityComponent clientIdentityComponent;
  mEntMng->GetComponent( clientEntity, clientIdentityComponent );
  auto clientKey = clientIdentityComponent.v;

  // обновить состояние клиента
  TClientStateComponent clientStateComponent;
  clientStateComponent.v = TClientStateComponent::RCM;
  mEntMng->SetComponent( clientEntity, clientStateComponent );

  // взять старый slaveSession
  auto slaveSessionId = mEntMng->ViewComponent<TSlaveSessionByClientComponent>( clientEntity )->v;

  // поместить в донор
  TDonorSessionComponent donorSessionComponent;
  donorSessionComponent.v = slaveSessionId;
  mEntMng->SetComponent( clientEntity, donorSessionComponent );

  // изменить на новый
  TSlaveSessionByClientComponent slaveSessionByClientComponent;
  slaveSessionByClientComponent.v = slaveSession;
  mEntMng->SetComponent( clientEntity, slaveSessionByClientComponent );

  // начать на уровне сценария перекоммутацию
  RcmByClientKeyContextSlaveSessionRecipient( clientKey, pCRCM, slaveSession );
}
//-------------------------------------------------------------------------    
void TGroupLogic::RcmByClientKeyContextSlaveSessionRecipient( unsigned int clientKey,
  TContextScRecommutationClient* pCRCM, unsigned int recipientSessionID )
{
  mBase->mControlSc->mRcm->SetContext( pCRCM );
  mBase->mControlSc->mRcm->Start( recipientSessionID, clientKey );
}
//-------------------------------------------------------------------------
