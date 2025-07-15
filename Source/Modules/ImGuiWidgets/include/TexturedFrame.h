/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ImGuiWidgets/Include/Frame.h"
#include "ImGuiWidgets/Include/TextureReference.h"
#include "ImGuiWidgets/Include/TextureSize.h"
#include "ImGuiWidgets/Include/TextureUv.h"

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
