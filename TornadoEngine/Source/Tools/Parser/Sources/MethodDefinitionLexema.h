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
    class DllExport TMethodDefinitionLexema : public ILexema
    {
    public:
        ILexema::LexemaType GetType() override { return ILexema::LexemaType::METHOD_DEFINITION; }

        bool CanFill(const TLineTokenEntity& line) const override
        {
            return false;
        }

        void Fill(const TLineTokenEntity& line) override
        {

        }

        ~TMethodDefinitionLexema() {}
    };
}