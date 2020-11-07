/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "ILexema.h"

namespace nsCppParser
{
    class DllExport TPragmaLexema : public ILexema
    {
    public:
        std::string mValue;

        ILexema::LexemaType GetType() override { return ILexema::LexemaType::PRAGMA; }

        bool CanFill(const TLineTokenEntity* line) const override
        {
            bool isPragma = false;

            using namespace boost::wave;
            for (auto& t : line->mTokenList) {

                if (t.id == T_PP_PRAGMA) {
                    isPragma = true;
                }
            }
            return isPragma;
        }

        void Fill(const TLineTokenEntity* line) override
        {
            bool isPragma = false;

            using namespace boost::wave;
            for (auto& t : line->mTokenList) {

                if (t.id == T_PP_PRAGMA) {
                    isPragma = true;
                }
                if (t.id == T_NEWLINE) {
                    isPragma = false;
                }
                if ((t.id == T_IDENTIFIER || t.id == T_STRINGLIT) && isPragma) {
                    mValue = t.value;
                }
            }
        }

        ~TPragmaLexema() {}

        std::string GetInfo() override
        {
            return fmt::format("{}: value {}", ILexema::GetInfo(), mValue);
        }
    };
}