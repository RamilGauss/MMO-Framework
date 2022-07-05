/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "EntityViewer.h"

#include "ProjectConfigContainer.h"

#include "SingletonManager.h"
#include "ECS/include/EntityManagerMaster.h"
#include "ECS/include/EntityManager.h"

#include "GuidComponent.h"
#include "NameComponent.h"

#include "GraphicEngine/imgui/imgui_internal.h"

using namespace nsTornadoEngine;

TEntityViewer::TEntityViewer()
{
    mColors.push_back({ 0.3f, 0.3f, 0.0f, 1.0f });
    mColors.push_back({ 0.4f, 0.1f, 0.0f, 1.0f });
    mColors.push_back({ 0.1f, 0.1f, 0.3f, 1.0f });
    mColors.push_back({ 0.3f, 0.1f, 0.3f, 1.0f });
    mColors.push_back({ 0.1f, 0.3f, 0.1f, 1.0f });
    mColors.push_back({ 0.0f, 0.3f, 0.2f, 1.0f });
    mColors.push_back({ 0.0f, 0.3f, 0.3f, 1.0f });
    mColors.push_back({ 0.0f, 0.0f, 0.3f, 1.0f });
    mColors.push_back({ 0.3f, 0.3f, 0.3f, 1.0f });
}
//----------------------------------------------------------------------------------------------------------------
void TEntityViewer::Init()
{
    if (!mIsNeedInited) {
        return;
    }

    mIsNeedInited = false;

    auto& componentNames = *(Project()->mScenePartAggregator->mComponents->mTypeInfo->GetTypeNameList());
    for (auto& fullComponentName : componentNames) {

        TComponentType componentType;

        componentType.componentName = fullComponentName;
        Project()->mScenePartAggregator->mComponents->mTypeInfo->ConvertNameToType(fullComponentName, componentType.rtti);

        mComponentTypes.insert({ fullComponentName, componentType });
    }
}
//----------------------------------------------------------------------------------------------------------------
void TEntityViewer::Render()
{
    Init();

    auto t = ImGui::GetTime();
    auto delta = t - mLastTimeUpdateModel;

    if (delta > 0.1) {
        UpdatelModel();
        mLastTimeUpdateModel = t;
    }

    RenderModel();
}
//----------------------------------------------------------------------------------------------------------------
void TEntityViewer::UpdateComponents()
{
    mComponentTypesMinusFilter = mComponentTypes;

    for (auto& component : mComponentFilter) {
        mComponentTypesMinusFilter.erase(component.first);
    }

    mNsComponentsMap.clear();

    for (auto& component : mComponentTypesMinusFilter) {

        if (component.first.find(mInputFilterValue) == std::string::npos) {
            continue;
        }

        auto fit = mNsComponentsMap.find(component.second.GetNs());
        if (fit == mNsComponentsMap.end()) {
            mNsComponentsMap.insert({ component.second.GetNs(), {} });
            fit = mNsComponentsMap.find(component.second.GetNs());
        }

        fit->second.push_back(component.second);
    }
}
//----------------------------------------------------------------------------------------------------------------
bool TEntityViewer::IsCanApplyComponentToFilter(const std::string& inputFilterValue)
{
    return mComponentTypesMinusFilter.find(inputFilterValue) != mComponentTypesMinusFilter.end();
}
//----------------------------------------------------------------------------------------------------------------
int InputTextCallback(ImGuiInputTextCallbackData* data)
{
    return 0;
}
//----------------------------------------------------------------------------------------------------------------
void TEntityViewer::RenderFilterSearching()
{
    // Search and add to the filter
    ImGui::Text("Search:");
    ImGui::SameLine();

    ImGui::PushID("SearchInputText");
    auto isInputTextEdited = ImGui::InputText("", mInputFilterValue, sizeof(mInputFilterValue), (int)ImGuiInputTextFlags_CallbackEdit, InputTextCallback);
    if (isInputTextEdited) {
        UpdateComponents();
    }
    ImGui::PopID();

    auto isActiveInputText = ImGui::IsItemActive();

    auto inputTextId = ImGui::GetItemID();
    ImVec2 textPos{ ImGui::GetItemRectMin().x, ImGui::GetItemRectMax().y };


    bool disabledButton = !IsCanApplyComponentToFilter(mInputFilterValue);

    if (disabledButton) {
        ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
        ImGui::PushStyleVar(ImGuiStyleVar_Alpha, ImGui::GetStyle().Alpha * 0.5f);
    }
    ImGui::SameLine();
    if (ImGui::Button("Add")) {
        auto component = mComponentTypesMinusFilter.find(mInputFilterValue)->second;
        mComponentFilter.insert({ mInputFilterValue, component });

        UpdateComponents();

        mInputFilterValue[0] = '\0';
    }

    if (disabledButton) {
        ImGui::PopItemFlag();
        ImGui::PopStyleVar();
    }

    if (isInputTextEdited && strlen(mInputFilterValue)) {
        ImGui::OpenPopup("##SearchComponent");
    }

    if (strlen(mInputFilterValue) == 0) {
        ImGui::CloseCurrentPopup();
    }

    ImGui::PushItemWidth(200);
    ImGui::SetNextWindowPos(textPos, ImGuiCond_Always);
    if (ImGui::BeginPopup("##SearchComponent", ImGuiWindowFlags_ChildWindow)) {
        ImGui::PushAllowKeyboardFocus(false);

        for (auto& components : mNsComponentsMap) {

            if (ImGui::BeginMenu(components.first.c_str())) {

                for (auto& component : components.second) {
                    if (ImGui::Selectable(component.GetTypeName().c_str())) {
                        strcpy(mInputFilterValue, component.componentName.c_str());
                    }
                }
                ImGui::EndMenu();
            }
        }

        ImGui::PopAllowKeyboardFocus();
        ImGui::EndPopup();
    }

    ImGui::SameLine();
    auto isClearFilter = ImGui::Button("Clear filters");
    if (isClearFilter) {
        mComponentFilter.clear();
    }

    ImGui::BeginChildFrame(ImGui::GetID("Applyed components"), {500,40});

    int i = 0;
    auto componentFilter = mComponentFilter;
    for (auto& component : componentFilter) {
        
        std::string s = component.second.GetNs() + "\n" + component.second.GetTypeName();

        auto isRemoveFilter = ImGui::Button(s.c_str());
        if (i < componentFilter.size()) {
            ImGui::SameLine();
        }
        i++;

        if (isRemoveFilter) {
            mComponentFilter.erase(component.first);
        }
    }
    ImGui::EndChildFrame();
}
//----------------------------------------------------------------------------------------------------------------
void TEntityViewer::RenderModel()
{
    std::string entMngItems;
    for (int i = 0; i < mEntMngCount; i++) {
        entMngItems += std::to_string(i) + '\0';
    }

    ImGui::SetWindowSize(mSize);

    bool isOpen = true;
    ImGui::Begin("Entity viewer", &isOpen, (int)ImGuiWindowFlags_NoDocking);

    ImGui::Text("EntityManager:"); 
    ImGui::SameLine();
    
    ImGui::SetNextItemWidth(50);
    ImGui::PushID("EntityManagerCombo");
    ImGui::Combo("", &mCurrentEntityManagerIndex, entMngItems.c_str());
    ImGui::PopID();
    
    ImGui::SameLine();
    ImGui::Text("Count: %d, FPS=%f", mModel.nameEntities.size(), ImGui::GetIO().Framerate);

    // Search and add to the filter
    RenderFilterSearching();

    auto entitiesId = ImGui::GetID("Entities");

    ImGui::BeginChildFrame(entitiesId, {200, 450});

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
    ImGui::SameLine();
    ImGui::BeginChildFrame(componentsId, { 500, 450 });

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
void TEntityViewer::UpdatelModel()
{
    mModel.Clear();

    auto& entMngs = SingletonManager()->Get<nsECSFramework::TEntityManagerMaster>()->GetEntityManager();
    mEntMngCount = entMngs.size();

    auto entMng = entMngs[mCurrentEntityManagerIndex];
    std::list<nsECSFramework::TEntityID> eids;
    entMng->GetAllEntities(eids);

    for (auto& eid : eids) {

        auto isPassedByFilter = IsPassedByFilter(eid);
        if (!isPassedByFilter) {
            continue;
        }

        TEntity entity;

        entity.eid = eid;

        auto pNameComponent = entMng->ViewComponent<nsCommonWrapper::TNameComponent>(eid);
        entity.name = pNameComponent == nullptr ?
            std::to_string(eid) : entMng->ViewComponent<nsCommonWrapper::TNameComponent>(eid)->value;

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
void TEntityViewer::SeparateToLines(const std::string& content, std::list<std::string>& lines)
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
bool TEntityViewer::IsPassedByFilter(nsECSFramework::TEntityID eid)
{
    for (auto& filter : mComponentFilter) {
        auto has = Project()->mScenePartAggregator->mComponents->mEntMng->HasComponent(eid, filter.second.rtti);
        if (!has) {
            return false;
        }
    }

    return true;
}
//----------------------------------------------------------------------------------------------------------------
const std::string TEntityViewer::TComponentType::GetNs() const
{
    auto nsEndIndex = componentName.find("::");
    if (nsEndIndex != std::string::npos) {
        return componentName.substr(0, nsEndIndex);
    }
    return "";
}
//----------------------------------------------------------------------------------------------------------------
const std::string TEntityViewer::TComponentType::GetTypeName() const
{
    auto nsEndIndex = componentName.find("::");
    if (nsEndIndex != std::string::npos) {
        return componentName.substr(nsEndIndex + strlen("::"));
    }
    return componentName;
}
//----------------------------------------------------------------------------------------------------------------
