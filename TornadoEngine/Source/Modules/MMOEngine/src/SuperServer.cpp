/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SuperServer.h"
#include "ManagerContextMoreDownClientConnection.h"
#include "ManagerContextDownConnection.h"

#include "Logger.h"
#include "IScenario.h"
#include "ContainerContextSc.h"
#include "ControlScenario.h"
#include "Events.h"

#include "ScenarioLoginMaster.h"
#include "ScenarioFlow.h"
#include "ScenarioSendToClient.h"
#include "ScenarioLoginClient.h"
#include "ScenarioDisconnectClient.h"

using namespace nsMMOEngine;

TSuperServer::TSuperServer()
{
  mMngContextClient.reset( new TManagerContextMoreDownClientConnection( this ) );
  mMngContextMaster.reset( new TManagerContextDownConnection( this ) );
  mContainer_SecondLogin.reset( new TContainerContextSc );

  mControlSc->mLoginClient->SetBehavior( TScenarioLoginClient::eSuperServer );

  SetupScForContext( mContainer_SecondLogin.get() );
}
//-------------------------------------------------------------------------
TSuperServer::~TSuperServer()
{

}
//-------------------------------------------------------------------------
void TSuperServer::SendByClientKey( std::list<unsigned int>& lKey, char* p, int size )
{
  SetupBP( p, size );
  mControlSc->mSendToClient->SendFromSuperServer( lKey, mBP );
}
//-------------------------------------------------------------------------
void TSuperServer::DisconnectInherit( unsigned int sessionID )
{
  if ( mMngContextMaster->FindContextBySession( sessionID ) == nullptr )
    return;

  // перечислить всех клиентов, которые сидят на этом мастере и их удаление
  int cClient;
  if ( mMngContextMaster->GetCountClientKey( sessionID, cClient ) == false )
    return;
  for ( int i = 0; i < cClient; i++ )
  {
    unsigned int clientKey;
    if ( mMngContextMaster->GetClientKeyByIndex( sessionID, i, clientKey ) )
      mMngContextClient->DeleteByKey( clientKey );
  }

  mMngContextMaster->DeleteContextBySession( sessionID );

  TDisconnectDownEvent event;
  event.sessionID = sessionID;
  AddEventCopy( &event, sizeof( event ) );
}
//-------------------------------------------------------------------------
int TSuperServer::GetClientCountBySessionID( unsigned int sessionID )
{
  int countClient;
  if ( mMngContextMaster->GetCountClientKey( sessionID, countClient ) == false )
    return 0;
  return countClient;
}
//-------------------------------------------------------------------------
void TSuperServer::GetDescDown( std::list<unsigned int>& sessionID_List )
{
  auto count = mMngContextMaster->GetCountSession();
  sessionID_List.clear();
  for ( int index = 0; index < count; index++ )
  {
    unsigned int sessionID;
    if ( mMngContextMaster->GetSessionByIndex( index, sessionID ) == false )
      continue;
    sessionID_List.push_back( sessionID );
  }
}
//-------------------------------------------------------------------------
void TSuperServer::SendDown( unsigned int sessionID, char* p, int size, bool check )
{
  TContainerContextSc* pC = mMngContextMaster->FindContextBySession( sessionID );
  if ( pC == nullptr )
    return;
  mControlSc->mFlow->SetContext( &pC->mFlow );

  SetupBP( p, size );
  mControlSc->mFlow->SendDown( mBP, check );
}
//-------------------------------------------------------------------------
void TSuperServer::NeedContextLoginMaster( unsigned int sessionID )
{
  TContainerContextSc* pC = mMngContextMaster->FindContextBySession( sessionID );
  if ( pC )
  {
    // внутренняя ошибка
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TSuperServer::LoginMaster() against try authorized.\n" );
    return;
  }
  pC = mMngContextMaster->AddContext( sessionID );
  // назначить контекст для сценария
  mControlSc->mLoginMaster->SetContext( &pC->mLoginMaster );
}
//-------------------------------------------------------------------------
void TSuperServer::NeedContextByMasterSessionByClientKey( unsigned int sessionID, unsigned int clientKey )
{
  // проверка на существование мастера
  if ( mMngContextMaster->FindContextBySession( sessionID ) == nullptr )
  {
    BL_FIX_BUG();
    return;
  }
  TContainerContextSc* pC = mMngContextClient->FindContextByClientKey( clientKey );
  bool fakeClient = false;
  if ( pC == nullptr )
  {
    // первый заход
    mMngContextMaster->AddClientKey( sessionID, clientKey );
    pC = mMngContextClient->AddContext( clientKey, sessionID );
    fakeClient = false;
  }
  else
  {
    // повторная авторизация
    pC = mContainer_SecondLogin.get();
    fakeClient = true;
  }
  mControlSc->mLoginClient->SetContext( &pC->mLoginClient );
  mControlSc->mLoginClient->SetFakeClient( fakeClient );
}
//-------------------------------------------------------------------------
void TSuperServer::NeedContextDisconnectClient( unsigned int clientKey )
{
  unsigned int id_session_master;
  // удалить запись в Мастере
  if ( mMngContextClient->FindSessionByClientKey( clientKey, id_session_master ) )
    mMngContextMaster->DeleteByClientKey( id_session_master, clientKey );
  // и сам клиент
  mMngContextClient->DeleteByKey( clientKey );
}
//-------------------------------------------------------------------------
void TSuperServer::EndDisconnectClient( IScenario* pSc )
{

}
//-------------------------------------------------------------------------
void TSuperServer::NeedContextSendToClient( unsigned int clientKey )
{
  TContainerContextSc* pContext = mMngContextClient->FindContextByClientKey( clientKey );
  if ( pContext )
    mControlSc->mSendToClient->SetContext( &pContext->mSendToClient );
  else
    mControlSc->mSendToClient->SetContext( nullptr );
}
//-------------------------------------------------------------------------
