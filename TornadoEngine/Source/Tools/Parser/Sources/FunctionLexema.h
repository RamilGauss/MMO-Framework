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

        TFunctionLexema(ILexema::LexemaType lexemaType) :mLexemaType(lexemaType) {};

        LexemaType GetType() const override
        {
            return mLexemaType;
        }

        bool CanFill(const TLineTokenEntity* line) const override
        {
            return mLexemaType == ILexema::LexemaType::FUNCTION_DECLARATION ?
                CanFillDeclaration(line) : CanFillDefinition(line);
        }

        void Fill(const TLineTokenEntity* line) override
        {
            mLexemaType == ILexema::LexemaType::FUNCTION_DECLARATION ?
                FillDeclaration(line) : FillDefinition(line);
        }

        ~TFunctionLexema() {}

        std::string ToString()
        {
            auto strCategory = magic_enum::enum_name<MethodCategoryType>(mCategory);            
            return fmt::format("{}: {}, {}, {}", ILexema::ToString(), strCategory.data(), mName, mReturnedType.mOriginalName);
        }
    protected:
        bool CanFillDefinition(const TLineTokenEntity* line) const
        {
            using namespace boost::wave;

            bool isIdentifier = false;
            int cornerCount = 0;
            int parenCount = 0;

            for (auto& t : line->mTokens) {

                if (t.id == T_IDENTIFIER && cornerCount == 0 && parenCount == 0) {
                    isIdentifier = true;
                }
                if (t.id == T_LESS) {
                    isIdentifier = false;
                    cornerCount++;
                }
                if (t.id == T_GREATER) {
                    isIdentifier = false;
                    cornerCount--;
                }
                if (t.id == T_LEFTPAREN) {
                    parenCount++;
                    if (parenCount == 1 && isIdentifier) {
                        return true;
                    }
                    isIdentifier = false;
                }
                if (t.id == T_RIGHTPAREN) {
                    parenCount--;
                }
                if (t.id != T_IDENTIFIER &&
                    t.id != T_SPACE &&
                    t.id != T_SPACE2 &&
                    t.id != T_NEWLINE &&
                    cornerCount == 0 && parenCount == 0) {
                    isIdentifier = false;
                }
            }
            return false;
        }

        bool CanFillDeclaration(const TLineTokenEntity* line) const
        {
            using namespace boost::wave;

            bool hasSemicolon = false;
            for (auto& t : line->mTokens) {

                if (t.id == T_SEMICOLON) {
                    hasSemicolon = true;
                }
            }
            return CanFillDefinition(line) && hasSemicolon;
        }

        void FillDeclaration(const TLineTokenEntity* line)
        {
            using namespace boost::wave;

            std::string lastIdentifier;

            bool isIdentifier = false;
            int cornerCount = 0;
            int parenCount = 0;

            for (auto& t : line->mTokens) {

                if (t.id == T_TEMPLATE) {
                    mCategory = MethodCategoryType::TEMPLATE;
                }
                if (t.id == T_STATIC) {
                    mCategory = MethodCategoryType::STATIC;
                }
                if (t.id == T_VIRTUAL) {
                    mCategory = MethodCategoryType::VIRTUAL;
                }
                if (t.id == T_ANY && t.value == "override") {
                    mCategory = MethodCategoryType::OVERRIDE;
                }
                if (t.id == T_ANY && t.value == "final") {
                    mCategory = MethodCategoryType::VIRTUAL_FINAL;
                }
                if (t.id == T_OPERATOR) {
                    mCategory = MethodCategoryType::OPERATOR;
                }

                if (t.id == T_COMPL) {
                    if (mCategory == MethodCategoryType::VIRTUAL) {
                        mCategory = MethodCategoryType::VIRTUAL_DTOR;
                    } else {
                        mCategory = MethodCategoryType::DTOR;
                    }
                }
                if (t.id == T_DECIMALINT && cornerCount == 0 && parenCount == 0) {
                    if (t.value == "0") {
                        mCategory = MethodCategoryType::VIRTUAL_PURE;
                    }
                }

                if (t.id == T_IDENTIFIER && cornerCount == 0 && parenCount == 0) {
                    lastIdentifier = t.value;
                    isIdentifier = true;
                }
                if (t.id == T_LESS) {
                    cornerCount++;
                }
                if (t.id == T_GREATER) {
                    cornerCount--;
                }
                if (t.id == T_LEFTPAREN) {
                    parenCount++;
                    if (parenCount == 1 && isIdentifier) {
                        isIdentifier = false;
                    }
                }
                if (t.id == T_RIGHTPAREN) {
                    parenCount--;
                }
                if (t.id != T_IDENTIFIER &&
                    t.id != T_SPACE &&
                    t.id != T_SPACE2 &&
                    t.id != T_NEWLINE &&
                    cornerCount == 0 && parenCount == 0) {
                    isIdentifier = false;
                }
            }
        }

        void FillDefinition(const TLineTokenEntity* line)
        {
            FillDeclaration(line);
            // TODO: add FillContent();
        }
    };
}