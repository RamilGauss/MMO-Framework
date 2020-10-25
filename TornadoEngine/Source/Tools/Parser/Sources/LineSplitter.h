/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include <memory>

#include "TypeDef.h"
#include "ITokenEntity.h"

namespace nsCppParser
{
    class DllExport TLineSplitter
    {
    public:

        void SplitLine(std::vector < std::shared_ptr<ITokenEntity>>& entities, int index);
    };
}