/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <ECS/include/OnAddCollectReactiveSystem.h>

#include "ObjectInstantiationCompletionHandlerComponent.h"

namespace nsLogicWrapper
{
    class DllExport TObjectInstantiationCompletionHandlerBuilderSystem :
        public nsECSFramework::TOnAddCollectReactiveSystem<nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent, 
                                                                           TObjectInstantiationCompletionHandlerBuilderSystem>
    {
    public:
        void Reactive(nsECSFramework::TEntityID eid, const nsLogicWrapper::TObjectInstantiationCompletionHandlerComponent* pC);
    };
}