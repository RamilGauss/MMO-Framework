/*
Author: Gudakov Ramil Sergeevich a.k.a.Gauss
Гудаков Рамиль Сергеевич
Contacts : [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

// ContainerCodeGenerator
// File has been generated at 2024_12_25 11:43:22.908
#include "ComponentRttiImpl.h"

#include "Generated files\Container\ComponentRtti.h"
#include "TornadoEngine\Generated files\Container\ComponentRtti.h"

using namespace nsTornadoEditor;

TComponentRttiImpl::TComponentRttiImpl()
{
    auto typeNameList = TComponentRtti::GetTypeNameList();
    mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());

    typeNameList = nsTornadoEngine::TComponentRtti::GetTypeNameList();
    mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());

    auto rttiList = TComponentRtti::GetRttiList();
    mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());

    rttiList = nsTornadoEngine::TComponentRtti::GetRttiList();
    mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());
}
//--------------------------------------------------------------------------------------------------
TComponentRttiImpl::~TComponentRttiImpl()
{

}
//--------------------------------------------------------------------------------------------------
void TComponentRttiImpl::Init()
{
    TComponentRtti::Init();
    nsTornadoEngine::TComponentRtti::Init();
}
//--------------------------------------------------------------------------------------------------
const std::list<std::string>* TComponentRttiImpl::GetTypeNameList()
{
    return &mTypeNameList;
}
//--------------------------------------------------------------------------------------------------
const std::list<int>* TComponentRttiImpl::GetRunTimeTypeIndexList()
{
    return &mRttiList;
}
//--------------------------------------------------------------------------------------------------
bool TComponentRttiImpl::ConvertTypeToName(int rtti, std::string& typeName)
{
    auto pTypeName = TComponentRtti::ConvertRttiToName(rtti);
    if (pTypeName != nullptr) {
        typeName = *pTypeName;
        return true;
    }
    pTypeName = nsTornadoEngine::TComponentRtti::ConvertRttiToName(rtti);
    if (pTypeName != nullptr) {
        typeName = *pTypeName;
        return true;
    }
    return false;
}
//--------------------------------------------------------------------------------------------------
bool TComponentRttiImpl::ConvertNameToType(const std::string& typeName, int& rtti)
{
    auto result = TComponentRtti::ConvertNameToRtti(typeName, rtti);
    if (result) {
        return true;
    }
    return nsTornadoEngine::TComponentRtti::ConvertNameToRtti(typeName, rtti);
}
//--------------------------------------------------------------------------------------------------
