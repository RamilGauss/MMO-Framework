/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "KeyMouseEventHandler.h"

using namespace nsGraphicEngine;

void TKeyMouseEventHandler::SetContainer(TKeyMouseEventContainer* keyMouseEventContainer)
{
    mKeyMouseEventContainer = keyMouseEventContainer;
}
//------------------------------------------------------------------------------------
void TKeyMouseEventHandler::ResetStates()
{
    if (mKeyMouseEventContainer == nullptr) {
        return;
    }

    mKeyMouseEventContainer->keyCodeState.fill(false);
    mKeyMouseEventContainer->mouseButtonState.fill(false);

    mKeyMouseEventContainer->mouseX = 0;
    mKeyMouseEventContainer->mouseY = 0;
}
//------------------------------------------------------------------------------------
void TKeyMouseEventHandler::ClearEvents()
{
    if (mKeyMouseEventContainer == nullptr) {
        return;
    }

    mKeyMouseEventContainer->keyEvents.clear();
    mKeyMouseEventContainer->mouseButtonEvents.clear();
    mKeyMouseEventContainer->mouseMotionEvents.clear();
    mKeyMouseEventContainer->mouseWheelEvents.clear();
}
//------------------------------------------------------------------------------------
void TKeyMouseEventHandler::AddSdl2Event(const SDL_Event& event)
{
    if (mKeyMouseEventContainer == nullptr) {
        return;
    }

    switch (event.type) {
        case SDL_EventType::SDL_KEYDOWN:
        case SDL_EventType::SDL_KEYUP:
        {
            TKeyboardEvent keyEvent;
            keyEvent.timestamp = event.key.timestamp;

            keyEvent.keyCode = (KeyCodes) event.key.keysym.scancode;
            keyEvent.state = event.type == SDL_EventType::SDL_KEYDOWN ? KeyState::DOWN : KeyState::UP;
            keyEvent.repeat = event.key.repeat;
            keyEvent.mod = (KeyMod) event.key.keysym.mod;
            mKeyMouseEventContainer->keyEvents.push_back(keyEvent);
        }
        break;
        case SDL_EventType::SDL_MOUSEBUTTONDOWN:
        case SDL_EventType::SDL_MOUSEBUTTONUP:
        {
            TMouseButtonEvent mouseButtonEvent;
            mouseButtonEvent.timestamp = event.button.timestamp;

            mouseButtonEvent.button = (MouseButton) event.button.button;
            mouseButtonEvent.state = event.type == SDL_EventType::SDL_MOUSEBUTTONDOWN ?
                MouseState::PRESSED : MouseState::RELEASED;
            mouseButtonEvent.clicks = event.button.clicks;
            mouseButtonEvent.x = event.button.x;
            mouseButtonEvent.y = event.button.y;

            mKeyMouseEventContainer->mouseButtonEvents.push_back(mouseButtonEvent);
        }
        break;
        case SDL_EventType::SDL_MOUSEMOTION:
        {
            TMouseMotionEvent mouseMotionEvent;
            mouseMotionEvent.timestamp = event.motion.timestamp;

            mouseMotionEvent.x = event.motion.x;
            mouseMotionEvent.y = event.motion.y;
            mouseMotionEvent.xrel = event.motion.xrel;
            mouseMotionEvent.yrel = event.motion.yrel;

            mKeyMouseEventContainer->mouseMotionEvents.push_back(mouseMotionEvent);
        }
        break;
        case SDL_EventType::SDL_MOUSEWHEEL:
        {
            TMouseWheelEvent mouseWheelEvent;
            mouseWheelEvent.timestamp = event.wheel.timestamp;

            mouseWheelEvent.x = event.wheel.x;
            mouseWheelEvent.y = event.wheel.y;

            mKeyMouseEventContainer->mouseWheelEvents.push_back(mouseWheelEvent);
        }
        break;
    }

    UpdateStates(event);
}
//------------------------------------------------------------------------------------
void TKeyMouseEventHandler::UpdateStates(const SDL_Event& event)
{
    switch (event.type) {
        case SDL_EventType::SDL_KEYDOWN:
            mKeyMouseEventContainer->keyCodeState[event.key.keysym.scancode] = true;
            break;
        case SDL_EventType::SDL_KEYUP:
            mKeyMouseEventContainer->keyCodeState[event.key.keysym.scancode] = false;
            break;
        case SDL_EventType::SDL_MOUSEBUTTONDOWN:
            mKeyMouseEventContainer->mouseButtonState[event.button.button] = true;
            break;
        case SDL_EventType::SDL_MOUSEBUTTONUP:
            mKeyMouseEventContainer->mouseButtonState[event.button.button] = false;
            break;
        case SDL_EventType::SDL_MOUSEMOTION:
            mKeyMouseEventContainer->mouseX = event.motion.x;
            mKeyMouseEventContainer->mouseY = event.motion.y;
            break;
    }
}
//------------------------------------------------------------------------------------
