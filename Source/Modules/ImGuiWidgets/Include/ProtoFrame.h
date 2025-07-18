/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "Base/Common/CallbackPool.h"

#include "GraphicEngine/Events.h"

#include "ImGuiWidgets/Include/Unit.h"
#include "ImGuiWidgets/Include/WidgetContainer.h"

namespace nsImGuiWidgets
{
    // Abstract class
    class DllExport TProtoFrame : public TUnit, public TWidgetContainer
    {
    public:
        TProtoFrame();

        SubType GetSubType() const override;

        virtual TWidget* GetChildByGlobalPos(const ImVec2& mousePos);

        // Property change events by User
        using TKeyCallback = TCallbackPool<nsGraphicEngine::TKeyboardEvent>;
        using TMouseClickCallback = TCallbackPool<nsGraphicEngine::TMouseButtonEvent>;
        using TMouseMoveCallback = TCallbackPool<nsGraphicEngine::TMouseMotionEvent>;
        using TMouseWheelCallback = TCallbackPool<nsGraphicEngine::TMouseWheelEvent>;

        TKeyCallback mOnKeyCB;
        TMouseClickCallback mOnMouseClickCB;
        TMouseMoveCallback  mOnMouseMoveCB;
        TMouseWheelCallback mOnMouseWheelCB;

    protected:

        void BeginRender() override;
        void RenderInheritance() override;
        void EndRender() override;

        void SearchInputEvents();

        virtual ImVec2 GetChildMinSize() const;
        virtual ImVec2 GetChildMaxSize() const;
    };
}
