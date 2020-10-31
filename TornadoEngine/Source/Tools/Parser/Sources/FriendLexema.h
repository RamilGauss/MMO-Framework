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
    class DllExport TFriendLexema : public ILexema
    {
    public:
        // friend type, etc.
        ILexema::LexemaType GetType() override { return ILexema::LexemaType::FRIEND; }

        bool CanFill(const TLineTokenEntity& line) const override
        {
            for (auto& t : line.mTokenList) {
                if (t.id == boost::wave::T_FRIEND) {
                    return true;
                }
            }
            return false;
        }

        void Fill(const TLineTokenEntity& line) override
        {

        }

        ~TFriendLexema() {}
    };
}