/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#pragma once

#include "TornadoEngine/ReflectionAggregators/HandlerReflectionAggregator.h"

namespace nsGuiProject
{
    struct DllExport THandlerReflectionAggregatorImpl : public nsTornadoEngine::THandlerReflectionAggregator
    {
        THandlerReflectionAggregatorImpl();
        virtual ~THandlerReflectionAggregatorImpl();
    };
}
