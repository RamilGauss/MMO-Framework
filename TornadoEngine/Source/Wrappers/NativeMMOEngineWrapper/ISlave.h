/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef NativeMMOEngineWrapperISlaveH
#define NativeMMOEngineWrapperISlaveH

namespace NativeMMOEngineWrapper
{
  class DllExport ISlave
  {
  public:
    virtual void SaveContext(unsigned int id_session, void* data, int size) = 0;
    virtual bool FindClientKeyBySession(unsigned int id_session, unsigned int &id) = 0;
    virtual bool FindSessionByClientKey(unsigned int id, unsigned int& id_session) = 0;
  };
}

#endif
