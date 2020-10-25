/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Parser.h"
#include "Tokenizer.h"
#include "EntitySplitter.h"

using namespace nsCppParser;

void TParser::Parse(const std::string& content)
{
    std::list<TTokenInfo> resultList;
    TTokenizer tokenizer;
    tokenizer.Work(content, resultList);

    TEntitySplitter entLineSplitter;
    entLineSplitter.Work(resultList, mRoot);

    LineSplit(&mRoot);
}
//--------------------------------------------------------------------------------------------------------
void TParser::LineSplit(TBlockTokenEntity* blockToken)
{
    int index = 0;
    for ( auto& token : blockToken->mTokens ) {

        if ( token->GetType() == ITokenEntity::Type::BLOCK ) {
            LineSplit( (TBlockTokenEntity*)token.get());
        }

        lineSplitter.SplitLine(blockToken->mTokens, index);
        index++;
    }
}
//--------------------------------------------------------------------------------------------------------