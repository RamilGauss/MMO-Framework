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
#include "Parser/Sources/TokenInfo.h"

namespace nsCppParser
{
    class DllExport TTokenizer
    {
    public:
        bool Work(const std::string& inStr, std::list<TTokenInfo>& resultList);

        std::string ErrorDesc();
    };
}