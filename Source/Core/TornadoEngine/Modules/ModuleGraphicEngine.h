/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "CallBackRegistrator.h"
#include "DstModule.h"
#include "GraphicEngine/GraphicEngine_Ogre_ImGui.h"

namespace nsTornadoEngine
{
    class DllExport TModuleGraphicEngine : public TDstModule
    {
        std::shared_ptr<nsGraphicEngine::TGraphicEngine_Ogre_ImGui> mGE;
    public:
        TModuleGraphicEngine();

        bool StartEvent() override;
        void Work() override;
        void StopEvent() override;

        nsGraphicEngine::TGraphicEngine_Ogre_ImGui* GetGE();
    protected:

    };
}