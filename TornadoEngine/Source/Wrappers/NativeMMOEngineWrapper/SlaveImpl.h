/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NativeMMOEngineWrapperSlaveImplH
#define NativeMMOEngineWrapperSlaveImplH

#include "ISlave.h"
#include "Slave.h"
#include "ActiveServerImpl.h"

namespace NativeMMOEngineWrapper
{
  class TSlaveImpl : public TActiveServerImpl, public ISlave
  {
    nsMMOEngine::TSlave* mSlave;
  public:
    TSlaveImpl();

    virtual void SaveContext(unsigned int id_session, void* data, int size);
    virtual bool FindClientKeyBySession(unsigned int id_session, unsigned int &id);
    virtual bool FindSessionByClientKey(unsigned int id, unsigned int& id_session);
  };
}

#endif
