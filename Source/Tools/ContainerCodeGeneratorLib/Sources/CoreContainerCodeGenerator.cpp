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
#include "ContainerCodeGeneratorLib/Sources/Components/ConfigTagComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Components/PathSettingComponent.h"

namespace nsContainerCodeGenerator
{
    TContainerCodeGenerator::Result TCoreContainerCodeGenerator::Generate(const TPathSetting& pathSetting, 
            const TCoreConfig& coreConfig, const TProjectConfig& projectConfig)
    {
        auto singleId = nsECSFramework::SingleEntity<TConfigTagComponent>(&mEntMng);

        TPathSettingComponent pathSettingcomponent;
        pathSettingcomponent.value = pathSetting;
        mEntMng.SetComponent(singleId, pathSettingcomponent);

        TCoreConfigComponent coreConfigComponent;
        coreConfigComponent.value = coreConfig;
        mEntMng.SetComponent(singleId, coreConfigComponent);

        mMainFeature.SetEntMng(&mEntMng);

        // Form the logic conveyor.
        mMainFeature.Add(&mCoreGeneratorFeature);

        return Execute();
    }
    //-------------------------------------------------------------------------------------------
}