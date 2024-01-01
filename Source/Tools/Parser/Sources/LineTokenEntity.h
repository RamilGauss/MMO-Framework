/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include <memory>

#include "Base/Common/TypeDef.h"
#include "ITokenEntity.h"
#include "TokenInfo.h"

namespace nsCppParser
{
    class DllExport TLineTokenEntity : public ITokenEntity
    {
    public:
        std::vector<TTokenInfo> mTokens;

        virtual Type GetType() override
        {
            return Type::LINE;
        }
    };
}