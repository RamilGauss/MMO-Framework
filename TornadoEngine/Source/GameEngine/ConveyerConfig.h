/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <vector>

#include "ReflectionMacro.h"
#include <map>

REFLECTION_ATTRIBUTE
struct TAppConfig
{
  std::vector<std::vector<std::string>> modulesInThreads;
};

REFLECTION_ATTRIBUTE
struct TConveyerConfig
{
  std::map<std::string, TAppConfig> appList;
};
