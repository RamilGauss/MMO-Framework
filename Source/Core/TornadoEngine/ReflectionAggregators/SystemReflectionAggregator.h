/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TornadoEngine/ReflectionAggregators/ITypeFactory.h"
#include "TornadoEngine/ReflectionAggregators/IRunTimeTypeInformation.h"
#include "TornadoEngine/ReflectionAggregators/IDynamicCaster.h"

namespace nsTornadoEngine
{
    struct DllExport TSystemReflectionAggregator
    {
        virtual ~TSystemReflectionAggregator() {}

        void Init()
        {
            mRtti->Init();
            mTypeFactory->Init();
            mDynamicCaster->Init();
        }

        IRunTimeTypeInformation* mRtti = nullptr;
        ITypeFactory* mTypeFactory = nullptr;
        IDynamicCaster* mDynamicCaster = nullptr;
    };
}
