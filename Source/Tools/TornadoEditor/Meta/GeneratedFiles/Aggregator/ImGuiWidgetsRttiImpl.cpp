/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2025_01_30 15:40:58.491
#include "ImGuiWidgetsRttiImpl.h"

#include "TornadoEngine\GeneratedFiles\Container\ImGuiWidgetsRtti.h"

using namespace nsTornadoEditor;

TImGuiWidgetsRttiImpl::TImGuiWidgetsRttiImpl()
{
    auto typeNameList = nsTornadoEngine::TImGuiWidgetsRtti::GetTypeNameList();
    mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());
    
    auto rttiList = nsTornadoEngine::TImGuiWidgetsRtti::GetRttiList();
    mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());
}
//--------------------------------------------------------------------------------------------------
TImGuiWidgetsRttiImpl::~TImGuiWidgetsRttiImpl()
{

}
//--------------------------------------------------------------------------------------------------
void TImGuiWidgetsRttiImpl::Init()
{
    nsTornadoEngine::TImGuiWidgetsRtti::Init();
}
//--------------------------------------------------------------------------------------------------
const std::list<std::string>* TImGuiWidgetsRttiImpl::GetTypeNameList()
{
    return &mTypeNameList;
}
//--------------------------------------------------------------------------------------------------
const std::list<int>* TImGuiWidgetsRttiImpl::GetRunTimeTypeIndexList()
{
    return &mRttiList;
}
//--------------------------------------------------------------------------------------------------
bool TImGuiWidgetsRttiImpl::ConvertTypeToName(int rtti, std::string & typeName)
{
    auto pTypeName = nsTornadoEngine::TImGuiWidgetsRtti::ConvertRttiToName(rtti);
    if (pTypeName != nullptr) {
        typeName = *pTypeName;
        return true;
    }
    return false;
}
//--------------------------------------------------------------------------------------------------
bool TImGuiWidgetsRttiImpl::ConvertNameToType(const std::string & typeName, int& rtti)
{
    return nsTornadoEngine::TImGuiWidgetsRtti::ConvertNameToRtti(typeName, rtti);
}
//--------------------------------------------------------------------------------------------------
