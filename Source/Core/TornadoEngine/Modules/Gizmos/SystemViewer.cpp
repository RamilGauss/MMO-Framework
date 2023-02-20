/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SystemViewer.h"

#include "GraphicEngine/imgui/imgui_internal.h"

#include "Modules.h"
#include "IGraphicEngineModule.h"
#include "ILogicModule.h"
#include "IPhysicEngineModule.h"
#include "IMMOEngineModule.h"
#include "INetTransportModule.h"
#include "ISoundEngineModule.h"
#include "IDataBaseModule.h"

#include "GuidGenerator.h"

using namespace nsTornadoEngine;

void TSystemViewer::Render()
{
    Init();

    UpdateStat();

    char str[1000];
    sprintf(str, "Dt = %d us, FPS = %.1f", (int)(mCommonSummaDt * 1'000'000.0), ImGui::GetIO().Framerate);
    mStat.SetText(str);

    mWindow.Render();
}
//----------------------------------------------------------------------------------------------------------------
void TSystemViewer::Init()
{
    if (!mIsNeedInited) {
        return;
    }

    mWindow.SetTitle("SystemViewer");
    mWindow.SetShow(true);
    mWindow.SetSize(mSize);

    mTreeView.SetLeftAnchor({ true, 8 });
    mTreeView.SetRightAnchor({ true, 8 });
    mTreeView.SetTopAnchor({ true, 45 });
    mTreeView.SetBottomAnchor({ true, 8 });
    mWindow.Add(&mTreeView);

    mStat.SetPosition({ 6, 20 });
    mStat.SetSize({ 200, 25 });
    mWindow.Add(&mStat);

    mRefresh.SetPosition({ 211, 20 });
    mRefresh.SetSize({ 60, 25 });
    mRefresh.SetTitle("Refresh");
    mRefresh.mOnClickCB.Register(this, [this](nsImGuiWidgets::TButton* pButton) { UpdateGui(); });
    mWindow.Add(&mRefresh);

    mIsNeedInited = false;

    auto graphic = nsTornadoEngine::Modules()->G();
    if (graphic != nullptr) {
        AddLogicWrapper(dynamic_cast<TLogicWrapperModule*>(graphic), "Graphic", { 0.4f, 0.1f, 0.1f, 1.0f });
    }

    auto logic = nsTornadoEngine::Modules()->L();
    if (logic != nullptr) {
        AddLogicModule(logic, "Logic", { 0.1f, 0.4f, 0.1f, 1.0f });
    }

    auto physic = nsTornadoEngine::Modules()->P();
    if (physic != nullptr) {
        AddLogicWrapper(dynamic_cast<TLogicWrapperModule*>(physic), "Physic", { 0.34f, 0.31f, 0.82f, 1.0f });
    }

    auto mmo = nsTornadoEngine::Modules()->MMO();
    if (mmo != nullptr) {
        AddLogicWrapper(dynamic_cast<TLogicWrapperModule*>(mmo), "MmoEngine", { 0.55f, 0.18f, 0.50f, 1.0f });
    }

    auto net = nsTornadoEngine::Modules()->Net();
    if (net != nullptr) {
        AddLogicWrapper(dynamic_cast<TLogicWrapperModule*>(net), "NetTransport", { 0.25f, 0.65f, 0.13f, 1.0f });
    }

    auto sound = nsTornadoEngine::Modules()->S();
    if (sound != nullptr) {
        AddLogicWrapper(dynamic_cast<TLogicWrapperModule*>(sound), "Sound", { 0.0f, 0.0f, 0.0f, 1.0f });
    }

    auto db = nsTornadoEngine::Modules()->DB();
    if (physic != nullptr) {
        AddLogicWrapper(dynamic_cast<TLogicWrapperModule*>(db), "DataBase", { 0.0f, 0.0f, 0.0f, 1.0f });
    }

    UpdateGui();
}
//----------------------------------------------------------------------------------------------------------------
void TSystemViewer::UpdateGui()
{
    mTreeView.RemoveAllNodes();
    for (auto& node : mNodes) {
        delete node;
    }

    mNodes.clear();
    mFeatureStatisticsMap.clear();
    mModuleNodeMap.clear();

    for (auto& module : mModules) {
        auto guid = TGuidGenerator::Generate();
        auto pNode = AddNode(module.name, guid, "root", &module.color);

        mModuleNodeMap.insert({ module.name, pNode });

        AddNode(module.beginFeatureMng, "Begin", guid);
        AddNode(module.logicFeatureMng, "Logic", guid);
        AddNode(module.endFeatureMng, "End", guid);
    }
}
//----------------------------------------------------------------------------------------------------------------
void TSystemViewer::UpdateStat()
{
    mCommonSummaDt = 0;

    for (auto& module : mModules) {
        double summaDt = 0;

        UpdateStat(module.beginFeatureMng, summaDt);
        UpdateStat(module.logicFeatureMng, summaDt);
        UpdateStat(module.endFeatureMng, summaDt);

        mCommonSummaDt += summaDt;

        auto moduleLastExecutionTime = module.pLogicWrapperModule->GetLastExecutionTime();
        if (module.stat.GetCount() > 1000) {
            module.stat.Exchange(moduleLastExecutionTime);
        } else {
            module.stat.Add(moduleLastExecutionTime);
        }

        auto fit = mModuleNodeMap.find(module.name);
        if (fit != mModuleNodeMap.end()) {

            auto moduleLastExecutionTime = module.stat.GetAverage() * 1'000'000.0;

            auto str = module.name + " Work=" + std::to_string((int)moduleLastExecutionTime) + " us, ECS dt=" + std::to_string((int)(summaDt * 1'000'000.0)) + " us";
            fit->second->SetTitle(str);
        }
    }
}
//----------------------------------------------------------------------------------------------------------------
void TSystemViewer::UpdateStat(TFeatureManager* pFeatureMng, double& summaDt)
{
    if (pFeatureMng == nullptr) {
        return;
    }

    double moduleSummaDt = 0;

    auto slotCount = pFeatureMng->GetSlotCount();
    for (int i = 0; i < slotCount; i++) {
        auto slot = pFeatureMng->GetSlotByIndex(i);
        UpdateStat(slot);

        auto fit = mFeatureStatisticsMap.find(slot);
        if (fit != mFeatureStatisticsMap.end()) {
            moduleSummaDt += fit->second.stat.GetAverage();

            auto dt = fit->second.stat.GetAverage() * 1'000'000.0;

            fit->second.pNode->SetTitle(slot->GetTypeName() + " " + std::to_string((int)dt) + " us");
        }
    }

    auto featureMngFit = mFeatureStatisticsMap.find(pFeatureMng);
    if (featureMngFit != mFeatureStatisticsMap.end()) {
        auto dt = moduleSummaDt * 1'000'000.0;
        featureMngFit->second.pNode->SetTitle(featureMngFit->second.name + " " + std::to_string((int)dt) + " us");
    }

    summaDt += moduleSummaDt;
}
//----------------------------------------------------------------------------------------------------------------
void TSystemViewer::UpdateStat(nsECSFramework::TFeature* pFeature)
{
    auto fit = mFeatureStatisticsMap.find(pFeature);
    if (fit != mFeatureStatisticsMap.end()) {
        auto& stat = fit->second.stat;
        if (stat.GetCount() > 1000) {
            stat.Exchange(pFeature->GetLastExecutionTime());
        } else {
            stat.Add(pFeature->GetLastExecutionTime());
        }

        auto executionTime = (int)(stat.GetAverage() * 1'000'000.0);
        auto title = pFeature->GetTypeName() + ", dt=" + std::to_string(executionTime) + " us";

        fit->second.pNode->SetTitle(title);
    }

    auto systems = pFeature->GetSystems();
    for (auto& system : systems) {
        auto isFeature = system->IsFeature();
        if (isFeature) {
            UpdateStat(dynamic_cast<nsECSFramework::TFeature*>(system));
        }
    }
}
//----------------------------------------------------------------------------------------------------------------
nsImGuiWidgets::TTreeNode* TSystemViewer::AddNode(const std::string& title, const std::string& id, const std::string& parentId,
    const ImVec4* pColor)
{
    auto pNode = new nsImGuiWidgets::TTreeNode();
    pNode->SetTitle(title);
    pNode->mStrId = id;
    pNode->mParentId = parentId;
    if (pColor != nullptr) {
        pNode->SetColor(*pColor);
    }

    mTreeView.AddNode(pNode);
    mNodes.push_back(pNode);

    return pNode;
}
//----------------------------------------------------------------------------------------------------------------
void TSystemViewer::AddNode(nsECSFramework::TFeature* pFeature, const std::string& parentId)
{
    auto guid = TGuidGenerator::Generate();

    auto pNode = AddNode(pFeature->GetTypeName(), guid, parentId);
    mFeatureStatisticsMap.insert({ pFeature , {pNode} });

    auto systems = pFeature->GetSystems();
    for (auto& system : systems) {
        auto isFeature = system->IsFeature();
        if (isFeature) {
            AddNode(dynamic_cast<nsECSFramework::TFeature*>(system), guid);
        } else {
            AddNode(system->GetTypeName(), TGuidGenerator::Generate(), guid);
        }
    }
}
//----------------------------------------------------------------------------------------------------------------
void TSystemViewer::AddNode(TFeatureManager* pFeatureMng, const std::string& name, const std::string& parentId)
{
    if (pFeatureMng == nullptr) {
        return;
    }

    auto guid = TGuidGenerator::Generate();
    auto pNode = AddNode(name, guid, parentId);
    mFeatureStatisticsMap.insert({ pFeatureMng , {pNode, name} });

    auto slotCount = pFeatureMng->GetSlotCount();
    for (int i = 0; i < slotCount; i++) {
        auto slot = pFeatureMng->GetSlotByIndex(i);
        AddNode(slot, guid);
    }
}
//----------------------------------------------------------------------------------------------------------------
void TSystemViewer::AddLogicWrapper(TLogicWrapperModule* pLogicWrapperModule, const std::string& name, const ImVec4& color)
{
    TModuleNode moduleNode;

    moduleNode.beginFeatureMng = pLogicWrapperModule->GetBeginLogicSlotManager();
    moduleNode.endFeatureMng = pLogicWrapperModule->GetEndLogicSlotManager();

    moduleNode.name = name;
    moduleNode.color = color;

    moduleNode.pLogicWrapperModule = pLogicWrapperModule;

    mModules.push_back(moduleNode);
}
//----------------------------------------------------------------------------------------------------------------
void TSystemViewer::AddLogicModule(ILogicModule* pLogicModule, const std::string& name, const ImVec4& color)
{
    TModuleNode moduleNode;

    moduleNode.beginFeatureMng = pLogicModule->GetBeginLogicSlotManager();
    moduleNode.logicFeatureMng = pLogicModule->GetWorkSlots();
    moduleNode.endFeatureMng = pLogicModule->GetEndLogicSlotManager();

    moduleNode.name = name;
    moduleNode.color = color;

    moduleNode.pLogicWrapperModule = dynamic_cast<TLogicWrapperModule*>(pLogicModule);

    mModules.push_back(moduleNode);
}
//----------------------------------------------------------------------------------------------------------------
