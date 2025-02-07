/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "FileParser.h"

std::string usingContent = R"(
#pragma once

class Using
{
    using x = int;
};
)";

TEST(Parser, Using)
{
    TFileParser fileParser;
    auto res = fileParser.Parse(std::move(usingContent), "Using.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);

    for (auto& type : res->mTypeList) {
        ASSERT_EQ(type->mName, "Using");
        ASSERT_TRUE(type->mMembers.size(), 3);

        auto& publicMembers = type->mMembers[(int) nsCppParser::AccessLevel::PUBLIC];
        ASSERT_EQ(publicMembers.size(), 0);
        auto& protectedMembers = type->mMembers[(int) nsCppParser::AccessLevel::PROTECTED];
        ASSERT_EQ(protectedMembers.size(), 0);
        auto& privateMembers = type->mMembers[(int) nsCppParser::AccessLevel::PRIVATE];
        ASSERT_EQ(privateMembers.size(), 0);
    }
}