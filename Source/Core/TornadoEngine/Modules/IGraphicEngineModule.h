/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IContextManager.h"
#include "GraphicEngineContext.h"

#include "LogicWrapperModule.h"
#include "GraphicEngine/GraphicEngine_Ogre_ImGui.h"

#include <ImGuiWidgets/include/DialogStack.h>

namespace nsTornadoEngine
{
    class DllExport IGraphicEngineModule : public TLogicWrapperModule, public IContextManager<TGraphicEngineContext>
    {
    public:
        virtual nsGraphicEngine::TGraphicEngine_Ogre_ImGui* GetGE() = 0;
        virtual void SetGE(nsGraphicEngine::TGraphicEngine_Ogre_ImGui* pGE) = 0;

        virtual nsImGuiWidgets::TDialogStack* GetDialogStack() = 0;
    };
}