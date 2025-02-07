/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "FileParser.h"

std::string templateClass = R"(
#pragma once

template <typename T>
class A
{

};

class B : public A<int>
{

};

class C
{
public: 
    A<int> a;
};
)";

std::string templateArgsInClass = R"(
#pragma once

template <typename T>
class Typed
{

};

template <int N>
class Numbered
{

};

template <typename T0, typename T1, typename T2>
class Args
{

};
)";

TEST(Parser, TemplateClass)
{
    TFileParser fileParser;
    auto res = fileParser.Parse(std::move(templateClass), "TemplateClass.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 3);

    bool hasA = false;
    bool hasB = false;
    bool hasC = false;

    for (auto& type : res->mTypeList) {
        if (type->mName == "A") {
            hasA = true;

            ASSERT_EQ(type->mTemplateArgs.size(), 1);
            ASSERT_EQ(type->mTemplateArgs[0], "typename T");
        }
        if (type->mName == "B") {
            hasB = true;
        }
        if (type->mName == "C") {
            hasC = true;

            auto& publicMembers = type->mMembers[(int)nsCppParser::AccessLevel::PUBLIC];
            ASSERT_EQ(publicMembers.size(), 1);

            ASSERT_EQ(publicMembers[0]->mTypeName, "A<int>");
            ASSERT_EQ(publicMembers[0]->mName, "a");
        }

        ASSERT_EQ(type->mType, nsCppParser::DeclarationType::CLASS);
    }

    ASSERT_TRUE(hasA);
    ASSERT_TRUE(hasB);
    ASSERT_TRUE(hasC);
}

TEST(Parser, TemplateArgsInClass)
{
    TFileParser fileParser;
    auto res = fileParser.Parse(std::move(templateArgsInClass), "TemplateArgsInClass.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 3);

    bool hasTyped = false;
    bool hasNumbered = false;
    bool hasArgs = false;

    for (auto& type : res->mTypeList) {
        if (type->mName == "Typed") {
            hasTyped = true;

            ASSERT_EQ(type->mTemplateArgs.size(), 1);
            ASSERT_EQ(type->mTemplateArgs[0], "typename T");
        }
        if (type->mName == "Numbered") {
            hasNumbered = true;

            ASSERT_EQ(type->mTemplateArgs.size(), 1);
            ASSERT_EQ(type->mTemplateArgs[0], "int N");
        }
        if (type->mName == "Args") {
            hasArgs = true;

            ASSERT_EQ(type->mTemplateArgs.size(), 3);
            ASSERT_EQ(type->mTemplateArgs[0], "typename T0");
            ASSERT_EQ(type->mTemplateArgs[1], "typename T1");
            ASSERT_EQ(type->mTemplateArgs[2], "typename T2");
        }

        ASSERT_EQ(type->mType, nsCppParser::DeclarationType::CLASS);
    }

    ASSERT_TRUE(hasTyped);
    ASSERT_TRUE(hasNumbered);
    ASSERT_TRUE(hasArgs);
}