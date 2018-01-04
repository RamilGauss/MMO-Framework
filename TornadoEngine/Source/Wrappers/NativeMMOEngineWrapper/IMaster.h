/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NativeMMOEngineWrapperIMasterH
#define NativeMMOEngineWrapperIMasterH

namespace NativeMMOEngineWrapper
{
  class DllExport IMaster
  {
  public:
    virtual bool TryCreateGroup(std::list<unsigned int>& l_id_client, unsigned int& id_group) = 0;
    virtual void DestroyGroup(unsigned int id_group) = 0;
    virtual void LeaveGroup(unsigned int id_client) = 0;
    virtual void GetListForGroup(unsigned int id_group, std::list<unsigned int>& l) = 0;
    virtual void SetResultLogin(bool res, unsigned int id_session, 
      unsigned int id_client, void* resForClient, int sizeResClient) = 0;
    virtual bool FindSlaveSessionByGroup(unsigned int id_group, unsigned int& id_session) = 0;
  };
}

#endif