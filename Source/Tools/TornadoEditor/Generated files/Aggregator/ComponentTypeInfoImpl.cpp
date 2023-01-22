/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_01_20 18:48:00.178
	
#include "ComponentTypeInfoImpl.h"

#include "Generated files\Container\ComponentTypeInfo.h"
#include "TornadoEngine\Generated files\Container\ComponentTypeInfo.h"

using namespace nsTornadoEditor;

TComponentTypeInfoImpl::TComponentTypeInfoImpl()
{
    auto typeNameList = TComponentTypeInfo::GetTypeNameList();
    mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());
    
    typeNameList = nsTornadoEngine::TComponentTypeInfo::GetTypeNameList();
    mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());
    
    auto rttiList = TComponentTypeInfo::GetRttiList();
    mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());
    
    rttiList = nsTornadoEngine::TComponentTypeInfo::GetRttiList();
    mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());
}
//--------------------------------------------------------------------------------------------------
TComponentTypeInfoImpl::~TComponentTypeInfoImpl()
{
    
}
//--------------------------------------------------------------------------------------------------
const std::list<std::string>* TComponentTypeInfoImpl::GetTypeNameList()
{
    return &mTypeNameList;
}
//--------------------------------------------------------------------------------------------------
const std::list<int>* TComponentTypeInfoImpl::GetRunTimeTypeIndexList()
{
    return &mRttiList;
}
//--------------------------------------------------------------------------------------------------
bool TComponentTypeInfoImpl::ConvertTypeToName(int rtti, std::string& typeName)
{
    auto pTypeName = TComponentTypeInfo::ConvertRttiToName(rtti);
    if (pTypeName != nullptr) {
        typeName = *pTypeName;
        return true;
    }
    pTypeName = nsTornadoEngine::TComponentTypeInfo::ConvertRttiToName(rtti);
    if (pTypeName != nullptr) {
        typeName = *pTypeName;
        return true;
    }
    return false;
}
//--------------------------------------------------------------------------------------------------
bool TComponentTypeInfoImpl::ConvertNameToType(const std::string& typeName, int& rtti)
{
    auto result = TComponentTypeInfo::ConvertNameToRtti(typeName, rtti);
    if (result) {
        return true;
    }
    return nsTornadoEngine::TComponentTypeInfo::ConvertNameToRtti(typeName, rtti);
}
//--------------------------------------------------------------------------------------------------
