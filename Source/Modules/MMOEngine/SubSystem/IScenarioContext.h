/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/BreakPacket.h"
#include "MMOEngine/SubSystem/StateTimeWait.h"

class TSrcEvent;
namespace nsMMOEngine
{
    class TScContextManager;
    class TSessionManager;
    class IScenario;
    class IScenarioContext
    {
        void* mUserPtr;
        unsigned int       mSessionID;
        TScContextManager* mManagerContextSc;
        TSessionManager* mSessionManager;
        TSrcEvent* mSrcEvent;

        IScenario* mScenario;
    protected:
        TBreakPacket mBP;
        TStateTimeWait mStateTimeWait;
    public:
        IScenarioContext();
        virtual ~IScenarioContext();

        bool Activate();
        void Deactivate();

        void DelayBegin();
        void Work();

        void SetSc(IScenario* pSc);
        IScenario* GetSc();

        void SetSessionID(unsigned int id);
        unsigned int GetSessionID();

        void SetMSc(TScContextManager* pMSc);
        TScContextManager* GetMSc();

        void SetMS(TSessionManager* pMS);
        TSessionManager* GetMS();

        void SetSE(TSrcEvent* pMS);
        TSrcEvent* GetSE();

        void SetUserPtr(void* p);
        void* GetUserPtr();
    protected:
    };
}