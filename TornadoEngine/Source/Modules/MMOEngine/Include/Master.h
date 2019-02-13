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
  class IScenario;
  class TManagerContextMoreDownClientConnection;
  class TManagerContextDownConnection_Slave;
  class TManagerContextClientLogining;
  class TManagerGroupClient;
  class TStatisticaClientInGroup;
  class TContextScRecommutationClient;
  class TManagerRecommutation;
  class DllExport TMaster : public TActiveServer
  {
    enum{
      eLimitLoadProcentOnSlaveForAdd = 70,
      eLimitLoadProcentOnSlaveForAdd_ClientInGroup = 75, // для Клиента, состоящего в Группе процент другой

      eLimitCountClientWaitFreeSpace = 2000,// максимальный размер очереди ожидающих
    };

    // DOWN
    //клиенты, которые уже в системе
    std::shared_ptr<TManagerContextMoreDownClientConnection> mMngContextClient;
    // Slaves
    std::shared_ptr<TManagerContextDownConnection_Slave>     mMngContextSlave;
    // клиенты, которые находятся в процессе авторизации
    std::shared_ptr<TManagerContextClientLogining>           mMngContextClientLogining;
    // группы клиентов
    std::shared_ptr<TManagerGroupClient>                     mMngGroup;
    // ID клиентов, которые ожидают в очереди, по причине загруженности Slave
    std::shared_ptr<TSetOrderElement>                        mSetClientKeyInQueue;
    // для создания группы, нужна статистика по клиентам, которые уже в группе
    std::shared_ptr<TStatisticaClientInGroup>                mStatisticaClientInGroup;
    // какой клиент с какими Slave связан в процессе перекоммутации
    // необходимо знать если произошел Дисконнект с Клиентом, Донором или Реципиентом, что бы 
    // уведомить оставшихся на связи об этом Дисконнекте.
    std::shared_ptr<TManagerRecommutation>                   mMngRcm;
  public:
    typedef enum
    {
      eAccept,
      eReject,
    }tResultLogin;

    TMaster();
    virtual ~TMaster();

    virtual bool TryCreateGroup( std::list<unsigned int>& l_id_client, unsigned int& groupID );
    virtual void DestroyGroup( unsigned int groupID );
    virtual void LeaveGroup( unsigned int clientID );
    virtual void GetListForGroup( unsigned int groupID, std::list<unsigned int>& l );
    virtual void SetResultLogin( bool res, unsigned int sessionID, unsigned int clientID, // ключ, из БД например
                                 void* resForClient, int sizeResClient );
    virtual bool FindSlaveSessionByGroup( unsigned int groupID, unsigned int& sessionID );

    // BaseServer
    virtual void SendByClientKey( std::list<unsigned int>& lKey, char* p, int size );
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
    virtual void WorkInherit();

  protected:// like slots
    virtual void NeedContextDisconnectClient( unsigned int clientID );
    virtual void NeedContextLoginClientBySessionLeaveQueue( unsigned int sessionID );
    virtual void NeedContextLoginClientBySession( unsigned int sessionID );
    virtual void NeedContextLoginClientBySessionAfterAuthorised( unsigned int sessionID );
    virtual void NeedContextLoginClientByClientKey( unsigned int id_key_client );
    virtual void NeedNumInQueueLoginClient( unsigned int sessionID );
    //--------------------------------------------------------------------------
    // RCM
    virtual void NeedContextByClientKeyRcm( unsigned int key );
    virtual void NeedSlaveSessionDonorRcm( IScenario* pSc );//M
    virtual void EventActivateRcm( IScenario* pSc );//M
    //----------------------------------------------------
    virtual void NeedContextLoginSlave( unsigned int sessionID );
    virtual void NeedContextSynchroSlave( unsigned int sessionID );
    virtual void NeedContextSendToClient( unsigned int clientID );
  protected:
    virtual void EndDisconnectClient( IScenario* );
    virtual void EndLoginMaster( IScenario* pSc );
    virtual void EndLoginSlave( IScenario* pSc );
    virtual void EndLoginClient( IScenario* pSc );
    virtual void EndRcm( IScenario* pSc );
    virtual void EndSynchroSlave( IScenario* pSc );
  private:
    unsigned char GetLimitLoadProcentByKey( unsigned int clientID );

    bool EvalCreateGroupNow( std::list<unsigned int>& l_id_client, unsigned int& groupID );
    bool LoadInFutureLessLimit( unsigned int id_session_slave, std::list<unsigned int>& l_id_client );
    void SolveExchangeClient( unsigned int clientID, TContainerContextSc* pC_ClientInGroup, unsigned int id_session_slave_recipient );
    void RcmByClientKeyContextSlaveSessionRecipient( unsigned int clientID, TContextScRecommutationClient* pCRCM, unsigned int id_session_slave_recipient );

  private:
    bool DisconnectSuperServer( unsigned int sessionID );
    bool DisconnectClientWait( unsigned int sessionID );
    bool DisconnectSlave( unsigned int sessionID );

    bool TryAddClientByGroup( unsigned int clientID, unsigned int groupID, unsigned int& id_session_slave );
    bool TryAddClient( unsigned int clientID, unsigned int& id_session_slave );
    void AddClientBySlaveSession( unsigned int clientID, unsigned int id_session_slave, void* resForClient, int sizeResClient );
    void AddInQueue( unsigned int clientID, void* resForClient, int sizeResClient );
    // при освобождении места на Slave попытаться добавить Клиента, который ждет в очереди
    bool TryFindClientForAdd( unsigned int& clientID, unsigned int& id_session_slave );
    void TryAddClientFromQueue();
    void Done();

    // находится ли Клиент в процессе перекоммутации
    bool IsClientRecommutation( unsigned int clientID );

    void NotifyRecipientAboutDisconnectClient( unsigned int clientID, TContainerContextSc* pC, unsigned int sessionID );
  };
}
