/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ReflectionCodeGeneratorLib/Sources/IOutDumper.h"

namespace nsReflectionCodeGenerator
{
    class DllExport TOutDumper : public IOutDumper
    {
    public:
        void Save(TExternalSource& extSrc, const std::string& fileAbsPath) override;
    };
}
