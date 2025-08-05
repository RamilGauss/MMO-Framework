/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include <fmt/core.h>
#include <fmt/color.h>

#include <magic_enum/magic_enum.hpp>

#include "Base/Common/LoadFromFile.h"

#include "ContainerCodeGeneratorLib/Sources/MessageException.h"
#include "ContainerCodeGeneratorLib/Sources/CoreContainerCodeGenerator.h"

#include "ContainerCodeGeneratorLib/Sources/Components/CoreConfigComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/FilePathComponent.h"

namespace nsContainerCodeGenerator
{
    TContainerCodeGenerator::Result TCoreContainerCodeGenerator::Generate(const std::string& filePath)
    {
        CreateSingleEntity(filePath);

        TCoreConfigComponent configComponent;
        auto singleId = nsECSFramework::SingleEntity<TFilePathComponent>(&mEntMng);
        mEntMng.SetComponent(singleId, configComponent);

        mMainFeature.SetEntMng(&mEntMng);

        // Form the logic conveyor.
        mMainFeature.Add(&mSetupConfigFeature);
        mMainFeature.Add(&mCoreGeneratorFeature);

        return Execute();
    }
    //-------------------------------------------------------------------------------------------
}