/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "LineTokenEntity.h"

#include "magic_enum.hpp"

#include "fmt/core.h"

namespace nsCppParser
{
    class DllExport ILexema
    {
    public:
        enum class LexemaType
        {
            EMPTY,

            NAMESPACE,

            ACCESS,

            CLASS,
            STRUCT,
            ENUM,
            ENUM_VALUES,

            VARIABLE_DECLARATION,

            FUNCTION_DECLARATION,
            FUNCTION_DEFINITION,

            FRIEND,

            PRAGMA,

            IDENTIFIER,
            // IF,
            // FOR,
            // CASE,
            // SWITCH,
            // LAMBDA,
            // TRY,
            // CATCH,
        };


        virtual LexemaType GetType() const = 0;

        virtual bool CanFill(const TLineTokenEntity* line) const = 0;
        virtual void Fill(const TLineTokenEntity* line) = 0;

        virtual ~ILexema() {}

        virtual std::string ToString()
        {
            auto type = magic_enum::enum_name<ILexema::LexemaType>(GetType());
            return type.data();
        }
    protected:
        void ThinningEmpty(const std::vector<TTokenInfo>& tokens, std::vector<TTokenInfo>& tokensOut) const
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

        int Find(const TLineTokenEntity* line, boost::wave::token_id targetId) const
        {
            int index = 0;
            for (auto& t : line->mTokens) {
                if (t.id == targetId) {
                    return index;
                }
                index++;
            }
            return -1;
        }
        int Find(const TLineTokenEntity* line, boost::wave::token_id targetId, std::string value) const
        {
            int index = 0;
            for (auto& t : line->mTokens) {
                if (t.id == targetId && t.value == value) {
                    return index;
                }
                index++;
            }
            return -1;
        }

        int ReverseFind(const std::vector<TTokenInfo>& tokens, boost::wave::token_id targetId) const
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
        int ReverseFind(const std::vector<TTokenInfo>& tokens, boost::wave::token_id targetId, std::string value) const
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
    };
}