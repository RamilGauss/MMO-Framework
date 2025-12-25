/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/IComponent.h"
#include "ContainerCodeGeneratorLib/Sources/Configs/PathSetting.h"

namespace nsContainerCodeGenerator
{
    struct DllExport TPathSettingComponent : nsECSFramework::IComponent
    {
        mutable TPathSetting value;
    };
}
