/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SLAVE_H
#define SLAVE_H

#include "ActiveServer.h"

#include <boost/smart_ptr/scoped_ptr.hpp>

namespace nsMMOEngine
{
  class IScenario;
  class TManagerContextClient_slave;
  class DllExport TSlave : public TActiveServer
  {
    enum{
      eDeltaSynchro = 300,// мс
    };

    unsigned int mTimeNeedSendSynchro;
    boost::scoped_ptr<TManagerContextClient_slave> mMngContextClient;
    // только для Клиентов, которые считают текущий Slave реципиентом
    boost::scoped_ptr<TManagerContextClient_slave> mMngContextClientSlaveRecipient;
  public:
    TSlave();
    virtual ~TSlave();
    
    virtual void SaveContext(unsigned int id_session, void* data, int size);
    virtual bool FindClientKeyBySession(unsigned int id_session, unsigned int &id);
    virtual bool FindSessionByClientKey(unsigned int id, unsigned int& id_session);

    // BaseServer
    virtual void SendByClientKey(std::list<unsigned int>& lKey, TBreakPacket& bp);

    struct TDescDownSlave // для GetDescDown
    {
      unsigned int id_session;
    };
    virtual int  GetCountDown();
    virtual bool GetDescDown(int index, void* pDesc, int& sizeDesc);// pDesc имеет тип TDescDownSlave
    virtual void SendDown(unsigned int id_session, TBreakPacket& bp, bool check = true);
    // ActiveServer      
    virtual void ConnectUp(unsigned int ip, unsigned short port, 
                           void* pLogin, int sizeLogin, void* pPassword, int sizePassword,
                           unsigned char subNet = 0);
  protected:
    // Base
    virtual void WorkInherit();
    virtual void DisconnectInherit(unsigned int id_session);
    
  protected:
    virtual void NeedContextLoginClientByClientKey(unsigned int id_client);
    virtual void NeedContextLoginClientByClientKey_SecondCallSlave(unsigned int id_client);
    virtual void NeedContextLoginClientByClientSessionByKeyClient(unsigned int id_session_client,
                                                                  unsigned int id_client);
    //-----------------------------------------------------------------
    virtual void NeedContextByRequestForRecipient(TDescRequestConnectForRecipient*);
    virtual void NeedContextByClientSessionForSlaveRcm(unsigned id_session, bool donor);
    virtual void NeedContextByClientForSlaveKeyRcm(unsigned int key, bool donor);
    virtual void EventDisconnectClientRcm(unsigned int key);
    virtual void EventTimeClientElapsedRcm(unsigned int key);
    //-----------------------------------------------------------------
    virtual void NeedContextSendToClient(unsigned int id_session);

    virtual void EndLoginClient(IScenario*);
    virtual void EndLoginSlave(IScenario*);
    virtual void EndRcm(IScenario*);

  private:
    void DisconnectAllClient();
  };
}

#endif
