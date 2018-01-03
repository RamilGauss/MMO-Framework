/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "WBaseServer.h"
#include "ActiveServer.h"
#include "WActiveServer.h"

namespace WrapperMMOEngine
{
  WActiveServer::WActiveServer( nsMMOEngine::TActiveServer* pActiveServer ) : WBaseServer( pActiveServer )
  {
    mActiveServer = (nsMMOEngine::TActiveServer*)GetBase();
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
