/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ConveyerFileParser.h"

#include "TextFile.h"
#include "GameEngineJsonSerializer.h"

using namespace nsGameEngine;

bool TConveyerFileParser::Parse(std::string& fileDescConveyer)
{
    std::string jsonContent;
    TTextFile::Load(fileDescConveyer, jsonContent);
    if (jsonContent.length() == 0) {
        strError = "No such file";
        return false;
    }
    std::string err;
    return TGameEngineJsonSerializer::Deserialize(&mConveyerConfig, jsonContent, err);
}
//---------------------------------------------------------------------------------------
std::string TConveyerFileParser::GetStrError()
{
    return strError;
}
//---------------------------------------------------------------------------------------
std::vector<std::string> TConveyerFileParser::GetResult()
{
    return mConveyerConfig.modules;
}
//---------------------------------------------------------------------------------------
