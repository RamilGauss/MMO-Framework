/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "FileParser.h"

const nsCppParser::TParserResultContainer* TFileParser::Parse(const char* path)
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