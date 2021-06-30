/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "imgui.h"

#include "IRenderable.h"

namespace nsImGuiWidgets
{
    class TWidget : public nsGraphicEngine::IRenderable
    {
    protected:
        std::string mName;

        bool mIsShown = true;

        ImVec2 mSize;
        ImVec2 mPos;
    public:
        TWidget(const std::string& name) { mName = name; }

        const char* GetName() { return mName.c_str(); }

        bool IsShown() { return mIsShown; }

        void SetShow(bool value) { mIsShown = value; }

        void Show() { SetShow(true); }
        void Hide() { SetShow(false); }

        const ImVec2* GetPos() { return &mPos; }
        const ImVec2* GetSize() { return &mSize; }

        void Render() override final
        {
            if (!mIsShown) {
                return;
            }

            RenderInheritance();

            mSize = ImGui::GetWindowSize();
            mPos = ImGui::GetWindowPos();
        }
    protected:
        virtual void RenderInheritance() = 0;
    };
}
