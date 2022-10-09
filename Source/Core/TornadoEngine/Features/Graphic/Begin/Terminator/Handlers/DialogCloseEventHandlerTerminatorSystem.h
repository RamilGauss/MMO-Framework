/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnRemoveInstantReactiveSystem.h>

#include "DialogCloseEventHandlerComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TDialogCloseEventHandlerTerminatorSystem :
        public nsECSFramework::TOnRemoveInstantReactiveSystem<nsGuiWrapper::TDialogCloseEventHandlerComponent, TDialogCloseEventHandlerTerminatorSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TDialogCloseEventHandlerComponent* pC);
    };
}