/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "BinaryPushMaster.h"
#include "BinaryPopMaster.h"
#include "ReflectionMacro.h"

REFLECTION_ATTRIBUTE
struct TFloat3
{
  float x = 1.2345678f;
  float y = 2.2345678f;
  float z = 3.2345678f;
};

REFLECTION_ATTRIBUTE
struct TFloat4
{
  float x = 1.2345678f;
  float y = 2.2345678f;
  float z = 3.2345678f;
  float w = 4.2345678f;
};

REFLECTION_ATTRIBUTE
class TParamClass
{
public:
  int id;
  TFloat3 pos;
  TFloat4 rot;
  TFloat3 vel;
};

