/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <list>

#include "Base/Common/TypeDef.h"

namespace nsTornadoEngine
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TLoggerConfig
    {
        bool enabled;
        std::string logFileName;
        int intervalTimeMs;
    };

#pragma REFLECTION_ATTRIBUTE
    struct DllExport TProjectConfig
    {
        std::string binaryFilePath;
        std::string conveyorFilePath;
        std::string resourcesFilePath;

        std::list<std::string> startScenesGuid;

        TLoggerConfig loggerConfig;
    };
}
