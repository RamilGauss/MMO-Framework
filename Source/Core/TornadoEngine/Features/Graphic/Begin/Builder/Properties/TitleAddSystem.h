/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnAddCollectReactiveSystem.h"

#include "TornadoEngine/Components/Gui/Properties/TitleComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TTitleAddSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsGuiWrapper::TTitleComponent, TTitleAddSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTitleComponent* pC);
    };
}
