/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "FileParser.h"

TEST(Parser, FunctionMember)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("FunctionMember.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);

    for (auto& type : res->mTypeList) {
        ASSERT_EQ(type->mName, "FunctionMember");
        if (type->mName == "FunctionMember") {
            ASSERT_TRUE(type->mMembers.size(), 3);

            auto& publicMembers = type->mMembers[(int) nsCppParser::AccessLevel::PUBLIC];
            ASSERT_EQ(publicMembers.size(), 3);
            auto& protectedMembers = type->mMembers[(int) nsCppParser::AccessLevel::PROTECTED];
            ASSERT_EQ(protectedMembers.size(), 0);
            auto& privateMembers = type->mMembers[(int) nsCppParser::AccessLevel::PRIVATE];
            ASSERT_EQ(privateMembers.size(), 0);

            auto member = publicMembers[0];
            ASSERT_EQ(member->mName, "func0");
            ASSERT_EQ(member->mTypeName, "std::function<void(int x)>");

            member = publicMembers[1];
            ASSERT_EQ(member->mName, "func1");
            ASSERT_EQ(member->mTypeName, "std::function<void(std::function<void(int x)> y, bool f)>");

            member = publicMembers[2];
            ASSERT_EQ(member->mName, "func2");
            ASSERT_EQ(member->mTypeName, "std::function<const void* (nsECSFramework::TEntityManager* pEntMng, nsECSFramework::TEntityID eid)>");
        }
    }
}