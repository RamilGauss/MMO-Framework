/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IImGuiRender.h"

class IDirect3DDevice9;

namespace nsImGuiRenderWrapper
{
    class TDirectx9_ImGuiRender : public IImGuiRender
    {
        IDirect3DDevice9* g_pd3dDevice = nullptr;
    public:
        TDirectx9_ImGuiRender();

        ~TDirectx9_ImGuiRender() override;
        bool Init(void* object) override;
        void NewFrame() override;
        void EndFrame(ImDrawData* draw_data) override;
        void Shutdown() override;
    };
}