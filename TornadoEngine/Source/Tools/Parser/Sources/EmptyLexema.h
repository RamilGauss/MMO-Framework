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
    class DllExport TEmptyLexema : public ILexema
    {
    public:
        ILexema::LexemaType GetType() override { return ILexema::LexemaType::EMPTY; }

        bool CanFill(const TLineTokenEntity* line) const override
        {
            using namespace boost::wave;

            for (auto& t : line->mTokens) {

                if (t.id != T_SPACE &&
                    t.id != T_SPACE2 &&
                    t.id != T_NEWLINE &&
                    t.id != T_SEMICOLON) {
                    return false;
                }
            }
            return true;
        }

        void Fill(const TLineTokenEntity* line) override
        {

        }

        ~TEmptyLexema() {}
    };
}