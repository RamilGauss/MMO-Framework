#include "gtest/gtest.h"

#include "FileParser.h"

TEST(Parser, Members)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("Members.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);

    for (auto& type : res->mTypeList) {
        ASSERT_EQ(type->mName, "A");
        if (type->mName == "A") {
            ASSERT_TRUE(type->mMembers.size(), 3);

            auto& publicMembers = type->mMembers[(int) nsCppParser::AccessLevel::PUBLIC];
            ASSERT_EQ(publicMembers.size(), 1);
            auto& protectedMembers = type->mMembers[(int) nsCppParser::AccessLevel::PROTECTED];
            ASSERT_EQ(protectedMembers.size(), 1);
            auto& privateMembers = type->mMembers[(int) nsCppParser::AccessLevel::PRIVATE];
            ASSERT_EQ(privateMembers.size(), 1);

            ASSERT_EQ(publicMembers[0]->mName, "pub");
            ASSERT_EQ(protectedMembers[0]->mName, "pro");
            ASSERT_EQ(privateMembers[0]->mName, "pri");
        }

    }
}

TEST(Parser, MembersExtended)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("MembersWithExtended.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);


    for (auto& type : res->mTypeList) {
        ASSERT_EQ(type->mName, "MWE");
        if (type->mName == "MWE") {
            ASSERT_TRUE(type->mMembers.size(), 3);

            auto& publicMembers = type->mMembers[(int) nsCppParser::AccessLevel::PUBLIC];
            ASSERT_EQ(publicMembers.size(), 3);
            auto& protectedMembers = type->mMembers[(int) nsCppParser::AccessLevel::PROTECTED];
            ASSERT_EQ(protectedMembers.size(), 0);
            auto& privateMembers = type->mMembers[(int) nsCppParser::AccessLevel::PRIVATE];
            ASSERT_EQ(privateMembers.size(), 0);

            auto& _0 = publicMembers[0];
            auto& _1 = publicMembers[1];
            auto& _2 = publicMembers[2];
            ASSERT_EQ(_0->mName, "str");

            ASSERT_EQ(_1->mName, "sp_str");

            ASSERT_EQ(_2->mName, "p");
        }
    }
}

TEST(Parser, MemberCategory)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("MemberCategory.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);


    for (auto& type : res->mTypeList) {
        ASSERT_EQ(type->mName, "MemberCategory");
        if (type->mName == "MemberCategory") {
            ASSERT_TRUE(type->mMembers.size(), 3);

            auto& publicMembers = type->mMembers[(int) nsCppParser::AccessLevel::PUBLIC];
            ASSERT_EQ(publicMembers.size(), 5);
            auto& protectedMembers = type->mMembers[(int) nsCppParser::AccessLevel::PROTECTED];
            ASSERT_EQ(protectedMembers.size(), 0);
            auto& privateMembers = type->mMembers[(int) nsCppParser::AccessLevel::PRIVATE];
            ASSERT_EQ(privateMembers.size(), 0);

            auto& _0 = publicMembers[0];
            auto& _1 = publicMembers[1];
            auto& _2 = publicMembers[2];
            auto& _3 = publicMembers[3];
            auto& _4 = publicMembers[4];
            ASSERT_EQ(_0->mName, "ms");
            ASSERT_EQ(_1->mName, "x");
            ASSERT_EQ(_2->mName, "y");
            ASSERT_EQ(_3->mName, "z");
            ASSERT_EQ(_4->mName, "m");

            ASSERT_EQ(_0->mCategory, nsCppParser::VariableCategory::NONE);
            ASSERT_EQ(_1->mCategory, nsCppParser::VariableCategory::STATIC);
            ASSERT_EQ(_2->mCategory, nsCppParser::VariableCategory::STATIC_CONST);
            ASSERT_EQ(_3->mCategory, nsCppParser::VariableCategory::CONST);
            ASSERT_EQ(_4->mCategory, nsCppParser::VariableCategory::MUTABLE);
        }
    }
}

TEST(Parser, MemberPragma)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("MemberPragma.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);


    for (auto& type : res->mTypeList) {
        ASSERT_EQ(type->mName, "MemberPragma");
        if (type->mName == "MemberPragma") {
            ASSERT_TRUE(type->mMembers.size(), 3);

            auto& publicMembers = type->mMembers[(int) nsCppParser::AccessLevel::PUBLIC];
            ASSERT_EQ(publicMembers.size(), 1);
            auto& protectedMembers = type->mMembers[(int) nsCppParser::AccessLevel::PROTECTED];
            ASSERT_EQ(protectedMembers.size(), 0);
            auto& privateMembers = type->mMembers[(int) nsCppParser::AccessLevel::PRIVATE];
            ASSERT_EQ(privateMembers.size(), 0);

            auto& _0 = publicMembers[0];

            ASSERT_EQ(_0->mName, "x");

            std::set<std::string> ethalon = {"\"x\"", "x"};
            ASSERT_EQ(_0->mPragmaTextSet, ethalon);

        }
    }
}
