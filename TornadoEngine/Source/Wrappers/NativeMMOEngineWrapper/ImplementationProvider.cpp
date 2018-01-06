/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ImplementationProvider.h"
#include "ClientImpl.h"
#include "SlaveImpl.h"
#include "MasterImpl.h"
#include "SuperServerImpl.h"

namespace NativeMMOEngineWrapper
{
  IClient* TImplementationProvider::MakeClient()
  {
    return new TClientImpl();
  }
  //-----------------------------------------------------------------
  ISlave* TImplementationProvider::MakeSlave()
  {
    return new TSlaveImpl();
  }
  //-----------------------------------------------------------------
  IMaster* TImplementationProvider::MakeMaster()
  {
    return new TMasterImpl();
  }
  //-----------------------------------------------------------------
  ISuperServer* TImplementationProvider::MakeSuperServer()
  {
    return new TSuperServerImpl();
  }
  //-----------------------------------------------------------------
  void TImplementationProvider::Delete(IBase* pBase)
  {
    delete pBase;
  }
  //-----------------------------------------------------------------
}
