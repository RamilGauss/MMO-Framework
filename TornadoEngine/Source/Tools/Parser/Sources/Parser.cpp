/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Parser.h"
#include "Tokenizer.h"
#include "EntitySplitter.h"
#include "LineLexemaEntity.h"
#include "ExtendedInfoTypeExtractor.h"

#include "magic_enum.hpp"

using namespace nsCppParser;

void TParser::Parse(const std::string& content, const std::string& fileName)
{
    mLastError = "";

    mTokenRoot.reset(new TBlockTokenEntity());
    mLexemaRoot.reset(new TBlockLexemaEntity());

    mContainer.Clear();

    std::list<TTokenInfo> resultList;
    TTokenizer tokenizer;
    tokenizer.Work(content, resultList);

    TEntitySplitter entLineSplitter;
    entLineSplitter.Work(resultList, mTokenRoot.get());

    LineSplit(mTokenRoot.get());

    ConvertTokenTreeToLexemaTree(mTokenRoot.get(), mLexemaRoot.get());

    mTypeInfoCollector.mFileName = fileName;
    mTypeInfoCollector.CollectLexemasToInfoByBlock(mLexemaRoot.get());

    mContainer.mTypeList = mTypeInfoCollector.mTypeResult;

    FillExtendedInfo();
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
void TParser::ConvertTokenTreeToLexemaTree(TBlockTokenEntity* blockToken, TBlockLexemaEntity* blockLexema)
{
    for (auto& token : blockToken->mTokens) {

        switch (token->GetType()) {
            case ITokenEntity::Type::BLOCK:
                {
                    std::shared_ptr<ILexemaEntity> newBlock;
                    newBlock.reset(new TBlockLexemaEntity());
                    auto pBlockLexemaEntity = (TBlockLexemaEntity*) newBlock.get();
                    pBlockLexemaEntity->mParentBlock = blockLexema;

                    blockLexema->mTokens.push_back(newBlock);

                    ConvertTokenTreeToLexemaTree((TBlockTokenEntity*) token.get(), pBlockLexemaEntity);
                }
                break;
            case ITokenEntity::Type::LINE:
                {
                    std::shared_ptr<ILexemaEntity> spLexemaEntity;
                    std::shared_ptr<ILexema> spLexema;
                    auto lexema = mLexemaEngine.Work((TLineTokenEntity*) token.get());
                    if (lexema != nullptr) {
                        spLexema.reset(lexema);

                        spLexemaEntity.reset(new TLineLexemaEntity());
                        auto pLineLexemaEntity = (TLineLexemaEntity*) spLexemaEntity.get();
                        pLineLexemaEntity->mLexemas.push_back(spLexema);
                        blockLexema->mTokens.push_back(spLexemaEntity);
                    }
                }
                break;
        }
    }
}
//--------------------------------------------------------------------------------------------------------
std::string TParser::GetInfo()
{
    std::string info = "nsCppParser lexema supports: ";

    constexpr auto& lexemas = magic_enum::enum_values<ILexema::LexemaType>();
    for (auto& lexema : lexemas) {

        info += magic_enum::enum_name<ILexema::LexemaType>(lexema);
        info += ", ";
    }

    return info;
}
//--------------------------------------------------------------------------------------------------------
void TParser::FillExtendedInfo()
{
    TExtendedInfoTypeExtractor extendedInfoMaker;

    for (auto& type : mContainer.mTypeList) {
        for (auto& members : type->mMembers) {
            for (auto& m : members) {
                extendedInfoMaker.Convert(m->mTypeName, &(m->mExtendedInfo));
            }
        }
    }
}
//--------------------------------------------------------------------------------------------------------
void TParser::SetupTypes(std::map<std::string, TypeCategory>& nameTypeMap, bool append)
{
    if (!append) {
        mNameTypeMap = nameTypeMap;
    } else {
        mNameTypeMap.insert(nameTypeMap.begin(), nameTypeMap.end());
    }
}
//--------------------------------------------------------------------------------------------------------
std::string TParser::GetLastError() const
{
    return mLastError;
}
//--------------------------------------------------------------------------------------------------------
void TParser::AddError(std::string& str)
{
    //mLastError += str;// TODO: 
}
//--------------------------------------------------------------------------------------------------------