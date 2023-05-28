/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_05_28 18:14:10.746
	
#pragma once

#include "IJsonSerializer.h"

namespace nsTornadoEditor
{
    struct DllExport TComponentJsonSerializerImpl : public nsTornadoEngine::IJsonSerializer
    {
        TComponentJsonSerializerImpl();
        virtual ~TComponentJsonSerializerImpl();
        
        void Serialize(void* p, std::string& json, int rtti) override;
        bool Deserialize(void* p, const std::string& json, int rtti, std::string& err) override;
    };
}
