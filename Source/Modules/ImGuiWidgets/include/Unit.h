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
#include "Focus.h"

namespace nsImGuiWidgets
{
    class DllExport TUnit : public TWidget, public TFocus
    {
    public:
        void Render() override final;

        SubType GetSubType() const override;
    protected:
        virtual void BeginRender();
        virtual void RenderInheritance() = 0;
        virtual void EndRender();

        ImGuiID mIdFromWindow = 0;
    };
}
