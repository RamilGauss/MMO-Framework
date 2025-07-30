/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include "ReflectionCodeGeneratorLib/Sources/Config.h"

namespace nsReflectionCodeGenerator
{
    class DllExport IOutDumper
    {
    public:
        virtual void Save(TExternalSource& extSrc, const std::string& fileAbsPath) = 0;
    };
}
