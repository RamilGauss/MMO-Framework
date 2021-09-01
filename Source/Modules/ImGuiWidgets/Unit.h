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
#include "Visibility.h"
#include "Location.h"

namespace nsImGuiWidgets
{
    class DllExport TUnit : public TWidget, public TVisibility, public TLocation
    {
    protected:
        ImVec2 mScreenPos;
    public:
        void Render() override final;

        SubType GetSubType() const override;
    protected:
        virtual void BeginRender();
        virtual void RenderInheritance() = 0;
        virtual void EndRender();
    };
}
