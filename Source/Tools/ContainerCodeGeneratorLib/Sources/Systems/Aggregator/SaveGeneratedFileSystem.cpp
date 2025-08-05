/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <fmt/core.h>

#include "Base/Common/HiTimer.h"
#include "Base/Common/TextFile.h"

#include "ECS/Include/Helper.h"

#include "ContainerCodeGeneratorLib/Sources/Constants.h"

#include "ContainerCodeGeneratorLib/Sources/Components/GeneratedFilesComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Systems/Aggregator/SaveGeneratedFileSystem.h"

namespace nsContainerCodeGenerator::nsAggregator
{
    void TSaveGeneratedFileSystem::Execute()
    {
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        if (generatedFilesComponent == nullptr) {
            return;
        }

        for (auto& gen : generatedFilesComponent->value) {
            nsBase::nsCommon::TTextFile::Save(gen.absPath, gen.content);
        }
    }
}