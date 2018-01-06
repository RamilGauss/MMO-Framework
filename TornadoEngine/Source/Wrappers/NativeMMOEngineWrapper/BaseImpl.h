/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NativeMMOEngineWrapperBaseImplH
#define NativeMMOEngineWrapperBaseImplH

#include "Base.h"
#include "IBase.h"

namespace NativeMMOEngineWrapper
{
  class TBaseImpl : public IBase
  {
    nsMMOEngine::TBase* mBase;
  public:
    TBaseImpl( nsMMOEngine::TBase* pBase );
    virtual ~TBaseImpl();

    // base
    virtual void Init(nsMMOEngine::IMakerTransport* pMakerTransport);
    virtual bool Open(nsMMOEngine::TDescOpen* pDesc, int count = 1);
    virtual void DisconnectUp();
    virtual void SendUp(char* p, int size, bool check = true);
    virtual void Work();
    virtual bool IsConnectUp();
    virtual bool IsConnect(unsigned int id);
    virtual void SetLoad(int procent);
    virtual void SetTimeLiveSession(unsigned int time_ms);
    virtual bool GetInfoSession(unsigned int id_session, TIP_Port& ip_port);

  protected:
    nsMMOEngine::TBase* GetBase();
  };
}

#endif