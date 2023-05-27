/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ProjectContainerCodeGenerator.h"

#include <fmt/core.h>
#include <fmt/color.h>

#include <magic_enum.hpp>

#include "LoadFromFile.h"

#include "MessageException.h"

#include "Components/CoreConfigComponent.h"
#include "Components/ProjectConfigComponent.h"
#include "Components/FilePathComponent.h"


namespace nsContainerCodeGenerator
{
    TContainerCodeGenerator::Result TProjectContainerCodeGenerator::Generate(const std::string& filePath)
    {
        CreateSingleEntity(filePath);

        auto singleId = nsECSFramework::SingleEntity<TFilePathComponent>(&mEntMng);

        TCoreConfigComponent configComponent;
        mEntMng.SetComponent(singleId, configComponent);

        TProjectConfigComponent configComponent;
        mEntMng.SetComponent(singleId, configComponent);

        mMainFeature.SetEntMng(&mEntMng);

        // Form the logic conveyor.
        mMainFeature.Add(&mSetupConfigFeature);
        mMainFeature.Add(&mProjectGeneratorFeature);
        mMainFeature.Add(&mAggregatorDumperFeature);

        return Execute();
    }
    //-------------------------------------------------------------------------------------------
}