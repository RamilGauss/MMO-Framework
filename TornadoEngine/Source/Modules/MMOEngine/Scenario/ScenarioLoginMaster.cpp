/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ScenarioLoginMaster.h"
#include "Logger.h"
#include "SessionManager.h"
#include "Events.h"
#include "EnumMMO.h"
#include "SrcEvent_ex.h"

using namespace nsMMOEngine;

TScenarioLoginMaster::TScenarioLoginMaster()
{

}
//--------------------------------------------------------------
TScenarioLoginMaster::~TScenarioLoginMaster()
{

}
//--------------------------------------------------------------
void TScenarioLoginMaster::ConnectToSuperServer( TIP_Port& ip_port, std::string& login, std::string& password, unsigned char subNet )
{
  if( Begin() == false )
  {
    End();
    // верхнее соединение занято выполнением другого сценария - такого не должно быть
    // внутренняя ошибка
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TScenarioLoginMaster::ConnectToSuperServer() scenario is not active.\n" );
    BL_FIX_BUG();
    return;
  }
  Context()->GetMS()->CloseSession( Context()->GetSessionID() );
  Context()->SetSessionID( INVALID_HANDLE_SESSION );

  auto context = Context();
  auto scenario = this;
  Context()->GetMS()->ConnectAsync( ip_port, login, password, subNet, [scenario, context]( int sessionID )
  {
    scenario->SetContext( context );
    scenario->ConnectToSuperServerAfterConnect( sessionID );
  } );
}
//--------------------------------------------------------------
void TScenarioLoginMaster::ConnectToSuperServerAfterConnect( int sessionID )// transport thread
{
  if( sessionID == INVALID_HANDLE_SESSION )
  {
    // Генерация ошибки
    TErrorEvent event;
    event.code = LoginMaster_SSNotReady;
    Context()->GetSE()->AddEventCopy( &event, sizeof( event ) );
    End();
    return;
  }
  Context()->SetSessionID( sessionID );
  // создать пакет
  mBP.Reset();
  THeaderFromMaster h;
  mBP.PushFront( (char*) &h, sizeof( h ) );
  Context()->GetMS()->Send( sessionID, mBP, true );
  Context()->SetTimeWait( ht_GetMSCount() + eTimeoutWait_ms );
}
//--------------------------------------------------------------
void TScenarioLoginMaster::Work()
{
  // если нет связи с верхним соединением, ждем соединения, если не дождемся нам об этом сообщит SessionManager
  if( Context()->GetSessionID() == INVALID_HANDLE_SESSION )
    return;

  unsigned int now = ht_GetMSCount();
  if( Context()->GetTimeWait() < now )
  {
    // ошибка на той стороне
    TErrorEvent event;
    event.code = LoginMaster_NoAnswerFromSS;
    Context()->GetSE()->AddEventCopy( &event, sizeof( event ) );
    End();
  }
}
//--------------------------------------------------------------
void TScenarioLoginMaster::RecvFromSuperServer( TDescRecvSession* pDesc )
{
  End();
}
//-------------------------------------------------------------------------------------
void TScenarioLoginMaster::RecvFromMaster( TDescRecvSession* pDesc )
{
  if( Begin() == false )
  {
    End();
    // верхнее соединение занято выполнением другого сценария - такого не должно быть
    // внутренняя ошибка
    GetLogger( STR_NAME_MMO_ENGINE )->
      WriteF_time( "TScenarioLoginMaster::RecvFromMaster() scenario is not active.\n" );
    BL_FIX_BUG();
    return;
  }
  Context()->SetSessionID( pDesc->sessionID );

  // событие наружу
  TConnectDownEvent* pEvent = new TConnectDownEvent;
  pEvent->sessionID = pDesc->sessionID;
  // сохранить информацию о логине и пароле клиента
  char* data = pDesc->data + sizeof( THeaderFromMaster );
  int dataSize = pDesc->dataSize - sizeof( THeaderFromMaster );
  pEvent->c.SetDataByCount( data, dataSize );
  Context()->GetSE()->AddEventWithoutCopy<TConnectDownEvent>( pEvent );

  mBP.Reset();
  THeaderAnswerFromSS h;
  mBP.PushFront( (char*) &h, sizeof( h ) );
  Context()->GetMS()->Send( Context()->GetSessionID(), mBP );
  End();
}
//-------------------------------------------------------------------------------------
void TScenarioLoginMaster::Recv( TDescRecvSession* pDesc )
{
  NeedContextBySession( pDesc->sessionID );
  THeaderLoginMaster* pPacket = (THeaderLoginMaster*) pDesc->data;
  switch( pPacket->subType )
  {
    case eFromMaster:
      RecvFromMaster( pDesc );
      break;
    case eAnswerFromSS:
      RecvFromSuperServer( pDesc );
      break;
    default:BL_FIX_BUG();
  }
}
//-------------------------------------------------------------------------------------
