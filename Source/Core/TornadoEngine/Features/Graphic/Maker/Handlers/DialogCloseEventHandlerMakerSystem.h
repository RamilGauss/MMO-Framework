/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>

#include "DialogCloseEventHandlerComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TDialogCloseEventHandlerMakerSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TDialogCloseEventHandlerComponent, TDialogCloseEventHandlerMakerSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TDialogCloseEventHandlerComponent* pC);
    };
}