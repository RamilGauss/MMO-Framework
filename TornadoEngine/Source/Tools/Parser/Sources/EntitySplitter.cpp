/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "EntitySplitter.h"

#include <boost/wave/token_ids.hpp>

using namespace nsCppParser;
using namespace boost::wave;

void TEntitySplitter::Work(const std::list<TTokenInfo>& tokenList, TBlockTokenEntity& root)
{
    mCurrentBlock = &root;
    for ( auto tokenInfo : tokenList ) {
        HandleToken(tokenInfo);
    }
}
//---------------------------------------------------------------------------------------------
void TEntitySplitter::HandleToken(const TTokenInfo& tokenInfo)
{
    switch ( tokenInfo.id )
    {
        case T_LEFTBRACE:
        {
            AddLineToCurrentBlock();

            std::shared_ptr<TBlockTokenEntity> newBlock;
            newBlock.reset(new TBlockTokenEntity());
            mCurrentBlock->mTokens.push_back(newBlock);
            newBlock->mParentBlock = mCurrentBlock;

            mCurrentBlock = newBlock.get();
            break;
        }
        case T_RIGHTBRACE:
            AddLineToCurrentBlock();

            mCurrentBlock = mCurrentBlock->mParentBlock;
            break;
        case T_SEMICOLON:
            mLineToken.mTokenList.push_back(tokenInfo);

            AddLineToCurrentBlock();
            break;
        default:
            mLineToken.mTokenList.push_back(tokenInfo);
    }
}
//---------------------------------------------------------------------------------------------
void TEntitySplitter::AddLineToCurrentBlock()
{
    std::shared_ptr<TLineTokenEntity> newLine;

    newLine.reset(new TLineTokenEntity());
    *newLine = mLineToken;
    mCurrentBlock->mTokens.push_back(newLine);
    mLineToken.mTokenList.clear();
}
//---------------------------------------------------------------------------------------------