/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include <list>
#include <string>

#include "TypeDef.h"

namespace nsTornadoEngine
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TProjectInfo
    {
        std::string company;
        std::string appName;
        std::string license;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TGeneratorConfig
    {
        std::string nameSpace;
        std::string directoryPath;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TProjectConfig
    {
        TProjectInfo info;

        std::string binaryFilePath;

        std::string conveyorFilePath;
        std::string resourcesFilePath;

        TGeneratorConfig generatorConfig;
    };
}