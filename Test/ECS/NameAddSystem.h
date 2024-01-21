/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <fmt/core.h>

#include "OnAddInstantReactiveSystem.h"

#include "Components/Meta/NameComponent.h"

class TNameAddSystem : public nsECSFramework::TOnAddInstantReactiveSystem<TNameComponent, TNameAddSystem>
{
public:
    void Reactive(nsECSFramework::TEntityID eid, const TNameComponent* pC)
    {
        fmt::print("name {} was added instant\n", pC->name);
    }
};