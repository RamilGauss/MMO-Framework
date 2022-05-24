/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GuiDemo.h"

using namespace nsGraphicEngine;

void TGuiDemo::Load(const std::string& path)
{
    mTexture = TTextureFactory::Load(path);
}
//--------------------------------------------------------------------------------------
void TGuiDemo::SetTexture(const nsGraphicEngine::TTexture* pTexture)
{
    mTexture = pTexture;
}
//--------------------------------------------------------------------------------------
void TGuiDemo::Render()
{
    ImGui::Begin("OpenGL Texture Text");
    ImGui::Text("FPS=%d, Camera controls:", (int)ImGui::GetIO().Framerate);
    ImGui::Text("W - forward, S - backward, D - right");
    ImGui::Text("A - left, Q - down, E - up");
    ImGui::Text("T - switch camera");
    ImGui::Text("Current camera index %d", mCameraIndex);

    // Invserse UV by Y axe.
    ImGui::Image((void*)(intptr_t)mTexture->mId, ImVec2(mTexture->mWidth / 3, mTexture->mHeight / 3), 
        {0,1}, {1,0});
    ImGui::End();
}
//--------------------------------------------------------------------------------------
void TGuiDemo::SetCameraIndex(int value)
{
    mCameraIndex = value;
}
//--------------------------------------------------------------------------------------
