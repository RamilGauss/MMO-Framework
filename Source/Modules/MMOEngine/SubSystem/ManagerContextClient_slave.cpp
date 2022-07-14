/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ManagerContextClient_slave.h"

#include "Logger.h"
#include "ContainerContextSc.h"
#include "EnumMMO.h"

using namespace nsMMOEngine;
using namespace std;

TManagerContextClient_slave::TManagerContextClient_slave(TBase* pBase) :
    TDelegateManagerContextSc(pBase)
{

}
//-------------------------------------------------------------------------
TManagerContextClient_slave::~TManagerContextClient_slave()
{
    Clear();
}
//-------------------------------------------------------------------------
bool TManagerContextClient_slave::FindSessionByKey(unsigned int id, unsigned int& sessionID)
{
    return FindInMapUintUint(mMapKeySession, id, sessionID);
}
//-------------------------------------------------------------------------
bool TManagerContextClient_slave::FindKeyBySession(unsigned int sessionID, unsigned int& id)
{
    return FindInMapUintUint(mMapSessionKey, sessionID, id);
}
//-------------------------------------------------------------------------
TContainerContextSc* TManagerContextClient_slave::FindContextByKey(unsigned int id)
{
    TMapUintPtrIt fit = mMapKeyContext.find(id);
    if (fit == mMapKeyContext.end()) {
        GetLogger(STR_NAME_MMO_ENGINE)->
            WriteF_time("TManagerContextClient_slave::FindContextByKey(key=%u) not found.\n", id);
        return nullptr;
    }
    return fit->second;
}
//-------------------------------------------------------------------------
TContainerContextSc* TManagerContextClient_slave::FindContextBySession(unsigned int sessionID)
{
    unsigned int id;
    if (FindKeyBySession(sessionID, id) == false)
        return nullptr;
    return FindContextByKey(id);
}
//-------------------------------------------------------------------------
bool TManagerContextClient_slave::GetSessionByIndex(int index, unsigned int& sessionID)
{
    if (index >= GetCountSession() || index < 0) {
        GetLogger(STR_NAME_MMO_ENGINE)->
            WriteF_time("TManagerContextClient_slave::GetSessionByIndex() index=%d is out of band c=%d.\n",
                index, GetCountSession());
        return false;
    }
    TMapUintUintIt it = mMapSessionKey.begin();
    for (int i = 0; i < index; i++)// + index
        it++;
    sessionID = it->first;
    return true;
}
//-------------------------------------------------------------------------
int TManagerContextClient_slave::GetCountSession()
{
    return mMapSessionKey.size();
}
//-------------------------------------------------------------------------
bool TManagerContextClient_slave::GetFirstKey(unsigned int& id)
{
    if (GetCountKey() == 0)
        return false;
    id = mMapKeyContext.begin()->first;
    return true;
}
//-------------------------------------------------------------------------
int TManagerContextClient_slave::GetCountKey()
{
    return mMapKeyContext.size();
}
//-------------------------------------------------------------------------
TContainerContextSc* TManagerContextClient_slave::AddContextByKey(unsigned int id)
{
    // проверка на существование ключа
    TContainerContextSc* pC = FindContextByKey(id);
    if (pC) {
        BL_FIX_BUG();
        return pC;
    }
    pC = AddContainer();

    mMapKeyContext.insert(TMapUintPtr::value_type(id, pC));
    mMapKeySession.insert(TMapUintUint::value_type(id, INVALID_HANDLE_SESSION));
    return pC;
}
//-------------------------------------------------------------------------
void TManagerContextClient_slave::AddSessionByKey(unsigned int id, unsigned int sessionID)
{
    BL_ASSERT(sessionID != INVALID_HANDLE_SESSION);

    TMapUintUintIt fit = mMapKeySession.find(id);
    if (fit == mMapKeySession.end()) {
        GetLogger(STR_NAME_MMO_ENGINE)->
            WriteF_time("TManagerContextClient_slave::SetSessionByKey(key=%u) not found.\n", id);
        BL_FIX_BUG();
        return;
    }
    fit->second = sessionID;

    unsigned int key_for_check;
    if (FindKeyBySession(sessionID, key_for_check)) {
        BL_FIX_BUG();
        return;
    }

    mMapSessionKey.insert(TMapUintUint::value_type(sessionID, id));
}
//-------------------------------------------------------------------------
void TManagerContextClient_slave::DeleteByKey(unsigned int key)
{
    TContainerContextSc* pC = FindContextByKey(key);
    if (pC == nullptr)
        return;

    DeleteContainer(pC);

    unsigned int sessionID;
    bool findSession = FindSessionByKey(key, sessionID);

    mMapKeyContext.erase(key);
    mMapKeySession.erase(key);

    if (findSession)
        mMapSessionKey.erase(sessionID);
}
//-------------------------------------------------------------------------
void TManagerContextClient_slave::Clear()
{
    for (auto& bit : mMapKeyContext)
        DeleteContainer(bit.second);

    mMapKeyContext.clear();
    mMapKeySession.clear();
    mMapSessionKey.clear();
}
//-------------------------------------------------------------------------
bool TManagerContextClient_slave::FindInMapUintUint(TMapUintUint& map, unsigned int key, unsigned int& value)
{
    TMapUintUintIt fit = map.find(key);
    if (fit == map.end()) {
        GetLogger(STR_NAME_MMO_ENGINE)->
            WriteF_time("TManagerContextClient_slave::FindInMapUintUint(key=%u) not found.\n", key);
        return false;
    }
    value = fit->second;
    return true;
}
//-------------------------------------------------------------------------
