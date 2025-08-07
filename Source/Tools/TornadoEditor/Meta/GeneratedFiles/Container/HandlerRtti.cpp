/*
Project Handler
*/
// ReflectionCodeGenerator version 2.5.0, build 59 [Binary, DynamicCaster, Json, EcsComponentExtension, ImGui, Reflection, RTTI, TypeInformation]

#include "TornadoEditor/Meta/GeneratedFiles/Container/HandlerRtti.h"

#include "Base/Common/SingletonManager.h"
#include "Base/Common/RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

std::list<std::string> THandlerRtti::mTypeNameList;
std::list<int> THandlerRtti::mRttiList;

std::vector<std::string> THandlerRtti::mNameVector;
std::unordered_map<std::string, int> THandlerRtti::mNameRttiMap;

void THandlerRtti::Init()
{
    static bool isNeedInit = true;
    if (!isNeedInit) {
        return;
    }
    isNeedInit = false;
    
    auto globalTypeIdentifier = SingletonManager()->Get<TRunTimeTypeIndex<>>();
    
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
const std::list<std::string>* THandlerRtti::GetTypeNameList()
{
    Init();
    return &mTypeNameList;
}
//---------------------------------------------------------------------------------------
const std::list<int>* THandlerRtti::GetRttiList()
{
    Init();
    return &mRttiList;
}
//---------------------------------------------------------------------------------------
const std::string* THandlerRtti::ConvertRttiToName(int rtti)
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
bool THandlerRtti::ConvertNameToRtti(const std::string& typeName, int& rtti)
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
