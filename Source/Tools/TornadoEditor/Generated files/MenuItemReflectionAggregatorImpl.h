/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "MenuItemReflectionAggregator.h"

namespace nsTornadoEditor
{
    struct DllExport TMenuItemReflectionAggregatorImpl : public nsTornadoEngine::TMenuItemReflectionAggregator
    {
        TMenuItemReflectionAggregatorImpl();
        virtual ~TMenuItemReflectionAggregatorImpl();
    };
}