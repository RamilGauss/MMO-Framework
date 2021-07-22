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
    class DllExport TOnUpdateInstantReactiveSystem : public TBaseReactiveSystem
    {
    public:
        void SetEntMng(TEntityManager* entMng) override
        {
            mEntMng = entMng;
            mEntMng->RegisterOnUpdateComponent<Component>()->Register(&TBaseReactiveSystem::Reactive, this);
        }
    };
}