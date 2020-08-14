/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include <string>

struct TMemberTypeExtendedInfo
{
    enum TypeCategory
    {
        BuiltIn,
        Vector, List, Set, Map,// containers
        String,
        Reflection
    };
    TypeCategory mCategory;

    enum AccessMethod
    {
        Object,
        Pointer,
        SmartPointer// std::auto_ptr, std::shared_ptr, std::weak_ptr, std::unique
    };
    AccessMethod mAccessMethod = AccessMethod::Object;

    std::vector<TMemberTypeExtendedInfo> mTemplateChildArr;

    std::string mType;// builtIn, reflection, std

    std::string mNameSpaceForReflection;// example: MySpace

    std::string mSmartPtrType;

public:
    bool IsContainer();

    std::string GetCollectSubType();
    std::string GetTypeNameWithNameSpace();
    std::string GetTypeNameWithNameSpaceReflection();

    std::string GetAccessOperator();
private:
};
