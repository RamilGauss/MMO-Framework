/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GenerateFilesByReflectionSystem.h"

#include <fmt/core.h>

#include <ECS/include/Helper.h>

#include "Components/ConfigComponent.h"
#include "Components/ReflectionConfigComponent.h"
#include "Components/ResultComponent.h"

namespace nsContainerCodeGenerator
{
    void TGenerateFilesByReflectionSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TConfigComponent>(mEntMng);
        auto reflectionConfigComponent = nsECSFramework::SingleComponent<TReflectionConfigComponent>(mEntMng);
        auto resultComponent = nsECSFramework::SingleComponent<TResultComponent>(mEntMng);

        auto cmd = fmt::format("{} {}", 
            configComponent->value.reflectionCodeGeneratorFileName, 
            reflectionConfigComponent->absFileName);

        auto cmdResult = std::system(cmd.c_str());

        if (cmdResult == 0) {
            return;
        }

        resultComponent->value = fmt::format("ReflectionCodeGenerator returns {}", cmdResult);
        throw std::exception();
    }
}