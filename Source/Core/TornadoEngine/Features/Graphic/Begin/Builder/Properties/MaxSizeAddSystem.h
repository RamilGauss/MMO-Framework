/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnAddCollectReactiveSystem.h"

#include "TornadoEngine/Components/Gui/Properties/MaxSizeComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TMaxSizeAddSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TMaxSizeComponent, TMaxSizeAddSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TMaxSizeComponent* pC);
    };
}
