/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "BaseServer.h"

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

        // BaseServer
        virtual void SendByClientKey(std::list<unsigned int>& lKey, char* p, int size);

        virtual void GetDescDown(std::list<unsigned int>& sessionID_List);
        virtual int GetClientCountBySessionID(unsigned int sessionID);

        virtual void SendDown(unsigned int sessionID, char* p, int size, bool check = true);

    protected:
        // Base
        virtual void DisconnectInherit(unsigned int sessionID);
    protected:
        virtual void NeedContextDisconnectClient(unsigned int clientKey);
        virtual void NeedContextLoginMaster(unsigned int sessionID);
        virtual void NeedContextByMasterSessionByClientKey(unsigned int sessionID, unsigned int clientKey);//SS
        virtual void NeedContextSendToClient(unsigned int clientKey);
    protected:
        virtual void EndDisconnectClient(IScenario*);
    };
}
