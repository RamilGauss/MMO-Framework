/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ActiveServer.h"

namespace nsMMOEngine
{
    class IScenario;
    class TManagerContextClient_slave;
    class DllExport TSlave : public TActiveServer
    {
        enum {
            eDeltaSynchro = 300,// мс
        };

        unsigned int mTimeNeedSendSynchro;
        std::shared_ptr<TManagerContextClient_slave> mMngContextClient;
        // только для Клиентов, которые считают текущий Slave реципиентом
        std::shared_ptr<TManagerContextClient_slave> mMngContextClientSlaveRecipient;
    public:
        TSlave();
        virtual ~TSlave();

        virtual void SaveContext(unsigned int sessionID, void* data, int size);
        virtual bool FindClientKeyBySession(unsigned int sessionID, unsigned int& id);
        virtual bool FindSessionByClientKey(unsigned int id, unsigned int& sessionID);

        // BaseServer
        void SendByClientKey(std::list<unsigned int>& lKey, char* p, int size) override;

        void GetDescDown(std::list<unsigned int>& sessionID_List) override;

        void SendDown(unsigned int sessionID, char* p, int size, bool check = true) override;
        // ActiveServer      
        void ConnectUp(TIP_Port& ip_port, const std::string& login, const std::string& password, unsigned char subNet = 0) override;
    protected:
        // Base
        void WorkInherit() override;
        void DisconnectInherit(unsigned int sessionID) override;

    protected:
        void NeedContextLoginClientByClientKey(unsigned int clientKey) override;
        void NeedContextLoginClientByClientKey_SecondCallSlave(unsigned int clientKey) override;
        void NeedContextLoginClientByClientSessionByKeyClient(unsigned int id_session_client, unsigned int clientKey) override;
        //-----------------------------------------------------------------
        void NeedContextByRequestForRecipient(TDescRequestConnectForRecipient*) override;
        void NeedContextByClientSessionForSlaveRcm(unsigned sessionID, bool donor) override;
        void NeedContextByClientForSlaveKeyRcm(unsigned int key, bool donor) override;
        void EventDisconnectClientRcm(unsigned int key) override;
        void EventTimeClientElapsedRcm(unsigned int key) override;
        //-----------------------------------------------------------------
        void NeedContextSendToClient(unsigned int sessionID) override;

        void EndLoginClient(IScenario*) override;
        void EndLoginSlave(IScenario*) override;
        void EndRcm(IScenario*) override;

    private:
        void DisconnectAllClient();
    };
}
