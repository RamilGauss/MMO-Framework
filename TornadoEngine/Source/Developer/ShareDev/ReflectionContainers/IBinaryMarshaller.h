/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"
#include "ContainerRise.h"

namespace nsShareDev
{
    class DllExport IBinaryMarshaller
    {
    public:
        virtual void Serialize(void* p, TContainerRise& c, const std::string& typeName) = 0;
        virtual bool Deserialize(void*& p, void* serData, int size, const std::string& typeName) = 0;
        virtual bool Fill(void* p, void* serData, int size, const std::string& typeName) = 0;

        virtual void Serialize(void* p, TContainerRise& c, int typeIdentifier) = 0;
        virtual bool Deserialize(void*& p, void* serData, int size, int typeIdentifier) = 0;
        virtual bool Fill(void* p, void* serData, int size, int typeIdentifier) = 0;

        virtual void Pack(void* p, TContainerRise& c, const std::string& typeName) = 0;
        virtual bool Unpack(void*& p, void* serData, int size, std::string& typeName) = 0;

        virtual void Pack(void* p, TContainerRise& c, int typeIdentifier) = 0;
        virtual bool Unpack(void*& p, void* serData, int size, int& typeIdentifier) = 0;
    };
}