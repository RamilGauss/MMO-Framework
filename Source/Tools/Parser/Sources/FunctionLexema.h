/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "ILexema.h"
#include "TypeReference.h"
#include "MethodInfo.h"

namespace nsCppParser
{
    class DllExport TFunctionLexema : public ILexema
    {
        ILexema::LexemaType mLexemaType;

    public:
        std::string mName;

        MethodCategoryType mCategory = MethodCategoryType::NONE;

        TTypeReference mReturnedType;

        std::vector<TTypeReference> mArguments;

        std::vector<TTemplateArgument> mTemplateArguments;

        TMethodContent mContent;

        TFunctionLexema(ILexema::LexemaType lexemaType);
        ~TFunctionLexema();

        LexemaType GetType() const override;
        bool CanFill(const TLineTokenEntity* line) const override;
        void Fill(const TLineTokenEntity* line) override;

        std::string ToString() override;
    protected:
        bool CanFillDefinition(const TLineTokenEntity* line) const;
        bool CanFillDeclaration(const TLineTokenEntity* line) const;

        bool CanFill(std::vector<TTokenInfo>& normalizedTokens, size_t size) const;

        void FillDeclaration(const TLineTokenEntity* line);

        void FillDefinition(const TLineTokenEntity* line);
        void FillName(std::vector<TTokenInfo>& tokens);
    };
}