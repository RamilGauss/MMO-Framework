/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MANAGER_MANAGER_CONTEXT_SC_H
#define MANAGER_MANAGER_CONTEXT_SC_H

#include <set>
#include "ManagerContextSc.h"

namespace nsMMOEngine
{
  class TManagerManagerContextSc
  {
    typedef std::set<TManagerContextSc*> TSetPtr;
    TSetPtr mSetManagerContextSc;

    TSetPtr mSetActiveManagerContextSc;
  public:
    TManagerManagerContextSc();
    ~TManagerManagerContextSc();

    TManagerContextSc* Add();
    void Remove(TManagerContextSc* pMСSc);
    // для обработки внутренних событий
    void Work();
  protected:
    void ActiveEvent(TManagerContextSc* pMCSc);
    void DisactiveEvent(TManagerContextSc* pMCSc);
  };
}

#endif