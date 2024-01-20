/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/ExecuteSystem.h>

#include "Components/Gui/Properties/TitleComponent.h"
#include "Share/HandlerPool.h"

namespace nsGraphicWrapper
{
    class DllExport TCameraUpdaterToModuleSystem : public nsECSFramework::TExecuteSystem
    {
    public:
        void Execute() override;
    };
}