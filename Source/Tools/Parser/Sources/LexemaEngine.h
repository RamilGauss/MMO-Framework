/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <array>
#include <memory>
#include <magic_enum/magic_enum.hpp>

#include "Base/Common/TypeDef.h"

#include "Parser/Sources/ILexema.h"

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