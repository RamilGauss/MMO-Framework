/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ILexema.h"

using namespace nsCppParser;

std::string ILexema::ToString()
{
    auto type = magic_enum::enum_name<ILexema::LexemaType>(GetType());
    return type.data();
}
//-------------------------------------------------------------------------------------------------------------
void ILexema::ThinningEmpty(const std::vector<TTokenInfo>& tokens, std::vector<TTokenInfo>& tokensOut) const
{
    using namespace boost::wave;
    for (auto& t : tokens) {
        switch (t.id) {
            case T_SPACE:
            case T_SPACE2:
            case T_NEWLINE:
                break;
            default:
                tokensOut.push_back(t);
                break;
        }
    }
}
//-------------------------------------------------------------------------------------------------------------
int ILexema::Find(const TLineTokenEntity* line, boost::wave::token_id targetId) const
{
    return Find(line->mTokens, targetId);
}
//-------------------------------------------------------------------------------------------------------------
int ILexema::Find(const TLineTokenEntity* line, boost::wave::token_id targetId, std::string value) const
{
    return Find(line->mTokens, targetId, value);
}
//-------------------------------------------------------------------------------------------------------------
int ILexema::ReverseFind(const std::vector<TTokenInfo>& tokens, boost::wave::token_id targetId) const
{
    int index = 0;
    auto cnt = (int) tokens.size();
    for (int i = cnt - 1; i >= 0; i--) {
        auto& t = tokens[i];
        if (t.id == targetId) {
            return i;
        }
    }
    return -1;
}
//-------------------------------------------------------------------------------------------------------------
int ILexema::ReverseFind(const std::vector<TTokenInfo>& tokens, boost::wave::token_id targetId, std::string value) const
{
    int index = 0;
    auto cnt = (int) tokens.size();
    for (int i = cnt - 1; i >= 0; i--) {
        auto& t = tokens[i];
        if (t.id == targetId && t.value == value) {
            return i;
        }
    }
    return -1;
}
//-------------------------------------------------------------------------------------------------------------
int ILexema::Find(const std::vector<TTokenInfo>& tokens, boost::wave::token_id targetId) const
{
    int index = 0;
    for (auto& t : tokens) {
        if (t.id == targetId) {
            return index;
        }
        index++;
    }
    return -1;
}
//-------------------------------------------------------------------------------------------------------------
int ILexema::Find(const std::vector<TTokenInfo>& tokens, boost::wave::token_id targetId, std::string value) const
{
    int index = 0;
    for (auto& t : tokens) {
        if (t.id == targetId && t.value == value) {
            return index;
        }
        index++;
    }
    return -1;
}
//-------------------------------------------------------------------------------------------------------------