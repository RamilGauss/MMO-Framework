/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "WBaseServer.h"
#include "BaseServer.h"

namespace WrapperMMOEngine
{
  WBaseServer::WBaseServer( nsMMOEngine::TBaseServer* pBaseServer ) : WBase( pBaseServer )
  {
    mBaseServer = (nsMMOEngine::TBaseServer*)GetBase();
  }
  //-------------------------------------------------------------------------------
  bool WBaseServer::IsSessionSecurity(unsigned int id_session, void* crypt, int size_crypt, 
    void* pLogin, int sizeLogin, void* pPassword, int sizePassword)
  {
    return mBaseServer->IsSessionSecurity(id_session, crypt, size_crypt, pLogin, sizeLogin, pPassword, sizePassword);
  }
  //-------------------------------------------------------------------------------
  void WBaseServer::SendByClientKey(std::list<unsigned int>& l, char* p, int size )
  {
    mBaseServer->SendByClientKey( l, p, size );
  }
  //-------------------------------------------------------------------------------
  void WBaseServer::SendDown(unsigned int id_session, char* p, int size, bool check )
  {
    mBaseServer->SendDown( id_session, p, size, check );
  }
  //-------------------------------------------------------------------------------
  int  WBaseServer::GetCountDown()
  {
    return mBaseServer->GetCountDown();
  }
  //-------------------------------------------------------------------------------
  bool WBaseServer::GetDescDown(int index, void* pDesc, int& sizeDesc)
  {
    return mBaseServer->GetDescDown( index, pDesc, sizeDesc);
  }
  //-------------------------------------------------------------------------------
}
