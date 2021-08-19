/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "Events.h"

#include <list>
#include <array>

namespace nsGraphicEngine
{
    struct DllExport TKeyMouseEventContainer
    {
        std::list<TKeyboardEvent> keyEvents;
        std::list<TMouseMotionEvent> mouseMotionEvents;
        std::list<TMouseButtonEvent> mouseButtonEvents;
        std::list<TMouseWheelEvent> mouseWheelEvents;

        std::array<bool, (size_t) KeyCodes::NUM_SCANCODES> keyCodeState;
        std::array<bool, (size_t) MouseButton::COUNT> mouseButtonState;

        int mouseX = 0;
        int mouseY = 0;
    };
}

