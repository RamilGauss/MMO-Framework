/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnAddCollectReactiveSystem.h"

#include "Components/Gui/Widgets/DialogComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TDialogMakerSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TDialogComponent, TDialogMakerSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TDialogComponent* pC);
    };
}
