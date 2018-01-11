/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "WBase.h"
#include <stddef.h>

#include "Logger.h"
#include "MakerNetTransport.h"
//#include "ImplementationProvider.h"
#include "EnumMMO.h"

namespace ManagedMMOEngineWrapper
{
  WBase::WBase( nsMMOEngine::TBase* pBase )
  {
    mBase = pBase;
    mMakerTransport = new TMakerNetTransport();
  }
  //-----------------------------------------------------------------------------------------
  WBase::~WBase()
  {
    delete mBase;
  }
  //-----------------------------------------------------------------------------------------
  void WBase::Init( System::String^ logName )
  {
    pin_ptr<const wchar_t> wch = PtrToStringChars( logName );
    size_t convertedChars = 0;  
    size_t  sizeInBytes = ((logName->Length + 1) * 2);  
    errno_t err = 0;  
    char    *ch = (char *)malloc(sizeInBytes);  

    err = wcstombs_s(&convertedChars,   
      ch, sizeInBytes,  
      wch, sizeInBytes);  
    if (err != 0)  
      printf_s("wcstombs_s  failed!\n");  

    printf_s("%s\n", ch);  

    GetLogger()->Register(STR_NAME_MMO_ENGINE);
    GetLogger()->Register(STR_NAME_NET_TRANSPORT);
    GetLogger()->Init( ch );
    GetLogger()->SetPrintf(false);
    GetLogger()->SetEnable(false);

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
  bool WBase::GetInfoSession( unsigned int id_session, WIP_Port^ ip_port )
  {
    TIP_Port native_ip_port;
    native_ip_port.Set(ip_port->ip, ip_port->port);

    bool result = mBase->GetInfoSession( id_session, native_ip_port );

    ip_port->Set(native_ip_port.ip, native_ip_port.port);
    return result;
  }
  //-----------------------------------------------------------------------------------------
  WBaseEvent^ WBase::GetEvent()
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
