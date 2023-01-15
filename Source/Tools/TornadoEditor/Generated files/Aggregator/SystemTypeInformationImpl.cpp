/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_01_15 11:03:02.045
	
#include "SystemTypeInformationImpl.h"

#include "Generated files\Container\EcsTypeInfo.h"

using namespace nsTornadoEditor;

TSystemTypeInformationImpl::TSystemTypeInformationImpl()
{
    auto typeNameList = TEcsTypeInfo::GetTypeNameList();
    mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());
    
    auto rttiList = TEcsTypeInfo::GetRttiList();
    mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());
}
//--------------------------------------------------------------------------------------------------
TSystemTypeInformationImpl::~TSystemTypeInformationImpl()
{
    
}
//--------------------------------------------------------------------------------------------------
const std::list<std::string>* TSystemTypeInformationImpl::GetTypeNameList()
{
    return &mTypeNameList;
}
//--------------------------------------------------------------------------------------------------
const std::list<int>* TSystemTypeInformationImpl::GetRunTimeTypeIndexList()
{
    return &mRttiList;
}
//--------------------------------------------------------------------------------------------------
bool TSystemTypeInformationImpl::ConvertTypeToName(int rtti, std::string& typeName)
{
    auto pTypeName = TEcsTypeInfo::ConvertRttiToName(rtti);
    if (pTypeName != nullptr) {
        typeName = *pTypeName;
        return true;
    }
    return false;
}
//--------------------------------------------------------------------------------------------------
bool TSystemTypeInformationImpl::ConvertNameToType(const std::string& typeName, int& rtti)
{
    return TEcsTypeInfo::ConvertNameToRtti(typeName, rtti);;
}
//--------------------------------------------------------------------------------------------------
