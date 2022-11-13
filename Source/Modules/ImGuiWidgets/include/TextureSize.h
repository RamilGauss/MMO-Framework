/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <imgui.h>

#include "TypeDef.h"

namespace nsImGuiWidgets
{
    struct DllExport TTextureSize
    {
    public:
        virtual void SetTextureSize(unsigned int width, unsigned int height);

        virtual unsigned int GetTextureWidth() const;
        virtual unsigned int GetTextureHeight() const;
    protected:
        unsigned int mTextureWidth = 0;
        unsigned int mTextureHeight = 0;
    };
}
