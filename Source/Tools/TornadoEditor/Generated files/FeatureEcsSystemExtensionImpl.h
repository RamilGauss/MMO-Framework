/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IEcsSystemExtension.h"

namespace nsTornadoEditor
{
    struct DllExport TFeatureEcsSystemExtensionImpl : public nsTornadoEngine::IEcsSystemExtension
    {
        TFeatureEcsSystemExtensionImpl();
        virtual ~TFeatureEcsSystemExtensionImpl();

        nsECSFramework::TSystem* DynamicCast(void* p, int rtti) override;
    };
}
