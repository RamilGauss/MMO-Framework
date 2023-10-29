/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "IRunTimeTypeInformation.h"

namespace nsTornadoEngine
{
    struct DllExport TMenuItemReflectionAggregator
    {
        virtual ~TMenuItemReflectionAggregator() {}

        void Init()
        {
            mRunTimeTypeInfo->Init();
        }

        IRunTimeTypeInformation* mRunTimeTypeInfo = nullptr;
    };
}
