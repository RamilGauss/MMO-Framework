#include "gtest/gtest.h"

#include "FileParser.h"


TEST(Parser, Pragmas)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("Pragmas.h");

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
    auto res = fileParser.Parse("PragmaPack.h");

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