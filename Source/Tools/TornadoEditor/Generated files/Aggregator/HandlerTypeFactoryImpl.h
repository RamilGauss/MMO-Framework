/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// File has been generated at 2022_12_29 17:47:00.841
	
#pragma once

#include "ITypeFactory.h"

namespace nsTornadoEditor
{
    struct DllExport THandlerTypeFactoryImpl : public nsTornadoEngine::ITypeFactory
    {
        THandlerTypeFactoryImpl();
        virtual ~THandlerTypeFactoryImpl();
        
        void* New(int rtti) override;
        void Delete(void* p, int rtti) override;
    };
}
