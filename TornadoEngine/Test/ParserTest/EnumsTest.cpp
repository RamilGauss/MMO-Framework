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

            std::map<std::string, int64_t> ethalon = {{"X", 42}, {"Y", 15}, {"Z", 16}};
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

            std::map<std::string, int64_t> ethalon = {{"A", 0}, {"B", -1}, {"C", 100}, {"D", 101}};
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

            std::map<std::string, int64_t> ethalon = {{"F", 0}};
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