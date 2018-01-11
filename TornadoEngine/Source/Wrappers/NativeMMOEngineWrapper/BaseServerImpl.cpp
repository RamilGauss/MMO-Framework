/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BaseServerImpl.h"

namespace NativeMMOEngineWrapper
{
  TBaseServerImpl::TBaseServerImpl( nsMMOEngine::TBaseServer* pBaseServer ) 
    : TBaseImpl( pBaseServer )
  {
    mBaseServer = pBaseServer;
  }
  //-------------------------------------------------------------------------
  // base server
  bool TBaseServerImpl::IsSessionSecurity(unsigned int id_session, void* crypt, int size_crypt, 
    void* pLogin, int sizeLogin, void* pPassword, int sizePassword)
  {
    return mBaseServer->IsSessionSecurity( id_session, crypt, size_crypt, pLogin, sizeLogin, pPassword, sizePassword);
  }
  //----------------------------------------------------------------------------
  void TBaseServerImpl::DisconnectByKeyClient(unsigned int id_client)
  {
    mBaseServer->DisconnectByKeyClient(id_client);
  }
  //----------------------------------------------------------------------------
  void TBaseServerImpl::SendByClientKey(std::list<unsigned int>& l, char* p, int size )
  {
    mBaseServer->SendByClientKey(l, p, size );
  }
  //----------------------------------------------------------------------------
  void TBaseServerImpl::SendDown(unsigned int id_session, char* p, int size, bool check )
  {
    mBaseServer->SendDown(id_session, p, size, check );
  }
  //----------------------------------------------------------------------------
  int TBaseServerImpl::GetCountDown()
  {
    return mBaseServer->GetCountDown();
  }
  //----------------------------------------------------------------------------
  bool TBaseServerImpl::GetDescDown(int index, void* pDesc, int& sizeDesc)
  {
    return mBaseServer->GetDescDown(index, pDesc, sizeDesc);
  }
  //----------------------------------------------------------------------------
}