/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BaseImpl.h"

namespace NativeMMOEngineWrapper
{
  TBaseImpl::TBaseImpl( nsMMOEngine::TBase* pBase )
  {
    mBase = pBase;
  }
  //------------------------------------------------------------------------------
  TBaseImpl::~TBaseImpl()
  {
    delete mBase;
  }
  //------------------------------------------------------------------------------
  // base
  void TBaseImpl::Init(nsMMOEngine::IMakerTransport* pMakerTransport)
  {
    mBase->Init( pMakerTransport );
  }
  //------------------------------------------------------------------------------
  bool TBaseImpl::Open(nsMMOEngine::TDescOpen* pDesc, int count )
  {
    return mBase->Open( pDesc, count );
  }
  //------------------------------------------------------------------------------
  void TBaseImpl::DisconnectUp()
  {
    mBase->DisconnectUp();
  }
  //------------------------------------------------------------------------------
  void TBaseImpl::SendUp(char* p, int size, bool check )
  {
    mBase->SendUp( p, size, check );
  }
  //------------------------------------------------------------------------------
  void TBaseImpl::Work()
  {
    mBase->Work();
  }
  //------------------------------------------------------------------------------
  bool TBaseImpl::IsConnectUp()
  {
    return mBase->IsConnectUp();
  }
  //------------------------------------------------------------------------------
  bool TBaseImpl::IsConnect(unsigned int id)
  {
    return mBase->IsConnect(id);
  }
  //------------------------------------------------------------------------------
  void TBaseImpl::SetLoad(int procent)
  {
    mBase->SetLoad(procent);
  }
  //------------------------------------------------------------------------------
  void TBaseImpl::SetTimeLiveSession(unsigned int time_ms)
  {
    mBase->SetTimeLiveSession( time_ms );
  }
  //------------------------------------------------------------------------------
  bool TBaseImpl::GetInfoSession(unsigned int id_session, TIP_Port& ip_port)
  {
    return mBase->GetInfoSession( id_session, ip_port);
  }
  //------------------------------------------------------------------------------
  nsMMOEngine::TBase* TBaseImpl::GetBase()
  {
    return mBase;
  }
  //------------------------------------------------------------------------------
}
