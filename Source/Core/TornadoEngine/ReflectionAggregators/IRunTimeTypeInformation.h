/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <list>

#include "Base/Common/TypeDef.h"

namespace nsTornadoEngine
{
    class DllExport IRunTimeTypeInformation
    {
    public:
        virtual ~IRunTimeTypeInformation() {}

        virtual void Init() = 0;

        virtual const std::list<std::string>* GetTypeNameList() = 0;
        virtual const std::list<int>* GetRunTimeTypeIndexList() = 0;

        virtual bool ConvertTypeToName(int rtti, std::string& typeName) = 0;
        virtual bool ConvertNameToType(const std::string& typeName, int& rtti) = 0;
    };
}
