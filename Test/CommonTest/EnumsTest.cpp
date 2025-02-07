/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "FileParser.h"

std::string enum_0 = R"(
#pragma once

class X
{
public:
    enum class Enum_0
    {
        // asdasd
        X = 42, Y = 0x0F, Z
    };
};
)";

std::string enum_1 = R"(
#pragma once

class X
{
public:
    enum Enum_1
    {
        A, B = -1, C = 100, D
    };
};
)";

std::string enum_2 = R"(
#pragma once

enum class Enum_2
{
    F
};
)";

std::string enum_3 = R"(
#pragma once

#pragma X
enum class Enum_3
{
    F
};
)";

std::string emptyEnum = R"(
#pragma once

namespace nsEmptyEnum
{
    enum
    {
        X = 42
    };
};
)";

std::string enumInNamespace = R"(
#pragma once

namespace nsEnumSpace
{
    enum class A0
    {
        X = 42, Y = 0x0F, Z
    };
    enum class A1
    {
        X = 42, Y = 0x0F, Z
    };
}
)";

TEST(Parser, Enum_0)
{
    TFileParser fileParser;
    auto res = fileParser.Parse(std::move(enum_0), "Enum_0.h");
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
    auto res = fileParser.Parse(std::move(enum_1), "Enum_1.h");
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
    auto res = fileParser.Parse(std::move(enum_2), "Enum_2.h");
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
    auto res = fileParser.Parse(std::move(enum_3), "Enum_3.h");
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
    auto res = fileParser.Parse(std::move(enumInNamespace), "EnumInNamespace.h");
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

TEST(Parser, EmptyEnum)
{
    TFileParser fileParser;
    auto res = fileParser.Parse(std::move(emptyEnum), "EmptyEnum.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 0);
}