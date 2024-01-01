/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>
#include <map>
#include <array>

#include "Base/Common/TypeDef.h"

namespace nsGraphicEngine
{
    class TTexture;

    class DllExport TTextureFactory
    {
    public:
        [[nodiscard]]
        static TTexture* Load(const std::string& absPath);
        static bool Save(const TTexture* pTexture, const std::string& absPath);

        static void Unload(TTexture* pTexture);
    };
}
