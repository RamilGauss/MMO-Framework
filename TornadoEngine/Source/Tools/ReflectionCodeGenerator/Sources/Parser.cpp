/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/
#include "Parser.h"
#include "Tokenizer.h"
#include "LoadFromFile.h"
#include "TokenInfoManager.h"
#include "ConfigContainer.h"
#include "FileLexer.h"


using namespace nsReflectionCodeGenerator;
namespace fs = std::filesystem;

void TParser::Work()
{
    auto config = SingletonManager()->Get<TConfigContainer>()->Config();

    // 1. Создать список файлов по папкам и с учетом расширений
    mFilePathForParseSet.clear();

    if ( auto configContainer = config->targetForParsing.recursive )
        CollectAbsPaths<fs::recursive_directory_iterator>();
    else
        CollectAbsPaths<fs::directory_iterator>();

    // 2.1. Прогнать через токенизатор
    Tokenize();
}
//--------------------------------------------------------------------------------------------------------
void TParser::Tokenize()
{
    auto tokenInfoMng = SingletonManager()->Get<TTokenInfoManager>();

    TTokenizer tokenizer;
    TLoadFromFile loader;
    for ( auto& absPath : mFilePathForParseSet )
    {
        if ( loader.ReOpen((char*)absPath.data()) == false ) {
            continue;
        }
        TContainer data;
        loader.ReadSmall(data);

        tokenInfoMng->mTokenInfoMap.insert(TTokenInfoManager::TStrListMapVT(absPath, std::list<TTokenInfo>()));
        auto& tokenList = tokenInfoMng->mTokenInfoMap[absPath];

        std::string instr;
        instr.append(data.GetPtr(), data.GetSize());

        mCppParser.Parse(instr);

        auto parseResult = mCppParser.GetResult();
    }
}
//--------------------------------------------------------------------------------------------------------
