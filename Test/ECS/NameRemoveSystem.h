/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <fmt/core.h>

#include "OnRemoveInstantReactiveSystem.h"

#include "Components/Meta/NameComponent.h"

class TNameRemoveSystem : 
    public nsECSFramework::TOnRemoveInstantReactiveSystem<TNameComponent, TNameRemoveSystem>
{
public:
    void Reactive(nsECSFramework::TEntityID eid, const TNameComponent* pC)
    {
        fmt::print("name {} was removed\n", pC->name);
    }
};
