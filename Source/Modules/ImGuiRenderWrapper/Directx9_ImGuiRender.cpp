/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Directx9_ImGuiRender.h"

#include "imgui_impl_dx9.h"
#include <d3d9.h>

using namespace nsImGuiRenderWrapper;

TDirectx9_ImGuiRender::TDirectx9_ImGuiRender()
{

}
//--------------------------------------------------------------------------
TDirectx9_ImGuiRender::~TDirectx9_ImGuiRender()
{

}
//--------------------------------------------------------------------------
bool TDirectx9_ImGuiRender::Init(void* object)
{
    g_pd3dDevice = (IDirect3DDevice9*) object;
    return ImGui_ImplDX9_Init(g_pd3dDevice);
}
//--------------------------------------------------------------------------
void TDirectx9_ImGuiRender::NewFrame()
{
    ImGui_ImplDX9_NewFrame();
    ImGui::NewFrame();
}
//--------------------------------------------------------------------------
void TDirectx9_ImGuiRender::EndFrame(ImDrawData* draw_data)
{
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    ImGui::EndFrame();
    g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
    g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);
    g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, FALSE);
    D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int) (clear_color.x * clear_color.w * 255.0f), (int) (clear_color.y * clear_color.w * 255.0f), (int) (clear_color.z * clear_color.w * 255.0f), (int) (clear_color.w * 255.0f));
    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
    if (g_pd3dDevice->BeginScene() >= 0) {
        ImGui::Render();
        ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
        g_pd3dDevice->EndScene();
    }
}
//--------------------------------------------------------------------------
void TDirectx9_ImGuiRender::Shutdown()
{
    ImGui_ImplDX9_Shutdown();
    ImGui::DestroyContext();
}
//--------------------------------------------------------------------------
