/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.5, build 56 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2022_01_09 09:44:00.228
	
#include "ComponentTypeInformation.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

std::list<std::string> TComponentTypeInformation::mTypeNameList;
std::list<int> TComponentTypeInformation::mRttiList;

std::vector<std::string> TComponentTypeInformation::mNameVector;
std::map<std::string, int> TComponentTypeInformation::mNameRttiMap;

void TComponentTypeInformation::Init()
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
    
    int nsTornadoEditor_TEditorInfoTagComponent_i = globalTypeIdentifier->Type<nsTornadoEditor::TEditorInfoTagComponent>();
    std::string nsTornadoEditor_TEditorInfoTagComponent_n = "nsTornadoEditor::TEditorInfoTagComponent";
    mTypeNameList.push_back(nsTornadoEditor_TEditorInfoTagComponent_n);
    mRttiList.push_back(nsTornadoEditor_TEditorInfoTagComponent_i);
    mNameRttiMap.insert({ nsTornadoEditor_TEditorInfoTagComponent_n, nsTornadoEditor_TEditorInfoTagComponent_i });
    
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
    
    int nsTornadoEditor_TInspectorWindowTagComponent_i = globalTypeIdentifier->Type<nsTornadoEditor::TInspectorWindowTagComponent>();
    std::string nsTornadoEditor_TInspectorWindowTagComponent_n = "nsTornadoEditor::TInspectorWindowTagComponent";
    mTypeNameList.push_back(nsTornadoEditor_TInspectorWindowTagComponent_n);
    mRttiList.push_back(nsTornadoEditor_TInspectorWindowTagComponent_i);
    mNameRttiMap.insert({ nsTornadoEditor_TInspectorWindowTagComponent_n, nsTornadoEditor_TInspectorWindowTagComponent_i });
    
    int nsTornadoEditor_TObjectHierarchyWindowTagComponent_i = globalTypeIdentifier->Type<nsTornadoEditor::TObjectHierarchyWindowTagComponent>();
    std::string nsTornadoEditor_TObjectHierarchyWindowTagComponent_n = "nsTornadoEditor::TObjectHierarchyWindowTagComponent";
    mTypeNameList.push_back(nsTornadoEditor_TObjectHierarchyWindowTagComponent_n);
    mRttiList.push_back(nsTornadoEditor_TObjectHierarchyWindowTagComponent_i);
    mNameRttiMap.insert({ nsTornadoEditor_TObjectHierarchyWindowTagComponent_n, nsTornadoEditor_TObjectHierarchyWindowTagComponent_i });
    
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
const std::list<std::string>* TComponentTypeInformation::GetTypeNameList()
{
    Init();
    return &mTypeNameList;
}
//---------------------------------------------------------------------------------------
const std::list<int>* TComponentTypeInformation::GetRttiList()
{
    Init();
    return &mRttiList;
}
//---------------------------------------------------------------------------------------
const std::string* TComponentTypeInformation::ConvertRttiToName(int rtti)
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
bool TComponentTypeInformation::ConvertNameToRtti(const std::string& typeName, int& rtti)
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
