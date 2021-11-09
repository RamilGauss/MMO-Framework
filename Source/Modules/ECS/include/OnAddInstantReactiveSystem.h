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
    class DllExport TOnAddInstantReactiveSystem : public TBaseReactiveSystem
    {
    public:
        void TearDown() override
        {
            mEntMng->RegisterOnAddComponent<Component>()->Unregister(this);
        }

        void SetEntMng(TEntityManager* entMng) override
        {
            mEntMng = entMng;
            auto callbackPool = mEntMng->RegisterOnAddComponent<Component>();
            callbackPool->Register<TOnAddInstantReactiveSystem>(this, &TOnAddInstantReactiveSystem::Reactive);
        }
    };
}