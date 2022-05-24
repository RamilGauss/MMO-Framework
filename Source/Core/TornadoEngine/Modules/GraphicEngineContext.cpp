/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngineContext.h"

//--------------------------------------------------------------------------------------------
nsImGuiWidgets::TDialogStack* nsTornadoEngine::TGraphicEngineContext::GetDialogStack()
{
    return &mDialogStack;
}
//---------------------------------------------------------------------------------
nsGraphicEngine::TGraphicEngineContext* nsTornadoEngine::TGraphicEngineContext::GetGraphicEngineContext() const
{
    return mGraphicEngineContext;
}
//---------------------------------------------------------------------------------
void nsTornadoEngine::TGraphicEngineContext::SetGraphicEngineContext(nsGraphicEngine::TGraphicEngineContext* pCtx)
{
    pCtx->AddRender(&mDialogStack);

    mGraphicEngineContext = pCtx;
}
//---------------------------------------------------------------------------------