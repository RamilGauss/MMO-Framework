/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "DstModule.h"
#include "GraphicEngine/GraphicEngine_Ogre_ImGui.h"

namespace nsTornadoEngine
{
    class DllExport IGraphicEngineModule : public TDstModule
    {
    public:
        virtual nsGraphicEngine::TGraphicEngine_Ogre_ImGui* GetGE() = 0;
        virtual void SetGE(nsGraphicEngine::TGraphicEngine_Ogre_ImGui* pGE) = 0;
    };
}