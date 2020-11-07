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
    class DllExport TFunctionDeclarationLexema : public ILexema
    {
    public:


        ILexema::LexemaType GetType() override { return ILexema::LexemaType::FUNCTION_DECLARATION; }

        bool CanFill(const TLineTokenEntity* line) const override
        {
            using namespace boost::wave;

            //bool isEnum = false;
            //for (auto& t : line->mTokenList) {

            //    if (t.id == T_ENUM) {
            //        isEnum = true;
            //    }
            //}

            //return line->mTokenList[line->mTokenList.size()-1].id == T_SEMICOLON;
            return false;
        }

        void Fill(const TLineTokenEntity* line) override
        {

        }

        ~TFunctionDeclarationLexema() {}
    };
}