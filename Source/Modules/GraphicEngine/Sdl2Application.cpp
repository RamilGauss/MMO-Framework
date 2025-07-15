/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngine/Sdl2Application.h"

using namespace nsGraphicEngine;

bool TSdl2Application::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return false;
    }

    auto windowFlag = SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI;
    mWindow = SDL_CreateWindow(mTitle.c_str(), mX, mY, mWidth, mHeight, windowFlag);

    auto rendererFlag = SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE;
    mRenderer = SDL_CreateRenderer(mWindow, -1, rendererFlag);

    if (mRenderer == nullptr) {
        return false;
    }

    // Create a OpenGL context on SDL2
    mCtx = SDL_GL_CreateContext(mWindow);

    // Load GL extensions using glad
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
        return false;
    }

    glEnable(GL_DEPTH_TEST);

    return true;
}
//-------------------------------------------------------------------------------
void TSdl2Application::SetTitle(const std::string& title)
{
    SDL_SetWindowTitle(mWindow, title.c_str());

    mTitle = title;
}
//-------------------------------------------------------------------------------
void TSdl2Application::SetSize(int width, int height)
{
    SDL_SetWindowSize(mWindow, width, height);

    mWidth = width;
    mHeight = height;
}
//-------------------------------------------------------------------------------
void TSdl2Application::SetPosition(int x, int y)
{
    SDL_SetWindowPosition(mWindow, x, y);

    mX = x;
    mY = y;
}
//-------------------------------------------------------------------------------
const std::string TSdl2Application::GetTitle()
{
    return SDL_GetWindowTitle(mWindow);
}
//-------------------------------------------------------------------------------
int TSdl2Application::GetWidth() const
{
    int w, h;
    SDL_GetWindowSize(mWindow, &w, &h);
    return w;
}
//-------------------------------------------------------------------------------
int TSdl2Application::GetHeight() const
{
    int w, h;
    SDL_GetWindowSize(mWindow, &w, &h);
    return h;
}
//-------------------------------------------------------------------------------
int TSdl2Application::GetX() const
{
    int x, y;
    SDL_GetWindowPosition(mWindow, &x, &y);
    return x;
}
//-------------------------------------------------------------------------------
int TSdl2Application::GetY() const
{
    int x, y;
    SDL_GetWindowPosition(mWindow, &x, &y);
    return y;
}
//-------------------------------------------------------------------------------
bool TSdl2Application::GenerateInputEvents()
{
    mKeyMouseEventHandler.ClearEvents();

    bool done = false;
    std::list<SDL_Event> newEvents;

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            done = true;
        }
        if ((event.type == SDL_WINDOWEVENT) &&
            (event.window.event == SDL_WINDOWEVENT_CLOSE) &&
            (event.window.windowID == SDL_GetWindowID(mWindow))) {
            done = true;
        }

        newEvents.push_back(event);
    }

    if (newEvents.size() == 0) {
        return !done;
    }

    std::list<SDL_Event> afterGuiEvents;
    ApplyInputEventsToGui(newEvents, afterGuiEvents);

    for (auto& event : afterGuiEvents) {
        mKeyMouseEventHandler.AddSdl2Event(event);
    }

    return !done;
}
//-------------------------------------------------------------------------------
void TSdl2Application::Draw()
{
    Render();

    SDL_GL_SwapWindow(mWindow);
}
//-------------------------------------------------------------------------------
void TSdl2Application::Done()
{
    SDL_GL_DeleteContext(mCtx);
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);

    SDL_Quit();
}
//-------------------------------------------------------------------------------
const std::string TSdl2Application::GetLastError() const
{
    return SDL_GetError();
}
//-------------------------------------------------------------------------------
void TSdl2Application::SetKeyMouseEventContainer(TKeyMouseEventContainer* pKeyMouseEventContainer)
{
    mKeyMouseEventContainer = pKeyMouseEventContainer;
    mKeyMouseEventHandler.SetContainer(mKeyMouseEventContainer);
}
//-------------------------------------------------------------------------------
TKeyMouseEventContainer* TSdl2Application::GetKeyMouseEventContainer() const
{
    return mKeyMouseEventContainer;
}
//-------------------------------------------------------------------------------
SDL_GLContext TSdl2Application::GetSdlCtx() const
{
    return mCtx;
}
//-------------------------------------------------------------------------------
SDL_Window* TSdl2Application::GetSdlWindow() const
{
    return mWindow;
}
//-------------------------------------------------------------------------------
