/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "TypeDef.h"
#include <typeindex>
#include <map>

class DllExport TSingletonManager
{
  typedef std::map<std::type_index, void*> TIntPtrMap;// std::type_index is faster than size_t

  TIntPtrMap mTypeObjMap;
public:
  template<typename Type>
  Type* Get()// low-speed method, after call have to remember Type*
  {
    Type* pObj = nullptr;
    auto id = std::type_index( typeid(Type) );

    auto fit = mTypeObjMap.find( id );
    if( fit == mTypeObjMap.end() )
    {
      pObj = new Type();
      mTypeObjMap.insert( TIntPtrMap::value_type( id, pObj ) );
    }
    else
      pObj = (Type*) fit->second;
    return pObj;
  }
};

extern DllExport TSingletonManager* SingletonManager();
