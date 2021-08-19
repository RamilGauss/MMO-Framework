/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <list>
#include <array>

#include <SDL.h>
#include <SDL_video.h>
#include <SDL_syswm.h>

#include "KeyMouseEventContainer.h"

namespace nsGraphicEngine
{
    class DllExport TKeyMouseEventHandler
    {
        TKeyMouseEventContainer* mKeyMouseEventContainer = nullptr;
    public:
        void SetContainer(TKeyMouseEventContainer* keyMouseEventContainer);

        void ResetStates();
        void ClearEvents();
        void AddSdl2Event(const SDL_Event& event);
    private:
        void UpdateStates(const SDL_Event& event);
    };
}

