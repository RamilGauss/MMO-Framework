/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ReceiverTransport.h"
#include "SessionManager.h"
#include "INetTransport.h"
#include "CallBackRegistrator.h"

using namespace nsMMOEngine;

TReceiverTransport::TReceiverTransport( INetTransport* pTransport, TSessionManager* pMS )
{
  mTransport = pTransport;
  mMngSession = pMS;

  mTransport->GetCallbackRecv()->Register( &TReceiverTransport::Recv, this );
  mTransport->GetCallbackDisconnect()->Register( &TReceiverTransport::Disconnect, this );
  mTransport->GetCallbackConnectFrom()->Register( &TReceiverTransport::ConnectFrom, this );
}
//----------------------------------------------------------------------
TReceiverTransport::~TReceiverTransport()
{
}
//----------------------------------------------------------------------
void TReceiverTransport::Recv( INetTransport::TDescRecv* pDescRecv )
{
  mMngSession->Recv( pDescRecv );
}
//----------------------------------------------------------------------
void TReceiverTransport::Disconnect( TIP_Port* ip_port )
{
  mMngSession->Disconnect( ip_port );
}
//----------------------------------------------------------------------
void TReceiverTransport::ConnectFrom( TIP_Port* ip_port )
{
  mMngSession->ConnectFrom( ip_port, mTransport );
}
//----------------------------------------------------------------------
