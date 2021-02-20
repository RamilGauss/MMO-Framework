#include "gtest/gtest.h"

#include "FileParser.h"

TEST(Parser, ClassDeclaration)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("ClassDeclaration.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 0);
}
