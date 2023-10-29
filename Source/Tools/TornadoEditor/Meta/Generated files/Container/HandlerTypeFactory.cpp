/*
Project Handler
*/
// ReflectionCodeGenerator version 2.4.2, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_10_29 11:16:50.213
	
#include "HandlerTypeFactory.h"
#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

std::vector<THandlerTypeFactory::Data> THandlerTypeFactory::mDataVector;
void THandlerTypeFactory::Init()
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
    
    Data nsTornadoEditor_TBootstrapperFeature_Data;
    nsTornadoEditor_TBootstrapperFeature_Data.newFunc = [](){ return new nsTornadoEditor::TBootstrapperFeature(); };
    nsTornadoEditor_TBootstrapperFeature_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TBootstrapperFeature*)p; };
    nsTornadoEditor_TBootstrapperFeature_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperFeature>();
    
    datas.push_back(nsTornadoEditor_TBootstrapperFeature_Data);
    
    Data nsTornadoEditor_TBootstrapperSystem_Data;
    nsTornadoEditor_TBootstrapperSystem_Data.newFunc = [](){ return new nsTornadoEditor::TBootstrapperSystem(); };
    nsTornadoEditor_TBootstrapperSystem_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TBootstrapperSystem*)p; };
    nsTornadoEditor_TBootstrapperSystem_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperSystem>();
    
    datas.push_back(nsTornadoEditor_TBootstrapperSystem_Data);
    
    Data nsTornadoEditor_TCurrentPathToInputTextHandler_Data;
    nsTornadoEditor_TCurrentPathToInputTextHandler_Data.newFunc = [](){ return new nsTornadoEditor::TCurrentPathToInputTextHandler(); };
    nsTornadoEditor_TCurrentPathToInputTextHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TCurrentPathToInputTextHandler*)p; };
    nsTornadoEditor_TCurrentPathToInputTextHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TCurrentPathToInputTextHandler>();
    
    datas.push_back(nsTornadoEditor_TCurrentPathToInputTextHandler_Data);
    
    Data nsTornadoEditor_TDialogButtonClickHandler_Data;
    nsTornadoEditor_TDialogButtonClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TDialogButtonClickHandler(); };
    nsTornadoEditor_TDialogButtonClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TDialogButtonClickHandler*)p; };
    nsTornadoEditor_TDialogButtonClickHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TDialogButtonClickHandler>();
    
    datas.push_back(nsTornadoEditor_TDialogButtonClickHandler_Data);
    
    Data nsTornadoEditor_TEditorInfoTagComponent_Data;
    nsTornadoEditor_TEditorInfoTagComponent_Data.newFunc = [](){ return new nsTornadoEditor::TEditorInfoTagComponent(); };
    nsTornadoEditor_TEditorInfoTagComponent_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TEditorInfoTagComponent*)p; };
    nsTornadoEditor_TEditorInfoTagComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TEditorInfoTagComponent>();
    
    datas.push_back(nsTornadoEditor_TEditorInfoTagComponent_Data);
    
    Data nsTornadoEditor_TFileHierarchyWindowInitSystem_Data;
    nsTornadoEditor_TFileHierarchyWindowInitSystem_Data.newFunc = [](){ return new nsTornadoEditor::TFileHierarchyWindowInitSystem(); };
    nsTornadoEditor_TFileHierarchyWindowInitSystem_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TFileHierarchyWindowInitSystem*)p; };
    nsTornadoEditor_TFileHierarchyWindowInitSystem_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowInitSystem>();
    
    datas.push_back(nsTornadoEditor_TFileHierarchyWindowInitSystem_Data);
    
    Data nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data;
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data.newFunc = [](){ return new nsTornadoEditor::TFileHierarchyWindowRefreshSystem(); };
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TFileHierarchyWindowRefreshSystem*)p; };
    nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshSystem>();
    
    datas.push_back(nsTornadoEditor_TFileHierarchyWindowRefreshSystem_Data);
    
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
    
    Data nsTornadoEditor_TInitWindowsFeature_Data;
    nsTornadoEditor_TInitWindowsFeature_Data.newFunc = [](){ return new nsTornadoEditor::TInitWindowsFeature(); };
    nsTornadoEditor_TInitWindowsFeature_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TInitWindowsFeature*)p; };
    nsTornadoEditor_TInitWindowsFeature_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TInitWindowsFeature>();
    
    datas.push_back(nsTornadoEditor_TInitWindowsFeature_Data);
    
    Data nsTornadoEditor_TInspectorWindowTagComponent_Data;
    nsTornadoEditor_TInspectorWindowTagComponent_Data.newFunc = [](){ return new nsTornadoEditor::TInspectorWindowTagComponent(); };
    nsTornadoEditor_TInspectorWindowTagComponent_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TInspectorWindowTagComponent*)p; };
    nsTornadoEditor_TInspectorWindowTagComponent_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TInspectorWindowTagComponent>();
    
    datas.push_back(nsTornadoEditor_TInspectorWindowTagComponent_Data);
    
    Data nsTornadoEditor_TMainFeature_Data;
    nsTornadoEditor_TMainFeature_Data.newFunc = [](){ return new nsTornadoEditor::TMainFeature(); };
    nsTornadoEditor_TMainFeature_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TMainFeature*)p; };
    nsTornadoEditor_TMainFeature_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TMainFeature>();
    
    datas.push_back(nsTornadoEditor_TMainFeature_Data);
    
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
    
    Data nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data;
    nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data.newFunc = [](){ return new nsTornadoEditor::TObjectHierarchyWindowInitSystem(); };
    nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TObjectHierarchyWindowInitSystem*)p; };
    nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowInitSystem>();
    
    datas.push_back(nsTornadoEditor_TObjectHierarchyWindowInitSystem_Data);
    
    Data nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data;
    nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data.newFunc = [](){ return new nsTornadoEditor::TObjectHierarchyWindowRefreshSystem(); };
    nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TObjectHierarchyWindowRefreshSystem*)p; };
    nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem>();
    
    datas.push_back(nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_Data);
    
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
    
    Data nsTornadoEditor_TOnCloseDialogHandler_Data;
    nsTornadoEditor_TOnCloseDialogHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnCloseDialogHandler(); };
    nsTornadoEditor_TOnCloseDialogHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnCloseDialogHandler*)p; };
    nsTornadoEditor_TOnCloseDialogHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOnCloseDialogHandler>();
    
    datas.push_back(nsTornadoEditor_TOnCloseDialogHandler_Data);
    
    Data nsTornadoEditor_TOnCloseWindowHandler_Data;
    nsTornadoEditor_TOnCloseWindowHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnCloseWindowHandler(); };
    nsTornadoEditor_TOnCloseWindowHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnCloseWindowHandler*)p; };
    nsTornadoEditor_TOnCloseWindowHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOnCloseWindowHandler>();
    
    datas.push_back(nsTornadoEditor_TOnCloseWindowHandler_Data);
    
    Data nsTornadoEditor_TOnExitClickHandler_Data;
    nsTornadoEditor_TOnExitClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnExitClickHandler(); };
    nsTornadoEditor_TOnExitClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnExitClickHandler*)p; };
    nsTornadoEditor_TOnExitClickHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOnExitClickHandler>();
    
    datas.push_back(nsTornadoEditor_TOnExitClickHandler_Data);
    
    Data nsTornadoEditor_TOnFileHierarchyClickHandler_Data;
    nsTornadoEditor_TOnFileHierarchyClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnFileHierarchyClickHandler(); };
    nsTornadoEditor_TOnFileHierarchyClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnFileHierarchyClickHandler*)p; };
    nsTornadoEditor_TOnFileHierarchyClickHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOnFileHierarchyClickHandler>();
    
    datas.push_back(nsTornadoEditor_TOnFileHierarchyClickHandler_Data);
    
    Data nsTornadoEditor_TOnMouseClickFileNodeHandler_Data;
    nsTornadoEditor_TOnMouseClickFileNodeHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnMouseClickFileNodeHandler(); };
    nsTornadoEditor_TOnMouseClickFileNodeHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnMouseClickFileNodeHandler*)p; };
    nsTornadoEditor_TOnMouseClickFileNodeHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOnMouseClickFileNodeHandler>();
    
    datas.push_back(nsTornadoEditor_TOnMouseClickFileNodeHandler_Data);
    
    Data nsTornadoEditor_TOnOpenComponentViewerClickHandler_Data;
    nsTornadoEditor_TOnOpenComponentViewerClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnOpenComponentViewerClickHandler(); };
    nsTornadoEditor_TOnOpenComponentViewerClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnOpenComponentViewerClickHandler*)p; };
    nsTornadoEditor_TOnOpenComponentViewerClickHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOnOpenComponentViewerClickHandler>();
    
    datas.push_back(nsTornadoEditor_TOnOpenComponentViewerClickHandler_Data);
    
    Data nsTornadoEditor_TOnOpenProjectClickHandler_Data;
    nsTornadoEditor_TOnOpenProjectClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnOpenProjectClickHandler(); };
    nsTornadoEditor_TOnOpenProjectClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnOpenProjectClickHandler*)p; };
    nsTornadoEditor_TOnOpenProjectClickHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOnOpenProjectClickHandler>();
    
    datas.push_back(nsTornadoEditor_TOnOpenProjectClickHandler_Data);
    
    Data nsTornadoEditor_TOnOpenSystemViewerClickHandler_Data;
    nsTornadoEditor_TOnOpenSystemViewerClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOnOpenSystemViewerClickHandler(); };
    nsTornadoEditor_TOnOpenSystemViewerClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOnOpenSystemViewerClickHandler*)p; };
    nsTornadoEditor_TOnOpenSystemViewerClickHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOnOpenSystemViewerClickHandler>();
    
    datas.push_back(nsTornadoEditor_TOnOpenSystemViewerClickHandler_Data);
    
    Data nsTornadoEditor_TOpenProjectCancelButtonClickHandler_Data;
    nsTornadoEditor_TOpenProjectCancelButtonClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOpenProjectCancelButtonClickHandler(); };
    nsTornadoEditor_TOpenProjectCancelButtonClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOpenProjectCancelButtonClickHandler*)p; };
    nsTornadoEditor_TOpenProjectCancelButtonClickHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOpenProjectCancelButtonClickHandler>();
    
    datas.push_back(nsTornadoEditor_TOpenProjectCancelButtonClickHandler_Data);
    
    Data nsTornadoEditor_TOpenProjectOkButtonClickHandler_Data;
    nsTornadoEditor_TOpenProjectOkButtonClickHandler_Data.newFunc = [](){ return new nsTornadoEditor::TOpenProjectOkButtonClickHandler(); };
    nsTornadoEditor_TOpenProjectOkButtonClickHandler_Data.deleteFunc = [](void* p){ delete (nsTornadoEditor::TOpenProjectOkButtonClickHandler*)p; };
    nsTornadoEditor_TOpenProjectOkButtonClickHandler_Data.rtti = globalTypeIdentifier->Type<nsTornadoEditor::TOpenProjectOkButtonClickHandler>();
    
    datas.push_back(nsTornadoEditor_TOpenProjectOkButtonClickHandler_Data);
    
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
void* THandlerTypeFactory::New(int rtti)
{
    Init();
    return mDataVector[rtti].newFunc();
}
//---------------------------------------------------------------------------------------
void THandlerTypeFactory::Delete(void* p, int rtti)
{
    Init();
    mDataVector[rtti].deleteFunc(p);
}
//---------------------------------------------------------------------------------------
bool THandlerTypeFactory::Has(int rtti)
{
    Init();
    if (rtti < 0 || rtti >= mDataVector.size()) {
        return false;
    }
    return mDataVector[rtti].deleteFunc != nullptr;
}
//---------------------------------------------------------------------------------------
