/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnRemoveInstantReactiveSystem.h>

#include "Components/Gui/Widgets/LabelComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TLabelTerminatorSystem :
        public nsECSFramework::TOnRemoveInstantReactiveSystem<nsGuiWrapper::TLabelComponent, TLabelTerminatorSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TLabelComponent* pC);
    };
}