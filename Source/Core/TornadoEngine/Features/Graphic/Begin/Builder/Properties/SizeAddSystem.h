/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnAddCollectReactiveSystem.h"

#include "TornadoEngine/Components/Gui/Properties/SizeComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TSizeAddSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TSizeComponent, TSizeAddSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TSizeComponent* pC);
    };
}
