
/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "TypeDef.h"

#include <SDL2/SDL.h>

#include "IRenderable.h"

struct ImGuiContext;

namespace nsGraphicEngine
{
    class DllExport TImGuiContext
    {
        ImGuiContext* mImGuiCtx = nullptr;

        std::list<IRenderable*> mRenderables;
    public:
        void Init(SDL_Window* window, void* sdl_gl_context);

        void HandleEvents(const std::list<SDL_Event>& events, std::list<SDL_Event>& unusedEvents,
            int xOffset, int yOffset);

        void Render();

        // GUI
        void AddRender(IRenderable* pRenderable);
        void RemoveRender(IRenderable* pRenderable);

    private:
        void CorrectEvent(SDL_Event& event, int xOffset, int yOffset);
    };
}