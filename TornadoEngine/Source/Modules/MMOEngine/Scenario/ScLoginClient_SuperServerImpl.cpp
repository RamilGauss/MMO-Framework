/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ScLoginClient_SuperServerImpl.h"
#include "Logger.h"
#include "ContextScLoginClient.h"
#include "SessionManager.h"
#include "Events.h"
#include "EnumMMO.h"

using namespace nsMMOEngine;
using namespace nsLoginClientStruct;

TScLoginClient_SuperServerImpl::TScLoginClient_SuperServerImpl( IScenario* pSc ) :
  TBaseScLoginClient( pSc )
{

}
//-----------------------------------------------------------------------------
void TScLoginClient_SuperServerImpl::RecvInherit( TDescRecvSession* pDesc )
{
  THeader* pHeader = (THeader*) pDesc->data;
  switch( pHeader->from )
  {
    case eMaster:
      RecvFromMaster( pDesc );
      break;
    default:BL_FIX_BUG();
  }
}
//-----------------------------------------------------------------------------
void TScLoginClient_SuperServerImpl::Work( unsigned int time_ms )
{
  BL_FIX_BUG();
}
//-----------------------------------------------------------------------------
void TScLoginClient_SuperServerImpl::RecvFromMaster( TDescRecvSession* pDesc )
{
  THeader* pHeader = (THeader*) pDesc->data;
  switch( pHeader->subType )
  {
    case eRequestM2SS:
      RequestM2SS( pDesc );
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------
void TScLoginClient_SuperServerImpl::RequestM2SS( TDescRecvSession* pDesc )
{
  unsigned int id_session_master = pDesc->sessionID;

  THeaderRequestM2SS* pRequest = (THeaderRequestM2SS*) pDesc->data;
  NeedContextByMasterSessionByClientKey( id_session_master, pRequest->clientKey );

  bool isExist = false;
  if( Context()->GetFakeClient() )
    isExist = true;
  // проверка
  if( Begin() == false )
  {
    BL_FIX_BUG();
  }
  End();
  // формирование пакета
  mBP.Reset();
  THeaderCheckRequestSS2M h;
  h.clientKey = pRequest->clientKey;
  h.isExistInSystem = isExist;
  mBP.PushFront( (char*) &h, sizeof( h ) );
  // отослать пакет для попытки авторизации
  Context()->GetMS()->Send( id_session_master, mBP );
}
//--------------------------------------------------------------
void TScLoginClient_SuperServerImpl::SetFakeClient( bool val )
{
  Context()->SetFakeClient( val );
}
//--------------------------------------------------------------
