/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "ActiveServer.h"

class TSetOrderElement;
namespace nsMMOEngine
{
  class TSlaveAuthLogic;
  class TClientAuthLogic;
  class TGroupLogic;
  class DllExport TMaster : public TActiveServer
  {
    enum
    {
      eLimitLoadPercentOnSlaveForAdd = 70,
      eLimitLoadPercentOnSlaveForAdd_ClientInGroup = 75, // для Клиента, состоящего в Группе процент другой

      eDefaultLoadPerClientIfClientCountZero = 5,// если на Slave нет клиентов, то считать нагрузку на одного клиента равным этому значению

      eLimitCountClientWaitFreeSpace = 10000,// максимальный размер очереди ожидающих
    };

    // для доступа к Master
    friend class TSlaveAuthLogic;
    friend class TClientAuthLogic;
    friend class TGroupLogic;

    std::shared_ptr<TSlaveAuthLogic> mSlaveAuthLogic;
    std::shared_ptr<TClientAuthLogic> mClientAuthLogic;
    std::shared_ptr<TGroupLogic> mGroupLogic;

  public:
    typedef enum
    {
      eAccept,
      eReject,
    }tResultLogin;

    TMaster();
    virtual ~TMaster();

    virtual bool TryCreateGroup( std::list<unsigned int>& clientKeyList, unsigned int& groupID );
    virtual void DestroyGroup( unsigned int groupID );
    virtual void LeaveGroup( unsigned int clientKey );
    virtual void GetListForGroup( unsigned int groupID, std::list<unsigned int>& clientKeyList );
    virtual void SetResultLogin( bool res, unsigned int sessionID, unsigned int clientKey, // ключ, из БД например
      void* resForClient, int sizeResClient );
    virtual bool FindSlaveSessionByGroup( unsigned int groupID, unsigned int& sessionID );

    // BaseServer
    virtual void SendByClientKey( std::list<unsigned int>& clientKeyList, char* p, int size );
    struct TDescDownMaster
    {
      unsigned int sessionID;
    };
    virtual int  GetCountDown();
    virtual bool GetDescDown( int index, void* pDesc, int& sizeDesc );// pDesc имеет тип TDescDownMaster*

    virtual void SendDown( unsigned int sessionID, char* p, int size, bool check = true );
    // ActiveServer      
    virtual void ConnectUp( TIP_Port& ip_port, std::string& login, std::string& password, unsigned char subNet = 0 );
  protected:
    // Base
    virtual void DisconnectInherit( unsigned int sessionID );
    virtual void WorkInherit(){}
  protected:// like slots
            // DisconnectClient
    virtual void NeedContextDisconnectClient( unsigned int clientKey );
    // LoginClient
    virtual void NeedContextLoginClientBySessionLeaveQueue( unsigned int sessionID );
    virtual void NeedContextLoginClientBySession( unsigned int sessionID );
    virtual void NeedContextLoginClientBySessionAfterAuthorised( unsigned int sessionID );
    virtual void NeedContextLoginClientByClientKey( unsigned int clientKey );
    virtual void NeedNumInQueueLoginClient( unsigned int sessionID );
    // RCM
    virtual void NeedContextByClientKeyRcm( unsigned int clientKey );
    virtual void NeedSlaveSessionDonorRcm( IScenario* pSc );
    virtual void EventActivateRcm( IScenario* pSc );
    // others
    virtual void NeedContextLoginSlave( unsigned int sessionID );// login slave
    virtual void NeedContextSynchroSlave( unsigned int sessionID );// synchro slave
    virtual void NeedContextSendToClient( unsigned int clientKey );// send to client
  protected:
    virtual void EndDisconnectClient( IScenario* );
    virtual void EndLoginMaster( IScenario* pSc );
    virtual void EndLoginSlave( IScenario* pSc );
    virtual void EndLoginClient( IScenario* pSc );
    virtual void EndRcm( IScenario* pSc );
    virtual void EndSynchroSlave( IScenario* pSc );
  private:
  };
}
