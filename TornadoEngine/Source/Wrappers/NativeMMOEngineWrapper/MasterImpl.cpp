/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MasterImpl.h"

namespace NativeMMOEngineWrapper
{
  TMasterImpl::TMasterImpl() : TActiveServerImpl(new nsMMOEngine::TMaster())
  {
    mMaster = (nsMMOEngine::TMaster*)GetBase();
  }
  //----------------------------------------------------------------------------
  bool TMasterImpl::TryCreateGroup(std::list<unsigned int>& l_id_client, unsigned int& id_group)
  {
    return mMaster->TryCreateGroup( l_id_client, id_group);
  }
  //----------------------------------------------------------------------------
  void TMasterImpl::DestroyGroup(unsigned int id_group)
  {
    mMaster->DestroyGroup(id_group);
  }
  //----------------------------------------------------------------------------
  void TMasterImpl::LeaveGroup(unsigned int id_client)
  {
    mMaster->LeaveGroup(id_client);
  }
  //----------------------------------------------------------------------------
  void TMasterImpl::GetListForGroup(unsigned int id_group, std::list<unsigned int>& l)
  {
    mMaster->GetListForGroup(id_group, l);
  }
  //----------------------------------------------------------------------------
  void TMasterImpl::SetResultLogin(bool res, unsigned int id_session, 
    unsigned int id_client, void* resForClient, int sizeResClient)
  {
    mMaster->SetResultLogin(res, id_session, id_client, resForClient, sizeResClient);
  }
  //----------------------------------------------------------------------------
  bool TMasterImpl::FindSlaveSessionByGroup(unsigned int id_group, unsigned int& id_session)
  {
    return mMaster->FindSlaveSessionByGroup(id_group, id_session);
  }
  //----------------------------------------------------------------------------
}
