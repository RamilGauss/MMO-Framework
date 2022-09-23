/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SystemViewer.h"

#include "GraphicEngine/imgui/imgui_internal.h"

using namespace nsTornadoEngine;

void TSystemViewer::Render()
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
void TSystemViewer::Init()
{
    if (!mIsNeedInited) {
        return;
    }

    mIsNeedInited = false;

    //auto& componentNames = *(Project()->mScenePartAggregator->mComponents->mTypeInfo->GetTypeNameList());
    //for (auto& fullComponentName : componentNames) {

    //    TComponentType componentType;

    //    componentType.componentName = fullComponentName;
    //    Project()->mScenePartAggregator->mComponents->mTypeInfo->ConvertNameToType(fullComponentName, componentType.rtti);

    //    mComponentTypes.insert({ fullComponentName, componentType });
    //}
}
//----------------------------------------------------------------------------------------------------------------
void TSystemViewer::UpdatelModel()
{

}
//----------------------------------------------------------------------------------------------------------------
void TSystemViewer::RenderModel()
{

}
//----------------------------------------------------------------------------------------------------------------
void TSystemViewer::RenderFilterSearching()
{

}
//----------------------------------------------------------------------------------------------------------------
