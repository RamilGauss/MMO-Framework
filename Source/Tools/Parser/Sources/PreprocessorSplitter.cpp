/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Parser/Sources/PreprocessorSplitter.h"
#include "Parser/Sources/LineTokenEntity.h"

using namespace nsCppParser;

const bool IsPreprocessor(boost::wave::token_id id)
{
    using namespace boost::wave;

    return id == T_PP_DEFINE ||
        id == T_PP_IF ||
        id == T_PP_IFDEF ||
        id == T_PP_IFNDEF ||
        id == T_PP_ELSE ||
        id == T_PP_ELIF ||
        id == T_PP_ENDIF ||
        id == T_PP_ERROR ||
        id == T_PP_LINE ||
        id == T_PP_PRAGMA ||
        id == T_PP_UNDEF ||
        id == T_PP_WARNING ||

        id == T_PP_INCLUDE ||
        id == T_PP_QHEADER ||
        id == T_PP_HHEADER ||
        id == T_PP_INCLUDE_NEXT ||
        id == T_PP_QHEADER_NEXT ||
        id == T_PP_HHEADER_NEXT ||
        id == T_PP_NUMBER;

}
//--------------------------------------------------------------------------------------------------
void TPreprocessorSplitter::SplitLine(std::shared_ptr<ITokenEntity>& entity, std::vector<std::shared_ptr<ITokenEntity>>& result)
{
    using namespace boost::wave;

    std::shared_ptr<ITokenEntity> newLine;
    newLine.reset(new TLineTokenEntity());

    auto line = (TLineTokenEntity*) entity.get();

    bool isPreprocessor = false;
    for (auto& token : line->mTokens) {

        ((TLineTokenEntity*) newLine.get())->mTokens.push_back(token);

        isPreprocessor |= IsPreprocessor(token.id);
        if (isPreprocessor) {
            if (token.id == T_NEWLINE) {

                result.push_back(newLine);
                newLine.reset(new TLineTokenEntity());

                isPreprocessor = false;
            }
        }
    }

    auto size = ((TLineTokenEntity*) newLine.get())->mTokens.size();
    if (size > 0) {
        result.push_back(newLine);
    }
}
//--------------------------------------------------------------------------------------------------