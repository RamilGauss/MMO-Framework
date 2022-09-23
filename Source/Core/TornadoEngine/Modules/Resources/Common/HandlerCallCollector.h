/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <functional>

namespace nsTornadoEngine
{
    class DllExport THandlerCallCollector
    {
        std::list<std::function<void()>> mFuncs;

    public:
        void Add(std::function<void()> func);
        void Clear();
        void CallAll();
    };
}