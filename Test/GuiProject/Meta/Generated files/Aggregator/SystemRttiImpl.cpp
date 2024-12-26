/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2024_12_26 15:38:43.598
#include "SystemRttiImpl.h"

#include "Generated files\Container\EcsRtti.h"

using namespace nsTornadoEditor;

TSystemRttiImpl::TSystemRttiImpl()
{
    auto typeNameList = TEcsRtti::GetTypeNameList();
    mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());

    auto rttiList = TEcsRtti::GetRttiList();
    mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());
}
//--------------------------------------------------------------------------------------------------
TSystemRttiImpl::~TSystemRttiImpl()
{

}
//--------------------------------------------------------------------------------------------------
void TSystemRttiImpl::Init()
{
    TEcsRtti::Init();
}
//--------------------------------------------------------------------------------------------------
const std::list<std::string>* TSystemRttiImpl::GetTypeNameList()
{
    return &mTypeNameList;
}
//--------------------------------------------------------------------------------------------------
const std::list<int>* TSystemRttiImpl::GetRunTimeTypeIndexList()
{
    return &mRttiList;
}
//--------------------------------------------------------------------------------------------------
bool TSystemRttiImpl::ConvertTypeToName(int rtti, std::string& typeName)
{
    auto pTypeName = TEcsRtti::ConvertRttiToName(rtti);
    if (pTypeName != nullptr) {
        typeName = *pTypeName;
        return true;
    }
    return false;
}
//--------------------------------------------------------------------------------------------------
bool TSystemRttiImpl::ConvertNameToType(const std::string& typeName, int& rtti)
{
    return TEcsRtti::ConvertNameToRtti(typeName, rtti);
}
//--------------------------------------------------------------------------------------------------
