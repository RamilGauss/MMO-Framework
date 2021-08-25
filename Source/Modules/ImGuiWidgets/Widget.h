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
#include "KeyMouseEventContainer.h"

namespace nsImGuiWidgets
{
    class DllExport TWidget : public nsGraphicEngine::IRenderable
    {
        static ImGuiID mLastId;
        static nsGraphicEngine::TKeyMouseEventContainer* mKeyMouseInputContainer;
    protected:
        std::string mTitle = "<Unknown>";
        ImGuiID mId;

    public:
        TWidget();

        enum class SubType
        {
            WIDGET, NODE, UNIT, FRAME
        };
        virtual SubType GetSubType() const;

        void SetTitle(std::string title);
        std::string GetTitle() const;

        static void SetInputContainer(nsGraphicEngine::TKeyMouseEventContainer* keyMouseContainer);
        static nsGraphicEngine::TKeyMouseEventContainer* GetInputContainer();
    };
}
