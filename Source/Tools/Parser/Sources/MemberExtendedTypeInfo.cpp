/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MemberExtendedTypeInfo.h"
#include "fmt/core.h"
#include <magic_enum/magic_enum.hpp>

using namespace nsCppParser;

void TMemberExtendedTypeInfo::Reset()
{
    mAccessMethod = AccessMethod::OBJECT;
    mTemplateChildArr.clear();

    mShortType = "";
    mLongType = "";
    mNameSpace = "";
    mSmartPtrType = "";
}
//---------------------------------------------------------------------------------
bool TMemberExtendedTypeInfo::IsContainer()
{
    return mCategory == TypeCategory::VECTOR ||
        mCategory == TypeCategory::LIST ||
        mCategory == TypeCategory::SET ||
        mCategory == TypeCategory::MAP ||
        mCategory == TypeCategory::ARRAY;
}
//---------------------------------------------------------------------------------
std::string TMemberExtendedTypeInfo::GetCollectSubType()
{
    switch (mCategory) {
        case TypeCategory::REFLECTION:
            return GetTypeNameWithNameSpaceReflection();
        case TypeCategory::BOOL:
        case TypeCategory::NUMBER:
        case TypeCategory::CEIL_NUMBER:
        case TypeCategory::STRING:
            return GetTypeNameWithNameSpace();
        case TypeCategory::LIST:
        case TypeCategory::VECTOR:
        case TypeCategory::SET:
            {
                auto key = mTemplateChildArr[0].GetCollectSubType();
                return fmt::format("{}<{}>", GetTypeNameWithNameSpace(), key);
            }
        case TypeCategory::MAP:
            {
                auto key = mTemplateChildArr[0].GetCollectSubType();
                auto value = mTemplateChildArr[1].GetCollectSubType();
                return fmt::format("{}<{},{}>", GetTypeNameWithNameSpace(), key, value);
            }
    }
    return "";
}
//---------------------------------------------------------------------------------
std::string TMemberExtendedTypeInfo::GetTypeNameWithNameSpaceReflection()
{
    switch (mAccessMethod) {
        case AccessMethod::OBJECT:
            return GetTypeNameWithNameSpace();
        case AccessMethod::POINTER:
            return fmt::format("{}*", GetTypeNameWithNameSpace());
        case AccessMethod::SMART_POINTER:
            return fmt::format("{}<{}>", mSmartPtrType, GetTypeNameWithNameSpace());
    }
    return "";
}
//---------------------------------------------------------------------------------
std::string TMemberExtendedTypeInfo::GetAccessOperator()
{
    switch (mAccessMethod) {
        case AccessMethod::OBJECT:
            return ".";
        case AccessMethod::POINTER:
        case AccessMethod::SMART_POINTER:
            return "->";
    }
    return "";
}
//---------------------------------------------------------------------------------
std::string TMemberExtendedTypeInfo::GetTypeNameWithNameSpace()
{
    return mLongType;
}
//---------------------------------------------------------------------------------