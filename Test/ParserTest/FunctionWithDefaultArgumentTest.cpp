/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "FileParser.h"

TEST(Parser, FunctionWithDefaultArgument)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("FunctionWithDefaultArgument.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);

    for (auto& type : res->mTypeList) {
        ASSERT_EQ(type->mName, "FunctionWithDefaultArgument");
        if (type->mName == "FunctionWithDefaultArgument") {
            ASSERT_TRUE(type->mMethods.size(), 3);

            auto& publicMethods = type->mMethods[(int) nsCppParser::AccessLevel::PUBLIC];
            ASSERT_EQ(publicMethods.size(), 1);
            auto& protectedMethods = type->mMethods[(int) nsCppParser::AccessLevel::PROTECTED];
            ASSERT_EQ(protectedMethods.size(), 0);
            auto& privateMethods = type->mMethods[(int) nsCppParser::AccessLevel::PRIVATE];
            ASSERT_EQ(privateMethods.size(), 0);

            auto method = publicMethods[0];
            ASSERT_EQ(method->mName, "Func");
            ASSERT_EQ(method->mCategory, nsCppParser::MethodCategoryType::OVERRIDE);
        }
    }
}