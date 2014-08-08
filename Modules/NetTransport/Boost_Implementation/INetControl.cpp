/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "INetControl.h"

static TNetTransport_Boost* g_pNetTransportBoost = NULL;

static TCallBackRegistrator1<INetTransport::TDescRecv*> mCallBackRecv;
static TCallBackRegistrator1<TIP_Port*>                 mCallBackDisconnect;

INetControl::INetControl()
{

}
//------------------------------------------------------------------------------
INetControl::~INetControl()
{

}
//------------------------------------------------------------------------------
void INetControl::SetNetBoost(TNetTransport_Boost* pNM)
{
  g_pNetTransportBoost = pNM;
}
//------------------------------------------------------------------------------
TNetTransport_Boost* INetControl::GetNetBoost()
{
  return g_pNetTransportBoost;
}
//------------------------------------------------------------------------------
void INetControl::NotifyRecv(INetTransport::TDescRecv* p)
{
	mCallBackRecv.Notify(p);
}
//------------------------------------------------------------------------------
void INetControl::NotifyDisconnect(TIP_Port* p)
{
	mCallBackDisconnect.Notify(p);
}
//------------------------------------------------------------------------------
TCallBackRegistrator1<INetTransport::TDescRecv*>* INetControl::GetCallbackRecv()
{
  return &mCallBackRecv;
}
//------------------------------------------------------------------------------
TCallBackRegistrator1<TIP_Port* >* INetControl::GetCallbackDisconnect()
{
  return &mCallBackDisconnect;
}
//------------------------------------------------------------------------------