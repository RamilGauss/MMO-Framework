/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "FeatureReflectionAggregator.h"

namespace nsTornadoEditor
{
    struct DllExport TFeatureReflectionAggregatorImpl : public nsTornadoEngine::TFeatureReflectionAggregator
    {
        TFeatureReflectionAggregatorImpl();
        virtual ~TFeatureReflectionAggregatorImpl();
    };
}