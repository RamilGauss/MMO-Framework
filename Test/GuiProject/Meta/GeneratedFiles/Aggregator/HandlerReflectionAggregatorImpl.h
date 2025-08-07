/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#pragma once

#include "HandlerReflectionAggregator.h"

namespace nsTornadoEditor
{
    struct DllExport THandlerReflectionAggregatorImpl : public nsTornadoEngine::THandlerReflectionAggregator
    {
        THandlerReflectionAggregatorImpl();
        virtual ~THandlerReflectionAggregatorImpl();
    };
}
