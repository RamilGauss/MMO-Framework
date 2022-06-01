/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ComponentViewer.h"

#include "ProjectConfigContainer.h"

#include "SingletonManager.h"
#include "ECS/include/EntityManagerMaster.h"
#include "ECS/include/EntityManager.h"

#include "GuidComponent.h"
#include "NameComponent.h"

using namespace nsTornadoEngine;

void TComponentViewer::Render()
{
    FillModel();
    RenderModel();
}
//----------------------------------------------------------------------------------------------------------------
void TComponentViewer::RenderModel()
{
    std::string entMngItems;

    for (int i = 0; i < mEntMngCount; i++) {
        entMngItems += std::to_string(i) + '\0';
        i++;
    }

    ImGui::SetWindowSize(mSize);

    ImGui::Begin("Component viewer");

    ImGui::Combo("EntityManager", &mCurrentEntityManagerIndex, entMngItems.c_str());

    ImGui::Text("Count: %d", mModel.nameEntities.size());

    auto entitiesId = ImGui::GetID("Entities");

    ImGui::SetCursorPos({ 0,100 });
    ImGui::BeginChildFrame(entitiesId, {300, 500});

    for (auto& entity : mModel.nameEntities) {

        bool selectedEid = false;
        if (entity.eid == mSelectedEid) {
            selectedEid = true;
        }

        ImGui::PushID(entity.eid);
        ImGui::Selectable(entity.name.c_str(), &selectedEid);
        ImGui::PopID();

        if (selectedEid) {
            mSelectedEid = entity.eid;
        }
    }

    ImGui::EndChildFrame();

    auto componentsId = ImGui::GetID("Components");
    ImGui::SetCursorPos({ 300, 100 });
    ImGui::BeginChildFrame(componentsId, { 300, 500 });

    for (auto& nsComponentName : mModel.nsSelectedEntityComponents) {

        auto componentId = ImGui::GetID(nsComponentName.first.c_str());
        ImGui::PushStyleColor((int)ImGuiCol_FrameBg, { 255, 0, 0, 255 });
        ImGui::BeginChild(componentId);

        for (auto& componentName : nsComponentName.second) {
            ImGui::Text(componentName.c_str());
        }

        ImGui::EndChildFrame();
        ImGui::PopStyleColor();
    }

    ImGui::EndChildFrame();

    ImGui::End();
}
//----------------------------------------------------------------------------------------------------------------
void TComponentViewer::FillModel()
{
    mModel.Clear();

    auto& entMngs = SingletonManager()->Get<nsECSFramework::TEntityManagerMaster>()->GetEntityManager();
    mEntMngCount = entMngs.size();

    auto entMng = entMngs[mCurrentEntityManagerIndex];
    auto& guidEids = *(entMng->GetByHas<nsCommonWrapper::TGuidComponent>());

    for (auto& eid : guidEids) {

        TEntity entity;

        entity.eid = eid;
        entity.name = entMng->ViewComponent<nsCommonWrapper::TNameComponent>(eid)->value;

        if (eid == mSelectedEid) {
            std::list<short> componentIndexes;
            entMng->GetComponentList(mSelectedEid, componentIndexes);
            for (auto& cid : componentIndexes) {

                std::string fullComponentName;
                Project()->mScenePartAggregator->mComponents->mTypeInfo->ConvertTypeToName(cid, fullComponentName);

                std::string ns;
                std::string componentName = fullComponentName;

                auto nsEndIndex = fullComponentName.find("::");
                if (nsEndIndex != std::string::npos) {
                    ns = fullComponentName.substr(0, nsEndIndex);
                    componentName = fullComponentName.substr(nsEndIndex + strlen("::"));
                }

                auto fit = mModel.nsSelectedEntityComponents.find(ns);
                if (fit == mModel.nsSelectedEntityComponents.end()) {
                    mModel.nsSelectedEntityComponents.insert({ ns, {} });
                    fit = mModel.nsSelectedEntityComponents.find(ns);
                }

                fit->second.push_back(componentName);
            }
        }

        mModel.nameEntities.push_back(entity);
    }
}
//----------------------------------------------------------------------------------------------------------------
