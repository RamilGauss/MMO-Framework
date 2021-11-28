/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "HandlerTypeInformationImpl.h"

#include "HandlerTypeInformation.h"
#include "TornadoEngine/Generated files/HandlerTypeInformation.h"

using namespace nsTornadoEditor;

THandlerTypeInformationImpl::THandlerTypeInformationImpl()
{
    auto typeNameList = THandlerTypeInformation::GetTypeNameList();
    mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());

    typeNameList = nsTornadoEngine::THandlerTypeInformation::GetTypeNameList();
    mTypeNameList.insert(mTypeNameList.end(), typeNameList->begin(), typeNameList->end());

    auto rttiList = THandlerTypeInformation::GetRttiList();
    mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());

    rttiList = nsTornadoEngine::THandlerTypeInformation::GetRttiList();
    mRttiList.insert(mRttiList.end(), rttiList->begin(), rttiList->end());
}
//------------------------------------------------------------------------------
THandlerTypeInformationImpl::~THandlerTypeInformationImpl()
{

}
//------------------------------------------------------------------------------
const std::list<std::string>* THandlerTypeInformationImpl::GetTypeNameList()
{
    return &mTypeNameList;
}
//------------------------------------------------------------------------------
const std::list<int>* THandlerTypeInformationImpl::GetRunTimeTypeIndexList()
{
    return &mRttiList;
}
//------------------------------------------------------------------------------
bool THandlerTypeInformationImpl::ConvertTypeToName(int rtti, std::string& typeName)
{
    auto pTypeName = THandlerTypeInformation::ConvertRttiToName(rtti);
    if (pTypeName != nullptr) {
        typeName = *pTypeName;
        return true;
    }
    pTypeName = nsTornadoEngine::THandlerTypeInformation::ConvertRttiToName(rtti);
    if (pTypeName != nullptr) {
        typeName = *pTypeName;
        return true;
    }
    return false;
}
//------------------------------------------------------------------------------
bool THandlerTypeInformationImpl::ConvertNameToType(const std::string& typeName, int& rtti)
{
    auto result = THandlerTypeInformation::ConvertNameToRtti(typeName, rtti);
    if (result) {
        return true;
    }
    return nsTornadoEngine::THandlerTypeInformation::ConvertNameToRtti(typeName, rtti);
}
//------------------------------------------------------------------------------
