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

TComponentViewer::TComponentViewer()
{
    std::srand(std::time(nullptr));

    for (int i = 0; i < 10; i++) {

        ImVec4 color;

        color.x = std::rand() * 0.3f / RAND_MAX;
        color.y = std::rand() * 0.3f / RAND_MAX;
        color.z = std::rand() * 0.3f / RAND_MAX;

        color.w = 1.0f;

        mColors.push_back(color);
    }
}
//----------------------------------------------------------------------------------------------------------------
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
    }

    ImGui::SetWindowSize(mSize);

    bool isOpen = true;
    ImGui::Begin("Component viewer", &isOpen, (int)ImGuiWindowFlags_NoDocking);

    ImGui::Combo("EntityManager", &mCurrentEntityManagerIndex, entMngItems.c_str());
    ImGui::Text("Count: %d, FPS=%f", mModel.nameEntities.size(), ImGui::GetIO().Framerate);

    auto entitiesId = ImGui::GetID("Entities");

    ImGui::SetCursorPos({ 0,70 });
    ImGui::BeginChildFrame(entitiesId, { 200, 500 });

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
    ImGui::SetCursorPos({ 200, 70 });
    ImGui::BeginChildFrame(componentsId, { 500, 500 });

    int colorIndex = 0;
    for (auto& nsComponentName : mModel.nsSelectedEntityComponents) {

        auto color = mColors[colorIndex];
        colorIndex++;
        colorIndex %= mColors.size();

        ImGui::Text(nsComponentName.first.c_str());

        for (auto& component : nsComponentName.second) {
            ImGui::PushStyleColor((int)ImGuiCol_Header, color);
            auto openTree = ImGui::TreeNodeEx(component.typeName.c_str(), ImGuiTreeNodeFlags_Framed);
            ImGui::PopStyleColor();
            if (openTree) {
                ImGui::Text(component.content.c_str());
                ImGui::TreePop();
            }
        }
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

                auto pComponent = Project()->mScenePartAggregator->mComponents->mEntMng->ViewComponent(eid, cid);
                std::string content;
                Project()->mScenePartAggregator->mComponents->mJson->Serialize((void*)pComponent, content, cid);

                std::list<std::string> lines;
                SeparateToLines(content, lines);
                
                if (lines.size() > 0) {
                    lines.pop_front();
                }
                if (lines.size() > 0) {
                    lines.pop_back();
                }
                
                content = "";
                for (auto& line : lines) {
                    content += line.substr(4);
                }

                if (content.size() == 0) {
                    content = "Tag component";
                }

                TComponent component;
                component.typeName = componentName;
                component.content = content;
                fit->second.push_back(component);
            }
        }

        mModel.nameEntities.push_back(entity);
    }
}
//----------------------------------------------------------------------------------------------------------------
void TComponentViewer::SeparateToLines(const std::string& content, std::list<std::string>& lines)
{
    size_t offset = 0;
    size_t lastRetIndex = 0;

    const std::string CRCRLF = "\n";

    while (true) {
        auto retIndex = content.find(CRCRLF, offset);

        if (retIndex == std::string::npos) {
            lines.push_back(content.substr(offset, content.size() - lastRetIndex));
            return;
        }

        retIndex += CRCRLF.size();

        auto delta = retIndex - lastRetIndex;

        lines.push_back(content.substr(offset, delta));

        offset += delta;
        lastRetIndex = retIndex;
    }
}
//----------------------------------------------------------------------------------------------------------------