/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "MMOEngine/SubSystem/ScContextManager.h"

#include "MMOEngine/ScenarioContext/ContextScDisconnectClient.h"
#include "MMOEngine/ScenarioContext/ContextScFlow.h"
#include "MMOEngine/ScenarioContext/ContextScLoginClient.h"
#include "MMOEngine/ScenarioContext/ContextScLoginSlave.h"
#include "MMOEngine/ScenarioContext/ContextScLoginMaster.h"
#include "MMOEngine/ScenarioContext/ContextScRecommutationClient.h"
#include "MMOEngine/ScenarioContext/ContextScSynchroSlave.h"
#include "MMOEngine/ScenarioContext/ContextScSendToClient.h"

namespace nsMMOEngine
{
    // сценарии, содержащиеся в контейнере взаимно блокируются
    class TContainerContextSc
    {
        typedef std::list<IScenarioContext*> TListPtr;
        TListPtr mListContext;

        unsigned int mSessionID;
    protected:
        TScContextManager* mManagerContextSc;
    public:
        TContextScDisconnectClient    mDisClient;
        TContextScFlow                mFlow;
        TContextScLoginClient         mLoginClient;
        TContextScLoginSlave          mLoginSlave;
        TContextScLoginMaster         mLoginMaster;
        TContextScRecommutationClient mRcm;
        TContextScSynchroSlave        mSynchroSlave;
        TContextScSendToClient        mSendToClient;

        TContainerContextSc();

        void SetMCSc(TScContextManager* pMCSc);
        TScContextManager* GetMCSc();

        void SetSessionID(unsigned int sessionID);
        unsigned int GetSessionID();
        void SetMS(TSessionManager* pMS);
        void SetSE(TSrcEvent* pSE);
        void SetUserPtr(void* p);

        bool IsRcmActive();
        bool IsLoginClientActive();
    };
}