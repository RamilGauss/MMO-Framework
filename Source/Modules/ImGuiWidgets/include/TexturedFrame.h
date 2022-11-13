/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Frame.h"
#include "TextureReference.h"
#include "TextureSize.h"
#include "TextureUv.h"

namespace nsImGuiWidgets
{
    class DllExport TTexturedFrame : public TFrame, public TTextureReference, public TTextureSize, public TTextureUv
    {
    public:
        TTexturedFrame();
    protected:

        void RenderInheritance() override;
    };
}
