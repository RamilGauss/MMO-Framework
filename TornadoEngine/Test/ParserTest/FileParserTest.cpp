#include "gtest/gtest.h"

#include "FileParser.h"

TEST(Parser, PassMustBeFails)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("this file is not existed.h");

    ASSERT_EQ(res, nullptr);
}