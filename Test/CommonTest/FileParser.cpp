/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FileParser.h"

const nsCppParser::TParserResultContainer* TFileParser::Parse(std::string&& content, std::string&& fileName)
{
    try {
        mParser.Parse(content, fileName);
        return mParser.GetResult();
    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return nullptr;
}
