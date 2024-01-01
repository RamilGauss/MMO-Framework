/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "ILexema.h"

namespace nsCppParser
{
    class DllExport TIdentifierLexema : public ILexema
    {
    public:
        std::string mIdentifier;

        ILexema::LexemaType GetType() const override { return ILexema::LexemaType::IDENTIFIER; }

        bool CanFill(const TLineTokenEntity* line) const override
        {
            return false;
            //using namespace boost::wave;
            //bool hasIdentifier = false;

            //for (auto& t : line->mTokens) {

            //    if (t.id != T_IDENTIFIER &&
            //        t.id != T_SPACE &&
            //        t.id != T_SPACE2 &&
            //        t.id != T_NEWLINE) {
            //        return false;
            //    }
            //    if (t.id == T_IDENTIFIER) {
            //        hasIdentifier = true;
            //    }

            //}
            //return hasIdentifier;
        }

        void Fill(const TLineTokenEntity* line) override
        {
            using namespace boost::wave;
            for (auto& t : line->mTokens) {

                if (t.id != T_IDENTIFIER) {
                    mIdentifier = t.value;
                }
            }
        }

        ~TIdentifierLexema() {}
    };
}