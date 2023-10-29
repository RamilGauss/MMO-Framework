/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ProgramInfo.h"

#include <fmt/core.h>

using namespace nsReflectionCodeGenerator;

const std::string TProgramInfo::NAME = "ReflectionCodeGenerator";
const std::string TProgramInfo::VERSION_MAJOR = "2";
const std::string TProgramInfo::VERSION_MINOR_HIGH = "5";
const std::string TProgramInfo::VERSION_MINOR_LOW = "0";
const int TProgramInfo::COUNTER_BUILD = 59;
const std::string TProgramInfo::INFO = "Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation";

std::string TProgramInfo::Get()
{
    return fmt::format("{} version {}.{}.{}, build {} [{}]",
        NAME,
        VERSION_MAJOR,
        VERSION_MINOR_HIGH,
        VERSION_MINOR_LOW,
        COUNTER_BUILD, INFO);
}
