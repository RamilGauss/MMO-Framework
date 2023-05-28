/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_05_28 11:36:55.110
	
#pragma once

#include "IDynamicCaster.h"

namespace nsTornadoEditor
{
    struct DllExport TComponentDynamicCasterImpl : public nsTornadoEngine::IDynamicCaster
    {
        TComponentDynamicCasterImpl();
        virtual ~TComponentDynamicCasterImpl();
        
        void* Cast(int srcRtti, void* srcPtr, int dstRtti) override;
    };
}
