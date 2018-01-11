/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NativeMMOEngineWrapperMasterImplH
#define NativeMMOEngineWrapperMasterImplH

#include "IMaster.h"
#include "Master.h"
#include "ActiveServerImpl.h"

namespace NativeMMOEngineWrapper
{
  class TMasterImpl : public TActiveServerImpl, public IMaster
  {
    nsMMOEngine::TMaster* mMaster;
  public:
    TMasterImpl();

    virtual bool TryCreateGroup(std::list<unsigned int>& l_id_client, unsigned int& id_group);
    virtual void DestroyGroup(unsigned int id_group);
    virtual void LeaveGroup(unsigned int id_client);
    virtual void GetListForGroup(unsigned int id_group, std::list<unsigned int>& l);
    virtual void SetResultLogin(bool res, unsigned int id_session, 
      unsigned int id_client, void* resForClient, int sizeResClient);
    virtual bool FindSlaveSessionByGroup(unsigned int id_group, unsigned int& id_session);
  };
}

#endif