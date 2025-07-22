/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "AddHeaderInGeneratedFilesSystem.h"

#include <fmt/core.h>

#include "Base/Common/HiTimer.h"
#include "Base/Common/TextFile.h"

#include "ECS/Include/Helper.h"

#include "Constants.h"

#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsAggregator
{
    void TAddHeaderInGeneratedFilesSystem::Execute()
    {
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        if (generatedFilesComponent == nullptr) {
            return;
        }

        for (auto& gen : generatedFilesComponent->value) {

            std::string content;

            content += TConstants::GetHeader();
            content += "\n";
            content += fmt::format("// {}\n// File has been generated at {}\n", 
                TConstants::GetProgramName(), ht_GetTimeStr());
            content += gen.content;

            gen.content = content;
        }
    }
}