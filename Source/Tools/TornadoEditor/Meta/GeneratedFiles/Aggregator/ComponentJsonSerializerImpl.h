/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2025_01_30 15:40:58.491
#pragma once

#include "TornadoEngine/ReflectionAggregators/IJsonSerializer.h"

namespace nsTornadoEditor
{
    struct DllExport TComponentJsonSerializerImpl : public nsTornadoEngine::IJsonSerializer
    {
        TComponentJsonSerializerImpl();
        virtual ~TComponentJsonSerializerImpl();
        
        void Init() override;
        void Serialize(void* p, std::string& json, int rtti) override;
        bool Deserialize(void* p, const std::string& json, int rtti, std::string& err) override;
    };
}
