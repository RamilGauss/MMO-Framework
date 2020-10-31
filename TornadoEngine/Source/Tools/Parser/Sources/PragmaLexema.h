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

        bool CanFill(const TLineTokenEntity& line) const override
        {
            if (line.mTokenList[0].id == boost::wave::T_PP_PRAGMA ) {
                return true;
            }
            return false;
        }

        void Fill(const TLineTokenEntity& line) override
        {

        }

        ~TPragmaLexema() {}
    };
}