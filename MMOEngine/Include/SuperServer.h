/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SUPERSERVER_H
#define SUPERSERVER_H

#include "BaseServer.h"
#include <boost/smart_ptr/scoped_ptr.hpp>

namespace nsMMOEngine
{
  class TManagerContextMoreDownClientConnection;
  class TManagerContextDownConnection;
  class MMO_ENGINE_EI TSuperServer : public TBaseServer
  {
    // в случае если повторная авторизация, что бы избежать замусоривания контекста
    boost::scoped_ptr<TContainerContextSc> mContainer_SecondLogin;

    // DOWN
    boost::scoped_ptr<TManagerContextMoreDownClientConnection> mMngContextClient;
    boost::scoped_ptr<TManagerContextDownConnection>           mMngContextMaster;
  public:
    TSuperServer();
    virtual ~TSuperServer();
    
		// BaseServer
    virtual void SendByClientKey(std::list<unsigned int>& lKey, TBreakPacket bp);

		struct TDescDownSuperServer
		{
			unsigned int id_session;
			int countClient;
		};
		virtual int  GetCountDown();
		virtual bool GetDescDown(int index, void* pDesc, int& sizeDesc);
    virtual void SendDown(unsigned int id_session, TBreakPacket bp, bool check = true);

	protected:
    // Base
    virtual void DisconnectInherit(unsigned int id_session);
	protected:
    virtual void NeedContextDisconnectClient(unsigned int id_client);
    virtual void NeedContextLoginMaster(unsigned int id_session);
    virtual void NeedContextByMasterSessionByClientKey(unsigned int id_session,unsigned int id_client);//SS
		virtual void NeedContextSendToClient(unsigned int id_client);
	protected:
    virtual void EndDisconnectClient(IScenario*);
  };
}

#endif