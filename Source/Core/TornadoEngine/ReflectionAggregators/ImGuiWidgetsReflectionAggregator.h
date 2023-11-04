/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IRunTimeTypeInformation.h"
#include "IDynamicCaster.h"

namespace nsTornadoEngine
{
    struct DllExport TImGuiWidgetsReflectionAggregator
    {
        virtual ~TImGuiWidgetsReflectionAggregator() {}

        void Init()
        {
            mRtti->Init();
            mDynamicCaster->Init();
        }

        IRunTimeTypeInformation* mRtti = nullptr;
        IDynamicCaster* mDynamicCaster = nullptr;
    };
}
