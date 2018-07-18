/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "INetControl.h"
#include "NetTransport_Boost.h"

INetControl::INetControl( TNetTransport_Boost* pNetTransportBoost )
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
void INetControl::NotifyRecv( nsMMOEngine::INetTransport::TDescRecv* p )
{
  mNetTransportBoost->GetCallbackRecv()->Notify( p );
}
//------------------------------------------------------------------------------
void INetControl::NotifyDisconnect( TIP_Port* p, TNetTransport_Boost* pNetTransportBoost )
{
  // требует пояснения: передается указатель pNetTransportBoost, потому что
  // при разрыве соединения объект типа INetControl* будет удален,
  // но тогда будет нельзя уведомить, т.к. информация внутри объекта будет уничтожена
  // Но удалять позже самого уведомления нельзя, потому что другой поток,
  // который использует данное событие опередит удаление объекта
  // и удаление произойдет в процессе работы с объектом.
  pNetTransportBoost->GetCallbackDisconnect()->Notify( p );
}
//------------------------------------------------------------------------------
