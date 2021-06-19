/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <set>
#include "ScContextManager.h"

namespace nsMMOEngine
{
  class TManagerManagerContextSc
  {
    typedef std::set<TScContextManager*> TSetPtr;
    TSetPtr mSetManagerContextSc;

    TSetPtr mSetActiveManagerContextSc;
  public:
    TManagerManagerContextSc();
    ~TManagerManagerContextSc();

    TScContextManager* Add();
    void Remove( TScContextManager* pMCSc );
    // для обработки внутренних событий
    void Work();
  protected:
    void ActiveEvent( TScContextManager* pMCSc );
    void DisactiveEvent( TScContextManager* pMCSc );
  };
}
