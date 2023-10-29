/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "Parser/Sources/TypeInfo.h"

namespace nsTornadoEngine
{
    class DllExport ITypeInformation
    {
    public:
        virtual ~ITypeInformation() {}

        virtual void Init() = 0;

        virtual const nsCppParser::TTypeInfo* Get(int rtti) = 0;
    };
}
