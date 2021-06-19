/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ScRecommutationClient_MasterImpl.h"
#include "ContextScRecommutationClient.h"
#include "SessionManager.h"
#include "BL_Debug.h"
#include "DescRequestConnectForRecipient.h"

using namespace nsMMOEngine;
using namespace nsRecommutationClientStruct;

TScRecommutationClient_MasterImpl::TScRecommutationClient_MasterImpl( IScenario* pSc ) :
  TBaseScRecommutationClient( pSc )
{

}
//--------------------------------------------------------------------------------------
void TScRecommutationClient_MasterImpl::Work( unsigned int time_ms )
{

}
//--------------------------------------------------------------------------------------
void TScRecommutationClient_MasterImpl::RecvInherit( TDescRecvSession* pDesc )
{
  THeader* pHeader = (THeader*) pDesc->data;
  switch ( pHeader->from )
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
void TScRecommutationClient_MasterImpl::RecvFromSlaveDonor( TDescRecvSession* pDesc )
{
  THeader* pHeader = (THeader*) pDesc->data;
  switch ( pHeader->subType )
  {
    case eCheckBeginDonor:
      CheckBeginDonor( pDesc );
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------------------------------
void TScRecommutationClient_MasterImpl::RecvFromSlaveRecipient( TDescRecvSession* pDesc )
{
  THeader* pHeader = (THeader*) pDesc->data;
  switch ( pHeader->subType )
  {
    case eCheckBeginRecipient:
      CheckBeginRecipient( pDesc );
      break;
    case eClientConnect:
      ClientConnect( pDesc );
      break;
    default:BL_FIX_BUG();
  }
}
//--------------------------------------------------------------------------------------
void TScRecommutationClient_MasterImpl::Start( unsigned int recipientSessionID, unsigned int clientKey )
{
  Context()->SetClientKey( clientKey );
  Context()->SetSessionRecipient( recipientSessionID );
  if ( Begin() == false )
  {
    return;
  }
  SendFirstPacket();
}
//--------------------------------------------------------------
void TScRecommutationClient_MasterImpl::DelayBegin()
{
  SendFirstPacket();
}
//--------------------------------------------------------------
void TScRecommutationClient_MasterImpl::SendFirstPacket()
{
  // откуда уходим?
  NeedSessionDonorByClientKey( mScenario );
  // сценарий активен
  EventActivate();
  // проверка на совпадение  Донора с Реципиентом
  if ( Context()->GetSessionDonor() == Context()->GetSessionRecipient() )
  {
    End();
    return;
  }

  mBP.Reset();
  THeaderBeginDonor h;
  h.clientKey = Context()->GetClientKey();
  mBP.PushFront( (char*) &h, sizeof( h ) );
  Context()->GetMS()->Send( Context()->GetSessionDonor(), mBP );
}
//--------------------------------------------------------------
void TScRecommutationClient_MasterImpl::CheckBeginDonor( TDescRecvSession* pDesc )
{
  THeaderCheckBeginDonor* pHeader = (THeaderCheckBeginDonor*) pDesc->data;
  NeedContextByClientKey( pHeader->clientKey );
  if ( Context() == nullptr )
  {
    return;
  }
  // запомнить число, которое знают только участники перекоммутации
  TDescRequestConnectForRecipient privateNum;
  privateNum.Generate();
  Context()->SetRandomNum( privateNum.random_num );

  mBP.Reset();
  // поместить контекст Донора в пакет
  mBP.PushFront( pDesc->data + sizeof( THeaderCheckBeginDonor ),
    pDesc->dataSize - sizeof( THeaderCheckBeginDonor ) );

  THeaderBeginRecipient h;
  h.clientKey = Context()->GetClientKey();
  h.random_num = privateNum.random_num;
  mBP.PushFront( (char*) &h, sizeof( h ) );

  Context()->GetMS()->Send( Context()->GetSessionRecipient(), mBP );
}
//--------------------------------------------------------------
void TScRecommutationClient_MasterImpl::CheckBeginRecipient( TDescRecvSession* pDesc )
{
  THeaderCheckBeginRecipient* pHeader = (THeaderCheckBeginRecipient*) pDesc->data;
  NeedContextByClientKey( pHeader->clientKey );
  if ( Context() == nullptr )
  {
    return;
  }
  //==============================================
  // узнать IP и порт Реципиента
  TIP_Port ip_port_recipient;
  bool resIP_recipient =
    Context()->GetMS()->GetInfo( Context()->GetSessionRecipient(), ip_port_recipient );
  if ( resIP_recipient == false )
  {
    End();
    BL_FIX_BUG();
    return;
  }
  //==============================================
  mBP.Reset();
  THeaderInfoRecipientToDonor h;
  h.clientKey = Context()->GetClientKey();
  h.random_num = Context()->GetRandomNum();
  h.ip_port_recipient = ip_port_recipient;
  mBP.PushFront( (char*) &h, sizeof( h ) );

  Context()->GetMS()->Send( Context()->GetSessionDonor(), mBP );
}
//--------------------------------------------------------------
void TScRecommutationClient_MasterImpl::ClientConnect( TDescRecvSession* pDesc )
{
  THeaderClientConnect* pHeader = (THeaderClientConnect*) pDesc->data;
  NeedContextByClientKey( pHeader->clientKey );
  if ( Context() == nullptr )
    return;

  End();
}
//--------------------------------------------------------------
void TScRecommutationClient_MasterImpl::DisconnectClient()
{
  // уведомить Реципиента о потере связи с Клиентом
  mBP.Reset();
  THeaderDisconnectClient h;
  h.clientKey = Context()->GetClientKey();
  mBP.PushFront( (char*) &h, sizeof( h ) );
  Context()->GetMS()->Send( Context()->GetSessionRecipient(), mBP );
  //Нельзя вызывать End();
}
//--------------------------------------------------------------

