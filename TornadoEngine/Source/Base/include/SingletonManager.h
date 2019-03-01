/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "TypeDef.h"
#include "TypeIdentifier.h"
#include <vector>

// not Thread-safe!
class DllExport TSingletonManager
{
  typedef std::vector<void*> TPtrVector;
  
  TPtrVector mTypeObjVec;
public:
  template<typename Type>
  Type* Get()
  {
    auto index = GlobalTypeIdentifier()->type<Type>();
    if ( mTypeObjVec.size() < index + 1 )
      mTypeObjVec.resize( index + 1 );
    if ( mTypeObjVec[index] == nullptr )
      mTypeObjVec[index] = new Type();
    return (Type*)mTypeObjVec[index];
  }
};

extern DllExport TSingletonManager* SingletonManager();
