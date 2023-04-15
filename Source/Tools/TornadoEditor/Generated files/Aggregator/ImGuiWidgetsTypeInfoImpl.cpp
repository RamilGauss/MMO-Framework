/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_03_30 15:33:35.569
	
#include "ImGuiWidgetsTypeInfoImpl.h"

#include "TornadoEngine\Generated files\Container\ImGuiWidgetsTypeInfo.h"

using namespace nsTornadoEditor;

TImGuiWidgetsTypeInfoImpl::TImGuiWidgetsTypeInfoImpl()
{
    auto typeNameList = nsTornadoEngine::TImGuiWidgetsTypeInfo::GetTypeNameList();
    mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());
    
    auto rttiList = nsTornadoEngine::TImGuiWidgetsTypeInfo::GetRttiList();
    mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());
}
//--------------------------------------------------------------------------------------------------
TImGuiWidgetsTypeInfoImpl::~TImGuiWidgetsTypeInfoImpl()
{
    
}
//--------------------------------------------------------------------------------------------------
const std::list<std::string>* TImGuiWidgetsTypeInfoImpl::GetTypeNameList()
{
    return &mTypeNameList;
}
//--------------------------------------------------------------------------------------------------
const std::list<int>* TImGuiWidgetsTypeInfoImpl::GetRunTimeTypeIndexList()
{
    return &mRttiList;
}
//--------------------------------------------------------------------------------------------------
bool TImGuiWidgetsTypeInfoImpl::ConvertTypeToName(int rtti, std::string& typeName)
{
    auto pTypeName = nsTornadoEngine::TImGuiWidgetsTypeInfo::ConvertRttiToName(rtti);
    if (pTypeName != nullptr) {
        typeName = *pTypeName;
        return true;
    }
    return false;
}
//--------------------------------------------------------------------------------------------------
bool TImGuiWidgetsTypeInfoImpl::ConvertNameToType(const std::string& typeName, int& rtti)
{
    return nsTornadoEngine::TImGuiWidgetsTypeInfo::ConvertNameToRtti(typeName, rtti);
}
//--------------------------------------------------------------------------------------------------
