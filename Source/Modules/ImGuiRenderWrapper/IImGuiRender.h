/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "ImGuiRenderFactory.h"
#include "imgui.h"

namespace nsImGuiRenderWrapper
{
    class DllExport IImGuiRender
    {
    public:
        virtual ~IImGuiRender();
        virtual bool Init(void* object) = 0;
        virtual void NewFrame() = 0;
        virtual void EndFrame(ImDrawData* draw_data) = 0;
        virtual void Shutdown() = 0;
    };
}