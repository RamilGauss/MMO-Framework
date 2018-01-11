/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NativeMMOEngineWrapperClientImplH
#define NativeMMOEngineWrapperClientImplH

#include "Client.h"
#include "IClient.h"
#include "BaseImpl.h"

namespace NativeMMOEngineWrapper
{
  class TClientImpl : public TBaseImpl, public IClient
  {
    nsMMOEngine::TClient* mClient;

  public:
    TClientImpl();

    // client
    virtual void Login(unsigned int ip, unsigned short port, 
      void* pLogin, int sizeLogin, void* pPassword, int sizePassword);
    virtual void LeaveQueue();
  };
}

#endif