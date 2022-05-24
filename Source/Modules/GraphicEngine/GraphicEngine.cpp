/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngine.h"
#include "IRenderable.h"
#include "GraphicEngineContext.h"

using namespace nsGraphicEngine;

TGraphicEngineContext* TGraphicEngine::CreateContext(PipeLineType pipeLineType)
{
    auto pCtx = new TGraphicEngineContext();
    pCtx->Init(this);
    mContexts.push_back(pCtx);
    return pCtx;
}
//---------------------------------------------------------------------
void TGraphicEngine::DestroyContext(TGraphicEngineContext* pCtx)
{
    mContexts.remove(pCtx);
    delete pCtx;
}
//---------------------------------------------------------------------
void TGraphicEngine::Render() 
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (auto& ctx : mContexts) {
        ctx->Render();
    }
}
//---------------------------------------------------------------------
void TGraphicEngine::ApplyInputEventsToGui(const std::list<SDL_Event>& events, std::list<SDL_Event>& unusedEvents)
{
    bool isApplyEventsByActive = false;
    std::list<SDL_Event> allUnusedEvents;
    if (mActiveCtx) {
        mActiveCtx->HandleEvents(events, allUnusedEvents);

        isApplyEventsByActive = (events.size() != allUnusedEvents.size());

        if (isApplyEventsByActive) {
            unusedEvents = allUnusedEvents;
        }
    }

    TGraphicEngineContext* newActiveCtx = nullptr;

    for (auto& ctx : mContexts) {

        if (mActiveCtx == ctx) {
            continue;
        }
        allUnusedEvents.clear();
        ctx->HandleEvents(events, allUnusedEvents);

        auto isApplyEvents = (events.size() != allUnusedEvents.size());

        if (isApplyEventsByActive && isApplyEvents) {
            //BL_ASSERT();
        }

        if (isApplyEvents) {
            if (newActiveCtx != nullptr) {
                //BL_ASSERT();
            }
            newActiveCtx = ctx;
            unusedEvents = allUnusedEvents;
        }
    }

    if (!isApplyEventsByActive) {
        mActiveCtx = nullptr;
    }

    if (newActiveCtx) {
        mActiveCtx = newActiveCtx;
    }

    if (mActiveCtx == nullptr) {
        unusedEvents = events;
    }
}
//---------------------------------------------------------------------

 