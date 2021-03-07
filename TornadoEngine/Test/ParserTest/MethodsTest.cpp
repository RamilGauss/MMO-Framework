#include "gtest/gtest.h"

#include "FileParser.h"

TEST(Parser, MethodNames)
{
    TFileParser fileParser;
    auto res = fileParser.Parse("MethodNames.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);

    for (auto& type : res->mTypeList) {
        ASSERT_EQ(type->mName, "MethodNames");
        if (type->mName == "MethodNames") {
            ASSERT_TRUE(type->mMethods.size(), 3);

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
    auto res = fileParser.Parse("MethodCategory.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 2);

    for (auto& type : res->mTypeList) {
        if (type->mName == "MethodCategory") {
            ASSERT_TRUE(type->mMethods.size(), 3);

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
    auto res = fileParser.Parse("MethodCategory.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 2);

    for (auto& type : res->mTypeList) {
        if (type->mName == "BaseMethodCategory") {
            ASSERT_TRUE(type->mMethods.size(), 3);

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
    auto res = fileParser.Parse("MethodPragma.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);

    for (auto& type : res->mTypeList) {
        ASSERT_EQ(type->mName, "MethodPragma");
        if (type->mName == "MethodPragma") {
            ASSERT_TRUE(type->mMethods.size(), 3);

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