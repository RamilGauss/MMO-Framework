/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>
#include <string>

#include "Base/Common/BreakPacket.h"
#include "Base/Common/ShareMisc.h"

#include "MMOEngine/SubSystem/IScenarioContext.h"

namespace nsMMOEngine
{
    class TContextScLoginClient : public IScenarioContext
    {
    public:
        enum StateWait
        {
            MasterWaitDeveloper,
            MasterWaitInQueue,
            MasterWaitSuperServer,
            MasterWaitSlave,
            MasterWaitClient,
            MasterWaitClientConnectToSlave,

            ClientWaitMasterAnswer,
            ClientWaitSlaveInfo,
            ClientWaitDisconnectFromMaster,
            ClientWaitSlaveAnswer,
            ClientWaitInQueue,

            SlaveWaitClient,
            SlaveWaitMaster,

            NoWait,
        };
        enum tStateResult
        {
            eUndef,
            eReject,
            eAccept,
        };
    private:

        tStateResult mState;

        int mNumInQueue;

        bool flgConnected = false;
        unsigned int mTimeLastNeedNumInQueue;

        unsigned int mDeltaTimeWait_ms;

        typedef std::map<std::string, unsigned int> TMapStrUint;
        typedef TMapStrUint::iterator TMapStrUintIt;
        TMapStrUint mMapStrID_Session;

        TContainer mAcceptData;
        TContainer mQueueData;

        unsigned int mClientKey;

        TIP_Port mIP_Port_slave;

        bool flgFakeClient;

        bool flgNeedLeaveQueue;

        unsigned char mSubNet;

        std::string mLogin;
        std::string mPassword;

        // используется на стороне Slave для определения стартовал ли контекст
        bool flgWasBegin;

    public:
        TContextScLoginClient();
        virtual ~TContextScLoginClient();

        bool WasBegin();
        void SetWasBegin();

        unsigned int GetClientKey();
        void SetClientKey(unsigned int id);

        unsigned int GetDeltaTimeWaitMS();
        void SetDeltaTimeWaitMS(unsigned int delta);

        void SetTimeLastNeedNumInQueue(unsigned int v);
        unsigned int GetTimeLastNeedNumInQueue();

        void Accept();
        void Reject();

        bool IsReject();
        bool IsAccept();

        unsigned int GetID_SessionClientMaster();
        void SetID_SessionClientMaster(unsigned int id);
        unsigned int GetID_SessionClientSlave();
        void SetID_SessionClientSlave(unsigned int id);
        unsigned int GetID_SessionMasterSlave();
        void SetID_SessionMasterSlave(unsigned int id);
        unsigned int GetID_SessionMasterSS();
        void SetID_SessionMasterSS(unsigned int id);

        bool IsConnectUp();

        void SetNumInQueue(int val);
        int  GetNumInQueue();

        void SaveAcceptData(void* resForClient, int sizeResClient);
        void* GetSaveAcceptDataPtr();
        int   GetSaveAcceptDataSize();

        void SaveQueueData(void* resForClient, int sizeResClient);
        void* GetSaveQueueDataPtr();
        int   GetSaveQueueDataSize();

        void SetNeedLeaveQueue(bool val);
        bool NeedLeaveQueue();

        TIP_Port GetSlaveIP_Port();
        void SetSlaveIP_Port(TIP_Port& ip_port);

        // только для SuperServer
        bool GetFakeClient();
        void SetFakeClient(bool val);

        void SetSubNet(unsigned char v);
        unsigned char GetSubNet();

        void SetLogin(const std::string& login);
        std::string GetLogin();

        void SetPassword(const std::string& password);
        std::string GetPassword();

        void SetCurrentStateWait(StateWait state);
        bool IsStateTimeExpired(unsigned int now);

        unsigned int GetCurrentStateErrorCode();

    private:
        void SetSessionID(std::string& name, unsigned int id);
        unsigned int GetSessionID(std::string& name);
    };
}
