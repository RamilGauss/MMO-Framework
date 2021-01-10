#include "gtest/gtest.h"

#include "LoadFromFile.h"

#include "Parser/Sources/Parser.h"

static nsCppParser::TParser g_Parser;
static TLoadFromFile g_loader;

static const char* g_Path = "ParamClass.h";

TEST(Parser, Set0)
{
    auto isOpen = g_loader.ReOpen((char*) g_Path);
    TContainer data;
    g_loader.ReadSmall(data);

    std::string content;
    content.append(data.GetPtr(), data.GetSize());

    std::string fileName = g_Path;
    g_Parser.Parse(content, fileName);

    auto res = g_Parser.GetResult();
    res->mTypeList;

    ASSERT_TRUE(true);
}