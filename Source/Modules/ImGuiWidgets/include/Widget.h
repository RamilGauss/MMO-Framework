/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "imgui.h"
#include "Base/Common/TypeDef.h"

#include "GraphicEngine/IRenderable.h"
#include "GraphicEngine/KeyMouseEventContainer.h"

#include "ImGuiWidgets/Include/Title.h"
#include "ImGuiWidgets/Include/Size.h"
#include "ImGuiWidgets/Include/Position.h"
#include "ImGuiWidgets/Include/Visibility.h"
#include "ImGuiWidgets/Include/Identity.h"
#include "ImGuiWidgets/Include/Color.h"

namespace nsImGuiWidgets
{
    class DllExport TWidget : public nsGraphicEngine::IRenderable, 
        public TTitle, public TColor, public TSize, public TPosition, public TVisibility, public TIdentity
    {
        static nsGraphicEngine::TKeyMouseEventContainer* mKeyMouseInputContainer;
    protected:
        TWidget* mParent = nullptr;

    public:
        virtual ~TWidget() {};

        enum class SubType
        {
            WIDGET, NODE, UNIT, PROTO_FRAME, FRAME
        };
        virtual SubType GetSubType() const;

        static void SetInputContainer(nsGraphicEngine::TKeyMouseEventContainer* keyMouseContainer);
        static nsGraphicEngine::TKeyMouseEventContainer* GetInputContainer();

        void SetParent(TWidget* parent);
        TWidget* GetParent() const;

        ImVec2 GetGlobalPos();
    };
}
