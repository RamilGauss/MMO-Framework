/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Window.h"

namespace nsImGuiWidgets
{
    class TMainWindow : public TWindow
    {
    public:
        TMainWindow(const std::string& name) : TWindow(name) {}
    protected:
        const int TOOLBAR_HEIGHT = 20;

        ImGuiWindowFlags s_DockSpaceFlags = ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse
            | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus
            | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBackground;

        void RenderInheritance() override
        {
            ImGuiViewport* viewport = ImGui::GetMainViewport();
            ImVec2 size(viewport->Size.x, (viewport->Size.y - TOOLBAR_HEIGHT));
            ImVec2 position(viewport->Pos.x, (viewport->Pos.y + TOOLBAR_HEIGHT));

            ImGui::SetNextWindowSize(size);
            ImGui::SetNextWindowPos(position);
            ImGui::SetNextWindowViewport(viewport->ID);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));

            ImGui::Begin(mName.c_str(), nullptr, s_DockSpaceFlags);
            {
                ImGui::DockSpace(ImGui::GetID("Dockspace"), ImVec2(0, 0), ImGuiDockNodeFlags_PassthruCentralNode);
            }
            ImGui::PopStyleVar(3);

            for (auto& child : mChildList) {
                child->Render();
            }

            ImGui::End();
        }
    };
}
