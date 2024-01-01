/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Base/Common/TypeDef.h"

namespace nsTornadoEngine
{
    class DllExport IJsonSerializer
    {
    public:
        virtual ~IJsonSerializer() {}

        virtual void Init() = 0;

        // Не должен знать о существовании rtti, если это нужно используй ITypeInformation.
        virtual void Serialize(void* p, std::string& json, int rtti) = 0;
        virtual bool Deserialize(void* p, const std::string& json, int rtti, std::string& err) = 0;
    };
}
