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

namespace nsTornadoEngine
{
    class DllExport IBinaryMarshaller
    {
    public:
        virtual ~IBinaryMarshaller() {}

        virtual void Init() = 0;

        virtual void Serialize(void* p, TContainerRise& c, int rtti) = 0;
        virtual bool Deserialize(void* p, void* serData, int size, int rtti) = 0;

        virtual void Pack(void* p, TContainerRise& c, int rtti) = 0;

        virtual bool GetRtti(void* serData, int size, int& rtti) = 0;
        virtual bool Unpack(void* p, void* serData, int size) = 0;
    };
}