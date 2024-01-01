/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <imgui.h>

#include "Base/Common/TypeDef.h"

namespace nsImGuiWidgets
{
    struct DllExport TTextureSize
    {
    public:
        void SetTextureSize(unsigned int width, unsigned int height);

        unsigned int GetTextureWidth() const;
        unsigned int GetTextureHeight() const;
    protected:
        unsigned int mTextureWidth = 0;
        unsigned int mTextureHeight = 0;
    };
}
