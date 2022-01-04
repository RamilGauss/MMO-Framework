/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include "Unit.h"
#include "WidgetContainer.h"
#include "Events.h"
#include "CallbackPool.h"

namespace nsImGuiWidgets
{
    // Abstract class
    class DllExport TFrame : public TUnit, public TWidgetContainer
    {
    public:
        TFrame();

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

    };
}
