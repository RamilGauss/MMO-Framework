/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include "LineTokenEntity.h"

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

            FUNCTION_DECLARATION,
            FUNCTION_DEFINITION,
            
            MEMBER,
            
            METHOD_DECLARATION,
            METHOD_DEFINITION,

            FRIEND,

            PRAGMA,
            // IF,
            // FOR,
            // CASE,
            // SWITCH,
            // LAMBDA,
            // TRY,
            // CATCH,
            COUNT,
        };


        virtual LexemaType GetType() = 0;

        virtual bool CanFill(const TLineTokenEntity& line) const = 0;
        virtual void Fill(const TLineTokenEntity& line) = 0;

        virtual ~ILexema() {}
    };
}