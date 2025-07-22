/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnAddCollectReactiveSystem.h"

#include "Components/Gui/Widgets/MenuNodeComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TMenuNodeBuilderSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TMenuNodeComponent, TMenuNodeBuilderSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMenuNodeComponent* pC);
    };
}
