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