/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator

#include "HandlerRttiImpl.h"

#include "GeneratedFiles\Container\HandlerRtti.h"

using namespace nsTornadoEditor;

THandlerRttiImpl::THandlerRttiImpl()
{
    auto typeNameList = THandlerRtti::GetTypeNameList();
    mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());
    
    auto rttiList = THandlerRtti::GetRttiList();
    mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());
}
//--------------------------------------------------------------------------------------------------
THandlerRttiImpl::~THandlerRttiImpl()
{

}
//--------------------------------------------------------------------------------------------------
void THandlerRttiImpl::Init()
{
    THandlerRtti::Init();
}
//--------------------------------------------------------------------------------------------------
const std::list<std::string>* THandlerRttiImpl::GetTypeNameList()
{
    return &mTypeNameList;
}
//--------------------------------------------------------------------------------------------------
const std::list<int>* THandlerRttiImpl::GetRunTimeTypeIndexList()
{
    return &mRttiList;
}
//--------------------------------------------------------------------------------------------------
bool THandlerRttiImpl::ConvertTypeToName(int rtti, std::string & typeName)
{
    auto pTypeName = THandlerRtti::ConvertRttiToName(rtti);
    if (pTypeName != nullptr) {
        typeName = *pTypeName;
        return true;
    }
    return false;
}
//--------------------------------------------------------------------------------------------------
bool THandlerRttiImpl::ConvertNameToType(const std::string & typeName, int& rtti)
{
    return THandlerRtti::ConvertNameToRtti(typeName, rtti);;
}
//--------------------------------------------------------------------------------------------------
