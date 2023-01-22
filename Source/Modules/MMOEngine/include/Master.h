/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ActiveServer.h"

class TSetOrderElement;

namespace nsMMOEngine
{
    class TRCMLogic;
    class TGroupLogic;
    class TSlaveOnMasterLogic;
    class TClientOnMasterLogic;
    class DllExport TMaster : public TActiveServer
    {
        std::shared_ptr<TRCMLogic> mRCMLogic;
        std::shared_ptr<TGroupLogic> mGroupLogic;
        std::shared_ptr<TSlaveOnMasterLogic> mSlaveLogic;
        std::shared_ptr<TClientOnMasterLogic> mClientLogic;

    public:
        enum class tResultLogin
        {
            eAccept,
            eReject,
        };

        TMaster();

        virtual bool TryCreateGroup(std::list<unsigned int>& clientKeyList, unsigned int& groupID);
        virtual void DestroyGroup(unsigned int groupID);
        virtual void LeaveGroup(unsigned int clientKey);
        virtual void GetListForGroup(unsigned int groupID, std::list<unsigned int>& clientKeyList);
        virtual void SetResultLogin(bool res, unsigned int sessionID, unsigned int clientKey, // ключ, из БД например
            void* resForClient, int sizeResClient);
        virtual bool FindSlaveSessionByGroup(unsigned int groupID, unsigned int& sessionID);

        // BaseServer
        void SendByClientKey(std::list<unsigned int>& clientKeyList, char* p, int size) override;

        void GetDescDown(std::list<unsigned int>& sessionIDList) override;

        void SendDown(unsigned int sessionID, char* p, int size, bool check = true) override;
        // ActiveServer      
        void ConnectUp(TIP_Port& ip_port, const std::string& login, const std::string& password, unsigned char subNet = 0) override;
    protected:
        // Base
        void DisconnectInherit(unsigned int sessionID) override;
        void WorkInherit()  override {}
    protected:// like slots
              // DisconnectClient
        void NeedContextDisconnectClient(unsigned int clientKey) override;
        // LoginClient
        void NeedContextLoginClientBySessionLeaveQueue(unsigned int sessionID) override;
        void NeedContextLoginClientBySession(unsigned int sessionID) override;
        void NeedContextLoginClientBySessionAfterAuthorised(unsigned int sessionID) override;
        void NeedContextLoginClientByClientKey(unsigned int clientKey) override;
        void NeedNumInQueueLoginClient(unsigned int sessionID) override;
        // RCM
        void NeedContextByClientKeyRcm(unsigned int clientKey) override;
        void NeedSlaveSessionDonorRcm(IScenario* pSc) override;
        void EventActivateRcm(IScenario* pSc) override;
        // others
        void NeedContextLoginSlave(unsigned int sessionID) override;// login slave
        void NeedContextSynchroSlave(unsigned int sessionID) override;// synchro slave
        void NeedContextSendToClient(unsigned int clientKey) override;// send to client
    protected:
        void EndDisconnectClient(IScenario*) override;
        void EndLoginMaster(IScenario* pSc) override;
        void EndLoginSlave(IScenario* pSc) override;
        void EndLoginClient(IScenario* pSc) override;
        void EndRcm(IScenario* pSc) override;
        void EndSynchroSlave(IScenario* pSc) override;
    private:
        bool DisconnectSuperServer(unsigned int sessionID);
        bool DisconnectClientWait(unsigned int sessionID);
        bool DisconnectSlave(unsigned int sessionID);
    };
}
