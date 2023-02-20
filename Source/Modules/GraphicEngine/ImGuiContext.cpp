
/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <string>

#include "ImGuiContext.h"

#include "imgui/imgui_internal.h"

#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

#include <glad/glad.h>

using namespace nsGraphicEngine;

void TImGuiContext::Init(SDL_Window* window, void* sdl_gl_context)
{
    mImGuiCtx = ImGui::CreateContext();

    ImGui::SetCurrentContext(mImGuiCtx);

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking

    io.IniFilename = nullptr;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();

    const std::string GLSL_VERSION = "#version 130";

    // Setup Platform/Renderer backends
    ImGui_ImplSDL2_InitForOpenGL(window, sdl_gl_context);
    ImGui_ImplOpenGL3_Init(GLSL_VERSION.c_str());
}
//-------------------------------------------------------------------------------
void TImGuiContext::SetupGuiViewport(int winWidth, int winHeight, float x, float y, float width, float height)
{
    mWindowWidth = winWidth;
    mWindowHeight = winHeight;
    mX = x;
    mY = y;
    mWidth = width;
    mHeight = height;

    ApplyViewportParams();
}
//-------------------------------------------------------------------------------
void TImGuiContext::ApplyViewportParams()
{
    mImGuiCtx->IO.DisplaySize = { mWidth, mHeight };

    auto v = mImGuiCtx->Viewports[0];
    v->Size = { mWidth, mHeight };
    v->WorkSize = { mWidth, mHeight };
    v->DrawDataP.DisplaySize = { mWidth, mHeight };
}
//-------------------------------------------------------------------------------
void TImGuiContext::Render()
{
    ImGui::SetCurrentContext(mImGuiCtx);

    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();

    ImGui::NewFrame();

    for (auto pRenderable : mRenderables) {
        pRenderable->Render();
    }

    ImGui::Render();

    ApplyViewportParams();

    auto pDrawData = ImGui::GetDrawData();
    ImGui_ImplOpenGL3_RenderDrawData(pDrawData);
}
//-------------------------------------------------------------------------------
void TImGuiContext::HandleEvents(const std::list<SDL_Event>& events, std::list<SDL_Event>& unusedEvents)
{
    ImGui::SetCurrentContext(mImGuiCtx);

    for (SDL_Event event : events) {
        CorrectEvent(event);

        auto applyed = ImGui_ImplSDL2_ProcessEvent(&event);

        auto& io = ImGui::GetIO();

        if (!applyed || (!io.WantCaptureMouse && !io.WantCaptureKeyboard)) {
            unusedEvents.push_back(event);
        }
    }
}
//--------------------------------------------------------------------------------------------
void TImGuiContext::AddRender(IRenderable* pRenderable)
{
    mRenderables.push_back(pRenderable);
}
//--------------------------------------------------------------------------------------------
void TImGuiContext::RemoveRender(IRenderable* pRenderable)
{
    mRenderables.remove(pRenderable);
}
//--------------------------------------------------------------------------------------------
void TImGuiContext::CorrectEvent(SDL_Event& event)
{
    float dY = mWindowHeight - (mY + mHeight);

    switch (event.type) {
        case SDL_MOUSEMOTION:
        {
            event.motion.x -= mX;
            event.motion.y -= dY;
            //event.motion.xrel -= xOffset;
            //event.motion.yrel -= yOffset;
            break;
        }
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
        {
            event.button.x -= mX;
            event.button.y -= dY;
            break;
        }
    }
}
//--------------------------------------------------------------------------------------------