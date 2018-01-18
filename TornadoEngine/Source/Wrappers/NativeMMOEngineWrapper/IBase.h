/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NativeMMOEngineWrapperIBaseH
#define NativeMMOEngineWrapperIBaseH

#include "TypeDef.h"
#include "ShareMisc.h"
#include "Structs.h"
#include "IMakerTransport.h"

namespace NativeMMOEngineWrapper
{
  interface class DllExport IBase
  {
  public:
    virtual void Init(nsMMOEngine::IMakerTransport* pMakerTransport) = 0;
    virtual bool Open(nsMMOEngine::TDescOpen* pDesc, int count = 1) = 0;
    virtual void DisconnectUp() = 0;
    virtual void SendUp(char* p, int size, bool check = true) = 0;
    virtual void Work() = 0;
    virtual bool IsConnectUp() = 0;
    virtual bool IsConnect(unsigned int id) = 0;
    virtual void SetLoad(int procent) = 0;
    virtual void SetTimeLiveSession(unsigned int time_ms) = 0;
    virtual bool GetInfoSession(unsigned int id_session, TIP_Port& ip_port) = 0;
  };
}

#endif