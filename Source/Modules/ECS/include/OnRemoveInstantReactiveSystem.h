/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "BaseReactiveSystem.h"

namespace nsECSFramework
{
    template<typename Component, typename SystemTypeImplementation>
    class DllExport TOnRemoveInstantReactiveSystem : public TBaseReactiveSystem
    {
    public:
        void TearDown() override
        {
            mEntMng->RegisterOnRemoveComponent<Component>()->Unregister(this);
        }

        void SetEntMng(TEntityManager* entMng) override final
        {
            TSystem::SetEntMng(entMng);

            auto callbackPool = mEntMng->RegisterOnRemoveComponent<Component>();
            callbackPool->Register(this, [this](TEntityID eid, const IComponent* pC)
            {
                ((SystemTypeImplementation*) (this))->Reactive(eid, (const Component*) pC);
            });
        }
    };

}