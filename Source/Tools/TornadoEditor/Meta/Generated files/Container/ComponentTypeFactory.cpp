/*
Project Component
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]
// File has been generated at 2024_12_27 12:43:34.641
#include "ComponentTypeFactory.h"
#include "Base/Common/SingletonManager.h"
#include "Base/Common/RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

std::vector<TComponentTypeFactory::Data> TComponentTypeFactory::mDataVector;
void TComponentTypeFactory::Init()
{
    static bool isNeedInit = true;
    if ( !isNeedInit )
    {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    std::list<Data> datas;
    
    Data nsTornadoEditor_TAbsoluteFilePathComponent_Data;
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.newFunc = [](){ return new nsTornadoEditor::TAbsoluteFilePathComponent(); };
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TAbsoluteFilePathComponent*)p; };
    nsTornadoEditor_TAbsoluteFilePathComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TAbsoluteFilePathComponent>();
    
    datas.push_back(nsTornadoEditor_TAbsoluteFilePathComponent_Data);
    
    Data nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data;
    nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data.newFunc = [](){ return new nsTornadoEditor::TAssetAbsoluteFilePathComponent(); };
    nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TAssetAbsoluteFilePathComponent*)p; };
    nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TAssetAbsoluteFilePathComponent>();
    
    datas.push_back(nsTornadoEditor_TAssetAbsoluteFilePathComponent_Data);
    
    Data nsTornadoEditor_TEditorInfoTagComponent_Data;
    nsTornadoEditor_TEditorInfoTagComponent_Data.newFunc = [](){ return new nsTornadoEditor::TEditorInfoTagComponent(); };
    nsTornadoEditor_TEditorInfoTagComponent_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TEditorInfoTagComponent*)p; };
    nsTornadoEditor_TEditorInfoTagComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TEditorInfoTagComponent>();
    
    datas.push_back(nsTornadoEditor_TEditorInfoTagComponent_Data);
    
    Data nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data;
    nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data.newFunc = [](){ return new nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent(); };
    nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent*)p; };
    nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>();
    
    datas.push_back(nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_Data);
    
    Data nsTornadoEditor_TFileHierarchyWindowTagComponent_Data;
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.newFunc = [](){ return new nsTornadoEditor::TFileHierarchyWindowTagComponent(); };
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TFileHierarchyWindowTagComponent*)p; };
    nsTornadoEditor_TFileHierarchyWindowTagComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowTagComponent>();
    
    datas.push_back(nsTornadoEditor_TFileHierarchyWindowTagComponent_Data);
    
    Data nsTornadoEditor_TFilePathNodeComponent_Data;
    nsTornadoEditor_TFilePathNodeComponent_Data.newFunc = [](){ return new nsTornadoEditor::TFilePathNodeComponent(); };
    nsTornadoEditor_TFilePathNodeComponent_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TFilePathNodeComponent*)p; };
    nsTornadoEditor_TFilePathNodeComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFilePathNodeComponent>();
    
    datas.push_back(nsTornadoEditor_TFilePathNodeComponent_Data);
    
    Data nsTornadoEditor_TInspectorWindowTagComponent_Data;
    nsTornadoEditor_TInspectorWindowTagComponent_Data.newFunc = [](){ return new nsTornadoEditor::TInspectorWindowTagComponent(); };
    nsTornadoEditor_TInspectorWindowTagComponent_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TInspectorWindowTagComponent*)p; };
    nsTornadoEditor_TInspectorWindowTagComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TInspectorWindowTagComponent>();
    
    datas.push_back(nsTornadoEditor_TInspectorWindowTagComponent_Data);
    
    Data nsTornadoEditor_TMainWindowPrefabGuidComponent_Data;
    nsTornadoEditor_TMainWindowPrefabGuidComponent_Data.newFunc = [](){ return new nsTornadoEditor::TMainWindowPrefabGuidComponent(); };
    nsTornadoEditor_TMainWindowPrefabGuidComponent_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TMainWindowPrefabGuidComponent*)p; };
    nsTornadoEditor_TMainWindowPrefabGuidComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TMainWindowPrefabGuidComponent>();
    
    datas.push_back(nsTornadoEditor_TMainWindowPrefabGuidComponent_Data);
    
    Data nsTornadoEditor_TMainWindowTagComponent_Data;
    nsTornadoEditor_TMainWindowTagComponent_Data.newFunc = [](){ return new nsTornadoEditor::TMainWindowTagComponent(); };
    nsTornadoEditor_TMainWindowTagComponent_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TMainWindowTagComponent*)p; };
    nsTornadoEditor_TMainWindowTagComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TMainWindowTagComponent>();
    
    datas.push_back(nsTornadoEditor_TMainWindowTagComponent_Data);
    
    Data nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data;
    nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data.newFunc = [](){ return new nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent(); };
    nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent*)p; };
    nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>();
    
    datas.push_back(nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_Data);
    
    Data nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data;
    nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data.newFunc = [](){ return new nsTornadoEditor::TObjectHierarchyWindowTagComponent(); };
    nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TObjectHierarchyWindowTagComponent*)p; };
    nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowTagComponent>();
    
    datas.push_back(nsTornadoEditor_TObjectHierarchyWindowTagComponent_Data);
    
    Data nsTornadoEditor_TProjectConfigComponent_Data;
    nsTornadoEditor_TProjectConfigComponent_Data.newFunc = [](){ return new nsTornadoEditor::TProjectConfigComponent(); };
    nsTornadoEditor_TProjectConfigComponent_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TProjectConfigComponent*)p; };
    nsTornadoEditor_TProjectConfigComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TProjectConfigComponent>();
    
    datas.push_back(nsTornadoEditor_TProjectConfigComponent_Data);
    
    int max = 0;
    for (auto& d : datas) {
        max = std::max(d.rtti, max);
    }
    
    mDataVector.resize(max + 1);
    for (auto& d : datas) {
        mDataVector[d.rtti] = d;
    }
}
//---------------------------------------------------------------------------------------
void* TComponentTypeFactory::New(int rtti)
{
    Init();
    return mDataVector[rtti].newFunc();
}
//---------------------------------------------------------------------------------------
void TComponentTypeFactory::Delete(void* p, int rtti)
{
    Init();
    mDataVector[rtti].deleteFunc(p);
}
//---------------------------------------------------------------------------------------
bool TComponentTypeFactory::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mDataVector.size()) {
        return false;
    }
    return mDataVector[rtti].deleteFunc != nullptr;
}
//---------------------------------------------------------------------------------------
