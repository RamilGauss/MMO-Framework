/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TornadoEngine/ReflectionAggregators/ITypeFactory.h"
#include "TornadoEngine/ReflectionAggregators/ITypeInformation.h"
#include "TornadoEngine/ReflectionAggregators/IRunTimeTypeInformation.h"

namespace nsTornadoEngine
{
    struct DllExport THandlerReflectionAggregator
    {
        virtual ~THandlerReflectionAggregator() {}

        void Init()
        {
            mTypeInfo->Init();
            mRtti->Init();
            mTypeFactory->Init();
        }

        std::shared_ptr<IRunTimeTypeInformation> mRtti;
        std::shared_ptr<ITypeInformation> mTypeInfo;
        std::shared_ptr<ITypeFactory> mTypeFactory;
    };
}
