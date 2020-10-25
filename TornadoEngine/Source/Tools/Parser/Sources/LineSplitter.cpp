/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "LineSplitter.h"
#include "LineTokenEntity.h"

using namespace nsCppParser;

void TLineSplitter::SplitLine(std::vector<std::shared_ptr<ITokenEntity>>& entities, int index)
{
    auto& ent = entities[index];

    if ( ent->GetType() != ITokenEntity::Type::LINE ) {
        return;
    }

    auto line = (TLineTokenEntity*)ent.get();

    std::string str;
    for ( auto& tokenInfo : line->mTokenList )
    {
        str += tokenInfo.value;
    }

    printf("\n%s\n", str.data());
}
//--------------------------------------------------------------------------------------------------
