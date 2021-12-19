/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "CallBackRegistrator.h"
#include "IGraphicEngineModule.h"

#include "BeginGraphicFeature.h"
#include "EndGraphicFeature.h"

namespace nsTornadoEngine
{
    class DllExport TGraphicEngineModule : public IGraphicEngineModule
    {
        std::shared_ptr<nsGraphicEngine::TGraphicEngine_Ogre_ImGui> mGE;

        nsGraphicWrapper::TBeginGraphicFeature mBeginFeature;
        nsGraphicWrapper::TEndGraphicFeature mEndFeature;

        nsImGuiWidgets::TDialogStack mDialogStack;
    public:
        TGraphicEngineModule();

        bool StartEvent() override;
        void ModuleWork() override;
        void StopEvent() override;

        nsGraphicEngine::TGraphicEngine_Ogre_ImGui* GetGE() override;
        void SetGE(nsGraphicEngine::TGraphicEngine_Ogre_ImGui* pGE) override;

        nsImGuiWidgets::TDialogStack* GetDialogStack() override;
    protected:

    };
}