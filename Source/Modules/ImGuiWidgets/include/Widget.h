/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "imgui.h"
#include "TypeDef.h"

#include "GraphicEngine/IRenderable.h"
#include "GraphicEngine/KeyMouseEventContainer.h"

#include "Title.h"
#include "Geometry.h"
#include "Visibility.h"
#include "Identity.h"

namespace nsImGuiWidgets
{
    class DllExport TWidget : public nsGraphicEngine::IRenderable, 
        public TTitle, public TGeometry, public TVisibility, public TIdentity
    {
        static nsGraphicEngine::TKeyMouseEventContainer* mKeyMouseInputContainer;
    protected:
        TWidget* mParent = nullptr;

    public:
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
