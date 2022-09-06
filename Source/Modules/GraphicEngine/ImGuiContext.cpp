
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
void TImGuiContext::Render(float glPosX, float glPosY, float width, float height)
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

    auto pDrawData = ImGui::GetDrawData();
    ImGui_ImplOpenGL3_RenderDrawData(pDrawData);
}
//-------------------------------------------------------------------------------
void TImGuiContext::HandleEvents(const std::list<SDL_Event>& events, std::list<SDL_Event>& unusedEvents,
    int xOffset, int yOffset)
{
    ImGui::SetCurrentContext(mImGuiCtx);

    for (SDL_Event event : events) {
        CorrectEvent(event, xOffset, yOffset);

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
void TImGuiContext::CorrectEvent(SDL_Event& event, int xOffset, int yOffset)
{
    switch (event.type) {
        case SDL_MOUSEMOTION:
        {
            event.motion.x -= xOffset;
            event.motion.y -= yOffset;
            event.motion.xrel -= xOffset;
            event.motion.yrel -= yOffset;
            break;
        }
        case SDL_MOUSEBUTTONDOWN:
        case SDL_MOUSEBUTTONUP:
        {
            event.button.x -= xOffset;
            event.button.y -= yOffset;
            break;
        }
    }
}
//--------------------------------------------------------------------------------------------
