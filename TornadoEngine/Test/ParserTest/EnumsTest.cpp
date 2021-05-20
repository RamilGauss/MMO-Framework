/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "FileParser.h"

TEST(Parser, Enum_0)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("Enum_0.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 2);

    for (auto& type : res->mTypeList) {
        if (type->mName == "Enum_0") {
            ASSERT_EQ(type->mType, nsCppParser::DeclarationType::ENUM);

            std::set<std::string> ethalon = {"X", "Y", "Z"};
            ASSERT_EQ(type->mEnumKeys, ethalon);
        }
    }
}

TEST(Parser, Enum_1)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("Enum_1.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 2);

    for (auto& type : res->mTypeList) {
        if (type->mName == "Enum_1") {
            ASSERT_EQ(type->mType, nsCppParser::DeclarationType::ENUM);

            std::set<std::string> ethalon = {"A", "B", "C", "D"};
            ASSERT_EQ(type->mEnumKeys, ethalon);
        }
    }
}

TEST(Parser, Enum_2)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("Enum_2.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);

    for (auto& type : res->mTypeList) {
        if (type->mName == "Enum_2") {
            ASSERT_EQ(type->mType, nsCppParser::DeclarationType::ENUM);

            std::set<std::string> ethalon = {"F"};
            ASSERT_EQ(type->mEnumKeys, ethalon);
        }
    }
}

TEST(Parser, EnumPragma)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("Enum_3.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);

    for (auto& type : res->mTypeList) {
        if (type->mName == "Enum_3") {
            ASSERT_EQ(type->mType, nsCppParser::DeclarationType::ENUM);

            std::set<std::string> ethalon = {"once", "X"};
            ASSERT_EQ(type->mPragmaTextSet, ethalon);
        }
    }
}

TEST(Parser, EnumInNamespace)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("EnumInNamespace.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 2);

    for (auto& type : res->mTypeList) {
        if (type->mName == "A0") {
            ASSERT_EQ(type->mType, nsCppParser::DeclarationType::ENUM);

            ASSERT_EQ(type->GetTypeNameWithNameSpace(), "nsEnumSpace::A0");
        }
        if (type->mName == "A1") {
            ASSERT_EQ(type->mType, nsCppParser::DeclarationType::ENUM);
            ASSERT_EQ(type->GetTypeNameWithNameSpace(), "nsEnumSpace::A1");
        }
    }
}