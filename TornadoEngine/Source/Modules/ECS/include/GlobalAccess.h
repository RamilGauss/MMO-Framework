/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "TypeDef.h"
#include "EntityManager.h"

// Доступ к данным ECS инфраструктуры

namespace nsECSFramework
{
  class DllExport TGlobalAccess
  {
    TEntityManager* mEntMng;
  public:
    TEntityManager* GetEntityManager()
    {
      return mEntMng;
    }
    inline void SetEntityManager( TEntityManager* entMng )
    {
      mEntMng = entMng;
    }
  };
}
