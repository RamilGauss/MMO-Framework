/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagedMMOEngineWrapperWActiveServerH
#define ManagedMMOEngineWrapperWActiveServerH

#include "WBaseServer.h"
#include "ActiveServer.h"

namespace ManagedMMOEngineWrapper
{
  public ref class WActiveServer : public WBaseServer
  {
    nsMMOEngine::TActiveServer* mActiveServer;
  public:
    WActiveServer( nsMMOEngine::TActiveServer* pActiveServer );

    void ConnectUp(unsigned int ip, unsigned short port,  
      void* pLogin, int sizeLogin, void* pPassword, int sizePassword,
      unsigned char subNet );
  };
}

#endif