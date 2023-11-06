/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_11_06 16:43:44.858
	
#pragma once

#include "IDynamicCaster.h"

namespace nsTornadoEditor
{
    struct DllExport TSystemDynamicCasterImpl : public nsTornadoEngine::IDynamicCaster
    {
        TSystemDynamicCasterImpl();
        virtual ~TSystemDynamicCasterImpl();
        
        void Init() override;
        void* Cast(int srcRtti, void* srcPtr, int dstRtti) override;
    };
}
