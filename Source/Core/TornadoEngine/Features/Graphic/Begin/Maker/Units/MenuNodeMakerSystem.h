/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>

#include "Components/Gui/Widgets/MenuNodeComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TMenuNodeMakerSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TMenuNodeComponent, TMenuNodeMakerSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeComponent* pC);
    };
}