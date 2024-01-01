/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <iostream>

#include "Base/Common/LoadFromFile.h"
#include "Parser/Sources/Parser.h"

class TFileParser
{
    nsCppParser::TParser g_Parser;
    TLoadFromFile g_loader;
public:
    const nsCppParser::TParserResultContainer* Parse(const char* path);
};

