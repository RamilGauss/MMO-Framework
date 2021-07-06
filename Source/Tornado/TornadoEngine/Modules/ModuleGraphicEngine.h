/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "CallBackRegistrator.h"
#include "ModuleComponent.h"
#include "GraphicEngine/GraphicEngine_Ogre_ImGui.h"

class DllExport TModuleGraphicEngine : public TModuleComponent
{
    std::shared_ptr<nsGraphicEngine::TGraphicEngine_Ogre_ImGui> mGE;
public:
    TModuleGraphicEngine();

    virtual void StartEvent();
    virtual bool WorkInherit();
    virtual void StopEvent();

    nsGraphicEngine::TGraphicEngine_Ogre_ImGui* GetGE();
protected:

};
