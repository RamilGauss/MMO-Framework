/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IJsonSerializer.h"

namespace nsTornadoEditor
{
    struct DllExport TTornadoEditor_Component_JsonSerializer : public nsTornadoEngine::IJsonSerializer
    {
        TTornadoEditor_Component_JsonSerializer();
        virtual ~TTornadoEditor_Component_JsonSerializer();

        void Serialize(void* p, std::string& json, int rtti) override;
        bool Deserialize(void* p, const std::string& json, int rtti, std::string& err) override;
    };
}
