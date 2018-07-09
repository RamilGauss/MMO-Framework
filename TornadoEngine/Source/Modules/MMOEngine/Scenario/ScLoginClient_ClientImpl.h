/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SC_LOGIN_CLIENT_CLIENT_IMPL_H
#define SC_LOGIN_CLIENT_CLIENT_IMPL_H

#include "BaseScLoginClient.h"

namespace nsMMOEngine
{
  class TScLoginClient_ClientImpl : public TBaseScLoginClient
  {
    enum{
      eTimeWait=20000,
    };
    
  public:
    TScLoginClient_ClientImpl(IScenario* pSc);

    virtual void Work(unsigned int time_ms);

    void TryLogin( TIP_Port& ip_port, std::string& login, std::string& password, unsigned char subNet );
      
    void LeaveQueue();

    void Disconnect();

  protected:
    virtual void RecvInherit(TDescRecvSession* pDesc);

  private:
    void RecvFromSlave(TDescRecvSession* pDesc);
    void RecvFromMaster(TDescRecvSession* pDesc);

    void CheckConnectToSlaveS2C(TDescRecvSession* pDesc);
    void ResultLoginM2C(TDescRecvSession* pDesc);
    void InfoSlaveM2C(TDescRecvSession* pDesc);
  private:
    void CloseSessionMaster();

    void TryLoginAfterConnect( int sessionID );
    void DisconnectAfterConnect( int sessionID );
  };
  //------------------------------------------------------------
}
#endif
