/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.2.5, build 56 [Json, Binary, ImGui, EntityManager, Reflection, TypeInformation]
// File has been generated at 2021_12_30 17:13:40.625
	
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
