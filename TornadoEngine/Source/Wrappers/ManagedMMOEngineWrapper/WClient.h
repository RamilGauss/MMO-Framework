/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagedMMOEngineWrapperWClientH
#define ManagedMMOEngineWrapperWClientH

#include "WBase.h"
#include "Client.h"

namespace ManagedMMOEngineWrapper
{
  public ref class WClient : public WBase
  {
    nsMMOEngine::TClient* mClient;
  public:
    WClient();

    void Login(unsigned int ip, unsigned short port, 
      void* pLogin, int sizeLogin, void* pPassword, int sizePassword);
    void LeaveQueue();
  };
}

#endif