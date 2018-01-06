/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ActiveServerImpl.h"

namespace NativeMMOEngineWrapper
{
  TActiveServerImpl::TActiveServerImpl( nsMMOEngine::TActiveServer* pActiveServer ) :
    TBaseServerImpl( pActiveServer )
  {
    mActiveServer = (nsMMOEngine::TActiveServer*)GetBase();
  }
  //------------------------------------------------------------------------------
  void TActiveServerImpl::ConnectUp(unsigned int ip, unsigned short port,  
    void* pLogin, int sizeLogin, void* pPassword, int sizePassword,
    unsigned char subNet )
  {
    mActiveServer->ConnectUp(ip, port, pLogin, sizeLogin, pPassword, sizePassword, subNet );
  }
  //------------------------------------------------------------------------------
}
