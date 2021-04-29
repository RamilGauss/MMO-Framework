/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

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

TEST(Parser, MemberWithComments)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("MemberWithComments.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);

    for (auto& type : res->mTypeList) {
        ASSERT_EQ(type->mName, "X");
        if (type->mName == "X") {
            ASSERT_TRUE(type->mMembers.size(), 3);

            auto& publicMembers = type->mMembers[(int) nsCppParser::AccessLevel::PUBLIC];
            ASSERT_EQ(publicMembers.size(), 2);
            auto& protectedMembers = type->mMembers[(int) nsCppParser::AccessLevel::PROTECTED];
            ASSERT_EQ(protectedMembers.size(), 0);
            auto& privateMembers = type->mMembers[(int) nsCppParser::AccessLevel::PRIVATE];
            ASSERT_EQ(privateMembers.size(), 0);

            auto& _0 = publicMembers[0];

            ASSERT_EQ(_0->mName, "x");

            ASSERT_EQ(_0->mTypeName, "unsigned int");
            ASSERT_EQ(_0->mExtendedInfo.GetTypeNameWithNameSpace(), "unsigned int");

            auto& _1 = publicMembers[1];

            ASSERT_EQ(_1->mName, "y");
            ASSERT_EQ(_1->mTypeName, "int");
            ASSERT_EQ(_1->mExtendedInfo.GetTypeNameWithNameSpace(), "int");
        }
    }
}

namespace nsTest
{
    struct Type
    {
        std::string name;
        std::string type;
    };
}

TEST(Parser, MemberBuilyInTypes)
{
    std::vector<nsTest::Type> ethalon = {
        {"b",  "bool"},
        {"c",  "char"},
        {"uc", "unsigned char"},
        {"s",  "short"},

        {"us",  "unsigned short"},
        {"i",  "int"},
        {"ui", "unsigned int"},
        {"l",  "long"},
        {"ul",  "unsigned long"},

        {"ll",  "long long"},
        {"ull", "unsigned long long"},
        {"f",  "float"},
        {"d",  "double"},

        {"i8", "int8_t"},
        {"ui8", "uint8_t"},
        {"i16", "int16_t"},
        {"ui16", "uint16_t"},
        {"i32", "int32_t"},
        {"ui32", "uint32_t"},
        {"i64", "int64_t"},
        {"ui64", "uint64_t"},
    };

    TFileParser fileParser;
    auto res = fileParser.Parse("MemberBuiltInTypes.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);

    for (auto& type : res->mTypeList) {
        ASSERT_EQ(type->mName, "X");
        if (type->mName == "X") {
            ASSERT_TRUE(type->mMembers.size(), 3);

            auto& publicMembers = type->mMembers[(int) nsCppParser::AccessLevel::PUBLIC];
            ASSERT_EQ(publicMembers.size(), 21);
            auto& protectedMembers = type->mMembers[(int) nsCppParser::AccessLevel::PROTECTED];
            ASSERT_EQ(protectedMembers.size(), 0);
            auto& privateMembers = type->mMembers[(int) nsCppParser::AccessLevel::PRIVATE];
            ASSERT_EQ(privateMembers.size(), 0);

            int index = 0;
            for (auto& t : publicMembers) {
                ASSERT_EQ(t->mName, ethalon[index].name);
                ASSERT_EQ(t->mTypeName, ethalon[index].type);
                ASSERT_EQ(t->mExtendedInfo.GetTypeNameWithNameSpace(), ethalon[index].type);

                index++;
            }
        }
    }
}