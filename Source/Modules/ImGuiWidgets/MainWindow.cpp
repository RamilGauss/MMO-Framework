/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MainWindow.h"

using namespace nsImGuiWidgets;

TMainWindow::TMainWindow(const std::string& name) : TWindow(name) 
{
}
//----------------------------------------------------------------------------------------
void TMainWindow::RenderInheritance()
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
//----------------------------------------------------------------------------------------