/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_05_28 17:59:43.232
	
#pragma once

#include "ITypeFactory.h"

namespace nsTornadoEditor
{
    struct DllExport TSystemTypeFactoryImpl : public nsTornadoEngine::ITypeFactory
    {
        TSystemTypeFactoryImpl();
        virtual ~TSystemTypeFactoryImpl();
        
        void* New(int rtti) override;
        void Delete(void* p, int rtti) override;
    };
}
