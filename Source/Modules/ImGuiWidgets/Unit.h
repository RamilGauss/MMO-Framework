/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "Typedef.h"

#include "Widget.h"

namespace nsImGuiWidgets
{
    class DllExport TUnit : public TWidget
    {
    protected:
        bool mIsShown = true;

        ImVec2 mSize;
        ImVec2 mPos;
    public:
        bool IsShown();
        void SetShow(bool value);

        void Show();
        void Hide();

        void SetPos(const ImVec2& newPos);
        void SetSize(const ImVec2& newSize);

        const ImVec2* GetPos();
        const ImVec2* GetSize();

        void Render() override final;
    protected:
        virtual void BeginRender();
        virtual void RenderInheritance() = 0;
        virtual void EndRender();
    };
}
