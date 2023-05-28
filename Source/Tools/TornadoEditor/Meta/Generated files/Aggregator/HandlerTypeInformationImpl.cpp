/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2023_05_28 18:14:10.746
	
#include "HandlerTypeInformationImpl.h"

#include "Generated files\Container\HandlerTypeInfo.h"

using namespace nsTornadoEditor;

THandlerTypeInformationImpl::THandlerTypeInformationImpl()
{
    auto typeNameList = THandlerTypeInfo::GetTypeNameList();
    mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());
    
    auto rttiList = THandlerTypeInfo::GetRttiList();
    mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());
}
//--------------------------------------------------------------------------------------------------
THandlerTypeInformationImpl::~THandlerTypeInformationImpl()
{

}
//--------------------------------------------------------------------------------------------------
const std::list<std::string>* THandlerTypeInformationImpl::GetTypeNameList()
{
    return &mTypeNameList;
}
//--------------------------------------------------------------------------------------------------
const std::list<int>* THandlerTypeInformationImpl::GetRunTimeTypeIndexList()
{
    return &mRttiList;
}
//--------------------------------------------------------------------------------------------------
bool THandlerTypeInformationImpl::ConvertTypeToName(int rtti, std::string & typeName)
{
    auto pTypeName = THandlerTypeInfo::ConvertRttiToName(rtti);
    if (pTypeName != nullptr) {
        typeName = *pTypeName;
        return true;
    }
    return false;
}
//--------------------------------------------------------------------------------------------------
bool THandlerTypeInformationImpl::ConvertNameToType(const std::string & typeName, int& rtti)
{
    return THandlerTypeInfo::ConvertNameToRtti(typeName, rtti);;
}
//--------------------------------------------------------------------------------------------------
