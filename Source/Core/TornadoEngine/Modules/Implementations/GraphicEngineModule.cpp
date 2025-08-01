/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/BL_Debug.h"
#include "Base/Common/PathOperations.h"

#include "ImGuiWidgets/Include/Widget.h"

#include "TornadoEngine/TimeSliceEngine/ProjectConfigContainer.h"
#include "TornadoEngine/Modules/Common/Modules.h"
#include "TornadoEngine/Modules/Implementations/GraphicEngineModule.h"

using namespace nsGraphicEngine;
using namespace nsTornadoEngine; 
using namespace nsBase;

TGraphicEngineModule::TGraphicEngineModule()
{
    mGE.reset(new TGraphicEngine);
}
//---------------------------------------------------------------------------------
void TGraphicEngineModule::ModuleWork()
{
    mGE->SetupViewports();

    mGE->GenerateInputEvents();

    mGE->Draw();
}
//---------------------------------------------------------------------------------
TGraphicEngine* TGraphicEngineModule::GetGE()
{
    return mGE.get();
}
//---------------------------------------------------------------------------------
bool TGraphicEngineModule::ModuleStartEvent()
{
    auto entMng = Modules()->EntMng();

    auto beginSlotIndex = GetBeginLogicSlotManager()->CreateSlot(entMng);
    GetBeginLogicSlotManager()->SetCurrentSlotIndex(beginSlotIndex);
    GetBeginLogicSlotManager()->AddSystem(&mBeginFeature);

    auto endSlotIndex = GetEndLogicSlotManager()->CreateSlot(entMng);
    GetEndLogicSlotManager()->SetCurrentSlotIndex(endSlotIndex);
    GetEndLogicSlotManager()->AddSystem(&mEndFeature);
    
    mGE->SetPosition( 100, 100);   // TODO: get from config
    mGE->SetSize( 800, 600);       // TODO: get from config
    mGE->SetTitle("MMO Framework");// TODO: get from config
    mGE->Init();

    // Input
    auto keyMouse = Modules()->KeyMouse();
    mGE->SetKeyMouseEventContainer(keyMouse);
    nsImGuiWidgets::TWidget::SetInputContainer(keyMouse);

    return true;
}
//---------------------------------------------------------------------------------
void TGraphicEngineModule::StopEvent()
{
    mGE->Done();
    mGE.reset();
}
//---------------------------------------------------------------------------------
void TGraphicEngineModule::SetGE(nsGraphicEngine::TGraphicEngine* pGE)
{

}
//---------------------------------------------------------------------------------
IContext* TGraphicEngineModule::CreateContext()
{
    auto pModuleCtx = new TGraphicEngineContext();

    auto pCtx = mGE->CreateContext(TGraphicEngine::PipeLineType::SIMPLE);

    pModuleCtx->SetGraphicEngineContext(pCtx);

    return pModuleCtx;
}
//---------------------------------------------------------------------------------
void TGraphicEngineModule::DestroyContext(IContext* pCtx)
{
    mGE->DestroyContext(((TGraphicEngineContext*)pCtx)->GetGraphicEngineContext());

    delete pCtx;
}
//---------------------------------------------------------------------------------
