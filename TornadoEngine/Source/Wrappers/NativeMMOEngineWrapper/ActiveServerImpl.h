/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NativeMMOEngineWrapperActiveServerImplH
#define NativeMMOEngineWrapperActiveServerImplH

#include "IActiveServer.h"
#include "ActiveServer.h"
#include "BaseServerImpl.h"

namespace NativeMMOEngineWrapper
{
  class TActiveServerImpl : public TBaseServerImpl, public IActiveServer
  {
    nsMMOEngine::TActiveServer* mActiveServer;
  public:
    TActiveServerImpl(nsMMOEngine::TActiveServer* pActiveServer);

    // active server
    virtual void ConnectUp(unsigned int ip, unsigned short port,  
      void* pLogin, int sizeLogin, void* pPassword, int sizePassword,
      unsigned char subNet = 0);
  };
}

#endif