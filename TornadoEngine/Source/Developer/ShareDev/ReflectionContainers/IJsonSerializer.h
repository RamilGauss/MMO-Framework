/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"

namespace nsShareDev
{
    class DllExport IJsonSerializer
    {
    public:
        virtual void Serialize(void* p, std::string& json, const std::string& typeName) = 0;
        virtual bool Deserialize(void*& p, const std::string& json, const std::string& typeName, std::string& err) = 0;
        virtual bool Fill(void* p, std::string& json, const std::string& typeName, std::string& err) = 0;

        virtual void Serialize(void* p, std::string& json, int typeIdentifier) = 0;
        virtual bool Deserialize(void*& p, const std::string& json, int typeIdentifier, std::string& err) = 0;
        virtual bool Fill(void* p, std::string& json, int typeIdentifier, std::string& err) = 0;
    };
}