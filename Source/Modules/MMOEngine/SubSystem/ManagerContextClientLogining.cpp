/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/


#include "Base/Common/GlobalEventHub.h"
#include "Base/Common/BL_Debug.h"

#include "MMOEngine/Include/EnumMMO.h"
#include "MMOEngine/SubSystem/ContainerContextSc.h"
#include "MMOEngine/SubSystem/ManagerContextClientLogining.h"

using namespace nsMMOEngine;

TManagerContextClientLogining::TManagerContextClientLogining(TBase* pBase) :
    TDelegateManagerContextSc(pBase)
{

}
//-------------------------------------------------------------------------------------------
TManagerContextClientLogining::~TManagerContextClientLogining()
{
    Clear();
}
//-------------------------------------------------------------------------------------------
bool TManagerContextClientLogining::FindSessionByClientKey(unsigned int clientKey, unsigned int& sessionID)
{
    auto fit = mMapSessionKey.right.find(clientKey);
    if (fit == mMapSessionKey.right.end()) {
        nsBase::nsCommon::GetEventHub()->
            AddWarningEvent("TManagerContextClientLogining::FindSessionByClientKey(clientKey={}) not found.", clientKey);
        return false;
    }
    sessionID = fit->second;
    return true;
}
//-------------------------------------------------------------------------------------------
bool TManagerContextClientLogining::FindClientKeyBySession(unsigned int sessionID, unsigned int& clientKey)
{
    auto fit = mMapSessionKey.left.find(sessionID);
    if (fit == mMapSessionKey.left.end()) {
        nsBase::nsCommon::GetEventHub()->
            AddWarningEvent("TManagerContextClientLogining::FindClientKeyBySession(session={}) not found.", sessionID);
        return false;
    }
    clientKey = fit->second;
    return true;
}
//-------------------------------------------------------------------------------------------
TContainerContextSc* TManagerContextClientLogining::FindContextBySession(unsigned int sessionID)
{
    TMapUintPtrIt fit = mMapSessionContext.find(sessionID);
    if (fit == mMapSessionContext.end()) {
        nsBase::nsCommon::GetEventHub()->
            AddWarningEvent("TManagerContextClientLogining::FindContextBySession(session={}) not found.", sessionID);
        return nullptr;
    }
    return fit->second;
}
//-------------------------------------------------------------------------------------------
TContainerContextSc* TManagerContextClientLogining::AddContext(unsigned int sessionID)
{
    BL_ASSERT(sessionID != INVALID_HANDLE_SESSION);

    TContainerContextSc* pC = FindContextBySession(sessionID);
    if (pC == nullptr) {
        pC = AddContainer();
        mMapSessionContext.insert(TMapUintPtr::value_type(sessionID, pC));
    }
    return pC;
}
//-------------------------------------------------------------------------------------------
bool TManagerContextClientLogining::AddKeyBySession(unsigned int sessionID, unsigned int clientKey)
{
    if (FindContextBySession(sessionID) == nullptr) {
        BL_FIX_BUG();
        return false;
    }

    mMapSessionKey.insert(sessionID, clientKey);
    return true;
}
//-------------------------------------------------------------------------------------------
void TManagerContextClientLogining::DeleteBySession(unsigned int sessionID)
{
    TContainerContextSc* pC = FindContextBySession(sessionID);
    if (pC == nullptr) {
        return;
    }

    DeleteContainer(pC);
    mMapSessionContext.erase(sessionID);
    mMapSessionKey.left.erase(sessionID);
}
//-------------------------------------------------------------------------------------------
void TManagerContextClientLogining::Clear()
{
    for (auto& bit : mMapSessionContext) {
        DeleteContainer(bit.second);
    }

    mMapSessionContext.clear();
    mMapSessionKey.Clear();
}
//-------------------------------------------------------------------------------------------
void TManagerContextClientLogining::UnlinkContextBySession(unsigned int sessionID)
{
    TContainerContextSc* pC = FindContextBySession(sessionID);
    if (pC == nullptr) {
        return;
    }

    mMapSessionContext.erase(sessionID);
    mMapSessionKey.left.erase(sessionID);
}
//-------------------------------------------------------------------------------------------
