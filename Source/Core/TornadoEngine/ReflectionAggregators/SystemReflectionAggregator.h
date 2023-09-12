/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ITypeFactory.h"
#include "ITypeInformation.h"
#include "IDynamicCaster.h"

namespace nsTornadoEngine
{
    struct DllExport TSystemReflectionAggregator
    {
        virtual ~TSystemReflectionAggregator() {}

        void Init()
        {
            mTypeInfo->Init();
            mTypeFactory->Init();
            mDynamicCaster->Init();
        }

        ITypeInformation* mTypeInfo = nullptr;
        ITypeFactory* mTypeFactory = nullptr;
        IDynamicCaster* mDynamicCaster = nullptr;
    };
}