/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FunctionLexema.h"

using namespace nsCppParser;

TFunctionLexema::TFunctionLexema(ILexema::LexemaType lexemaType) : mLexemaType(lexemaType)
{

}
//--------------------------------------------------------------------------------------------------------
TFunctionLexema::LexemaType TFunctionLexema::GetType() const
{
    return mLexemaType;
}
//--------------------------------------------------------------------------------------------------------
bool TFunctionLexema::CanFill(const TLineTokenEntity* line) const
{
    return mLexemaType == ILexema::LexemaType::FUNCTION_DECLARATION ?
        CanFillDeclaration(line) : CanFillDefinition(line);
}
//--------------------------------------------------------------------------------------------------------
void TFunctionLexema::Fill(const TLineTokenEntity* line)
{
    mLexemaType == ILexema::LexemaType::FUNCTION_DECLARATION ?
        FillDeclaration(line) : FillDefinition(line);
}
//--------------------------------------------------------------------------------------------------------
TFunctionLexema::~TFunctionLexema()
{
}
//--------------------------------------------------------------------------------------------------------
std::string TFunctionLexema::ToString()
{
    auto strCategory = magic_enum::enum_name<MethodCategoryType>(mCategory);
    return fmt::format("{}: {}, {}, {}", ILexema::ToString(), strCategory.data(), mName, mReturnedType.mOriginalName);
}
//--------------------------------------------------------------------------------------------------------
bool TFunctionLexema::CanFillDefinition(const TLineTokenEntity* line) const
{
    std::vector<TTokenInfo> normalizedTokens;
    ThinningEmpty(line->mTokens, normalizedTokens);
    if (normalizedTokens.size() == 0) {
        return false;
    }

    using namespace boost::wave;
    if (normalizedTokens.back().id == T_SEMICOLON) {
        return false;
    }

    return CanFill(normalizedTokens, normalizedTokens.size());
}
//--------------------------------------------------------------------------------------------------------
bool TFunctionLexema::CanFillDeclaration(const TLineTokenEntity* line) const
{
    std::vector<TTokenInfo> normalizedTokens;
    ThinningEmpty(line->mTokens, normalizedTokens);
    if (normalizedTokens.size() == 0) {
        return false;
    }

    using namespace boost::wave;
    if (normalizedTokens.back().id != T_SEMICOLON) {
        return false;
    }

    return CanFill(normalizedTokens, normalizedTokens.size() - 1);
}
//--------------------------------------------------------------------------------------------------------
bool TFunctionLexema::CanFill(std::vector<TTokenInfo>& normalizedTokens, size_t size) const
{
    using namespace boost::wave;
    auto rightParenIndex = ReverseFind(normalizedTokens, T_RIGHTPAREN);

    if (rightParenIndex == -1) {
        return false;
    }

    for (size_t i = size - 1; i > rightParenIndex; i--) {
        auto& t = normalizedTokens[i];
        switch (t.id) {
            case T_CONST:
            case T_ASSIGN:
            case T_DEFAULT:
                break;
            case T_INTLIT:
                if (t.value != "0") {
                    return false;
                }
                break;
            case T_IDENTIFIER:
                if (t.value != "override" && t.value != "final") {
                    return false;
                }
                break;
            default:
                return false;
        }
    }
    return true;
}
//--------------------------------------------------------------------------------------------------------
void TFunctionLexema::FillDeclaration(const TLineTokenEntity* line)
{
    using namespace boost::wave;

    std::vector<TTokenInfo> normalizedTokens;
    ThinningEmpty(line->mTokens, normalizedTokens);

    FillName(normalizedTokens);

    std::string lastIdentifier;

    bool isIdentifier = false;
    int cornerCount = 0;
    int parenCount = 0;

    for (auto& t : normalizedTokens) {

        if (t.id == T_TEMPLATE) {
            mCategory = MethodCategoryType::TEMPLATE;
        }
        if (t.id == T_STATIC) {
            mCategory = MethodCategoryType::STATIC;
        }
        if (t.id == T_VIRTUAL) {
            mCategory = MethodCategoryType::VIRTUAL;
        }
        if (t.Id() == IdentifierToken::OVERRIDE) {
            mCategory = MethodCategoryType::OVERRIDE;
        }
        if (t.Id() == IdentifierToken::FINAL) {
            mCategory = MethodCategoryType::OVERRIDE_FINAL;
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
        if (t.id == T_INTLIT && cornerCount == 0 && parenCount == 0) {
            if (t.value == "0") {
                mCategory = MethodCategoryType::VIRTUAL_PURE;
            }
        }

        if (t.Id() == IdentifierToken::OTHER && cornerCount == 0 && parenCount == 0) {
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
            cornerCount == 0 && parenCount == 0) {
            isIdentifier = false;
        }
    }
}
//--------------------------------------------------------------------------------------------------------
void TFunctionLexema::FillDefinition(const TLineTokenEntity* line)
{
    FillDeclaration(line);
    // TODO: add FillContent();
}
//--------------------------------------------------------------------------------------------------------
void TFunctionLexema::FillName(std::vector<TTokenInfo>& tokens)
{
    using namespace boost::wave;
    auto rightParenIndex = ReverseFind(tokens, T_RIGHTPAREN);

    int parenBalance = 1;

    for (int i = rightParenIndex - 1; i >= 0; i--) {
        auto& token = tokens[i];
        if (token.id == T_RIGHTPAREN) {
            parenBalance++;
        }
        if (token.id == T_LEFTPAREN) {
            parenBalance--;
        }
        if (parenBalance == 0) {
            auto& prevToken = tokens[i - 1];
            if (prevToken.id != T_IDENTIFIER) {
                auto& prevPrevToken = tokens[i - 2];
                mName = prevPrevToken.value;
                mName += prevToken.value;
            } else {
                mName = prevToken.value;
            }
            break;
        }
    }
}
//--------------------------------------------------------------------------------------------------------