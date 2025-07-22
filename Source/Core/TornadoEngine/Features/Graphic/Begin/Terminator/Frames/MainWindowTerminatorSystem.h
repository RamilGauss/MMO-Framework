/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnRemoveInstantReactiveSystem.h"

#include "Components/Gui/Widgets/MainWindowComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TMainWindowTerminatorSystem :
        public nsECSFramework::TOnRemoveInstantReactiveSystem<nsGuiWrapper::TMainWindowComponent, TMainWindowTerminatorSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMainWindowComponent* pC);
    };
}