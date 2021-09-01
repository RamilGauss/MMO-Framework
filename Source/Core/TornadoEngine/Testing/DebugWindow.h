/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"
#include "IRenderable.h"
#include "imgui.h"

namespace nsTest
{
    class DllExport TDebugWindow : public nsGraphicEngine::IRenderable
    {
    public:
        void Render() override
        {
            ImGui::ShowDemoWindow();
        }
    };
}