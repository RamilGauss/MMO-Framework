/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"
#include <array>
#include <memory>
#include "ILexema.h"

#include "magic_enum.hpp"

namespace nsCppParser
{
    class DllExport TLexemaEngine
    {
        std::array<std::shared_ptr<ILexema>, magic_enum::enum_count<ILexema::LexemaType>()> mLexemas;

    public:
        TLexemaEngine();

        ILexema* Work(TLineTokenEntity* lineTokenEntity);
    };
}