/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2025_01_30 15:40:55.071
#pragma once

#include "ITypeFactory.h"

namespace nsTornadoEditor
{
    struct DllExport TComponentTypeFactoryImpl : public nsTornadoEngine::ITypeFactory
    {
        TComponentTypeFactoryImpl();
        virtual ~TComponentTypeFactoryImpl();
        
        void Init() override;
        void* New(int rtti) override;
        void Delete(void* p, int rtti) override;
    };
}
