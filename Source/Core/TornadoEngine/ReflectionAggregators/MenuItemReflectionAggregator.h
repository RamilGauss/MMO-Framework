/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "ITypeInformation.h"

namespace nsTornadoEngine
{
    struct DllExport TMenuItemReflectionAggregator
    {
        virtual ~TMenuItemReflectionAggregator() {}

        ITypeInformation* mTypeInfo = nullptr;
    };
}