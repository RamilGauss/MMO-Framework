/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "FeatureTypeInformationImpl.h"

#include "FeatureTypeInformation.h"
#include "TornadoEngine/Generated files/FeatureTypeInformation.h"

using namespace nsTornadoEditor;

TFeatureTypeInformationImpl::TFeatureTypeInformationImpl()
{
    auto typeNameList = TFeatureTypeInformation::GetTypeNameList();
    mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());

    typeNameList = nsTornadoEngine::TFeatureTypeInformation::GetTypeNameList();
    mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());

    auto rttiList = TFeatureTypeInformation::GetRttiList();
    mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());

    rttiList = nsTornadoEngine::TFeatureTypeInformation::GetRttiList();
    mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());
}
//------------------------------------------------------------------------------
TFeatureTypeInformationImpl::~TFeatureTypeInformationImpl()
{

}
//------------------------------------------------------------------------------
const std::list<std::string>* TFeatureTypeInformationImpl::GetTypeNameList()
{
    return &mTypeNameList;
}
//------------------------------------------------------------------------------
const std::list<int>* TFeatureTypeInformationImpl::GetRunTimeTypeIndexList()
{
    return &mRttiList;
}
//------------------------------------------------------------------------------
bool TFeatureTypeInformationImpl::ConvertTypeToName(int rtti, std::string& typeName)
{
    auto pTypeName = TFeatureTypeInformation::ConvertRttiToName(rtti);
    if (pTypeName != nullptr) {
        typeName = *pTypeName;
        return true;
    }
    pTypeName = nsTornadoEngine::TFeatureTypeInformation::ConvertRttiToName(rtti);
    if (pTypeName != nullptr) {
        typeName = *pTypeName;
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
bool TFeatureTypeInformationImpl::ConvertNameToType(const std::string& typeName, int& rtti)
{
    auto result = TFeatureTypeInformation::ConvertNameToRtti(typeName, rtti);
    if (result) {
        return true;
    }
    return nsTornadoEngine::TFeatureTypeInformation::ConvertNameToRtti(typeName, rtti);
}
//------------------------------------------------------------------------------
