/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/
// File has been generated by ReflectionCodeGenerator version 1.8 build 37, at 2020_04_28 13:59:45.282

#pragma once

#include <string>
#include "IncludeList.h"

namespace nsSql
{
  class TSqlTable
  {
  public:
    virtual std::string Create() = 0;
    virtual std::string Drop() = 0;
    virtual std::string Clear() = 0;
  };

  class TSqlGenerated
  {
  public:
    template <typename Type>
    static void Create( Type* p, std::string& str );
    template <typename Type>
    static void Drop( Type*& p, std::string& str );
    template <typename Type>
    static void Clear( Type* p, std::string& str );



  };
}