/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "IComponent.h"

struct TNameComponent : nsECSFramework::IComponent
{
    std::string name;

    bool IsLess(const IComponent* pOther) const override
    {
        return name < ((const TNameComponent*) (pOther))->name;
    }
    bool IsEqual(const IComponent* pOther) const override
    {
        return name == ((const TNameComponent*) (pOther))->name;
    }
};