/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagedMMOEngineWrapperWBaseH
#define ManagedMMOEngineWrapperWBaseH

#include "IBase.h"
#include "IMakerTransport.h"

#include "WIP_Port.h"
#include "WBaseEvent.h"

namespace ManagedMMOEngineWrapper
{
  class WDescOpen;
  public ref class WBase
  {
    NativeMMOEngineWrapper::IBase* mBase;
    nsMMOEngine::IMakerTransport* mMakerTransport;
  public:
    WBase( NativeMMOEngineWrapper::IBase* pBase );
    virtual ~WBase();

    void Init();
    bool Open( WDescOpen* pDesc, int count );
    void DisconnectUp();
    void SendUp( char* p, int size, bool check );
    void Work();
    bool IsConnectUp();
    bool IsConnect( unsigned int id );
    void SetLoad( int procent );
    void SetTimeLiveSession( unsigned int time_ms );
    bool GetInfoSession( unsigned int id_session, WIP_Port^ ip_port );
  public:
    WBaseEvent^ GetEvent();
  protected:
    void SetBase(NativeMMOEngineWrapper::IBase* pBase);
    NativeMMOEngineWrapper::IBase* GetBase();
  };
}

#endif