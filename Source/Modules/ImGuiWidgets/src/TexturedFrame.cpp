/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TexturedFrame.h"

#include "TextureFactory.h"
#include "Texture.h"


namespace nsImGuiWidgets
{
    TTexturedFrame::TTexturedFrame()
    {
    }
    //----------------------------------------------------------------------------------------------------
    void TTexturedFrame::RenderInheritance()
    {
        TFrame::RenderInheritance();

        auto textureId = GetTexture();
        if (textureId != -1) {
            ImGui::Image((void*)(intptr_t)textureId, GetSize());
        }
    }
    //----------------------------------------------------------------------------------------------------
}
