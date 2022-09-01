/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <list>
#include <string>

namespace nsGraphicEngine
{
    class DllExport TShaderPrefabs
    {
    public:
        static const std::list<std::string> GetRenderObjectVertex();
        static const std::list<std::string> GetRenderObjectFragment();

        static const std::list<std::string> GetRenderTextureOnDisplayVertex();
        static const std::list<std::string> GetRenderTextureOnDisplayFragment();
    };
}