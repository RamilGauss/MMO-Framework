/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef WrapperMMOEngineSuperServerH
#define WrapperMMOEngineSuperServerH

#include "WBaseServer.h"

namespace nsMMOEngine
{
  class TSuperServer;
}

namespace WrapperMMOEngine
{
  public ref class WDescDownSuperServer
  {
    unsigned int id_session;
    int countClient;
  };

  public ref class WSuperServer : public WBaseServer
  {
    nsMMOEngine::TSuperServer* mSuperServer;
  public:
    WSuperServer();
  };
}

#endif