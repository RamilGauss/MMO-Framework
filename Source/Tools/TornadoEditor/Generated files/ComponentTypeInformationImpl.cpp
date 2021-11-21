/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ComponentTypeInformationImpl.h"

#include "ComponentTypeInformation.h"
#include "TornadoEngine/Generated files/ComponentTypeInformation.h"

using namespace nsTornadoEditor;

TComponentTypeInformationImpl::TComponentTypeInformationImpl()
{
    auto typeNameList = TComponentTypeInformation::GetTypeNameList();
    mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());

    typeNameList = nsTornadoEngine::TComponentTypeInformation::GetTypeNameList();
    mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());

    auto rttiList = TComponentTypeInformation::GetRttiList();
    mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());

    rttiList = nsTornadoEngine::TComponentTypeInformation::GetRttiList();
    mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());
}
//------------------------------------------------------------------------------
TComponentTypeInformationImpl::~TComponentTypeInformationImpl()
{

}
//------------------------------------------------------------------------------
const std::list<std::string>* TComponentTypeInformationImpl::GetTypeNameList()
{
    return &mTypeNameList;
}
//------------------------------------------------------------------------------
const std::list<int>* TComponentTypeInformationImpl::GetRunTimeTypeIndexList()
{
    return &mRttiList;
}
//------------------------------------------------------------------------------
bool TComponentTypeInformationImpl::ConvertTypeToName(int rtti, std::string& typeName)
{
    auto pTypeName = TComponentTypeInformation::ConvertRttiToName(rtti);
    if (pTypeName != nullptr) {
        typeName = *pTypeName;
        return true;
    }
    pTypeName = nsTornadoEngine::TComponentTypeInformation::ConvertRttiToName(rtti);
    if (pTypeName != nullptr) {
        typeName = *pTypeName;
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
bool TComponentTypeInformationImpl::ConvertNameToType(const std::string& typeName, int& rtti)
{
    auto result = TComponentTypeInformation::ConvertNameToRtti(typeName, rtti);
    if (result) {
        return true;
    }
    return nsTornadoEngine::TComponentTypeInformation::ConvertNameToRtti(typeName, rtti);
}
//------------------------------------------------------------------------------
