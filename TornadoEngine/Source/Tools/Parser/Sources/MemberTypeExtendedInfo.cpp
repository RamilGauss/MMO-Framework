/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MemberTypeExtendedInfo.h"
#include "fmt/core.h"
#include "magic_enum.hpp"

using namespace nsCppParser;

bool TMemberTypeExtendedInfo::IsContainer()
{
    return mCategory == Vector ||
        mCategory == List ||
        mCategory == Set ||
        mCategory == Map;
}
//---------------------------------------------------------------------------------
std::string TMemberTypeExtendedInfo::GetCollectSubType()
{
    switch ( mCategory ) {
        case Reflection:
            return GetTypeNameWithNameSpaceReflection();
        case BuiltIn:
        case String:
            return GetTypeNameWithNameSpace();
        case List:
        case Vector:
        case Set:
        {
            auto key = mTemplateChildArr[0].GetCollectSubType();
            return fmt::format("{}<{}>", GetTypeNameWithNameSpace(), key);
        }
        case Map:
        {
            auto key = mTemplateChildArr[0].GetCollectSubType();
            auto value = mTemplateChildArr[1].GetCollectSubType();
            return fmt::format("{}<{},{}>", GetTypeNameWithNameSpace(), key, value);
        }
    }
    return "";
}
//---------------------------------------------------------------------------------
std::string TMemberTypeExtendedInfo::GetTypeNameWithNameSpace()
{
    if ( mNameSpaceForReflection.length() > 0 )
        return mNameSpaceForReflection + "::" + mType;
    return mType;
}
//---------------------------------------------------------------------------------
std::string TMemberTypeExtendedInfo::GetTypeNameWithNameSpaceReflection()
{
    switch ( mAccessMethod ) {
        case Object:
            return GetTypeNameWithNameSpace();
        case Pointer:
            return fmt::format("{}*", GetTypeNameWithNameSpace());
        case SmartPointer:
            return fmt::format("std::{}<{}>", mSmartPtrType, GetTypeNameWithNameSpace());
    }
    return "";
}
//---------------------------------------------------------------------------------
std::string TMemberTypeExtendedInfo::GetAccessOperator()
{
    switch ( mAccessMethod ) {
        case Object:
            return ".";
        case Pointer:
        case SmartPointer:
            return "->";
    }
    return "";
}
//---------------------------------------------------------------------------------
bool TMemberTypeExtendedInfo::IsBool()
{
    return mType == "bool";
}
//---------------------------------------------------------------------------------
bool TMemberTypeExtendedInfo::IsFloatingPoint()
{
    return mType == "double" || mType == "float";
}
//---------------------------------------------------------------------------------