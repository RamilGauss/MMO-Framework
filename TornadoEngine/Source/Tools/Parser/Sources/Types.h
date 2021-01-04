/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

namespace nsCppParser
{
    enum class DeclarationType
    {
        CLASS, STRUCT, ENUM
    };

    enum class AccessLevel
    {
        PUBLIC, PROTECTED, PRIVATE, COUNT
    };

    enum class MethodCategoryType
    {
        NONE,
        STATIC,
        CTOR,
        DTOR,
        VIRTUAL_DTOR,
        VIRTUAL,
        VIRTUAL_PURE,
        OVERRIDE,
        VIRTUAL_FINAL,
        TEMPLATE,
        OPERATOR,
    };

    enum class TemplateArgument
    {
        TYPENAME, CLASS, TYPE
    };

    enum class VariableCategory
    {
        NONE, STATIC, CONST, CONSTEXPR, STATIC_CONST
    };
}