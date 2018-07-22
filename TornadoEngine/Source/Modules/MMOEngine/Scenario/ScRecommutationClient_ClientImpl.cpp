/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ScRecommutationClient_ClientImpl.h"
#include "ContextScRecommutationClient.h"
#include "Logger.h"
#include "SessionManager.h"
#include "Events.h"

using namespace nsMMOEngine;
using namespace nsRecommutationClientStruct;

TScRecommutationClient_ClientImpl::TScRecommutationClient_ClientImpl( IScenario* pSc ) :
  TBaseScRecommutationClient( pSc )
{

}
//--------------------------------------------------------------------------------------
void TScRecommutationClient_ClientImpl::Work( unsigned int time_ms )
{

}
//--------------------------------------------------------------------------------------
void TScRecommutationClient_ClientImpl::RecvInherit( TDescRecvSession* pDesc )
{
  THeader* pHeader = (THeader*) pDesc->data;
  switch( pHeader->from )
  {
    case eSlaveDonor:
      RecvFromSlaveDonor( pDesc );
      break;
    case eSlaveRecipient:
      RecvFromSlaveRecipient( pDesc );
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------------------------------
void TScRecommutationClient_ClientImpl::RecvFromSlaveDonor( TDescRecvSession* pDesc )
{
  THeader* pHeader = (THeader*) pDesc->data;
  switch( pHeader->subType )
  {
    case eBeginClient:
      BeginClient( pDesc );
      break;
    case eInfoRecipientToClient:
      InfoRecipientToClient( pDesc );
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------------------------------
void TScRecommutationClient_ClientImpl::RecvFromSlaveRecipient( TDescRecvSession* pDesc )
{
  THeader* pHeader = (THeader*) pDesc->data;
  switch( pHeader->subType )
  {
    case eCheckRequestConnect:
      CheckRequestConnect( pDesc );
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------------------------------
void TScRecommutationClient_ClientImpl::BeginClient( TDescRecvSession* pDesc )
{
  THeaderBeginClient* pHeader = (THeaderBeginClient*) pDesc->data;
  // запомнить свой ключ, но хотя он и так известен.
  // это нужно для простоты
  Context()->SetClientKey( pHeader->clientID );
  SetID_SessionClientSlave( pDesc->sessionID );
  // начало сценария
  if( Begin() == false )
  {
    // генерация ошибки
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TScRecommutationClient_ClientImpl::BeginClient() scenario is not active.\n" );
    BL_FIX_BUG();
    return;
  }
  // сформировать пакет далее для Slave
  mBP.Reset();
  THeaderCheckBeginClient h;
  h.clientID = Context()->GetClientKey();
  mBP.PushFront( (char*) &h, sizeof( h ) );

  Context()->GetMS()->Send( GetID_SessionClientSlave(), mBP );
}
//--------------------------------------------------------------
void TScRecommutationClient_ClientImpl::InfoRecipientToClient( TDescRecvSession* pDesc )
{
  THeaderInfoRecipientToClient* pHeader = (THeaderInfoRecipientToClient*) pDesc->data;
  Context()->SetIP_PortRecipient( pHeader->ip_port_recipient );
  // запомнить число, пригодится при запросе к реципиенту
  Context()->SetRandomNum( pHeader->random_num );
  // сформировать пакет далее для Slave
  mBP.Reset();
  THeaderCheckInfoRecipient h;
  h.clientID = Context()->GetClientKey();
  mBP.PushFront( (char*) &h, sizeof( h ) );

  Context()->GetMS()->Send( GetID_SessionClientSlave(), mBP );
  // ждем дисконнекта
}
//--------------------------------------------------------------
void TScRecommutationClient_ClientImpl::CheckRequestConnect( TDescRecvSession* pDesc )
{
  End();
}
//--------------------------------------------------------------
void TScRecommutationClient_ClientImpl::DisconnectClient( unsigned char subNet )
{
  TIP_Port ip_port_recipient;
  Context()->GetIP_PortRecipient( ip_port_recipient );

  auto context = Context();
  auto scenario = this;
  auto login = Context()->GetLogin();
  auto password = Context()->GetPassword();
  Context()->GetMS()->ConnectAsync( ip_port_recipient, login, password, subNet, [scenario, context]( int sessionID )
  {
    scenario->SetContext( context );
    scenario->DisconnectClientAfterConnect( sessionID );
  } );
}
//--------------------------------------------------------------
void TScRecommutationClient_ClientImpl::DisconnectClientAfterConnect( int id_session_recipient )
{
  // подсоединились?
  if( id_session_recipient == INVALID_HANDLE_SESSION )
  {
    // нет связи с Реципиентом
    End();
    return;
  }

  mBP.Reset();
  THeaderRequestConnect h;
  h.clientID = Context()->GetClientKey();
  h.random_num = Context()->GetRandomNum();
  mBP.PushFront( (char*) &h, sizeof( h ) );
  Context()->GetMS()->Send( id_session_recipient, mBP, true );
  // запомнить на будущее
  Context()->SetSessionRecipient( id_session_recipient );
  Context()->SetSessionID( id_session_recipient );
}
//--------------------------------------------------------------
void TScRecommutationClient_ClientImpl::SetLoginPassword( std::string& login, std::string& password )
{
  Context()->SetLogin( login );
  Context()->SetPassword( password );
}
//--------------------------------------------------------------
