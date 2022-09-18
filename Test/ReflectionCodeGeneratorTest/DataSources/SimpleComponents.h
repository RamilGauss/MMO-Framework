/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IComponent.h"

template <typename T>
struct TPropertyOf
{
    mutable T* p = nullptr;
};

class TUnit
{};

namespace nsSimpleComponents
{
    struct TSizeComponent : TPropertyOf<TUnit>, nsECSFramework::IComponent
    {
        int x;
        int y;
    };

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