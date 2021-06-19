/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ColonSplitter.h"
#include "LineTokenEntity.h"

using namespace nsCppParser;

const bool IsAccessLevel(boost::wave::token_id id)
{
    using namespace boost::wave;

    return id == T_PUBLIC ||
        id == T_PROTECTED ||
        id == T_PRIVATE;

}
//--------------------------------------------------------------------------------------------------
void TColonSplitter::SplitLine(std::shared_ptr<ITokenEntity>& entity, std::vector<std::shared_ptr<ITokenEntity>>& result)
{
    using namespace boost::wave;

    std::shared_ptr<ITokenEntity> newLine;
    newLine.reset(new TLineTokenEntity());

    auto line = (TLineTokenEntity*) entity.get();

    bool isAccessLevel = false;
    for (auto& token : line->mTokens) {

        ((TLineTokenEntity*) newLine.get())->mTokens.push_back(token);

        auto isCurAccess = IsAccessLevel(token.id);;

        isAccessLevel |= isCurAccess;
        if (isAccessLevel) {
            if (token.id == T_COLON) {

                result.push_back(newLine);
                newLine.reset(new TLineTokenEntity());

                isAccessLevel = false;
            } else if (token.id != T_SPACE &&
                token.id != T_SPACE2 &&
                token.id != T_NEWLINE &&
                !isCurAccess) {
                isAccessLevel = false;
            }
        }
    }

    auto size = ((TLineTokenEntity*) newLine.get())->mTokens.size();
    if (size > 0) {
        result.push_back(newLine);
    }
}
//--------------------------------------------------------------------------------------------------
