/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ReciverTransport.h"
#include "ManagerSession.h"
#include "INetTransport.h"
#include "CallBackRegistrator.h"

using namespace nsMMOEngine;


TReciverTransport::TReciverTransport(INetTransport* pTransport, TManagerSession* pMS)
{
	mTransport  = pTransport;
	mMngSession = pMS;

	mTransport->GetCallbackRecv()->Register(&TReciverTransport::Recv, this);
	mTransport->GetCallbackDisconnect()->Register(&TReciverTransport::Disconnect, this);
}
//----------------------------------------------------------------------
TReciverTransport::~TReciverTransport()
{
	//mTransport->GetCallbackRecv()->Unregister(this);
	//mTransport->GetCallbackDisconnect()->Unregister(this);
}
//----------------------------------------------------------------------
void TReciverTransport::Recv( INetTransport::TDescRecv* pDescRecv)
{
	mMngSession->Recv(pDescRecv, mTransport);
}
//----------------------------------------------------------------------
void TReciverTransport::Disconnect(TIP_Port* ip_port)
{
	mMngSession->Disconnect(ip_port);
}
//----------------------------------------------------------------------
