/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GroupLogic.h"
#include "Components.h"
#include "Events.h"
#include "ScenarioRecommutationClient.h"
#include "Base.h"
#include "ControlScenario.h"

using namespace nsMMOEngine;
using namespace nsMappedComponents;

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
    auto clientEntity = mEntMng->GetUnique<TClientIdentityComponent>( clientIdentity );
    if ( clientEntity == TEntityManager::None )
    {
      AddError( CreateGroup_ClientNotExist );
      return false;
    }
    TGroupIDComponent groupIDComponent;
    mEntMng->GetComponent( clientEntity, groupIDComponent );
    if ( groupIDComponent.v != 0 )// уже состоит в какой-то группе
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
  auto groupEntity = mEntMng->GetUnique( groupIdentityComponent );
  if ( groupEntity == TEntityManager::None )
    return;// нет такой группы

  TGroupIDComponent groupIDComponent;
  groupIDComponent.v = groupID;
  auto mid = mEntMng->GetMultiID( groupIDComponent );
  groupIDComponent.v = 0;
  TSlaveSessionByClientComponent slaveSessionByClientComponent;
  for ( auto clientEntity : mEntMng->GetEntities( mid ) )
  {
    mEntMng->UpdateComponent( clientEntity, groupIDComponent );
    mEntMng->UpdateComponent( clientEntity, slaveSessionByClientComponent );// обнулить информацию о Slave
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
  auto clientEntID = mEntMng->GetUnique( clientIdentityComponent );
  if ( clientEntID == TEntityManager::None )
    return;
  TGroupIDComponent groupIDComponent;
  mEntMng->UpdateComponent( clientEntID, groupIDComponent );


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
  auto mid = mEntMng->GetMultiID( groupIDComponent );
  groupIDComponent.v = 0;
  for ( auto clientEntity : mEntMng->GetEntities( mid ) )
  {
    TClientIdentityComponent clientIdentityComponent;
    mEntMng->GetComponent( clientEntity, clientIdentityComponent );
    clientKeyList.push_back( clientIdentityComponent.v );
  }
}
//-------------------------------------------------------------------------------------------
bool TGroupLogic::FindSlaveSessionByGroup( unsigned int groupID, unsigned int& sessionID )
{
  TGroupIdentityComponent groupIdentityComponent;
  groupIdentityComponent.v = groupID;
  auto groupEntity = mEntMng->GetUnique( groupIdentityComponent );
  if ( groupEntity == TEntityManager::None )
    return false;// нет такой группы

  TSlaveSessionByGroupComponent slaveSessionByGroupComponent;
  mEntMng->GetComponent( groupEntity, slaveSessionByGroupComponent );
  sessionID = slaveSessionByGroupComponent.v;
  return true;
}
//-------------------------------------------------------------------------------------------
bool TGroupLogic::EvalCreateGroupNow( std::list<unsigned int>& clientKeyList, unsigned int& groupID )
{
  // считается какой вклад вносят группы в нагрузку на Slave и вносится в map
  // load / clientCountOnSlave - сколько процентов от нагрузки несет каждый клиент
  // умножаем на кол-во клиентов в группах - получаем нагрузку приходящуюся на клиентов в группах
  std::map<int, unsigned int> loadSlaveEntityMap;
  CalculateLoadMap( loadSlaveEntityMap );

  // ищем Slave, который содержит минимум Клиентов, состоящих в группе
  // ищем до последнего Slave, процессоры могут быть разными, поэтому в случае
  // неудачи пробовать следующего Slave
  for ( auto loadSlaveEntityPair : loadSlaveEntityMap )// sorted
  {
    auto slaveEntity = loadSlaveEntityPair.second;

    TSlaveSessionIdentityComponent slaveSessionIdentityComponent;
    mEntMng->GetComponent( slaveEntity, slaveSessionIdentityComponent );
    auto slaveSession = slaveSessionIdentityComponent.v;

    // искать только тех, кто onSlave
    std::list<TEntityManager::EntityID> clientEntityWithoutGroupList;
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
void TGroupLogic::CalculateLoadMap( std::map<int, TEntityManager::EntityID>& loadSlaveEntityMap )
{
  for ( auto slaveSession : mEntMng->GetUniqueEntities<TSlaveSessionIdentityComponent>() )
  {
    auto slaveEntity = slaveSession.second;
    TSlaveLoadInfoComponent slaveLoadComponent;
    mEntMng->GetComponent( slaveEntity, slaveLoadComponent );

    auto sessionID = slaveSession.first.v;

    TSlaveSessionByClientComponent slaveSessionByClientComponent;
    slaveSessionByClientComponent.v = sessionID;
    TClientStateComponent clientStateComponent;
    clientStateComponent.v = TClientStateComponent::OnSlave;
    auto clientOnSlaveMID = mEntMng->GetMultiID( slaveSessionByClientComponent, clientStateComponent );
    auto clientOnSlaveCount = mEntMng->GetMultiCount( clientOnSlaveMID );

    int clientCountInGroup = 0;

    TSlaveSessionByGroupComponent slaveSessionByGroupComponent;
    slaveSessionByGroupComponent.v = sessionID;
    auto groupMID = mEntMng->GetMultiID( slaveSessionByGroupComponent );
    for ( auto groupEntity : mEntMng->GetEntities( groupMID ) )
    {
      TGroupIdentityComponent groupIdentityComponent;
      mEntMng->GetComponent( groupEntity, groupIdentityComponent );

      TGroupIDComponent groupIDComponent;
      groupIDComponent.v = groupIdentityComponent.v;
      auto clientInGroupMID = mEntMng->GetMultiID( groupIDComponent );

      clientCountInGroup += mEntMng->GetMultiCount( clientInGroupMID );
    }

    int loadByGroup = 0;
    if ( clientOnSlaveCount > 0 )
      loadByGroup = (int) ( ( slaveLoadComponent.v / clientOnSlaveCount ) * clientCountInGroup );

    loadSlaveEntityMap.insert( {loadByGroup, slaveEntity} );
  }
}
//-------------------------------------------------------------------------------------------
int TGroupLogic::CalculateClientCountNotOnSlave( unsigned int slaveSession,
  std::list<unsigned int>& clientKeyList )
{
  int result = 0;

  std::list<TEntityManager::EntityID> clientEntityList;
  GetClientWithoutGroup( slaveSession, clientEntityList );

  for ( auto clientKey : clientKeyList )
  {
    TClientIdentityComponent clientIdentityComponent;
    clientIdentityComponent.v = clientKey;
    auto clientKey = mEntMng->GetUnique( clientIdentityComponent );

    TSlaveSessionByClientComponent slaveSessionByClientComponent;
    mEntMng->GetComponent( clientKey, slaveSessionByClientComponent );
    if ( slaveSessionByClientComponent.v == slaveSession )
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
  mEntMng->AddComponent( groupEntity, groupIdentityComponent );

  TSlaveSessionByGroupComponent slaveSessionByGroupComponent;
  slaveSessionByGroupComponent.v = slaveSession;
  mEntMng->AddComponent( groupEntity, slaveSessionByGroupComponent );

  for ( auto clientKey : clientKeyList )
  {
    TClientIdentityComponent clientIdentityComponent;
    clientIdentityComponent.v = clientKey;
    auto clientEntity = mEntMng->GetUnique( clientIdentityComponent );

    TGroupIDComponent groupIDComponent;
    groupIDComponent.v = groupID;
    mEntMng->UpdateComponent( clientEntity, groupIDComponent );
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
    auto clientEntity = mEntMng->GetUnique( clientIdentityComponent );

    TGroupIDComponent groupIDComponent;
    groupIDComponent.v = groupID;
    mEntMng->UpdateComponent( clientEntity, groupIDComponent );
  }
}
//-------------------------------------------------------------------------    
void TGroupLogic::ExchangeClients( unsigned int slaveSession,
  std::list<unsigned int>& clientKeyList,
  std::list<TEntityManager::EntityID>& clientEntityWithoutGroupList )
{
  for ( auto clientKey : clientKeyList )
  {
    // найти клиента
    TClientIdentityComponent clientIdentityComponent;
    auto clientEntity = mEntMng->GetUnique( clientIdentityComponent );

    TSlaveSessionByClientComponent slaveSessionByClientComponent;
    mEntMng->GetComponent( clientEntity, slaveSessionByClientComponent );

    if ( slaveSessionByClientComponent.v == slaveSession )
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
void TGroupLogic::StartRcm( TEntityManager::EntityID clientEntity, unsigned int slaveSession )
{
  TContextContainerComponent contextContainerComponent;
  mEntMng->GetComponent( clientEntity, contextContainerComponent );
  auto pCRCM = &(contextContainerComponent.v->mRcm);

  TClientIdentityComponent clientIdentityComponent;
  mEntMng->GetComponent( clientEntity, clientIdentityComponent );
  auto clientKey = clientIdentityComponent.v;

  // обновить состояние клиента
  TClientStateComponent clientStateComponent;
  clientStateComponent.v = TClientStateComponent::RCM;
  mEntMng->GetComponent( clientEntity, clientStateComponent );

  // взять старый slaveSession
  TSlaveSessionByClientComponent slaveSessionByClientComponent;
  mEntMng->GetComponent( clientEntity, slaveSessionByClientComponent );

  // поместить в донор
  TDonorSessionComponent donorSessionComponent;
  donorSessionComponent.v = slaveSessionByClientComponent.v;
  mEntMng->UpdateComponent( clientEntity, donorSessionComponent );

  // изменить на новый
  slaveSessionByClientComponent.v = slaveSession;
  mEntMng->UpdateComponent( clientEntity, slaveSessionByClientComponent );

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
