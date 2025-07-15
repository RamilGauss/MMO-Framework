/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "LineTokenEntity.h"

#include <magic_enum/magic_enum.hpp>

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

        virtual std::string ToString();
    protected:
        void ThinningEmpty(const std::vector<TTokenInfo>& tokens, std::vector<TTokenInfo>& tokensOut) const;

        int Find(const TLineTokenEntity* line, boost::wave::token_id targetId) const;
        int Find(const TLineTokenEntity* line, boost::wave::token_id targetId, std::string value) const;
        int ReverseFind(const std::vector<TTokenInfo>& tokens, boost::wave::token_id targetId) const;
        int ReverseFind(const std::vector<TTokenInfo>& tokens, boost::wave::token_id targetId, std::string value) const;
        int Find(const std::vector<TTokenInfo>& tokens, boost::wave::token_id targetId) const;
        int Find(const std::vector<TTokenInfo>& tokens, boost::wave::token_id targetId, std::string value) const;

        int FindIndexOutOfCorners(const std::vector<TTokenInfo>& tokens, boost::wave::token_id targetId, bool reverse) const;
    };
}