/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "FileParser.h"

std::string methodNames = R"(
#pragma once

class MethodNames
{
    void Pri();
protected:
    void Pro();
public:
    void Pub();
};
)";

std::string methodCategory = R"(
#pragma once

class BaseMethodCategory
{
public:
    virtual void Override() const = 0;

    virtual void Final() const {}
};

class MethodCategory : public BaseMethodCategory
{
public:
    static void Static() {}
    
    virtual void Virtual() {}

    virtual void VirtualPure() const = 0;

    void Override() const override {}

    void Final() const override final {}

    template<typename T>
    void Template() const {}

    bool operator == (const MethodCategory& other) const { return false; }
};
)";

std::string methodPragma = R"(
#pragma once

class MethodPragma
{
#pragma PRI
    void Pri();
protected:
#pragma PRO
    void Pro();
public:
#pragma PUB
    void Pub();
};
)";

std::string sizeOfInMethod = R"(
#pragma once

namespace X
{
    class Y
    {
        void Foo();
    };
    void Y::Foo()
    {
        const int headerSize = sizeof(int);
    }
}
)";

std::string functionContent = R"(
#pragma once

class X
{
    void Foo()
    {
        int x = 0;
        if (x == 0) {
        }
        for (int i = 0; i < 2; i++) {
        }
        try {
        } catch (...) {
        }
        switch (x) {
            case 0:
                break;
        }
    }
};
)";

std::string virtualMethodOverride  = R"(
#pragma once

class Y
{
    virtual void Foo() {}
};

class X : Y
{
    virtual void Foo() override;
};
)";

TEST(Parser, MethodNames)
{
    TFileParser fileParser;
    auto res = fileParser.Parse(std::move(methodNames), "MethodNames.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);

    for (auto& type : res->mTypeList) {
        ASSERT_EQ(type->mName, "MethodNames");
        if (type->mName == "MethodNames") {
            ASSERT_EQ(type->mMethods.size(), 3);

            auto& publicMethods = type->mMethods[(int) nsCppParser::AccessLevel::PUBLIC];
            ASSERT_EQ(publicMethods.size(), 1);
            auto& protectedMethods = type->mMethods[(int) nsCppParser::AccessLevel::PROTECTED];
            ASSERT_EQ(protectedMethods.size(), 1);
            auto& privateMethods = type->mMethods[(int) nsCppParser::AccessLevel::PRIVATE];
            ASSERT_EQ(privateMethods.size(), 1);

            ASSERT_EQ(publicMethods[0]->mName, "Pub");
            ASSERT_EQ(protectedMethods[0]->mName, "Pro");
            ASSERT_EQ(privateMethods[0]->mName, "Pri");
        }
    }
}

TEST(Parser, MethodCategory)
{
    TFileParser fileParser;
    auto res = fileParser.Parse(std::move(methodCategory), "MethodCategory.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 2);

    for (auto& type : res->mTypeList) {
        if (type->mName == "MethodCategory") {
            ASSERT_EQ(type->mMethods.size(), 3);

            auto& publicMethods = type->mMethods[(int) nsCppParser::AccessLevel::PUBLIC];
            ASSERT_EQ(publicMethods.size(), 7);
            auto& protectedMethods = type->mMethods[(int) nsCppParser::AccessLevel::PROTECTED];
            ASSERT_EQ(protectedMethods.size(), 0);
            auto& privateMethods = type->mMethods[(int) nsCppParser::AccessLevel::PRIVATE];
            ASSERT_EQ(privateMethods.size(), 0);

            for (auto& methods : publicMethods) {
                if (methods->mName == "Static") {
                    ASSERT_EQ(methods->mCategory, nsCppParser::MethodCategoryType::STATIC);
                } else if (methods->mName == "Virtual") {
                    ASSERT_EQ(methods->mCategory, nsCppParser::MethodCategoryType::VIRTUAL);
                } else if (methods->mName == "VirtualPure") {
                    ASSERT_EQ(methods->mCategory, nsCppParser::MethodCategoryType::VIRTUAL_PURE);
                } else if (methods->mName == "Override") {
                    ASSERT_EQ(methods->mCategory, nsCppParser::MethodCategoryType::OVERRIDE);
                } else if (methods->mName == "Final") {
                    ASSERT_EQ(methods->mCategory, nsCppParser::MethodCategoryType::OVERRIDE_FINAL);
                } else if (methods->mName == "Template") {
                    ASSERT_EQ(methods->mCategory, nsCppParser::MethodCategoryType::TEMPLATE);
                } else if (methods->mName == "operator==") {
                    ASSERT_EQ(methods->mCategory, nsCppParser::MethodCategoryType::OPERATOR);
                } else {
                    ASSERT_TRUE(false);
                }
            }
        }
    }
}

TEST(Parser, MethodCategoryDtor)
{
    TFileParser fileParser;
    auto res = fileParser.Parse(std::move(methodCategory), "MethodCategory.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 2);

    for (auto& type : res->mTypeList) {
        if (type->mName == "BaseMethodCategory") {
            ASSERT_EQ(type->mMethods.size(), 3);

            auto& publicMethods = type->mMethods[(int) nsCppParser::AccessLevel::PUBLIC];
            ASSERT_EQ(publicMethods.size(), 2);
            auto& protectedMethods = type->mMethods[(int) nsCppParser::AccessLevel::PROTECTED];
            ASSERT_EQ(protectedMethods.size(), 0);
            auto& privateMethods = type->mMethods[(int) nsCppParser::AccessLevel::PRIVATE];
            ASSERT_EQ(privateMethods.size(), 0);

            for (auto& methods : publicMethods) {
                if (methods->mName == "Override") {
                    ASSERT_EQ(methods->mCategory, nsCppParser::MethodCategoryType::VIRTUAL_PURE);
                } else if (methods->mName == "Final") {
                    ASSERT_EQ(methods->mCategory, nsCppParser::MethodCategoryType::VIRTUAL);
                } else {
                    ASSERT_TRUE(false);
                }
            }
        }
    }
}

TEST(Parser, MethodPragma)
{
    TFileParser fileParser;
    auto res = fileParser.Parse(std::move(methodPragma), "MethodPragma.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);

    for (auto& type : res->mTypeList) {
        ASSERT_EQ(type->mName, "MethodPragma");
        if (type->mName == "MethodPragma") {
            ASSERT_EQ(type->mMethods.size(), 3);

            auto& publicMethods = type->mMethods[(int) nsCppParser::AccessLevel::PUBLIC];
            ASSERT_EQ(publicMethods.size(), 1);
            auto& protectedMethods = type->mMethods[(int) nsCppParser::AccessLevel::PROTECTED];
            ASSERT_EQ(protectedMethods.size(), 1);
            auto& privateMethods = type->mMethods[(int) nsCppParser::AccessLevel::PRIVATE];
            ASSERT_EQ(privateMethods.size(), 1);

            std::set<std::string> ethalon;
            if (privateMethods[0]->mName == "Pri") {
                ethalon = {"PRI"};
                ASSERT_EQ(privateMethods[0]->mPragmaTextSet, ethalon);
            }
            if (protectedMethods[0]->mName == "Pro") {
                ethalon = {"PRO"};
                ASSERT_EQ(protectedMethods[0]->mPragmaTextSet, ethalon);
            }
            if (publicMethods[0]->mName == "Pub") {
                ethalon = {"PUB"};
                ASSERT_EQ(publicMethods[0]->mPragmaTextSet, ethalon);
            }
        }
    }
}

TEST(Parser, SizeOfInMethod)
{
    TFileParser fileParser;
    auto res = fileParser.Parse(std::move(sizeOfInMethod), "SizeOfInMethod.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);

    auto type = res->mTypeList.begin();

    for (auto& type : res->mTypeList) {
        ASSERT_EQ(type->mName, "Y");
        if (type->mName == "Y") {
            ASSERT_EQ(type->mMethods.size(), 3);

            auto& publicMethods = type->mMethods[(int) nsCppParser::AccessLevel::PUBLIC];
            ASSERT_EQ(publicMethods.size(), 0);
            auto& protectedMethods = type->mMethods[(int) nsCppParser::AccessLevel::PROTECTED];
            ASSERT_EQ(protectedMethods.size(), 0);
            auto& privateMethods = type->mMethods[(int) nsCppParser::AccessLevel::PRIVATE];
            ASSERT_EQ(privateMethods.size(), 1);

            ASSERT_EQ(privateMethods[0]->mName, "Foo");
        }
    }
}

TEST(Parser, FunctionContent)
{
    TFileParser fileParser;
    auto res = fileParser.Parse(std::move(functionContent), "FunctionContent.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);

    auto type = res->mTypeList.begin();

    for (auto& type : res->mTypeList) {
        ASSERT_EQ(type->mName, "X");
        if (type->mName == "X") {
            ASSERT_EQ(type->mMethods.size(), 3);

            auto& publicMethods = type->mMethods[(int) nsCppParser::AccessLevel::PUBLIC];
            ASSERT_EQ(publicMethods.size(), 0);
            auto& protectedMethods = type->mMethods[(int) nsCppParser::AccessLevel::PROTECTED];
            ASSERT_EQ(protectedMethods.size(), 0);
            auto& privateMethods = type->mMethods[(int) nsCppParser::AccessLevel::PRIVATE];
            ASSERT_EQ(privateMethods.size(), 1);

            ASSERT_EQ(privateMethods[0]->mName, "Foo");
        }
    }
}

TEST(Parser, VirtualMethodOverride)
{
    TFileParser fileParser;
    auto res = fileParser.Parse(std::move(virtualMethodOverride), "VirtualMethodOverride.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 2);

    bool isPassed = false;

    for (auto& type : res->mTypeList) {
        if (type->mName == "X") {
            ASSERT_EQ(type->mMethods.size(), 3);

            auto& publicMethods = type->mMethods[(int) nsCppParser::AccessLevel::PUBLIC];
            ASSERT_EQ(publicMethods.size(), 0);
            auto& protectedMethods = type->mMethods[(int) nsCppParser::AccessLevel::PROTECTED];
            ASSERT_EQ(protectedMethods.size(), 0);
            auto& privateMethods = type->mMethods[(int) nsCppParser::AccessLevel::PRIVATE];
            ASSERT_EQ(privateMethods.size(), 1);

            ASSERT_EQ(privateMethods[0]->mName, "Foo");

            ASSERT_EQ(type->mMembers[(int) nsCppParser::AccessLevel::PUBLIC].size(), 0);
            ASSERT_EQ(type->mMembers[(int) nsCppParser::AccessLevel::PROTECTED].size(), 0);
            ASSERT_EQ(type->mMembers[(int) nsCppParser::AccessLevel::PRIVATE].size(), 0);

            isPassed = true;
        }
    }

    ASSERT_EQ(isPassed, true);
}