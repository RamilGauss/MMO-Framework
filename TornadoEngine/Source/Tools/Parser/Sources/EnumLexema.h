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
    class DllExport TEnumLexema : public ILexema
    {
    public:
        std::string mName;

        ILexema::LexemaType GetType() override { return ILexema::LexemaType::ENUM; }

        bool CanFill(const TLineTokenEntity* line) const override
        {
            using namespace boost::wave;

            bool isEnum = false;
            for (auto& t : line->mTokens) {

                if (t.id == T_ENUM) {
                    isEnum = true;
                }
            }
            return isEnum;
        }

        void Fill(const TLineTokenEntity* line) override
        {

        }

        ~TEnumLexema() {}
    };
}