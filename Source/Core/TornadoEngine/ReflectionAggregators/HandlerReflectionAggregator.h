/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ITypeFactory.h"
#include "ITypeInformation.h"

namespace nsTornadoEngine
{
    struct DllExport THandlerReflectionAggregator
    {
        virtual ~THandlerReflectionAggregator() {}

        void Init()
        {
            mTypeInfo->Init();
            mTypeFactory->Init();
        }

        ITypeInformation* mTypeInfo = nullptr;
        ITypeFactory* mTypeFactory = nullptr;
    };
}