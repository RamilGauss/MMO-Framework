/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <list>

#include "TypeDef.h"

namespace nsShareDev
{
    class DllExport ITypeInformation
    {
    public:

        virtual const std::list<std::string>* GetTypeNameList() = 0;
        virtual const std::list<int>* GetTypeIdentifierList() = 0;

        virtual bool ConvertTypeToName(int typeIdentifier, std::string& typeName) = 0;
        virtual bool ConvertNameToType(const std::string& typeName, int& typeIdentifier) = 0;
    };
}