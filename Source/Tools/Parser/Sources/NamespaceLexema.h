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
    class DllExport TNamespaceLexema : public ILexema
    {
    public:
        std::string mName;

        ILexema::LexemaType GetType() const override { return ILexema::LexemaType::NAMESPACE; }

        bool CanFill(const TLineTokenEntity* line) const override
        {
            using namespace boost::wave;
            bool hasNamespace = false;
            bool hasUsing = false;

            for (auto& t : line->mTokens) {
                if (t.id == T_NAMESPACE) {
                    hasNamespace = true;
                }
                if (t.id == T_USING) {
                    hasUsing = true;
                }
            }
            return hasNamespace && !hasUsing;
        }

        void Fill(const TLineTokenEntity* line) override
        {
            using namespace boost::wave;
            bool hasNamespace = false;
            bool hasUsing = false;

            for (auto& t : line->mTokens) {
                if (t.id == T_IDENTIFIER) {
                    mName = t.value;
                }
            }
        }

        ~TNamespaceLexema() {}

        std::string ToString() override
        {
            return fmt::format("{}: \"{}\"", ILexema::ToString(), mName);
        }
    };
}