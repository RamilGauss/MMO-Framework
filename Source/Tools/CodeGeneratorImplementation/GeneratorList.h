/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include <TypeDef.h>

namespace nsCodeGeneratorImplementation
{
    struct DllExport TGeneratorList
    {
        static constexpr char BINARY[]                    = "BinaryMarshallerGenerator";
        static constexpr char DYNAMIC_CASTER[]            = "DynamicCaster";
        static constexpr char ECS_COMPONENT_EXTENSION[]   = "EcsComponentExtension";
        static constexpr char INCLUDE_LIST[]              = "IncludeListGenerator";
        static constexpr char JSON[]                      = "JsonSerializerGenerator";
        static constexpr char TYPE_FACTORY[]              = "TypeFactoryGenerator";
        static constexpr char TYPE_INFORMATION[]          = "TypeInformationGenerator";
        static constexpr char RUN_TIME_TYPE_INFORMATION[] = "RunTimeTypeInformationGenerator";
    };
}