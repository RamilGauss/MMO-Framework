/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <stdint.h>

#include "TypeDef.h"
#include "ReflectionMacro.h"

#pragma REFLECTION_ATTRIBUTE
#pragma Table
class DllExport ITable
{
public:
#pragma Primary_key
  uint64_t id;
};