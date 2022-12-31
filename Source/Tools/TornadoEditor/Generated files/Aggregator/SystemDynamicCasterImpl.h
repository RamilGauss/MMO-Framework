/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2022_12_31 15:11:55.544
	
#pragma once

#include "IDynamicCaster.h"

namespace nsTornadoEditor
{
    struct DllExport TSystemDynamicCasterImpl : public nsTornadoEngine::IDynamicCaster
    {
        TSystemDynamicCasterImpl();
        virtual ~TSystemDynamicCasterImpl();
        
        void* Cast(int srcRtti, void* srcPtr, int dstRtti) override;
    };
}
