/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Parser/Sources/LineSplitter.h"
#include "Parser/Sources/LineTokenEntity.h"
#include "Parser/Sources/PreprocessorSplitter.h"
#include "Parser/Sources/ColonSplitter.h"
#include "Parser/Sources/CommentRemover.h"

using namespace nsCppParser;

void TLineSplitter::SplitLine(std::shared_ptr<ITokenEntity>& entity, std::vector<std::shared_ptr<ITokenEntity>>& result)
{
    if (entity->GetType() != ITokenEntity::Type::LINE) {
        return;
    }

    std::vector<std::shared_ptr<ITokenEntity>> preprocessorResult;
    TPreprocessorSplitter::SplitLine(entity, preprocessorResult);

    for (auto& preprocessorprevTokenEnt : preprocessorResult) {
        std::vector<std::shared_ptr<ITokenEntity>> colonResult;
        TColonSplitter::SplitLine(preprocessorprevTokenEnt, colonResult);

        for (auto& colonTokenEnt : colonResult) {

            std::vector<std::shared_ptr<ITokenEntity>> commentResult;
            TCommentRemover::SplitLine(colonTokenEnt, commentResult);

            for (auto& commentTokenEnt : commentResult) {
                result.push_back(commentTokenEnt);
            }
        }
    }
}
//--------------------------------------------------------------------------------------------------
