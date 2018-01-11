/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagedMMOEngineWrapperWBaseServerH
#define ManagedMMOEngineWrapperWBaseServerH

#include "WBase.h"
#include <list>
#include "BaseServer.h"

namespace ManagedMMOEngineWrapper
{
  public ref class WBaseServer : public WBase
  {
    nsMMOEngine::TBaseServer* mBaseServer;
  public:
    WBaseServer( nsMMOEngine::TBaseServer* pBaseServer );

    // проверить на доверие сессию
    bool IsSessionSecurity(unsigned int id_session, void* crypt, int size_crypt, 
      void* pLogin, int sizeLogin, void* pPassword, int sizePassword);

    void SendByClientKey(std::list<unsigned int>& l, char* p, int size );

    void SendDown(unsigned int id_session, char* p, int size, bool check );
    int  GetCountDown();
    bool GetDescDown(int index, void* pDesc, int& sizeDesc);
  };
}

#endif