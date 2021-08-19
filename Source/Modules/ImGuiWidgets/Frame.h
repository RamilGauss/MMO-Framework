/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include "Unit.h"
#include "Events.h"
#include "CallbackPool.h"

namespace nsImGuiWidgets
{
    // Abstract class
    class DllExport TFrame : public TUnit
    {
    protected:
        bool mIsFocused = false;
        std::list<nsGraphicEngine::IRenderable*> mChildList;
    public:
        void Push(nsGraphicEngine::IRenderable* pWidget);
        void Remove(nsGraphicEngine::IRenderable* pWidget);

        void Clear();

        // Property change events by User
        using TFocusCallback = TCallbackPool<bool>;

        using TKeyCallback = TCallbackPool<nsGraphicEngine::TKeyboardEvent>;
        using TMouseClickCallback = TCallbackPool<nsGraphicEngine::TMouseButtonEvent>;
        using TMouseMoveCallback = TCallbackPool<nsGraphicEngine::TMouseMotionEvent>;
        using TMouseWheelCallback = TCallbackPool<nsGraphicEngine::TMouseWheelEvent>;

        TFocusCallback mFocusCB;

        bool IsFocused();

    protected:

        void BeginRender() override;
        void RenderInheritance() override;
        void EndRender() override;

        void SearchInputEvents();

    };
}
