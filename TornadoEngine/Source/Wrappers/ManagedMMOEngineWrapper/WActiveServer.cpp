/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "WBaseServer.h"
#include "WActiveServer.h"

namespace ManagedMMOEngineWrapper
{
  WActiveServer::WActiveServer( NativeMMOEngineWrapper::IActiveServer* pActiveServer  ) 
    : WBaseServer( (NativeMMOEngineWrapper::IBaseServer*)pActiveServer )
  {
    mActiveServer = pActiveServer;
  }
  //------------------------------------------------------------------------------
  void WActiveServer::ConnectUp(unsigned int ip, unsigned short port,  
    void* pLogin, int sizeLogin, void* pPassword, int sizePassword,
    unsigned char subNet )
  {
    mActiveServer->ConnectUp(ip, port, pLogin, sizeLogin, pPassword, sizePassword, subNet);
  }
  //------------------------------------------------------------------------------
}
