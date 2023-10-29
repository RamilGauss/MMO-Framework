/*
Project Handler
*/
// ReflectionCodeGenerator version 2.4.2, build 58 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, TypeInformation]
// File has been generated at 2023_10_29 11:16:50.218
	
#include "HandlerTypeInfo.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

std::list<std::string> THandlerTypeInfo::mTypeNameList;
std::list<int> THandlerTypeInfo::mRttiList;

std::vector<std::string> THandlerTypeInfo::mNameVector;
std::unordered_map<std::string, int> THandlerTypeInfo::mNameRttiMap;

void THandlerTypeInfo::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
    int nsTornadoEditor_TAbsoluteFilePathComponent_i = globalTypeIdentifier->Type<nsTornadoEditor::TAbsoluteFilePathComponent>();
    std::string nsTornadoEditor_TAbsoluteFilePathComponent_n = "nsTornadoEditor::TAbsoluteFilePathComponent";
    mTypeNameList.push_back(nsTornadoEditor_TAbsoluteFilePathComponent_n);
    mRttiList.push_back(nsTornadoEditor_TAbsoluteFilePathComponent_i);
    mNameRttiMap.insert({ nsTornadoEditor_TAbsoluteFilePathComponent_n, nsTornadoEditor_TAbsoluteFilePathComponent_i });
    
    int nsTornadoEditor_TAssetAbsoluteFilePathComponent_i = globalTypeIdentifier->Type<nsTornadoEditor::TAssetAbsoluteFilePathComponent>();
    std::string nsTornadoEditor_TAssetAbsoluteFilePathComponent_n = "nsTornadoEditor::TAssetAbsoluteFilePathComponent";
    mTypeNameList.push_back(nsTornadoEditor_TAssetAbsoluteFilePathComponent_n);
    mRttiList.push_back(nsTornadoEditor_TAssetAbsoluteFilePathComponent_i);
    mNameRttiMap.insert({ nsTornadoEditor_TAssetAbsoluteFilePathComponent_n, nsTornadoEditor_TAssetAbsoluteFilePathComponent_i });
    
    int nsTornadoEditor_TBootstrapperFeature_i = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperFeature>();
    std::string nsTornadoEditor_TBootstrapperFeature_n = "nsTornadoEditor::TBootstrapperFeature";
    mTypeNameList.push_back(nsTornadoEditor_TBootstrapperFeature_n);
    mRttiList.push_back(nsTornadoEditor_TBootstrapperFeature_i);
    mNameRttiMap.insert({ nsTornadoEditor_TBootstrapperFeature_n, nsTornadoEditor_TBootstrapperFeature_i });
    
    int nsTornadoEditor_TBootstrapperSystem_i = globalTypeIdentifier->Type<nsTornadoEditor::TBootstrapperSystem>();
    std::string nsTornadoEditor_TBootstrapperSystem_n = "nsTornadoEditor::TBootstrapperSystem";
    mTypeNameList.push_back(nsTornadoEditor_TBootstrapperSystem_n);
    mRttiList.push_back(nsTornadoEditor_TBootstrapperSystem_i);
    mNameRttiMap.insert({ nsTornadoEditor_TBootstrapperSystem_n, nsTornadoEditor_TBootstrapperSystem_i });
    
    int nsTornadoEditor_TCurrentPathToInputTextHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TCurrentPathToInputTextHandler>();
    std::string nsTornadoEditor_TCurrentPathToInputTextHandler_n = "nsTornadoEditor::TCurrentPathToInputTextHandler";
    mTypeNameList.push_back(nsTornadoEditor_TCurrentPathToInputTextHandler_n);
    mRttiList.push_back(nsTornadoEditor_TCurrentPathToInputTextHandler_i);
    mNameRttiMap.insert({ nsTornadoEditor_TCurrentPathToInputTextHandler_n, nsTornadoEditor_TCurrentPathToInputTextHandler_i });
    
    int nsTornadoEditor_TDialogButtonClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TDialogButtonClickHandler>();
    std::string nsTornadoEditor_TDialogButtonClickHandler_n = "nsTornadoEditor::TDialogButtonClickHandler";
    mTypeNameList.push_back(nsTornadoEditor_TDialogButtonClickHandler_n);
    mRttiList.push_back(nsTornadoEditor_TDialogButtonClickHandler_i);
    mNameRttiMap.insert({ nsTornadoEditor_TDialogButtonClickHandler_n, nsTornadoEditor_TDialogButtonClickHandler_i });
    
    int nsTornadoEditor_TEditorInfoTagComponent_i = globalTypeIdentifier->Type<nsTornadoEditor::TEditorInfoTagComponent>();
    std::string nsTornadoEditor_TEditorInfoTagComponent_n = "nsTornadoEditor::TEditorInfoTagComponent";
    mTypeNameList.push_back(nsTornadoEditor_TEditorInfoTagComponent_n);
    mRttiList.push_back(nsTornadoEditor_TEditorInfoTagComponent_i);
    mNameRttiMap.insert({ nsTornadoEditor_TEditorInfoTagComponent_n, nsTornadoEditor_TEditorInfoTagComponent_i });
    
    int nsTornadoEditor_TFileHierarchyWindowInitSystem_i = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowInitSystem>();
    std::string nsTornadoEditor_TFileHierarchyWindowInitSystem_n = "nsTornadoEditor::TFileHierarchyWindowInitSystem";
    mTypeNameList.push_back(nsTornadoEditor_TFileHierarchyWindowInitSystem_n);
    mRttiList.push_back(nsTornadoEditor_TFileHierarchyWindowInitSystem_i);
    mNameRttiMap.insert({ nsTornadoEditor_TFileHierarchyWindowInitSystem_n, nsTornadoEditor_TFileHierarchyWindowInitSystem_i });
    
    int nsTornadoEditor_TFileHierarchyWindowRefreshSystem_i = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshSystem>();
    std::string nsTornadoEditor_TFileHierarchyWindowRefreshSystem_n = "nsTornadoEditor::TFileHierarchyWindowRefreshSystem";
    mTypeNameList.push_back(nsTornadoEditor_TFileHierarchyWindowRefreshSystem_n);
    mRttiList.push_back(nsTornadoEditor_TFileHierarchyWindowRefreshSystem_i);
    mNameRttiMap.insert({ nsTornadoEditor_TFileHierarchyWindowRefreshSystem_n, nsTornadoEditor_TFileHierarchyWindowRefreshSystem_i });
    
    int nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_i = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent>();
    std::string nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_n = "nsTornadoEditor::TFileHierarchyWindowRefreshTagComponent";
    mTypeNameList.push_back(nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_n);
    mRttiList.push_back(nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_i);
    mNameRttiMap.insert({ nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_n, nsTornadoEditor_TFileHierarchyWindowRefreshTagComponent_i });
    
    int nsTornadoEditor_TFileHierarchyWindowTagComponent_i = globalTypeIdentifier->Type<nsTornadoEditor::TFileHierarchyWindowTagComponent>();
    std::string nsTornadoEditor_TFileHierarchyWindowTagComponent_n = "nsTornadoEditor::TFileHierarchyWindowTagComponent";
    mTypeNameList.push_back(nsTornadoEditor_TFileHierarchyWindowTagComponent_n);
    mRttiList.push_back(nsTornadoEditor_TFileHierarchyWindowTagComponent_i);
    mNameRttiMap.insert({ nsTornadoEditor_TFileHierarchyWindowTagComponent_n, nsTornadoEditor_TFileHierarchyWindowTagComponent_i });
    
    int nsTornadoEditor_TFilePathNodeComponent_i = globalTypeIdentifier->Type<nsTornadoEditor::TFilePathNodeComponent>();
    std::string nsTornadoEditor_TFilePathNodeComponent_n = "nsTornadoEditor::TFilePathNodeComponent";
    mTypeNameList.push_back(nsTornadoEditor_TFilePathNodeComponent_n);
    mRttiList.push_back(nsTornadoEditor_TFilePathNodeComponent_i);
    mNameRttiMap.insert({ nsTornadoEditor_TFilePathNodeComponent_n, nsTornadoEditor_TFilePathNodeComponent_i });
    
    int nsTornadoEditor_TInitWindowsFeature_i = globalTypeIdentifier->Type<nsTornadoEditor::TInitWindowsFeature>();
    std::string nsTornadoEditor_TInitWindowsFeature_n = "nsTornadoEditor::TInitWindowsFeature";
    mTypeNameList.push_back(nsTornadoEditor_TInitWindowsFeature_n);
    mRttiList.push_back(nsTornadoEditor_TInitWindowsFeature_i);
    mNameRttiMap.insert({ nsTornadoEditor_TInitWindowsFeature_n, nsTornadoEditor_TInitWindowsFeature_i });
    
    int nsTornadoEditor_TInspectorWindowTagComponent_i = globalTypeIdentifier->Type<nsTornadoEditor::TInspectorWindowTagComponent>();
    std::string nsTornadoEditor_TInspectorWindowTagComponent_n = "nsTornadoEditor::TInspectorWindowTagComponent";
    mTypeNameList.push_back(nsTornadoEditor_TInspectorWindowTagComponent_n);
    mRttiList.push_back(nsTornadoEditor_TInspectorWindowTagComponent_i);
    mNameRttiMap.insert({ nsTornadoEditor_TInspectorWindowTagComponent_n, nsTornadoEditor_TInspectorWindowTagComponent_i });
    
    int nsTornadoEditor_TMainFeature_i = globalTypeIdentifier->Type<nsTornadoEditor::TMainFeature>();
    std::string nsTornadoEditor_TMainFeature_n = "nsTornadoEditor::TMainFeature";
    mTypeNameList.push_back(nsTornadoEditor_TMainFeature_n);
    mRttiList.push_back(nsTornadoEditor_TMainFeature_i);
    mNameRttiMap.insert({ nsTornadoEditor_TMainFeature_n, nsTornadoEditor_TMainFeature_i });
    
    int nsTornadoEditor_TMainWindowPrefabGuidComponent_i = globalTypeIdentifier->Type<nsTornadoEditor::TMainWindowPrefabGuidComponent>();
    std::string nsTornadoEditor_TMainWindowPrefabGuidComponent_n = "nsTornadoEditor::TMainWindowPrefabGuidComponent";
    mTypeNameList.push_back(nsTornadoEditor_TMainWindowPrefabGuidComponent_n);
    mRttiList.push_back(nsTornadoEditor_TMainWindowPrefabGuidComponent_i);
    mNameRttiMap.insert({ nsTornadoEditor_TMainWindowPrefabGuidComponent_n, nsTornadoEditor_TMainWindowPrefabGuidComponent_i });
    
    int nsTornadoEditor_TMainWindowTagComponent_i = globalTypeIdentifier->Type<nsTornadoEditor::TMainWindowTagComponent>();
    std::string nsTornadoEditor_TMainWindowTagComponent_n = "nsTornadoEditor::TMainWindowTagComponent";
    mTypeNameList.push_back(nsTornadoEditor_TMainWindowTagComponent_n);
    mRttiList.push_back(nsTornadoEditor_TMainWindowTagComponent_i);
    mNameRttiMap.insert({ nsTornadoEditor_TMainWindowTagComponent_n, nsTornadoEditor_TMainWindowTagComponent_i });
    
    int nsTornadoEditor_TObjectHierarchyWindowInitSystem_i = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowInitSystem>();
    std::string nsTornadoEditor_TObjectHierarchyWindowInitSystem_n = "nsTornadoEditor::TObjectHierarchyWindowInitSystem";
    mTypeNameList.push_back(nsTornadoEditor_TObjectHierarchyWindowInitSystem_n);
    mRttiList.push_back(nsTornadoEditor_TObjectHierarchyWindowInitSystem_i);
    mNameRttiMap.insert({ nsTornadoEditor_TObjectHierarchyWindowInitSystem_n, nsTornadoEditor_TObjectHierarchyWindowInitSystem_i });
    
    int nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_i = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowRefreshSystem>();
    std::string nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_n = "nsTornadoEditor::TObjectHierarchyWindowRefreshSystem";
    mTypeNameList.push_back(nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_n);
    mRttiList.push_back(nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_i);
    mNameRttiMap.insert({ nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_n, nsTornadoEditor_TObjectHierarchyWindowRefreshSystem_i });
    
    int nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_i = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent>();
    std::string nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_n = "nsTornadoEditor::TObjectHierarchyWindowRefreshTagComponent";
    mTypeNameList.push_back(nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_n);
    mRttiList.push_back(nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_i);
    mNameRttiMap.insert({ nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_n, nsTornadoEditor_TObjectHierarchyWindowRefreshTagComponent_i });
    
    int nsTornadoEditor_TObjectHierarchyWindowTagComponent_i = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowTagComponent>();
    std::string nsTornadoEditor_TObjectHierarchyWindowTagComponent_n = "nsTornadoEditor::TObjectHierarchyWindowTagComponent";
    mTypeNameList.push_back(nsTornadoEditor_TObjectHierarchyWindowTagComponent_n);
    mRttiList.push_back(nsTornadoEditor_TObjectHierarchyWindowTagComponent_i);
    mNameRttiMap.insert({ nsTornadoEditor_TObjectHierarchyWindowTagComponent_n, nsTornadoEditor_TObjectHierarchyWindowTagComponent_i });
    
    int nsTornadoEditor_TOnCloseDialogHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOnCloseDialogHandler>();
    std::string nsTornadoEditor_TOnCloseDialogHandler_n = "nsTornadoEditor::TOnCloseDialogHandler";
    mTypeNameList.push_back(nsTornadoEditor_TOnCloseDialogHandler_n);
    mRttiList.push_back(nsTornadoEditor_TOnCloseDialogHandler_i);
    mNameRttiMap.insert({ nsTornadoEditor_TOnCloseDialogHandler_n, nsTornadoEditor_TOnCloseDialogHandler_i });
    
    int nsTornadoEditor_TOnCloseWindowHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOnCloseWindowHandler>();
    std::string nsTornadoEditor_TOnCloseWindowHandler_n = "nsTornadoEditor::TOnCloseWindowHandler";
    mTypeNameList.push_back(nsTornadoEditor_TOnCloseWindowHandler_n);
    mRttiList.push_back(nsTornadoEditor_TOnCloseWindowHandler_i);
    mNameRttiMap.insert({ nsTornadoEditor_TOnCloseWindowHandler_n, nsTornadoEditor_TOnCloseWindowHandler_i });
    
    int nsTornadoEditor_TOnExitClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOnExitClickHandler>();
    std::string nsTornadoEditor_TOnExitClickHandler_n = "nsTornadoEditor::TOnExitClickHandler";
    mTypeNameList.push_back(nsTornadoEditor_TOnExitClickHandler_n);
    mRttiList.push_back(nsTornadoEditor_TOnExitClickHandler_i);
    mNameRttiMap.insert({ nsTornadoEditor_TOnExitClickHandler_n, nsTornadoEditor_TOnExitClickHandler_i });
    
    int nsTornadoEditor_TOnFileHierarchyClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOnFileHierarchyClickHandler>();
    std::string nsTornadoEditor_TOnFileHierarchyClickHandler_n = "nsTornadoEditor::TOnFileHierarchyClickHandler";
    mTypeNameList.push_back(nsTornadoEditor_TOnFileHierarchyClickHandler_n);
    mRttiList.push_back(nsTornadoEditor_TOnFileHierarchyClickHandler_i);
    mNameRttiMap.insert({ nsTornadoEditor_TOnFileHierarchyClickHandler_n, nsTornadoEditor_TOnFileHierarchyClickHandler_i });
    
    int nsTornadoEditor_TOnMouseClickFileNodeHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOnMouseClickFileNodeHandler>();
    std::string nsTornadoEditor_TOnMouseClickFileNodeHandler_n = "nsTornadoEditor::TOnMouseClickFileNodeHandler";
    mTypeNameList.push_back(nsTornadoEditor_TOnMouseClickFileNodeHandler_n);
    mRttiList.push_back(nsTornadoEditor_TOnMouseClickFileNodeHandler_i);
    mNameRttiMap.insert({ nsTornadoEditor_TOnMouseClickFileNodeHandler_n, nsTornadoEditor_TOnMouseClickFileNodeHandler_i });
    
    int nsTornadoEditor_TOnOpenComponentViewerClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOnOpenComponentViewerClickHandler>();
    std::string nsTornadoEditor_TOnOpenComponentViewerClickHandler_n = "nsTornadoEditor::TOnOpenComponentViewerClickHandler";
    mTypeNameList.push_back(nsTornadoEditor_TOnOpenComponentViewerClickHandler_n);
    mRttiList.push_back(nsTornadoEditor_TOnOpenComponentViewerClickHandler_i);
    mNameRttiMap.insert({ nsTornadoEditor_TOnOpenComponentViewerClickHandler_n, nsTornadoEditor_TOnOpenComponentViewerClickHandler_i });
    
    int nsTornadoEditor_TOnOpenProjectClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOnOpenProjectClickHandler>();
    std::string nsTornadoEditor_TOnOpenProjectClickHandler_n = "nsTornadoEditor::TOnOpenProjectClickHandler";
    mTypeNameList.push_back(nsTornadoEditor_TOnOpenProjectClickHandler_n);
    mRttiList.push_back(nsTornadoEditor_TOnOpenProjectClickHandler_i);
    mNameRttiMap.insert({ nsTornadoEditor_TOnOpenProjectClickHandler_n, nsTornadoEditor_TOnOpenProjectClickHandler_i });
    
    int nsTornadoEditor_TOnOpenSystemViewerClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOnOpenSystemViewerClickHandler>();
    std::string nsTornadoEditor_TOnOpenSystemViewerClickHandler_n = "nsTornadoEditor::TOnOpenSystemViewerClickHandler";
    mTypeNameList.push_back(nsTornadoEditor_TOnOpenSystemViewerClickHandler_n);
    mRttiList.push_back(nsTornadoEditor_TOnOpenSystemViewerClickHandler_i);
    mNameRttiMap.insert({ nsTornadoEditor_TOnOpenSystemViewerClickHandler_n, nsTornadoEditor_TOnOpenSystemViewerClickHandler_i });
    
    int nsTornadoEditor_TOpenProjectCancelButtonClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOpenProjectCancelButtonClickHandler>();
    std::string nsTornadoEditor_TOpenProjectCancelButtonClickHandler_n = "nsTornadoEditor::TOpenProjectCancelButtonClickHandler";
    mTypeNameList.push_back(nsTornadoEditor_TOpenProjectCancelButtonClickHandler_n);
    mRttiList.push_back(nsTornadoEditor_TOpenProjectCancelButtonClickHandler_i);
    mNameRttiMap.insert({ nsTornadoEditor_TOpenProjectCancelButtonClickHandler_n, nsTornadoEditor_TOpenProjectCancelButtonClickHandler_i });
    
    int nsTornadoEditor_TOpenProjectOkButtonClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOpenProjectOkButtonClickHandler>();
    std::string nsTornadoEditor_TOpenProjectOkButtonClickHandler_n = "nsTornadoEditor::TOpenProjectOkButtonClickHandler";
    mTypeNameList.push_back(nsTornadoEditor_TOpenProjectOkButtonClickHandler_n);
    mRttiList.push_back(nsTornadoEditor_TOpenProjectOkButtonClickHandler_i);
    mNameRttiMap.insert({ nsTornadoEditor_TOpenProjectOkButtonClickHandler_n, nsTornadoEditor_TOpenProjectOkButtonClickHandler_i });
    
    int nsTornadoEditor_TProjectConfigComponent_i = globalTypeIdentifier->Type<nsTornadoEditor::TProjectConfigComponent>();
    std::string nsTornadoEditor_TProjectConfigComponent_n = "nsTornadoEditor::TProjectConfigComponent";
    mTypeNameList.push_back(nsTornadoEditor_TProjectConfigComponent_n);
    mRttiList.push_back(nsTornadoEditor_TProjectConfigComponent_i);
    mNameRttiMap.insert({ nsTornadoEditor_TProjectConfigComponent_n, nsTornadoEditor_TProjectConfigComponent_i });
    
    int max = 0;
    for (auto& nameRtti : mNameRttiMap) {
        max = std::max(max, nameRtti.second);
    }
    mNameVector.resize(max + 1);
    for (auto& nameRtti : mNameRttiMap) {
        mNameVector[nameRtti.second] = nameRtti.first;
    }
}
//---------------------------------------------------------------------------------------
const std::list<std::string>* THandlerTypeInfo::GetTypeNameList()
{
    Init();
    return &mTypeNameList;
}
//---------------------------------------------------------------------------------------
const std::list<int>* THandlerTypeInfo::GetRttiList()
{
    Init();
    return &mRttiList;
}
//---------------------------------------------------------------------------------------
const std::string* THandlerTypeInfo::ConvertRttiToName(int rtti)
{
    Init();
    
    if (rtti < 0 || rtti >= mNameVector.size()) {
        return nullptr;
    }
    auto pStr = &(mNameVector[rtti]);
    if (pStr->size() == 0) {
        return nullptr;
    }
    return pStr;
}
//---------------------------------------------------------------------------------------
bool THandlerTypeInfo::ConvertNameToRtti(const std::string& typeName, int& rtti)
{
    Init();
    auto fit = mNameRttiMap.find(typeName);
    if (fit == mNameRttiMap.end()) {
        return false;
    }
    rtti = fit->second;
    return true;
}
//---------------------------------------------------------------------------------------
