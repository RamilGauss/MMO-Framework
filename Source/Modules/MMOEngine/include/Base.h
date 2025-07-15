/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once


#include <list>
#include <memory>

#include "Base/Common/TypeDef.h"
#include "Base/Common/SrcEvent.h"

#include "MMOEngine/Include/Structs.h"
#include "MMOEngine/Include/IMakerTransport.h"
#include "MMOEngine/Include/EnumMMO.h"

namespace nsECSFramework
{
    class TEntityManager;
}

namespace nsMMOEngine
{
    class TSessionManager;
    struct TTryConnectDown;
    struct TDescConnectUp;
    class TScContextManager;
    class TManagerManagerContextSc;
    class TContainerContextSc;
    class TControlScenario;
    class TDelegateManagerContextSc;
    class IScenario;
    struct TDescRecvSession;
    struct TDescRequestConnectForRecipient;
    class DllExport TBase : public TSrcEvent
    {
        // для доступа к Base
        friend class TBaseLogic;
        friend class TBaseMasterLogic;
        friend class TRCMLogic;
        friend class TGroupLogic;
        friend class TSlaveOnMasterLogic;
        friend class TClientOnMasterLogic;

        std::shared_ptr<TManagerManagerContextSc> mMngMngContextSc;
    protected:

        // mini ECS
        std::shared_ptr<nsECSFramework::TEntityManager> mEntMng;

        std::shared_ptr<TControlScenario>    mControlSc;
        std::shared_ptr<TContainerContextSc> mContainerUp;

        // уведомления о разрыве связи
        using TListUint = rigtorp::MPMCQueue<std::shared_ptr<unsigned int>>;
        TListUint mDisconnectSessionID;
        // полученные пакеты от mSessionManager
        using TListRecvPacket = rigtorp::MPMCQueue< std::shared_ptr<TDescRecvSession>>;
        TListRecvPacket mRecvPacket;

        using TListTryConnectDown = rigtorp::MPMCQueue< std::shared_ptr<TTryConnectDown>>;
        TListTryConnectDown mTryConnectDown;

        // транспорт
        std::shared_ptr<TSessionManager> mSessionManager;
        // загрузка CPU
        float mLoadProcent = 0;// затраченное время/выделенное, %

        unsigned int mSessionUpID = INVALID_HANDLE_SESSION;

        typedef std::list<TContainerContextSc*> TListPtr;

        TListPtr mListDelayDeleteContainerSc;

        TBreakPacket mBP;
    public:
        TBase();
        virtual ~TBase();

        virtual void Init(IMakerTransport* pMakerTransport);
        virtual bool Open(TDescOpen* pDesc, int count = 1);// подготовка для использования транспорта, count - кол-во всех используемых подсетей
        virtual void DisconnectUp();
        virtual void SendUp(char* p, int size, bool check = true);
        void Work();
        virtual bool IsConnectUp();
        virtual bool IsConnect(unsigned int id);
        virtual void SetLoad(float procent);
        virtual float GetLoad();

        virtual void SetTimeLiveSession(unsigned int time_ms);

        bool GetInfoSession(unsigned int sessionID, TIP_Port& ip_port);
    protected:
        void Recv(TDescRecvSession* pDescRecvSession);
        void Disconnect(unsigned int id);
        void TryConnectDown(TTryConnectDown* pTryConnectDown);

        virtual void DisconnectInherit(unsigned int id) = 0;
        virtual void WorkInherit() {}
        // события сценариев
        virtual void NeedContextDisconnectClient(unsigned int clientKey) {}
        //----------------------------------------------------
        // LoginClient
        virtual void NeedContextByMasterSessionByClientKey(unsigned int sessionID, unsigned int clientKey) {}//SS
        virtual void NeedContextLoginClientBySessionLeaveQueue(unsigned int sessionID) {}// S,M
        virtual void NeedContextLoginClientBySession(unsigned int sessionID) {}// S,M
        virtual void NeedContextLoginClientBySessionAfterAuthorised(unsigned int sessionID) {}// M
        virtual void NeedContextLoginClientByClientKey(unsigned int clientKey) {}//S,M,SS
        virtual void NeedContextLoginClientByClientKey_SecondCallSlave(unsigned int clientKey) {}//S
        virtual void NeedNumInQueueLoginClient(unsigned int sessionID) {}// M
        virtual void EventSetClientKeyLoginClient(unsigned int clientKey) {};//C
        virtual void NeedContextLoginClientByClientSessionByKeyClient(unsigned int id_session_client, unsigned int clientKey) {}//S
        //----------------------------------------------------
        // RCM
        virtual void NeedContextByRequestForRecipient(TDescRequestConnectForRecipient* p) {}// Slave
        virtual void NeedContextByClientSessionForSlaveRcm(unsigned sessionID, bool donor) {}
        virtual void NeedContextByClientForSlaveKeyRcm(unsigned int key, bool donor) {}
        virtual void NeedContextByClientKeyRcm(unsigned int key) {}
        virtual void NeedSlaveSessionDonorRcm(IScenario* pSc) {}//M
        virtual void EventActivateRcm(IScenario* pSc) {}//M
        virtual void EventDisconnectClientRcm(unsigned int key) {}// Slave
        virtual void EventTimeClientElapsedRcm(unsigned int key) {}// Slave
        //----------------------------------------------------
        virtual void NeedContextLoginSlave(unsigned int sessionID) {}
        virtual void NeedContextLoginMaster(unsigned int sessionID) {}
        virtual void NeedContextSendToClient(unsigned int clientKey) {}
        virtual void NeedContextSynchroSlave(unsigned int sessionID) {}

        virtual void EndDisconnectClient(IScenario* p) {}
        virtual void EndDisconnectSlave(IScenario* p) {}
        virtual void EndLoginClient(IScenario* p) {}
        virtual void EndLoginSlave(IScenario* p) {}
        virtual void EndLoginMaster(IScenario* p) {}
        virtual void EndRcm(IScenario* p) {}
        virtual void EndSynchroSlave(IScenario* p) {}
    private:
        TScContextManager* AddManagerContextSc();
        void RemoveManagerContextSc(TScContextManager* pMCSc);
    protected:
        friend class TDelegateManagerContextSc;
        void SetupScForContext(TContainerContextSc* pCCSc);
        void DelayDeleteContainerScenario(TContainerContextSc* pCCSc);
    private:
        void HandleTryConnectDownList();
        void HandleListDisconnect();
        void HandleListRecv();

        void DeleteContainerScenario();
    private:
        void SetDefualtContextForScenario();
        void RegisterOnScenarioEvent();
        void RegisterNeedForLoginClient();
        void RegisterNeedForRcmClient();
    protected:
        void SetupBP(char* p, int size);
    };
}
