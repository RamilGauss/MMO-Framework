/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"

namespace nsContainerCodeGenerator
{
#pragma REFLECTION_ATTRIBUTE
    struct DllExport TPathSetting
    {
        std::string coreDir;
        std::string coreDirForParse;

        std::string reflectionCodeGeneratorFileName;
        std::string entityManagerDir;
        std::string ecsDir;
        std::string imGuiWidgetsDir;

        std::string projectDirForParse;

        std::string containerGeneratedFilesDir;
        std::string aggregatorGeneratedFilesDir;
    };
}
