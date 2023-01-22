/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "DstEvent.h"
#include "MMOEngine/include/BaseEvent.h"
#include "MMOEngine/include/Client.h"
#include <unordered_set>
#include <unordered_map>

class THandlerMMO : public TDstEvent
{
    nsMMOEngine::TBase* mBase = nullptr;

public:
    enum TypeMMO
    {
        eClient, eSlave, eMaster, eSuperServer
    };

    THandlerMMO(nsMMOEngine::TBase* pBase, TypeMMO type);
    void Work();

    virtual void WorkInherit()
    {};

    static int GetCountConnection(TypeMMO type);

    void AddConnection(unsigned int sessionID);
    void RemoveConnection(unsigned int sessionID);

    void AddConnectedClient(nsMMOEngine::TClient* pClient);
    void RemoveConnectedClient(nsMMOEngine::TClient* pClient);


    void AddClient(unsigned int clientKey);
    void RemoveClient(unsigned int clientKey);

    void AddTryConnectClientToMaster(unsigned int sessionID);

    nsMMOEngine::TBase* GetBase();
protected:
    virtual void HandleFromMMOEngine(nsEvent::TEvent* pEvent) = 0;

    static std::string ToString(TypeMMO type);

public:
    static void PrintCC(const char* loggerName);

    typedef std::unordered_set<nsMMOEngine::TClient*> TSetClient;
    typedef std::unordered_set<unsigned int> TSetUInt;
    typedef std::unordered_map<THandlerMMO::TypeMMO, TSetUInt> TMapTypeMMOSetUInt;
    typedef std::unordered_map<unsigned int, TSetUInt> TMapUIntSetUInt;
    typedef std::unordered_map<unsigned int, THandlerMMO*> TMapUIntPtr;

    static TSetUInt* GetClientKeySet();
private:
    TypeMMO mType;

    unsigned int mID;
};

