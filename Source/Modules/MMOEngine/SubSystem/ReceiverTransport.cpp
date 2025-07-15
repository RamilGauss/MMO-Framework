/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/CallBackRegistrator.h"
#include "MMOEngine/Include/INetTransport.h"
#include "MMOEngine/SubSystem/ReceiverTransport.h"
#include "MMOEngine/SubSystem/SessionManager.h"

using namespace nsMMOEngine;

TReceiverTransport::TReceiverTransport(INetTransport* pTransport, TSessionManager* pMS)
{
    mTransport = pTransport;
    mMngSession = pMS;

    mTransport->GetCallbackRecv()->Register(this, &TReceiverTransport::Recv);
    mTransport->GetCallbackDisconnect()->Register(this, &TReceiverTransport::Disconnect);
    mTransport->GetCallbackConnectFrom()->Register(this, &TReceiverTransport::ConnectFrom);
}
//----------------------------------------------------------------------
TReceiverTransport::~TReceiverTransport()
{
}
//----------------------------------------------------------------------
void TReceiverTransport::Recv(INetTransport::TDescRecv* pDescRecv)
{
    mMngSession->Recv(pDescRecv);
}
//----------------------------------------------------------------------
void TReceiverTransport::Disconnect(TIP_Port* ip_port)
{
    mMngSession->Disconnect(ip_port);
}
//----------------------------------------------------------------------
void TReceiverTransport::ConnectFrom(TIP_Port* ip_port)
{
    mMngSession->ConnectFrom(ip_port, mTransport);
}
//----------------------------------------------------------------------
