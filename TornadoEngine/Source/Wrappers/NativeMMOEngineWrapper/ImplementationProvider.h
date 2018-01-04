/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NativeMMOEngineWrapperISlaveH
#define NativeMMOEngineWrapperISlaveH

namespace NativeMMOEngineWrapper
{
  class DllExport TImplementationProvider
  {
  public:
    TImplementationProvider();

    IClient* MakeClient();
    ISlave* MakeSlave();
    IMaster* MakeMaster();
    ISuperServer* MakeSuperServer();
  };
}

#endif
