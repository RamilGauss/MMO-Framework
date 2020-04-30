/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once
#include <string>
#include <list>
#include <set>
#include "ReflectionMacro.h"

namespace nsBS
{
#pragma _42
#pragma REFLECTION_ATTRIBUTE
#pragma Table
  struct TBaseStruct
  {
#pragma Primary key
#pragma Index
    std::string s = "0123456789";
  };
}
