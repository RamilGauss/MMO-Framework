/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnRemoveInstantReactiveSystem.h>

#include "TreeViewComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TTreeViewTerminatorSystem :
        public nsECSFramework::TOnRemoveInstantReactiveSystem<nsGuiWrapper::TTreeViewComponent, TTreeViewTerminatorSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTreeViewComponent* pC);
    };
}