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

        std::shared_ptr<IRunTimeTypeInformation> mRtti;
        std::shared_ptr<ITypeFactory> mTypeFactory;
        std::shared_ptr<IDynamicCaster> mDynamicCaster;
    };
}
