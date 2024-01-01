/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>
#include "Base/Common/TypeDef.h"

#include "ILexema.h"

namespace nsCppParser
{
    class DllExport TEnumLexema : public ILexema
    {
    public:
        std::string mName;

        ILexema::LexemaType GetType() const override { return ILexema::LexemaType::ENUM; }

        bool CanFill(const TLineTokenEntity* line) const override
        {
            using namespace boost::wave;

            bool isEnum = false;
            bool isIdentifierAfterEnum = false;
            for (auto& t : line->mTokens) {

                if (t.id == T_ENUM) {
                    isEnum = true;
                }
                if (t.id == T_PP_PRAGMA) {
                    return false;
                }
                if (t.id == T_IDENTIFIER && isEnum) {
                    isIdentifierAfterEnum = true;
                }
            }
            return isEnum && isIdentifierAfterEnum;
        }

        void Fill(const TLineTokenEntity* line) override
        {
            using namespace boost::wave;
            for (auto& t : line->mTokens) {
                if (t.id == T_IDENTIFIER) {
                    mName = t.value;
                    return;
                }
            }
            BL_FIX_BUG();
        }

        ~TEnumLexema() {}

        std::string ToString() override
        {
            auto type = magic_enum::enum_name<ILexema::LexemaType>(GetType());
            return fmt::format("{} : {}", type.data(), mName);
        }
    };
}