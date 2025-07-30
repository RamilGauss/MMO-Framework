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
#include "Parser/Sources/ILexemaEntity.h"
#include "Parser/Sources/ILexema.h"

namespace nsCppParser
{
    class DllExport TLineLexemaEntity : public ILexemaEntity
    {
    public:
        std::vector<std::shared_ptr<ILexema>> mLexemas;

        virtual Type GetType() override
        {
            return Type::LINE;
        }
    };
}