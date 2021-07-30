/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "imgui.h"
#include "Typedef.h"

#include "IRenderable.h"

namespace nsImGuiWidgets
{
    class DllExport TWidget : public nsGraphicEngine::IRenderable
    {
    protected:
        std::string mName;

        bool mIsShown = true;

        ImVec2 mSize;
        ImVec2 mPos;
    public:
        TWidget(const std::string& name);

        const char* GetName();

        bool IsShown();

        void SetShow(bool value);

        void Show();
        void Hide();

        const ImVec2* GetPos();
        const ImVec2* GetSize();

        void Render() override final;
    protected:
        virtual void RenderInheritance() = 0;
    };
}
