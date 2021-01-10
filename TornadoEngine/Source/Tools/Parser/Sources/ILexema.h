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
    };
}