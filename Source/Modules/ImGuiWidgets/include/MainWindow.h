/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ProtoFrame.h"
#include "MenuNode.h"

namespace nsImGuiWidgets
{
    class DllExport TMainWindow : public TProtoFrame
    {
    protected:
        const int TOOLBAR_HEIGHT = 20;

        ImGuiWindowFlags s_DockSpaceFlags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse
            | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus
            | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBackground;

        void BeginRender() override;
        void RenderInheritance() override;
        void EndRender() override;
    };
}
