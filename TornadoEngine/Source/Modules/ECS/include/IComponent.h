/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <list>
#include <functional>

#include "LinkToList.h"
#include "MemoryObjectPool.h"
#include "SingletonManager.h"

namespace nsECSFramework
{
  class DllExport IComponent
  {
  public:
    virtual bool IsEqual( IComponent* pOther ) = 0;
    virtual bool IsLess( IComponent* pOther ) = 0;
    virtual bool IsMore( IComponent* pOther ) = 0;
  };
}