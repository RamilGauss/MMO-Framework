/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <fmt/core.h>

#include "OnAddInstantReactiveSystem.h"

#include "NameComponent.h"

class TNameAddSystem : public nsECSFramework::TOnAddInstantReactiveSystem<TNameComponent>
{
public:
    void Reactive(nsECSFramework::TEntityID eid, nsECSFramework::IComponent* pC) override
    {
        fmt::print("name {} was added instant\n", ((TNameComponent*) pC)->name);
    }
};