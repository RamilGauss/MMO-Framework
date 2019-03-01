/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "ActiveServer.h"

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
    std::shared_ptr<TManagerContextClient_slave> mMngContextClient;
    // только для Клиентов, которые считают текущий Slave реципиентом
    std::shared_ptr<TManagerContextClient_slave> mMngContextClientSlaveRecipient;
  public:
    TSlave();
    virtual ~TSlave();

    virtual void SaveContext( unsigned int sessionID, void* data, int size );
    virtual bool FindClientKeyBySession( unsigned int sessionID, unsigned int &id );
    virtual bool FindSessionByClientKey( unsigned int id, unsigned int& sessionID );

    // BaseServer
    virtual void SendByClientKey( std::list<unsigned int>& lKey, char* p, int size );

    virtual void GetDescDown( std::list<unsigned int>& sessionID_List );

    virtual void SendDown( unsigned int sessionID, char* p, int size, bool check = true );
    // ActiveServer      
    virtual void ConnectUp( TIP_Port& ip_port, std::string& login, std::string& password, unsigned char subNet = 0 );
  protected:
    // Base
    virtual void WorkInherit();
    virtual void DisconnectInherit( unsigned int sessionID );

  protected:
    virtual void NeedContextLoginClientByClientKey( unsigned int clientKey );
    virtual void NeedContextLoginClientByClientKey_SecondCallSlave( unsigned int clientKey );
    virtual void NeedContextLoginClientByClientSessionByKeyClient( unsigned int id_session_client, unsigned int clientKey );
    //-----------------------------------------------------------------
    virtual void NeedContextByRequestForRecipient( TDescRequestConnectForRecipient* );
    virtual void NeedContextByClientSessionForSlaveRcm( unsigned sessionID, bool donor );
    virtual void NeedContextByClientForSlaveKeyRcm( unsigned int key, bool donor );
    virtual void EventDisconnectClientRcm( unsigned int key );
    virtual void EventTimeClientElapsedRcm( unsigned int key );
    //-----------------------------------------------------------------
    virtual void NeedContextSendToClient( unsigned int sessionID );

    virtual void EndLoginClient( IScenario* );
    virtual void EndLoginSlave( IScenario* );
    virtual void EndRcm( IScenario* );

  private:
    void DisconnectAllClient();
  };
}
