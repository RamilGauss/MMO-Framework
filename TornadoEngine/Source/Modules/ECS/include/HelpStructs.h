/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "Entity.h"
#include <list>
#include <vector>
#include <type_traits>

#include <boost/dll/runtime_symbol_info.hpp>
#include <boost/dll/smart_library.hpp>
#include <boost/dll/import_class.hpp>
#include <boost/dll/shared_library.hpp>

#include "RunTimeTypeIndex.h"
#include "SingletonManager.h"

#include "Config.h"
#include "VectorRise.h"
#include "MemoryObjectPool.h"
#include "CallBackRegistrator.h"
#include "ColanderVector.h"
#include "ComplexType.h"
#include "ContainerForReactive.h"

namespace nsECSFramework
{
  template<class T>
  struct ptr_less
  {
    bool operator()( const T& pLHS, const T& pRHS ) const
    {
      return *pLHS < *pRHS;
    }
  };
  template<class T>
  struct component_ptr_less
  {
    bool operator()( const T& lhs, const T& rhs ) const
    {
      auto pL = (const IComponent*)lhs;
      auto pR = (const IComponent*)rhs;
      return pL->IsLess( pR );
    }
  };
  // usage: std::map<T*,second,ptr_less<T*>> mMap;
}