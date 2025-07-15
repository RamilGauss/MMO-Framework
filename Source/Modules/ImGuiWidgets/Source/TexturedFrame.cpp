/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ImGuiWidgets/Include/TexturedFrame.h"

#include "GraphicEngine/TextureFactory.h"
#include "GraphicEngine/Texture.h"


namespace nsImGuiWidgets
{
    TTexturedFrame::TTexturedFrame()
    {
    }
    //----------------------------------------------------------------------------------------------------
    void TTexturedFrame::RenderInheritance()
    {
        TFrame::RenderInheritance();

        auto textureId = GetTextureId();
        if (textureId != nullptr) {
            ImGui::Image(textureId, GetSize(), GetTextureMinUv(), GetTextureMaxUv());
        }
    }
    //----------------------------------------------------------------------------------------------------
}
