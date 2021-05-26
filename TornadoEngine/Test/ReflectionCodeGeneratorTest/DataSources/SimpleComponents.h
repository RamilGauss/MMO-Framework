/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IComponent.h"

namespace nsSimpleComponents
{
    struct TSimpleComponent : nsECSFramework::IComponent
    {
        int x = 42;
    };

    struct TValueComponent : nsECSFramework::IComponent
    {
        int x = 42;
    };

    class TNameComponent : public nsECSFramework::IComponent
    {
    public:
        std::string value;
    };
}