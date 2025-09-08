/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#pragma once

#include "TornadoEngine/ReflectionAggregators/ITypeFactory.h"

namespace nsGuiProject
{
    struct DllExport THandlerTypeFactoryImpl : public nsTornadoEngine::ITypeFactory
    {
        THandlerTypeFactoryImpl();
        virtual ~THandlerTypeFactoryImpl();
        
        void Init() override;
        void* New(int rtti) override;
        void Delete(void* p, int rtti) override;
    };
}
