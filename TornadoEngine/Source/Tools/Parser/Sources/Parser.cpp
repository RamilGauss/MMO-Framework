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
    mContainer.Clear();

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
    std::vector<std::shared_ptr<ITokenEntity>> result;
    for (auto& token : blockToken->mTokens) {

        switch (token->GetType()) {
            case ITokenEntity::Type::BLOCK:
                result.push_back(token);
                LineSplit((TBlockTokenEntity*) token.get());
                break;
            case ITokenEntity::Type::LINE:
                mLineSplitter.SplitLine(token, result);
                break;
        }
    }

    blockToken->mTokens.swap(result);
}
//--------------------------------------------------------------------------------------------------------
const TParserResultContainer* TParser::GetResult() const
{
    return &mContainer;
}
//--------------------------------------------------------------------------------------------------------