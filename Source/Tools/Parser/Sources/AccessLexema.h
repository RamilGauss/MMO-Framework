/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "ILexema.h"
#include "Types.h"
#include "Base/Common/BL_Debug.h"

namespace nsCppParser
{
    class DllExport TAccessLexema : public ILexema
    {
    public:
        AccessLevel mAccessLevel;

        ILexema::LexemaType GetType() const override { return ILexema::LexemaType::ACCESS; }

        bool CanFill(const TLineTokenEntity* line) const override
        {
            using namespace boost::wave;
            bool hasAccessAttribute = false;
            bool hasColon = false;

            for (auto& t : line->mTokens) {

                if (t.id == boost::wave::T_PUBLIC) {
                    hasAccessAttribute = true;
                }
                if (t.id == boost::wave::T_PRIVATE) {
                    hasAccessAttribute = true;
                }
                if (t.id == boost::wave::T_PROTECTED) {
                    hasAccessAttribute = true;
                }
                if (t.id == boost::wave::T_COLON && hasAccessAttribute) {
                    hasColon = true;
                }
            }
            return hasAccessAttribute && hasColon;
        }

        void Fill(const TLineTokenEntity* line) override
        {
            using namespace boost::wave;
            for (auto& t : line->mTokens) {

                if (t.id == T_PUBLIC) {
                    mAccessLevel = AccessLevel::PUBLIC;
                    return;
                }
                if (t.id == T_PRIVATE) {
                    mAccessLevel = AccessLevel::PRIVATE;
                    return;
                }
                if (t.id == T_PROTECTED) {
                    mAccessLevel = AccessLevel::PROTECTED;
                    return;
                }
            }
            BL_FIX_BUG();
        }

        ~TAccessLexema() {}
    };
}