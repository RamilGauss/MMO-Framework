/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <fmt/core.h>

#include "OnUpdateCollectReactiveSystem.h"

#include "NameComponent.h"

class TTestUpdateCollectorReactiveSystem : public nsECSFramework::TOnUpdateCollectReactiveSystem<TNameComponent>
{
public:
    void Reactive(nsECSFramework::TEntityID eid, nsECSFramework::IComponent* pC) override
    {
        fmt::print("name {} was updated collector\n", ((TNameComponent*) pC)->name);
    }
};