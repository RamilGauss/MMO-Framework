/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnAddCollectReactiveSystem.h"

#include "TornadoEngine/Components/Gui/Properties/AnchorsComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TAnchorsAddSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TAnchorsComponent, TAnchorsAddSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TAnchorsComponent* pC);
    };
}
