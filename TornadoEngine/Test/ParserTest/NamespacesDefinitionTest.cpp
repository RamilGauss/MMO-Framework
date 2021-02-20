#include "gtest/gtest.h"

#include "FileParser.h"

TEST(Parser, NamespaceDefinition)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("NamespaceDefinition.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 2);
    for (auto& type : res->mTypeList) {
        auto has0 = (type->GetTypeNameWithNameSpace() == "Namespace0::A");
        auto has1 = (type->GetTypeNameWithNameSpace() == "Namespace0::B");

        ASSERT_TRUE(has0 || has1);
    }
}

