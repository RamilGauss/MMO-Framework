/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include <memory>
#include <string>

#include "TypeDef.h"
#include "ILexemaEntity.h"

namespace nsCppParser
{
    class DllExport TBlockLexemaEntity : public ILexemaEntity
    {
    public:
        TBlockLexemaEntity* mParentBlock = nullptr;

        std::vector<std::shared_ptr<ILexemaEntity>> mTokens;

        virtual Type GetType() override
        {
            return Type::BLOCK;
        }

        std::string ToString(int indend = 0);
    };
}