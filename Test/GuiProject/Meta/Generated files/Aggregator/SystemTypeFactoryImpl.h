/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2024_12_27 12:43:40.406
#pragma once

#include "ITypeFactory.h"

namespace nsTornadoEditor
{
    struct DllExport TSystemTypeFactoryImpl : public nsTornadoEngine::ITypeFactory
    {
        TSystemTypeFactoryImpl();
        virtual ~TSystemTypeFactoryImpl();
        
        void Init() override;
        void* New(int rtti) override;
        void Delete(void* p, int rtti) override;
    };
}
