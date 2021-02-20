#pragma once

#include <iostream>

#include "LoadFromFile.h"
#include "Parser/Sources/Parser.h"

class TFileParser
{
    nsCppParser::TParser g_Parser;
    TLoadFromFile g_loader;
public:
    const nsCppParser::TParserResultContainer* Parse(const char* path);
};

