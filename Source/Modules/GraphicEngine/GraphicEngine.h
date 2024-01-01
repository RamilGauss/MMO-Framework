/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "Base/Common/TypeDef.h"

#include "Sdl2Application.h"

namespace nsGraphicEngine
{
    class TGraphicEngineContext;

    class DllExport TGraphicEngine : public TSdl2Application
    {
        std::list<TGraphicEngineContext*> mContexts;

        TGraphicEngineContext* mActiveCtx = nullptr;

    public:
        enum class PipeLineType
        {
            SIMPLE, 
            LIGHT,
            HDR,
        };

        TGraphicEngineContext* CreateContext(PipeLineType pipeLineType);
        void DestroyContext(TGraphicEngineContext* pCtx);

        void SetupViewports() override;

    protected:
        void Render() override;

        void ApplyInputEventsToGui(const std::list<SDL_Event>& events, std::list<SDL_Event>& unusedEvents) override;
    };
}