#include "gtest/gtest.h"

#include "FileParser.h"

TEST(Parser, TypeDefInClass)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("TypeDefInClass.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);

    for (auto& type : res->mTypeList) {
        ASSERT_EQ(type->mName, "TypeDefInClass");
        ASSERT_TRUE(type->mMembers.size(), 3);

        auto& publicMembers = type->mMembers[(int) nsCppParser::AccessLevel::PUBLIC];
        ASSERT_EQ(publicMembers.size(), 0);
        auto& protectedMembers = type->mMembers[(int) nsCppParser::AccessLevel::PROTECTED];
        ASSERT_EQ(protectedMembers.size(), 0);
        auto& privateMembers = type->mMembers[(int) nsCppParser::AccessLevel::PRIVATE];
        ASSERT_EQ(privateMembers.size(), 0);
    }
}