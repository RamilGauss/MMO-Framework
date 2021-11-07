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
    template<typename Component>
    class DllExport TOnRemoveInstantReactiveSystem : public TBaseReactiveSystem
    {
    public:
        virtual ~TOnRemoveInstantReactiveSystem()
        {
            mEntMng->RegisterOnRemoveComponent<Component>()->Unregister(this);
        }

        void SetEntMng(TEntityManager* entMng) override
        {
            mEntMng = entMng;
            auto callbacPool = mEntMng->RegisterOnRemoveComponent<Component>();
            callbacPool->Register<TOnRemoveInstantReactiveSystem>(this, &TOnRemoveInstantReactiveSystem::Reactive);
        }
    };

}