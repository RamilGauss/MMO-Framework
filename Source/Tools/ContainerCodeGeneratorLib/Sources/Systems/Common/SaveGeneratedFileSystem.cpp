/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SaveGeneratedFileSystem.h"

#include <TextFile.h>

#include <ECS/include/Helper.h>

#include "Components/GeneratedFilesComponent.h"

namespace nsContainerCodeGenerator::nsCommon
{
    void TSaveGeneratedFileSystem::Execute()
    {
        auto generatedFilesComponent = nsECSFramework::SingleComponent<TGeneratedFilesComponent>(mEntMng);

        if (generatedFilesComponent == nullptr) {
            return;
        }

        for (auto& gen : generatedFilesComponent->value) {
            TTextFile::Save(gen.absPath, gen.content);
        }
    }
}