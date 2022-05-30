/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ITypeFactory.h"
#include "ITypeInformation.h"
#include "IEcsSystemExtension.h"

namespace nsTornadoEngine
{
    struct DllExport TFeatureReflectionAggregator
    {
        virtual ~TFeatureReflectionAggregator() {}

        ITypeInformation* mTypeInfo = nullptr;

        ITypeFactory* mTypeFactory = nullptr;

        IEcsSystemExtension* mEcsSystemExtension = nullptr;
    };
}