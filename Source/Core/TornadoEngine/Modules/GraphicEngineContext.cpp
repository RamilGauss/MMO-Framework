/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngineContext.h"

using namespace nsTornadoEngine;

void TGraphicEngineContext::Init(nsGraphicEngine::TGraphicEngine_Ogre_ImGui* pGE)
{
    mGE = pGE;

    // Context
    //auto keyMouse = Modules()->KeyMouse();
    //mGE->SetKeyMouseEventContainer(keyMouse);
    //nsImGuiWidgets::TWidget::SetInputContainer(keyMouse);

    ////###
    //// Костыль
    //mGE->AddRender(&mDialogStack);
    //###
}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::AddRender(nsGraphicEngine::IRenderable* pRenderable)
{

}
//--------------------------------------------------------------------------------------------
void TGraphicEngineContext::RemoveRender(nsGraphicEngine::IRenderable* pRenderable)
{

}
//--------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------