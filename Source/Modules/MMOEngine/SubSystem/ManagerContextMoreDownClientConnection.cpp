/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <format>

#include "ManagerContextMoreDownClientConnection.h"

#include "Base/Common/EventHub.h"
#include "Base/Common/BL_Debug.h"

#include "ContainerContextSc.h"
#include "EnumMMO.h"

using namespace nsMMOEngine;
using namespace std;

TManagerContextMoreDownClientConnection::TManagerContextMoreDownClientConnection(TBase* pBase) :
    TDelegateManagerContextSc(pBase)
{

}
//-------------------------------------------------------------------------
TManagerContextMoreDownClientConnection::~TManagerContextMoreDownClientConnection()
{
    Clear();
}
//-------------------------------------------------------------------------
bool TManagerContextMoreDownClientConnection::FindSessionByClientKey(unsigned int clientKey, unsigned int& sessionID)
{
    TMapUintUintIt fit = mMapKeySession.find(clientKey);
    if (fit == mMapKeySession.end()) {
        nsBase::nsCommon::GetEventHub()->
            AddWarningEvent(std::format("TManagerContextMoreDownClientConnection::FindSessionByClientKey(key=%u) not found.", clientKey));
        return false;
    }
    sessionID = fit->second;
    return true;
}
//-------------------------------------------------------------------------
TContainerContextSc* TManagerContextMoreDownClientConnection::FindContextByClientKey(unsigned int clientKey)
{
    TMapUintPtrIt fit = mMapKeyContext.find(clientKey);
    if (fit == mMapKeyContext.end()) {
        nsBase::nsCommon::GetEventHub()->
            AddWarningEvent(std::format("TManagerContextMoreDownClientConnection::FindContextByClientKey(key=%u) not found.", clientKey));
        return nullptr;
    }
    return fit->second;
}
//-------------------------------------------------------------------------
TContainerContextSc* TManagerContextMoreDownClientConnection::AddContext(unsigned int clientKey, unsigned int sessionID)
{
    BL_ASSERT(sessionID != INVALID_HANDLE_SESSION);

    TContainerContextSc* pC = FindContextByClientKey(clientKey);
    if (pC == nullptr) {
        pC = AddContainer();

        mMapKeyContext.insert({ clientKey, pC });
        mMapKeySession.insert({ clientKey, sessionID });

        pC->SetSessionID(sessionID);
    }
    return pC;
}
//-------------------------------------------------------------------------
void TManagerContextMoreDownClientConnection::DeleteByKey(unsigned int key)
{
    TContainerContextSc* pC = FindContextByClientKey(key);
    if (pC == nullptr)
        return;

    DeleteContainer(pC);
    mMapKeyContext.erase(key);
    mMapKeySession.erase(key);
}
//-------------------------------------------------------------------------
void TManagerContextMoreDownClientConnection::Clear()
{
    for (auto& bit : mMapKeyContext)
        DeleteContainer(bit.second);

    mMapKeyContext.clear();
    mMapKeySession.clear();
}
//-------------------------------------------------------------------------
bool TManagerContextMoreDownClientConnection::SetSessionByClientKey(unsigned int clientKey, unsigned int sessionID)
{
    TMapUintUintIt fit = mMapKeySession.find(clientKey);
    if (fit == mMapKeySession.end()) {
        nsBase::nsCommon::GetEventHub()->
            AddWarningEvent(std::format("TManagerContextMoreDownClientConnection::SetSessionByClientKey(key=%u) not found.", clientKey));
        return false;
    }
    fit->second = sessionID;
    // изменить номер сессии для всех контекстов
    TContainerContextSc* pC = FindContextByClientKey(clientKey);
    if (pC)
        pC->SetSessionID(sessionID);

    return true;
}
//-------------------------------------------------------------------------
void TManagerContextMoreDownClientConnection::EntrustContext(unsigned int clientKey, unsigned int sessionID, TContainerContextSc* pContext)
{
    BL_ASSERT(sessionID != INVALID_HANDLE_SESSION);

    mMapKeyContext.insert({ clientKey, pContext });
    mMapKeySession.insert({ clientKey, sessionID });

    pContext->SetSessionID(sessionID);
}
//-------------------------------------------------------------------------
