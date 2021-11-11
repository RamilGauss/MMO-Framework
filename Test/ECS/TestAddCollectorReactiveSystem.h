/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <fmt/core.h>

#include "OnAddCollectReactiveSystem.h"

#include "NameComponent.h"

class TTestAddCollectorReactiveSystem : public nsECSFramework::TOnAddCollectReactiveSystem<TNameComponent>
{
public:
    void Reactive(nsECSFramework::TEntityID eid, nsECSFramework::IComponent* pC) override
    {
        fmt::print("name {} was added collector\n", ((TNameComponent*) pC)->name);
    }
};