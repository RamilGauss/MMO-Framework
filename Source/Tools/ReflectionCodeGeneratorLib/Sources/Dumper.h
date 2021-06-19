/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <list>

#include "IDumper.h"

namespace nsReflectionCodeGenerator
{
    class DllExport TDumper : public IDumper
    {
    public:
        void Save(const std::string& absFileName, std::list<std::string>& content) override;
    };
}
