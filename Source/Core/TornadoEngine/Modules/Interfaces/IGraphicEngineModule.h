/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "GraphicEngine/GraphicEngine.h"

#include "TornadoEngine/Modules/Contexts/GraphicEngineContext.h"
#include "TornadoEngine/Modules/Common/IContextManager.h"
#include "TornadoEngine/Modules/Common/LogicWrapperModule.h"

namespace nsTornadoEngine
{
    class DllExport IGraphicEngineModule : public TLogicWrapperModule, public IContextManager
    {
    public:
        virtual nsGraphicEngine::TGraphicEngine* GetGE() = 0;
        virtual void SetGE(nsGraphicEngine::TGraphicEngine* pGE) = 0;
    };
}