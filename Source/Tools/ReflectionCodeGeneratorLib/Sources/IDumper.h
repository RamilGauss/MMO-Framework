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

namespace nsReflectionCodeGenerator
{
    class DllExport IDumper
    {
    public:
        virtual void Save(const std::string& absFileName, std::list<std::string>& content) = 0;
    };
}
