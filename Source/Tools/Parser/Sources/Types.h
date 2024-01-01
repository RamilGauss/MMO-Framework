/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#ifdef CONST
#undef CONST
#endif

namespace nsCppParser
{
#pragma REFLECTION_ATTRIBUTE
    enum class DeclarationType
    {
        CLASS, STRUCT, ENUM
    };
#pragma REFLECTION_ATTRIBUTE
    enum class AccessLevel
    {
        PUBLIC, PROTECTED, PRIVATE, COUNT
    };

#pragma REFLECTION_ATTRIBUTE
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
        OVERRIDE_FINAL,
        TEMPLATE,
        TEMPLATE_STATIC,
        OPERATOR,
    };

#pragma REFLECTION_ATTRIBUTE
    enum class TemplateArgument
    {
        TYPENAME, CLASS, TYPE
    };

#pragma REFLECTION_ATTRIBUTE
    enum class VariableCategory
    {
        NONE, MUTABLE, STATIC, CONST, STATIC_CONST
    };

#pragma REFLECTION_ATTRIBUTE
    enum class TypeCategory
    {
        BOOL, NUMBER, CEIL_NUMBER, VECTOR, LIST, MAP, SET, ARRAY, STRING, REFLECTION, SMART_POINTER
    };

#pragma REFLECTION_ATTRIBUTE
    enum class AccessMethod
    {
        OBJECT, POINTER, SMART_POINTER
    };
}