/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnUpdateCollectReactiveSystem.h"

#include "TornadoEngine/Components/Gui/Properties/HorizontalAlignComponent.h"

namespace nsGraphicWrapper
{
    class DllExport THorizontalAlignUpdateSystem :
        public nsECSFramework::TOnUpdateCollectReactiveSystem<nsGuiWrapper::THorizontalAlignComponent, THorizontalAlignUpdateSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::THorizontalAlignComponent* pC);
    };
}