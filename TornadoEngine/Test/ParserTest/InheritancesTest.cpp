#include "gtest/gtest.h"

#include "FileParser.h"

TEST(Parser, Inheritance)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("Inheritance.h");

    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 2);
    auto hasParent = false;
    for (auto& type : res->mTypeList) {
        if (type->mName == "TChild") {
            ASSERT_TRUE(type->mInheritanceVec.size() == 1);

            if (type->mInheritanceVec[0].mShortTypeName == "TParent") {
                hasParent = true;
            }
        }

    }
    ASSERT_TRUE(hasParent);
}