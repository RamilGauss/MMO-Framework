/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/ExecuteSystem.h"

#include "TornadoEngine/Components/Gui/Properties/TitleComponent.h"
#include "TornadoEngine/Share/HandlerPool.h"

namespace nsGraphicWrapper
{
    class DllExport TCameraUpdaterToModuleSystem : public nsECSFramework::TExecuteSystem
    {
    public:
        void Execute() override;
    };
}
