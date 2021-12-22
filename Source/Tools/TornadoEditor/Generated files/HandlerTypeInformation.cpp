/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.4, build 55 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_12_22 08:22:04.740
	
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
    
    int nsTornadoEditor_TDeleteOnButtonClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TDeleteOnButtonClickHandler>();
    std::string nsTornadoEditor_TDeleteOnButtonClickHandler_n = "nsTornadoEditor::TDeleteOnButtonClickHandler";
    mTypeNameList.push_back(nsTornadoEditor_TDeleteOnButtonClickHandler_n);
    mRttiList.push_back(nsTornadoEditor_TDeleteOnButtonClickHandler_i);
    mNameRttiMap.insert({ nsTornadoEditor_TDeleteOnButtonClickHandler_n, nsTornadoEditor_TDeleteOnButtonClickHandler_i });
    
    int nsTornadoEditor_TDialogButtonClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TDialogButtonClickHandler>();
    std::string nsTornadoEditor_TDialogButtonClickHandler_n = "nsTornadoEditor::TDialogButtonClickHandler";
    mTypeNameList.push_back(nsTornadoEditor_TDialogButtonClickHandler_n);
    mRttiList.push_back(nsTornadoEditor_TDialogButtonClickHandler_i);
    mNameRttiMap.insert({ nsTornadoEditor_TDialogButtonClickHandler_n, nsTornadoEditor_TDialogButtonClickHandler_i });
    
    int nsTornadoEditor_TExitButtonClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TExitButtonClickHandler>();
    std::string nsTornadoEditor_TExitButtonClickHandler_n = "nsTornadoEditor::TExitButtonClickHandler";
    mTypeNameList.push_back(nsTornadoEditor_TExitButtonClickHandler_n);
    mRttiList.push_back(nsTornadoEditor_TExitButtonClickHandler_i);
    mNameRttiMap.insert({ nsTornadoEditor_TExitButtonClickHandler_n, nsTornadoEditor_TExitButtonClickHandler_i });
    
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
    
    int nsTornadoEditor_TOnOpenProjectClickHandler_i = globalTypeIdentifier->Type<nsTornadoEditor::TOnOpenProjectClickHandler>();
    std::string nsTornadoEditor_TOnOpenProjectClickHandler_n = "nsTornadoEditor::TOnOpenProjectClickHandler";
    mTypeNameList.push_back(nsTornadoEditor_TOnOpenProjectClickHandler_n);
    mRttiList.push_back(nsTornadoEditor_TOnOpenProjectClickHandler_i);
    mNameRttiMap.insert({ nsTornadoEditor_TOnOpenProjectClickHandler_n, nsTornadoEditor_TOnOpenProjectClickHandler_i });
    
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
