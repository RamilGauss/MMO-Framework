/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ModuleGraphicEngine.h"
#include "BL_Debug.h"

using namespace nsGraphicEngine;
using namespace nsTornadoEngine;

TModuleGraphicEngine::TModuleGraphicEngine()
{
    mGE.reset(new TGraphicEngine_Ogre_ImGui);
    mGE->SetSelfID(0);
    mGE->SetDstObject(this);
}
//---------------------------------------------------------------------------------
bool TModuleGraphicEngine::Work()
{
    return mGE->Work();
}
//---------------------------------------------------------------------------------
TGraphicEngine_Ogre_ImGui* TModuleGraphicEngine::GetGE()
{
    return mGE.get();
}
//---------------------------------------------------------------------------------
void TModuleGraphicEngine::StartEvent()
{
}
//---------------------------------------------------------------------------------
void TModuleGraphicEngine::StopEvent()
{
    mGE.reset();
}
//---------------------------------------------------------------------------------
