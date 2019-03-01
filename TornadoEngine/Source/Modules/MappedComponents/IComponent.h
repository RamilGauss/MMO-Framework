/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"

namespace nsMappedComponents
{
  struct DllExport IComponent 
  {
    typedef std::list<TEntityManager::EntityID>::iterator EntityIDListIt;
    std::vector<EntityIDListIt> mMappedIteratorVec;


    virtual ~IComponent()
    {
    }
    bool operator< ( const IComponent& other ) const
    {
      return true;
    }
  };
}
