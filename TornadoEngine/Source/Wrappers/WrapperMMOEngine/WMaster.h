/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef WrapperMMOEngineMasterH
#define WrapperMMOEngineMasterH

#include "WActiveServer.h"

namespace nsMMOEngine
{
  class TMaster;
}

namespace WrapperMMOEngine
{
  public ref class WDescDownMaster
  {
    unsigned int id_session;
  };

  public enum class LoginResult
  {
    eAccept,
    eReject,
  };

  public ref class WMaster : public WActiveServer
  {
    nsMMOEngine::TMaster* mMaster;
  public:
    WMaster();

    bool TryCreateGroup(std::list<unsigned int>& l_id_client, unsigned int& id_group); 
    void DestroyGroup(unsigned int id_group);
    void LeaveGroup(unsigned int id_client);
    void GetListForGroup(unsigned int id_group, std::list<unsigned int>& l);
    void SetResultLogin(bool res, unsigned int id_session, unsigned int id_client, void* resForClient, int sizeResClient);
    bool FindSlaveSessionByGroup(unsigned int id_group, unsigned int& id_session);
  };
}

#endif