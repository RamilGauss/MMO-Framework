/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "MMOEngine/Include/BaseServer.h"

namespace nsMMOEngine
{
    class TManagerContextMoreDownClientConnection;
    class TManagerContextDownConnection;
    class DllExport TSuperServer : public TBaseServer
    {
        // в случае если повторная авторизация, что бы избежать замусоривания контекста
        std::shared_ptr<TContainerContextSc> mContainer_SecondLogin;

        // DOWN
        std::shared_ptr<TManagerContextMoreDownClientConnection> mMngContextClient;
        std::shared_ptr<TManagerContextDownConnection>           mMngContextMaster;
    public:
        TSuperServer();
        virtual ~TSuperServer();

        virtual int GetClientCountBySessionID(unsigned int sessionID);

        // BaseServer
        void SendByClientKey(std::list<unsigned int>& lKey, char* p, int size) override;

        void GetDescDown(std::list<unsigned int>& sessionID_List) override;

        void SendDown(unsigned int sessionID, char* p, int size, bool check = true) override;

    protected:
        // Base
        void DisconnectInherit(unsigned int sessionID) override;
    protected:
        void NeedContextDisconnectClient(unsigned int clientKey) override;
        void NeedContextLoginMaster(unsigned int sessionID) override;
        void NeedContextByMasterSessionByClientKey(unsigned int sessionID, unsigned int clientKey) override;//SS
        void NeedContextSendToClient(unsigned int clientKey) override;
    protected:
        void EndDisconnectClient(IScenario*);
    };
}
