#include "gtest/gtest.h"

#include "LoadFromFile.h"

#include "Parser/Sources/Parser.h"

static nsCppParser::TParser g_Parser;
static TLoadFromFile g_loader;

const nsCppParser::TParserResultContainer* Parse(const char* path)
{
    try {
        auto isOpen = g_loader.ReOpen((char*) path);
        if (!isOpen) {
            return nullptr;
        }
        TContainer data;
        g_loader.ReadSmall(data);

        std::string content;
        content.append(data.GetPtr(), data.GetSize());

        std::string fileName = path;
        g_Parser.Parse(content, fileName);
        return g_Parser.GetResult();

    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return nullptr;
}

TEST(Parser, PassMustBeFails)
{
    auto res = Parse("this file is not existed");
    ASSERT_EQ(res, nullptr);
}

TEST(Parser, NamespaceDefinition)
{
    auto res = Parse("NamespaceDefinition.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 2);
    for (auto& type : res->mTypeList) {
        auto has0 = (type->GetTypeNameWithNameSpace() == "Namespace0::A");
        auto has1 = (type->GetTypeNameWithNameSpace() == "Namespace0::B");

        ASSERT_TRUE(has0 || has1);
    }
}

TEST(Parser, ClassDeclaration)
{
    auto res = Parse("ClassDeclaration.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 0);
}

TEST(Parser, Inheritance)
{
    auto res = Parse("Inheritance.h");
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

TEST(Parser, Pragmas)
{
    auto res = Parse("Pragmas.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 2);

    auto typeIt = res->mTypeList.begin();

    {
        ASSERT_EQ(typeIt->get()->mName, "ClassPragma");
        auto& pragmaSet = typeIt->get()->mPragmaTextSet;
        std::set<std::string> ethalon = {"once", "\"text 1\"", "\"text 0\""};
        ASSERT_EQ(ethalon, pragmaSet);
    }

    typeIt++;

    {
        ASSERT_EQ(typeIt->get()->mName, "StructPragma");
        auto& pragmaSet = typeIt->get()->mPragmaTextSet;
        std::set<std::string> ethalon = {"struct", "class", "enum", "enum class", "x y z"};
        ASSERT_EQ(ethalon, pragmaSet);
    }
}

TEST(Parser, Members)
{
    auto res = Parse("Members.h");
    ASSERT_NE(res, nullptr);

    ASSERT_EQ(res->mTypeList.size(), 1);

    for (auto& type : res->mTypeList) {
        if (type->mName == "A") {
            ASSERT_TRUE(type->mMembers.size(), 3);

            auto& publicMembers = type->mMembers[(int) nsCppParser::AccessLevel::PUBLIC];
            ASSERT_EQ(publicMembers.size(), 1);
            auto& protectedMembers = type->mMembers[(int) nsCppParser::AccessLevel::PROTECTED];
            ASSERT_EQ(protectedMembers.size(), 1);
            auto& privateMembers = type->mMembers[(int) nsCppParser::AccessLevel::PRIVATE];
            ASSERT_EQ(privateMembers.size(), 1);

            ASSERT_EQ(publicMembers[0]->mName, "pub");
            ASSERT_EQ(protectedMembers[0]->mName, "pro");
            ASSERT_EQ(privateMembers[0]->mName, "pri");
        }

    }
}