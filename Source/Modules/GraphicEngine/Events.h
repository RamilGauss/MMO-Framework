/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"
#include "GraphicEngine/KeyCodes.h"
#include <cstdint>

namespace nsGraphicEngine
{
    enum class DllExport KeyState
    {
        DOWN, UP
    };
    enum class DllExport MouseState
    {
        PRESSED, RELEASED
    };
    enum class DllExport MouseButton
    {
        LEFT, MIDDLE, RIGHT, COUNT
    };

    struct DllExport TBaseEvent
    {
        uint32_t timestamp;   // In milliseconds, populated using SDL_GetTicks()
    };
    struct DllExport TKeyboardEvent : public TBaseEvent
    {
        KeyCodes keyCode;

        KeyState state;
        uint8_t repeat; // Non-zero if this is a key repeat
        KeyMod mod;
    };
    struct DllExport TMouseMotionEvent : public TBaseEvent
    {
        int x;           // X coordinate, relative to window
        int y;           // Y coordinate, relative to window
        int xrel;        // The relative motion in the X direction
        int yrel;        // The relative motion in the Y direction
    };
    struct DllExport TMouseButtonEvent : public TBaseEvent
    {
        MouseButton button;
        MouseState state;
        uint8_t clicks;
        int x;           // X coordinate, relative to window
        int y;           // Y coordinate, relative to window
    };
    struct DllExport TMouseWheelEvent : public TBaseEvent
    {
        int x;           // The amount scrolled horizontally, positive to the right and negative to the left
        int y;           // The amount scrolled vertically, positive away from the user and negative toward the user
    };
}

