/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "OgreBitesPrerequisites.h"
#include "OgreInput.h"
#include "TypeDef.h"

namespace nsGraphicEngine
{
    struct DllExport TInputCollectorListener : public OgreBites::InputListener
    {
        TInputCollectorListener() {};
        bool keyPressed(const OgreBites::KeyboardEvent& evt) override {};
        bool keyReleased(const OgreBites::KeyboardEvent& evt) override {};
        bool mouseMoved(const OgreBites::MouseMotionEvent& evt) override {};
        bool mouseWheelRolled(const OgreBites::MouseWheelEvent& evt) override {};
        bool mousePressed(const OgreBites::MouseButtonEvent& evt) override {};
        bool mouseReleased(const OgreBites::MouseButtonEvent& evt) override {};
        bool textInput(const OgreBites::TextInputEvent& evt) override {};
    private:
    };
}

