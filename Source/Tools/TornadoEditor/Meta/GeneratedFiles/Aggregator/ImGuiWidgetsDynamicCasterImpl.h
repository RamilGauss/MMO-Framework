/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2025_01_30 15:40:58.491
#pragma once

#include "TornadoEngine/ReflectionAggregators/IDynamicCaster.h"

namespace nsTornadoEditor
{
    struct DllExport TImGuiWidgetsDynamicCasterImpl : public nsTornadoEngine::IDynamicCaster
    {
        TImGuiWidgetsDynamicCasterImpl();
        virtual ~TImGuiWidgetsDynamicCasterImpl();
        
        void Init() override;
        void* Cast(int srcRtti, void* srcPtr, int dstRtti) override;
    };
}
