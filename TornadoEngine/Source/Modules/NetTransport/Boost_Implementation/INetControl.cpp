/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "INetControl.h"
#include "NetTransport_Boost.h"

INetControl::INetControl(TNetTransport_Boost* pNetTransportBoost)
{
  mNetTransportBoost = pNetTransportBoost;
}
//------------------------------------------------------------------------------
INetControl::~INetControl()
{

}
//------------------------------------------------------------------------------
TNetTransport_Boost* INetControl::GetNetBoost()
{
  return mNetTransportBoost;
}
//------------------------------------------------------------------------------
void INetControl::NotifyRecv(INetTransport::TDescRecv* p)
{
	mNetTransportBoost->GetCallbackRecv()->Notify(p);
}
//------------------------------------------------------------------------------
void INetControl::NotifyDisconnect(TIP_Port* p)
{
	mNetTransportBoost->GetCallbackDisconnect()->Notify(p);
}
//------------------------------------------------------------------------------
