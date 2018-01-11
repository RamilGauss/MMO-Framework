/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef ManagedMMOEngineWrapperWSlaveH
#define ManagedMMOEngineWrapperWSlaveH

#include "WActiveServer.h"
#include "Slave.h"

namespace ManagedMMOEngineWrapper
{
  public ref struct WDescDownSlave // для GetDescDown
  {
    unsigned int id_session;
  };

  public ref class WSlave : public WActiveServer
  {
    nsMMOEngine::TSlave* mSlave;
  public:
    WSlave();

    void SaveContext(unsigned int id_session, void* data, int size);
    bool FindClientKeyBySession(unsigned int id_session, unsigned int &id);
    bool FindSessionByClientKey(unsigned int id, unsigned int& id_session);
  };
}

#endif
