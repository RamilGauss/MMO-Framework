/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "TypeDef.h"
#include "BlockTokenEntity.h"
#include "TokenInfo.h"
#include "LineTokenEntity.h"

namespace nsCppParser
{
    class DllExport TEntitySplitter
    {
        TBlockTokenEntity* mCurrentBlock = nullptr;

        TLineTokenEntity mLineToken;
    public:
        void Work(const std::list<TTokenInfo>& tokenList, TBlockTokenEntity& root);

    private:
        void HandleToken(const TTokenInfo& tokenInfo);

        void AddLineToCurrentBlock();
    };
}