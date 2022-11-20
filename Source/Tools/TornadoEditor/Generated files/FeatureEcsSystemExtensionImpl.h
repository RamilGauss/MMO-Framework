/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IDynamicCaster.h"

namespace nsTornadoEditor
{
    struct DllExport TFeatureEcsSystemExtensionImpl : public nsTornadoEngine::IDynamicCaster
    {
        TFeatureEcsSystemExtensionImpl();
        virtual ~TFeatureEcsSystemExtensionImpl();

        void* Cast(int srcRtti, void* srcPtr, int dstRtti) override;
    };
}
