/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "ILexema.h"
#include "Types.h"
#include "BL_Debug.h"

namespace nsCppParser
{
    class DllExport TAccessLexema : public ILexema
    {
    public:
        AccessLevel mAccessLevel;

        ILexema::LexemaType GetType() override { return ILexema::LexemaType::ACCESS; }

        bool CanFill(const TLineTokenEntity& line) const override
        {
            for (auto& t : line.mTokenList) {

                if (t.id == boost::wave::T_PUBLIC) {
                    return true;
                }
                if (t.id == boost::wave::T_PRIVATE) {
                    return true;
                }
                if (t.id == boost::wave::T_PROTECTED) {
                    return true;
                }
            }
            return false;
        }

        void Fill(const TLineTokenEntity& line) override
        {
            for (auto& t : line.mTokenList) {

                if (t.id == boost::wave::T_PUBLIC) {
                    mAccessLevel = AccessLevel::PUBLIC;
                    return;
                }
                if (t.id == boost::wave::T_PRIVATE) {
                    mAccessLevel = AccessLevel::PRIVATE;
                    return;
                }
                if (t.id == boost::wave::T_PROTECTED) {
                    mAccessLevel = AccessLevel::PROTECTED;
                    return;
                }
            }
            BL_FIX_BUG();
        }

        ~TAccessLexema() {}
    };
}