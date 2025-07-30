/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include <memory>

#include "Base/Common/TypeDef.h"
#include "Parser/Sources/ITokenEntity.h"

namespace nsCppParser
{
    class DllExport TColonSplitter
    {
    public:
        static void SplitLine(std::shared_ptr<ITokenEntity>& entity, std::vector<std::shared_ptr<ITokenEntity>>& result);
    };
}