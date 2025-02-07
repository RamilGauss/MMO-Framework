/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "FileParser.h"

std::string pragmas = R"(
#pragma once

#pragma "text 0"
#pragma "text 1"
class ClassPragma
{
};

#pragma struct 
#pragma class 
#pragma enum 
#pragma enum class 
#pragma x y z 
struct StructPragma
{
};
)";

std::string pragmaPack = R"(
#pragma once

namespace X
{
    class Y
    {
#pragma pack(push, 1)
        struct Z
        {
            int a = 0;
        };
#pragma pack(pop)
    };
}
)";

TEST(Parser, Pragmas)
{
    TFileParser fileParser;
    auto res = fileParser.Parse(std::move(pragmas), "Pragmas.h");

    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 2);

    auto typeIt = res->mTypeList.begin();

    {
        ASSERT_EQ(typeIt->get()->mName, "ClassPragma");
        auto& pragmaSet = typeIt->get()->mPragmaTextSet;
        std::set<std::string> ethalon = {"once", "\"text 1\"", "\"text 0\""};
        ASSERT_EQ(ethalon, pragmaSet);
    }

    typeIt++;

    {
        ASSERT_EQ(typeIt->get()->mName, "StructPragma");
        auto& pragmaSet = typeIt->get()->mPragmaTextSet;
        std::set<std::string> ethalon = {"struct", "class", "enum", "enum class", "x y z"};
        ASSERT_EQ(ethalon, pragmaSet);
    }
}

TEST(Parser, PragmaPack)
{
    TFileParser fileParser;
    auto res = fileParser.Parse(std::move(pragmaPack), "PragmaPack.h");

    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 2);

    auto typeIt = res->mTypeList.begin();

    {
        ASSERT_EQ(typeIt->get()->mName, "Y");
        auto& pragmaSet = typeIt->get()->mPragmaTextSet;
        std::set<std::string> ethalon;
        ASSERT_EQ(pragmaSet.size(), 0);
    }

    typeIt++;

    {
        ASSERT_EQ(typeIt->get()->mName, "Z");
        auto& pragmaSet = typeIt->get()->mPragmaTextSet;
        std::set<std::string> ethalon = {"pack(push, 1)"};
        ASSERT_EQ(ethalon, pragmaSet);
    }
}