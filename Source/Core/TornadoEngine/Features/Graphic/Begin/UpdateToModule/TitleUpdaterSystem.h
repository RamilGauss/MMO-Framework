/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ECS/Include/OnUpdateInstantReactiveSystem.h"
#include "ECS/Include/InitSystem.h"

#include "TornadoEngine/Components/Gui/Properties/TitleComponent.h"
#include "TornadoEngine/Share/HandlerPool.h"

namespace nsGraphicWrapper
{
    class DllExport TTitleUpdaterSystem :
        public nsECSFramework::TOnUpdateInstantReactiveSystem<nsGuiWrapper::TTitleComponent, TTitleUpdaterSystem>,
        public nsECSFramework::TInitSystem,
        public nsTornadoEngine::THandlerPool<nsGuiWrapper::TTitleComponent>
    {
        template<typename T>
        bool SetTitle(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTitleComponent* pC)
        {
            auto viewComponent = GetEntMng()->ViewComponent<T>(eid);
            if (viewComponent != nullptr) {
                viewComponent->value->SetTitle(pC->value);
            }
            return (viewComponent != nullptr);
        }
    public:
        void Init() override;
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TTitleComponent* pC);
    };
}