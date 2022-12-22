/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/IComponent.h>

#include <ReflectionCodeGeneratorLib/Sources/Config.h>

namespace nsContainerCodeGenerator
{
    struct DllExport TReflectionConfigComponent : nsECSFramework::IComponent
    {
        std::string absFileName;

        mutable nsReflectionCodeGenerator::TConfig value;
    };
}