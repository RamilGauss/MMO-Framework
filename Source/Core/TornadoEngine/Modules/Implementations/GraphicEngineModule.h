/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/CallBackRegistrator.h"

#include "TornadoEngine/Modules/Interfaces/IGraphicEngineModule.h"

#include "TornadoEngine/Features/Graphic/Begin/BeginGraphicFeature.h"
#include "TornadoEngine/Features/Graphic/End/EndGraphicFeature.h"

namespace nsTornadoEngine
{
    class DllExport TGraphicEngineModule : public IGraphicEngineModule
    {
        std::shared_ptr<nsGraphicEngine::TGraphicEngine> mGE;

        nsGraphicWrapper::TBeginGraphicFeature mBeginFeature;
        nsGraphicWrapper::TEndGraphicFeature mEndFeature;
    public:
        TGraphicEngineModule();

        bool ModuleStartEvent() override;
        void ModuleWork() override;
        void StopEvent() override;

        nsGraphicEngine::TGraphicEngine* GetGE() override;
        void SetGE(nsGraphicEngine::TGraphicEngine* pGE) override;
    protected:
        IContext* CreateContext() override;
        void DestroyContext(IContext* pCtx) override;
    };
}