/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "FileParser.h"

std::string mutableMembers = R"(
#pragma once

class A
{
public:
    mutable int pub;
protected:
    mutable int pro;
private:
    mutable int pri = 0;
};

struct B
{
public:
    mutable int pub;
protected:
    mutable int pro;
private:
    mutable int pri = 0;
};
)";

TEST(Parser, MutableMembers)
{
    TFileParser fileParser;
    auto res = fileParser.Parse(std::move(mutableMembers), "MutableMembers.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 2);

    bool hasA = false;
    bool hasB = false;

    for (auto& type : res->mTypeList) {
        if (type->mName == "A") {
            hasA = true;
            ASSERT_EQ(type->mType, nsCppParser::DeclarationType::CLASS);
        }
        if (type->mName == "B") {
            hasB = true;
            ASSERT_EQ(type->mType, nsCppParser::DeclarationType::STRUCT);
        }
        ASSERT_EQ(type->mMembers.size(), 3);

        auto& publicMembers = type->mMembers[(int)nsCppParser::AccessLevel::PUBLIC];
        ASSERT_EQ(publicMembers.size(), 1);
        auto& protectedMembers = type->mMembers[(int)nsCppParser::AccessLevel::PROTECTED];
        ASSERT_EQ(protectedMembers.size(), 1);
        auto& privateMembers = type->mMembers[(int)nsCppParser::AccessLevel::PRIVATE];
        ASSERT_EQ(privateMembers.size(), 1);

        ASSERT_EQ(publicMembers[0]->mName, "pub");
        ASSERT_EQ(protectedMembers[0]->mName, "pro");
        ASSERT_EQ(privateMembers[0]->mName, "pri");

        ASSERT_EQ(publicMembers[0]->mCategory, nsCppParser::VariableCategory::MUTABLE);
        ASSERT_EQ(protectedMembers[0]->mCategory, nsCppParser::VariableCategory::MUTABLE);
        ASSERT_EQ(privateMembers[0]->mCategory, nsCppParser::VariableCategory::MUTABLE);
    }

    ASSERT_TRUE(hasA);
    ASSERT_TRUE(hasB);
}
