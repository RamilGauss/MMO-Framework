/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "GraphicEngineModule.h"
#include "BL_Debug.h"
#include "ProjectConfigContainer.h"
#include "PathOperations.h"
#include "Modules.h"
#include "ImGuiWidgets/include/Widget.h"

using namespace nsGraphicEngine;
using namespace nsTornadoEngine; 
using namespace nsBase;

TGraphicEngineModule::TGraphicEngineModule()
{
    mGE.reset(new TGraphicEngine_Ogre_ImGui);
    mGE->SetSelfID(0);
    mGE->SetDstObject(this);
}
//---------------------------------------------------------------------------------
void TGraphicEngineModule::ModuleWork()
{
    mGE->Work();
}
//---------------------------------------------------------------------------------
TGraphicEngine_Ogre_ImGui* TGraphicEngineModule::GetGE()
{
    return mGE.get();
}
//---------------------------------------------------------------------------------
bool TGraphicEngineModule::StartEvent()
{
    auto resources = Project()->mResources.graphicEngine;
    auto resPath = Project()->GetResourcesAbsPath();
    resPath = TPathOperations::FileDirPath(resPath);
    auto pluginCfg = TPathOperations::CalculatePathBy(resPath, resources.pluginsCfg.Get());
    auto ogreCfg = TPathOperations::CalculatePathBy(resPath, resources.ogreCfg.Get());
    // настройка перед запуском
    if (mGE->InitOGRE(pluginCfg, ogreCfg) == false) {
        return false;
    }
    // пути для ресурсов графического движка
    for (auto& vtTypePath : resources.resources) {
        for (auto& type : vtTypePath.second) {
            auto absPath = TPathOperations::CalculatePathBy(resPath, type);
            mGE->AddResource(absPath, vtTypePath.first);
        }
    }

    mGE->InitMyGUI();

    auto keyMouse = Modules()->KeyMouse();
    mGE->SetKeyMouseEventContainer(keyMouse);
    nsImGuiWidgets::TWidget::SetInputContainer(keyMouse);
    return true;
}
//---------------------------------------------------------------------------------
void TGraphicEngineModule::StopEvent()
{
    mGE.reset();
}
//---------------------------------------------------------------------------------
void TGraphicEngineModule::SetGE(nsGraphicEngine::TGraphicEngine_Ogre_ImGui* pGE)
{

}
//---------------------------------------------------------------------------------
