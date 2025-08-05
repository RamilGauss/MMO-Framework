/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <fmt/core.h>

#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/MessageException.h"

#include "ContainerCodeGeneratorLib/Sources/Components/CoreConfigComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/ReflectionConfigComponent.h"

#include "ContainerCodeGeneratorLib/Sources/Systems/Common/GenerateFilesByReflectionSystem.h"

namespace nsContainerCodeGenerator::nsCommon
{
    void TGenerateFilesByReflectionSystem::Execute()
    {
        auto configComponent = nsECSFramework::SingleComponent<TCoreConfigComponent>(mEntMng);
        auto reflectionConfigComponent = nsECSFramework::SingleComponent<TReflectionConfigComponent>(mEntMng);

        if (reflectionConfigComponent == nullptr) {
            return;
        }

        auto cmd = fmt::format("{} \"{}\"", 
            configComponent->value.reflectionCodeGeneratorFileName, 
            reflectionConfigComponent->absFileName);

        auto cmdResult = std::system(cmd.c_str());

        if (cmdResult == 0) {
            return;
        }

        auto msg = fmt::format("ReflectionCodeGenerator returns {}", cmdResult);
        throw MSG_EXCEPTION(msg);
    }
}