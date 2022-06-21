/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnUpdateInstantReactiveSystem.h>
#include <ECS/include/InitSystem.h>

#include "PositionComponent.h"
#include "HandlerPool.h"

namespace nsGraphicWrapper
{
    class DllExport TPositionUpdaterSystem :
        public nsECSFramework::TOnUpdateInstantReactiveSystem<nsGuiWrapper::TPositionComponent, TPositionUpdaterSystem>,
        public nsECSFramework::TInitSystem,
        public nsTornadoEngine::THandlerPool<nsGuiWrapper::TPositionComponent>
    {
        template<typename T>
        bool SetInputTextValue(nsECSFramework::TEntityID eid, const nsGuiWrapper::TPositionComponent* pC)
        {
            auto viewComponent = GetEntMng()->ViewComponent<T>(eid);
            if (viewComponent != nullptr) {
                viewComponent->value->SetPos({(float)pC->x, (float)pC->y});
            }
            return (viewComponent != nullptr);
        }
    public:
        void Init() override;
        void Reactive(nsECSFramework::TEntityID eid, const nsGuiWrapper::TPositionComponent* pC);
    };
}