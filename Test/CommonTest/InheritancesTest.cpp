/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "FileParser.h"

std::string inheritance = R"(
#pragma once

namespace ParentNamespace
{
    class TParent {};
}

namespace Child
{
    class TChild : public ParentNamespace::TParent
    {
    };
}
)";

TEST(Parser, Inheritance)
{
    TFileParser fileParser;
    auto res = fileParser.Parse(std::move(inheritance), "Inheritance.h");

    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 2);
    auto hasParent = false;
    for (auto& type : res->mTypeList) {
        if (type->mName == "TChild") {
            ASSERT_TRUE(type->mInheritanceVec.size() == 1);

            if (type->mInheritanceVec[0].mShortTypeName == "TParent") {
                hasParent = true;
            }

            ASSERT_EQ(type->mInheritanceVec[0].mOriginalNameSpace, "ParentNamespace");
        }
    }
    ASSERT_TRUE(hasParent);
}