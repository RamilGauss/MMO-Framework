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
#include "Title.h"
#include "Geometry.h"
#include "Visibility.h"
#include "KeyMouseEventContainer.h"

namespace nsImGuiWidgets
{
    class DllExport TWidget : public nsGraphicEngine::IRenderable, public TTitle, public TGeometry, public TVisibility
    {
        static ImGuiID mLastId;
        static nsGraphicEngine::TKeyMouseEventContainer* mKeyMouseInputContainer;
    protected:
        ImGuiID mId;

        TWidget* mParent = nullptr;

    public:
        TWidget();

        enum class SubType
        {
            WIDGET, NODE, UNIT, FRAME
        };
        virtual SubType GetSubType() const;

        static void SetInputContainer(nsGraphicEngine::TKeyMouseEventContainer* keyMouseContainer);
        static nsGraphicEngine::TKeyMouseEventContainer* GetInputContainer();

        void SetParent(TWidget* parent);
        TWidget* GetParent() const;

        ImVec2 GetGlobalPos();
    };
}
