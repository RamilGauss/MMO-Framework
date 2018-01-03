/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "WBase.h"
#include "Base.h"
#include <stddef.h>
#include "MakerNetTransport.h"
#include "DstEvent.h"

namespace WrapperMMOEngine
{
  WBase::WBase( nsMMOEngine::TBase* pBase )
  {
    mBase = pBase;

    mMakerTransport = new TMakerNetTransport();
    mDstEvent = new TDstEvent();
  }
  //-----------------------------------------------------------------------------------------
  WBase::~WBase()
  {
    delete mMakerTransport;
    delete mBase;
  }
  //-----------------------------------------------------------------------------------------
  void WBase::Init()
  {
    mBase->Init( mMakerTransport );
  }
  //-----------------------------------------------------------------------------------------
  bool WBase::Open( WDescOpen* pDesc, int count )
  {
    return mBase->Open( NULL, count);
  }
  //-----------------------------------------------------------------------------------------
  void WBase::DisconnectUp()
  {
    mBase->DisconnectUp();
  }
  //-----------------------------------------------------------------------------------------
  void WBase::SendUp( char* p, int size, bool check )
  {
    mBase->SendUp( p, size, check );
  }
  //-----------------------------------------------------------------------------------------
  void WBase::Work()
  {
    mBase->Work();
  }
  //-----------------------------------------------------------------------------------------
  bool WBase::IsConnectUp()
  {
    return mBase->IsConnectUp();
  }
  //-----------------------------------------------------------------------------------------
  bool WBase::IsConnect( unsigned int id )
  {
    return mBase->IsConnect( id );
  }
  //-----------------------------------------------------------------------------------------
  void WBase::SetLoad( int procent )
  {
    mBase->SetLoad( procent );
  }
  //-----------------------------------------------------------------------------------------
  void WBase::SetTimeLiveSession( unsigned int time_ms )
  {
    mBase->SetLoad( time_ms );
  }
  //-----------------------------------------------------------------------------------------
  bool WBase::GetInfoSession( unsigned int id_session, WrapperBase::WIP_Port^ ip_port )
  {
    TIP_Port native_ip_port;
    native_ip_port.Set(ip_port->ip, ip_port->port);

    bool result = mBase->GetInfoSession( id_session, native_ip_port );

    ip_port->Set(native_ip_port.ip, native_ip_port.port);
    return result;
  }
  //-----------------------------------------------------------------------------------------
  WBaseEvent* WBase::GetEvent()
  {
    return nullptr;
  }
  //-----------------------------------------------------------------------------------------
  nsMMOEngine::TBase* WBase::GetBase()
  {
    return mBase;
  }
  //-----------------------------------------------------------------------------------------
}
