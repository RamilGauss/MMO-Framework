/*
Project Component
*/
// ReflectionCodeGenerator version 2.4.2, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_10_29 11:16:44.826
	
#include "ComponentEntMng.h"

using namespace nsTornadoEditor;
using namespace nsECSFramework;

std::vector<TComponentEntMng::Data> TComponentEntMng::mRttiVector;

void TComponentEntMng::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::list<Data> datas;
    
    Data nsTornadoEditor_TAbsoluteFilePathComponent_Data;
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TAbsoluteFilePathComponent*)p)); };
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TAbsoluteFilePathComponent>(eid); };
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TAbsoluteFilePathComponent>(eid); };
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TAbsoluteFilePathComponent>(eid); };
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TAbsoluteFilePathComponent>(); };
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TAbsoluteFilePathComponent>();
    
    datas.push_back(nsTornadoEditor_TAbsoluteFilePathComponent_Data);
    
    Data nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data;
    nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TAssetAbsoluteFilePathComponent*)p)); };
    nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TAssetAbsoluteFilePathComponent>(eid); };
    nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TAssetAbsoluteFilePathComponent>(eid); };
    nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TAssetAbsoluteFilePathComponent>(eid); };
    nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TAssetAbsoluteFilePathComponent>(); };
    nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TAssetAbsoluteFilePathComponent>();
    
    datas.push_back(nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data);
    
    Data nsTornadoEditor_TEditorInfoTagComponent_Data;
    nsTornadoEditor_TEditorInfoTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TEditorInfoTagComponent*)p)); };
    nsTornadoEditor_TEditorInfoTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TEditorInfoTagComponent>(eid); };
    nsTornadoEditor_TEditorInfoTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TEditorInfoTagComponent>(eid); };
    nsTornadoEditor_TEditorInfoTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TEditorInfoTagComponent>(eid); };
    nsTornadoEditor_TEditorInfoTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TEditorInfoTagComponent>(); };
    nsTornadoEditor_TEditorInfoTagComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TEditorInfoTagComponent>();
    
    datas.push_back(nsTornadoEditor_TEditorInfoTagComponent_Data);
    
    Data nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data;
    nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent*)p)); };
    nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>(eid); };
    nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>(eid); };
    nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>(eid); };
    nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>(); };
    nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>();
    
    datas.push_back(nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data);
    
    Data nsTornadoEditor_TFileHierarchyWindowTagComponent_Data;
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TFileHierarchyWindowTagComponent*)p)); };
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TFileHierarchyWindowTagComponent>(eid); };
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TFileHierarchyWindowTagComponent>(eid); };
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TFileHierarchyWindowTagComponent>(eid); };
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TFileHierarchyWindowTagComponent>(); };
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowTagComponent>();
    
    datas.push_back(nsTornadoEditor_TFileHierarchyWindowTagComponent_Data);
    
    Data nsTornadoEditor_TFilePathNodeComponent_Data;
    nsTornadoEditor_TFilePathNodeComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TFilePathNodeComponent*)p)); };
    nsTornadoEditor_TFilePathNodeComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TFilePathNodeComponent>(eid); };
    nsTornadoEditor_TFilePathNodeComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TFilePathNodeComponent>(eid); };
    nsTornadoEditor_TFilePathNodeComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TFilePathNodeComponent>(eid); };
    nsTornadoEditor_TFilePathNodeComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TFilePathNodeComponent>(); };
    nsTornadoEditor_TFilePathNodeComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFilePathNodeComponent>();
    
    datas.push_back(nsTornadoEditor_TFilePathNodeComponent_Data);
    
    Data nsTornadoEditor_TInspectorWindowTagComponent_Data;
    nsTornadoEditor_TInspectorWindowTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TInspectorWindowTagComponent*)p)); };
    nsTornadoEditor_TInspectorWindowTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TInspectorWindowTagComponent>(eid); };
    nsTornadoEditor_TInspectorWindowTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TInspectorWindowTagComponent>(eid); };
    nsTornadoEditor_TInspectorWindowTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TInspectorWindowTagComponent>(eid); };
    nsTornadoEditor_TInspectorWindowTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TInspectorWindowTagComponent>(); };
    nsTornadoEditor_TInspectorWindowTagComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TInspectorWindowTagComponent>();
    
    datas.push_back(nsTornadoEditor_TInspectorWindowTagComponent_Data);
    
    Data nsTornadoEditor_TMainWindowPrefabGuidComponent_Data;
    nsTornadoEditor_TMainWindowPrefabGuidComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TMainWindowPrefabGuidComponent*)p)); };
    nsTornadoEditor_TMainWindowPrefabGuidComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TMainWindowPrefabGuidComponent>(eid); };
    nsTornadoEditor_TMainWindowPrefabGuidComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TMainWindowPrefabGuidComponent>(eid); };
    nsTornadoEditor_TMainWindowPrefabGuidComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TMainWindowPrefabGuidComponent>(eid); };
    nsTornadoEditor_TMainWindowPrefabGuidComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TMainWindowPrefabGuidComponent>(); };
    nsTornadoEditor_TMainWindowPrefabGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TMainWindowPrefabGuidComponent>();
    
    datas.push_back(nsTornadoEditor_TMainWindowPrefabGuidComponent_Data);
    
    Data nsTornadoEditor_TMainWindowTagComponent_Data;
    nsTornadoEditor_TMainWindowTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TMainWindowTagComponent*)p)); };
    nsTornadoEditor_TMainWindowTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TMainWindowTagComponent>(eid); };
    nsTornadoEditor_TMainWindowTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TMainWindowTagComponent>(eid); };
    nsTornadoEditor_TMainWindowTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TMainWindowTagComponent>(eid); };
    nsTornadoEditor_TMainWindowTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TMainWindowTagComponent>(); };
    nsTornadoEditor_TMainWindowTagComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TMainWindowTagComponent>();
    
    datas.push_back(nsTornadoEditor_TMainWindowTagComponent_Data);
    
    Data nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data;
    nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent*)p)); };
    nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>(eid); };
    nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>(eid); };
    nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>(eid); };
    nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>(); };
    nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>();
    
    datas.push_back(nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data);
    
    Data nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data;
    nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TObjectHierarchyWindowTagComponent*)p)); };
    nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TObjectHierarchyWindowTagComponent>(eid); };
    nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TObjectHierarchyWindowTagComponent>(eid); };
    nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TObjectHierarchyWindowTagComponent>(eid); };
    nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TObjectHierarchyWindowTagComponent>(); };
    nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowTagComponent>();
    
    datas.push_back(nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data);
    
    Data nsTornadoEditor_TProjectConfigComponent_Data;
    nsTornadoEditor_TProjectConfigComponent_Data.setFunc = [](TEntityManager* pEntMng, TEntityID eid, void* p){ pEntMng->SetComponent(eid, *((nsTornadoEditor::TProjectConfigComponent*)p)); };
    nsTornadoEditor_TProjectConfigComponent_Data.viewFunc = [](TEntityManager* pEntMng, TEntityID eid){ return (void*) pEntMng->ViewComponent<nsTornadoEditor::TProjectConfigComponent>(eid); };
    nsTornadoEditor_TProjectConfigComponent_Data.hasFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->HasComponent<nsTornadoEditor::TProjectConfigComponent>(eid); };
    nsTornadoEditor_TProjectConfigComponent_Data.removeFunc = [](TEntityManager* pEntMng, TEntityID eid){ return pEntMng->RemoveComponent<nsTornadoEditor::TProjectConfigComponent>(eid); };
    nsTornadoEditor_TProjectConfigComponent_Data.getByHasFunc = [](TEntityManager* pEntMng){ return pEntMng->GetByHasCopy<nsTornadoEditor::TProjectConfigComponent>(); };
    nsTornadoEditor_TProjectConfigComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TProjectConfigComponent>();
    
    datas.push_back(nsTornadoEditor_TProjectConfigComponent_Data);
    
    int max = 0;
    for (auto& d : datas) {
        max = std::max(d.rtti, max);
    }
    
    mRttiVector.resize(max + 1);
    for (auto& d : datas) {
        mRttiVector[d.rtti] = d;
    }
}
//---------------------------------------------------------------------------------------
bool TComponentEntMng::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mRttiVector.size()) {
        return false;
    }
    return mRttiVector[rtti].setFunc != nullptr;
}
//---------------------------------------------------------------------------------------
void TComponentEntMng::SetComponent(TEntityManager* pEntMng, TEntityID eid, int rtti, void* p)
{
    Init();
    mRttiVector[rtti].setFunc(pEntMng, eid, p);
}
//---------------------------------------------------------------------------------------
const void* TComponentEntMng::ViewComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].viewFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
bool TComponentEntMng::HasComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    return mRttiVector[rtti].hasFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
void TComponentEntMng::RemoveComponent(TEntityManager* pEntMng, TEntityID eid, int rtti)
{
    Init();
    mRttiVector[rtti].removeFunc(pEntMng, eid);
}
//---------------------------------------------------------------------------------------
nsECSFramework::TEntityList TComponentEntMng::GetByHas(TEntityManager* pEntMng, int rtti)
{
    Init();
    return mRttiVector[rtti].getByHasFunc(pEntMng);
}
//---------------------------------------------------------------------------------------
