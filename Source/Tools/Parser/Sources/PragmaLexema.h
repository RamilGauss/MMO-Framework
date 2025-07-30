/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "Parser/Sources/ILexema.h"

namespace nsCppParser
{
    class DllExport TPragmaLexema : public ILexema
    {
    public:
        std::string mValue;

        ILexema::LexemaType GetType() const override { return ILexema::LexemaType::PRAGMA; }

        bool CanFill(const TLineTokenEntity* line) const override
        {
            bool isPragma = false;

            using namespace boost::wave;
            for (auto& t : line->mTokens) {

                if (t.id == T_PP_PRAGMA) {
                    isPragma = true;
                }
            }
            return isPragma;
        }

        void Fill(const TLineTokenEntity* line) override
        {
            mValue = "";
            bool isPragma = false;

            using namespace boost::wave;
            for (auto& t : line->mTokens) {

                if (t.id == T_PP_PRAGMA) {
                    isPragma = true;
                }
                if (t.id == T_NEWLINE) {
                    isPragma = false;
                }
                if (!isPragma) {
                    continue;
                }

                if (t.id == T_IDENTIFIER ||
                    t.id == T_STRINGLIT ||
                    t.id == T_LEFTPAREN ||
                    t.id == T_RIGHTPAREN ||
                    t.id == T_INTLIT ||
                    t.id == T_COMMA ||
                    t.id == T_CLASS ||
                    t.id == T_STRUCT ||
                    t.id == T_ENUM) {
                    mValue += t.value;
                }

                if (mValue.length() > 0 && t.id == T_SPACE) {
                    mValue += t.value;
                }
            }

            int cnt = (int)(mValue.length());
            for (int i = cnt - 1; i >= 0; i--) {
                if (mValue.at(i) != ' ') {
                    mValue.erase(i + 1, cnt - 1);
                    break;
                }
            }
        }

        ~TPragmaLexema() {}

        std::string ToString() override
        {
            return fmt::format("{}: {}", ILexema::ToString(), mValue);
        }
    };
}