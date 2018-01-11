/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NativeMMOEngineWrapperBaseServerImplH
#define NativeMMOEngineWrapperBaseServerImplH

#include "IBaseServer.h"
#include "BaseServer.h"
#include "BaseImpl.h"

namespace NativeMMOEngineWrapper
{
  class TBaseServerImpl : public TBaseImpl, public IBaseServer
  {
    nsMMOEngine::TBaseServer* mBaseServer;
  public:
    TBaseServerImpl( nsMMOEngine::TBaseServer* pBaseServer );

    // base server
    virtual bool IsSessionSecurity(unsigned int id_session, void* crypt, int size_crypt, 
      void* pLogin, int sizeLogin, void* pPassword, int sizePassword);
    virtual void DisconnectByKeyClient(unsigned int id_client);
    virtual void SendByClientKey(std::list<unsigned int>& l, char* p, int size );
    virtual void SendDown(unsigned int id_session, char* p, int size, bool check = true );
    virtual int  GetCountDown();
    virtual bool GetDescDown(int index, void* pDesc, int& sizeDesc);
  };
}

#endif