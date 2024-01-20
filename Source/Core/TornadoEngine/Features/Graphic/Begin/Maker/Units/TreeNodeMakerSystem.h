/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>

#include "Components/Gui/Widgets/TreeNodeComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TTreeNodeMakerSystem : 
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TTreeNodeComponent, TTreeNodeMakerSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTreeNodeComponent* pC);
    };
}