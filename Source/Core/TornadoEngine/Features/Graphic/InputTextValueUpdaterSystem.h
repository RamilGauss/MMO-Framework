/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnUpdateInstantReactiveSystem.h>

#include "InputTextValueComponent.h"

namespace nsGraphicWrapper
{
    class DllExport TInputTextValueUpdaterSystem : 
        public nsECSFramework::TOnUpdateInstantReactiveSystem<nsGuiWrapper::TInputTextValueComponent, TInputTextValueUpdaterSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TInputTextValueComponent* pC);
    };
}