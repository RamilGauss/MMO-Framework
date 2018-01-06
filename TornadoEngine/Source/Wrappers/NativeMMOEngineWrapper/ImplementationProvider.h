/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NativeMMOEngineWrapperImplementationProviderH
#define NativeMMOEngineWrapperImplementationProviderH

#include "IBase.h"
#include "IClient.h"
#include "ISlave.h"
#include "IMaster.h"
#include "ISuperServer.h"

namespace NativeMMOEngineWrapper
{
  class DllExport TImplementationProvider
  {
  public:
    static IClient* MakeClient();
    static ISlave* MakeSlave();
    static IMaster* MakeMaster();
    static ISuperServer* MakeSuperServer();

    static void Delete(IBase* pBase);
  };
}

#endif
