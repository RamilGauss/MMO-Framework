
/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include <SDL.h>

#include "Base/Common/TypeDef.h"

#include "GraphicEngine/IRenderable.h"

struct ImGuiContext;

namespace nsGraphicEngine
{
    class DllExport TImGuiContext
    {
        ImGuiContext* mImGuiCtx = nullptr;

        std::list<IRenderable*> mRenderables;

        float mX = 0;
        float mY = 0;
        float mWidth = 0;
        float mHeight = 0;

        int mWindowWidth = 0;
        int mWindowHeight = 0;
    public:
        void Init(SDL_Window* window, void* sdl_gl_context);

        void HandleEvents(const std::list<SDL_Event>& events, std::list<SDL_Event>& unusedEvents);

        void Render();

        // GUI
        void SetupGuiViewport(int winWidth, int winHeight, float x, float y, float width, float height);

        void AddRender(IRenderable* pRenderable);
        void RemoveRender(IRenderable* pRenderable);
    private:
        void CorrectEvent(SDL_Event& event);

        void ApplyViewportParams();
    };
}