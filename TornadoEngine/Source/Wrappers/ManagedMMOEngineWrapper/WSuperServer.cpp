/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "WSuperServer.h"
#include "ImplementationProvider.h"

namespace ManagedMMOEngineWrapper
{
  WSuperServer::WSuperServer() 
    : WBaseServer( (NativeMMOEngineWrapper::IBaseServer*)NativeMMOEngineWrapper::TImplementationProvider::MakeSuperServer() )
  {
    mSuperServer = (NativeMMOEngineWrapper::ISuperServer*)GetBase();
  }
}
