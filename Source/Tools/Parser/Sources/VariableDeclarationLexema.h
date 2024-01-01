/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"
#include "Types.h"
#include "ILexema.h"

namespace nsCppParser
{
    class DllExport TVariableDeclarationLexema : public ILexema
    {
    public:
        std::string mType;
        std::string mName;
        VariableCategory mCategory;

        ILexema::LexemaType GetType() const override;

        bool CanFill(const TLineTokenEntity* line) const override;

        void Fill(const TLineTokenEntity* line) override;

        ~TVariableDeclarationLexema() {}

        std::string ToString() override;
    private:
        static bool IsCanBeType(boost::wave::token_id id);
    };
}