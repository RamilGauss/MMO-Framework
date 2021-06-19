/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "CommentSplitter.h"
#include "LineTokenEntity.h"

using namespace nsCppParser;

const bool IsComment(boost::wave::token_id id)
{
    using namespace boost::wave;

    return id == T_CCOMMENT ||
        id == T_CPPCOMMENT;

}
//--------------------------------------------------------------------------------------------------
void TCommentSplitter::SplitLine(std::shared_ptr<ITokenEntity>& entity, std::vector<std::shared_ptr<ITokenEntity>>& result)
{
    using namespace boost::wave;

    std::shared_ptr<ITokenEntity> newLine;
    newLine.reset(new TLineTokenEntity());

    auto line = (TLineTokenEntity*) entity.get();

    for (auto& token : line->mTokens) {

        ((TLineTokenEntity*) newLine.get())->mTokens.push_back(token);

        auto isCurAccess = IsComment(token.id);;

        if (isCurAccess) {
            result.push_back(newLine);
            newLine.reset(new TLineTokenEntity());
        }
    }

    auto size = ((TLineTokenEntity*) newLine.get())->mTokens.size();
    if (size > 0) {
        result.push_back(newLine);
    }
}
//--------------------------------------------------------------------------------------------------
