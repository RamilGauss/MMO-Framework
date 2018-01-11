/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NativeMMOEngineWrapperSuperServerImplH
#define NativeMMOEngineWrapperSuperServerImplH

#include "ISuperServer.h"
#include "SuperServer.h"
#include "BaseServerImpl.h"

namespace NativeMMOEngineWrapper
{
  class TSuperServerImpl : public TBaseServerImpl, public ISuperServer
  {
    nsMMOEngine::TSuperServer* mSuperServer;
  public:
    TSuperServerImpl();
  };
}

#endif