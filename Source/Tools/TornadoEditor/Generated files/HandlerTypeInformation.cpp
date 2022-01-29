/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.5, build 56 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2022_01_29 20:21:39.081
	
#include "HandlerTypeInformation.h"

#include "SingletonManager.h"
#include "RunTimeTypeIndex.h"

using namespace nsTornadoEditor;

std::list<std::string> THandlerTypeInformation::mTypeNameList;
std::list<int> THandlerTypeInformation::mRttiList;

std::vector<std::string> THandlerTypeInformation::mNameVector;
std::map<std::string, int> THandlerTypeInformation::mNameRttiMap;

void THandlerTypeInformation::Init()
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
    
    int nsTornadoEditor_TOnOpenProjectClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOnOpenProjectClickHandler>();
    std::string nsTornadoEditor_TOnOpenProjectClickHandler_n = "nsTornadoEditor::TOnOpenProjectClickHandler";
    mTypeNameList.push_back(nsTornadoEditor_TOnOpenProjectClickHandler_n);
    mRttiList.push_back(nsTornadoEditor_TOnOpenProjectClickHandler_i);
    mNameRttiMap.insert({ nsTornadoEditor_TOnOpenProjectClickHandler_n, nsTornadoEditor_TOnOpenProjectClickHandler_i });
    
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
const std::list<std::string>* THandlerTypeInformation::GetTypeNameList()
{
    Init();
    return &mTypeNameList;
}
//---------------------------------------------------------------------------------------
const std::list<int>* THandlerTypeInformation::GetRttiList()
{
    Init();
    return &mRttiList;
}
//---------------------------------------------------------------------------------------
const std::string* THandlerTypeInformation::ConvertRttiToName(int rtti)
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
bool THandlerTypeInformation::ConvertNameToRtti(const std::string& typeName, int& rtti)
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
