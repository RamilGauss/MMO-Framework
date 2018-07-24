/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "TypeDef.h"

#include <boost/smart_ptr/scoped_ptr.hpp>
#include <list>

#include "Structs.h"
#include "SrcEvent.h"
#include "IMakerTransport.h"
#include "DataExchange2Thread.h"

namespace nsMMOEngine
{
  class TSessionManager;
  struct TTryConnectDown;
  struct TDescConnectUp;
  class TScContextManager;
  class TManagerManagerContextSc;
  class TContainerContextSc;
  class TControlScenario;
  class TDelegateManagerContextSc;
  class IScenario;
  struct TDescRecvSession;
  struct TDescRequestConnectForRecipient;
  class DllExport TBase : public TSrcEvent
  {
    std::shared_ptr<TManagerManagerContextSc> mMngMngContextSc;
  protected:
    std::shared_ptr<TControlScenario>    mControlSc;
    std::shared_ptr<TContainerContextSc> mContainerUp;

    // уведомления о разрыве связи
    typedef TDataExchange2Thread<unsigned int> TListUint;
    TListUint mDisconnectSessionID;
    // полученные пакеты от mSessionManager
    typedef TDataExchange2Thread<TDescRecvSession> TListRecvPacket;
    TListRecvPacket mRecvPacket;

    typedef TDataExchange2Thread<TTryConnectDown> TListTryConnectDown;
    TListTryConnectDown mTryConnectDown;

    // транспорт
    std::shared_ptr<TSessionManager> mSessionManager;
    // загрузка CPU
    int mLoadProcent;// затраченное время/выделенное, %

    unsigned int mSessionUpID;
    bool         flgConnectUp;

    typedef std::list<TContainerContextSc*> TListPtr;

    TListPtr mListDelayDeleteContainerSc;

    TBreakPacket mBP;
  public:
    TBase();
    virtual ~TBase();

    virtual void Init( IMakerTransport* pMakerTransport );
    virtual bool Open( TDescOpen* pDesc, int count = 1 );// подготовка для использования транспорта, count - кол-во всех используемых подсетей
    virtual void DisconnectUp();
    virtual void SendUp( char* p, int size, bool check = true );
    void Work();
    virtual bool IsConnectUp();
    virtual bool IsConnect( unsigned int id );
    virtual void SetLoad( int procent );

    virtual void SetTimeLiveSession( unsigned int time_ms );

    bool GetInfoSession( unsigned int sessionID, TIP_Port& ip_port );
  protected:
    void Recv( TDescRecvSession* pDescRecvSession );
    void Disconnect( unsigned int id );
    void TryConnectDown( TTryConnectDown* pTryConnectDown );

    virtual void DisconnectInherit( unsigned int id ) = 0;
    virtual void WorkInherit()
    {};
    // события сценариев
    virtual void NeedContextDisconnectClient( unsigned int id_client )
    {}
    //----------------------------------------------------
    // LoginClient
    virtual void NeedContextByMasterSessionByClientKey( unsigned int sessionID,
      unsigned int id_client )
    {}//SS
    virtual void NeedContextLoginClientBySessionLeaveQueue( unsigned int sessionID )
    {}// S,M
    virtual void NeedContextLoginClientBySession( unsigned int sessionID )
    {}// S,M
    virtual void NeedContextLoginClientBySessionAfterAuthorised( unsigned int sessionID )
    {}// M
    virtual void NeedContextLoginClientByClientKey( unsigned int id_client )
    {}//S,M,SS
    virtual void NeedContextLoginClientByClientKey_SecondCallSlave( unsigned int id_client )
    {}//S
    virtual void NeedNumInQueueLoginClient( unsigned int sessionID )
    {}// M
    virtual void EventSetClientKeyLoginClient( unsigned int id_client )
    {};//C
    virtual void NeedContextLoginClientByClientSessionByKeyClient( unsigned int id_session_client,
      unsigned int id_client )
    {}//S
   //----------------------------------------------------
   // RCM
    virtual void NeedContextByRequestForRecipient( TDescRequestConnectForRecipient* p )
    {}// Slave
    virtual void NeedContextByClientSessionForSlaveRcm( unsigned sessionID, bool donor )
    {}
    virtual void NeedContextByClientForSlaveKeyRcm( unsigned int key, bool donor )
    {}
    virtual void NeedContextByClientKeyRcm( unsigned int key )
    {}
    virtual void NeedSlaveSessionDonorRcm( IScenario* pSc )
    {}//M
    virtual void EventActivateRcm( IScenario* pSc )
    {}//M
    virtual void EventDisconnectClientRcm( unsigned int key )
    {}// Slave
    virtual void EventTimeClientElapsedRcm( unsigned int key )
    {}// Slave
       //----------------------------------------------------
    virtual void NeedContextLoginSlave( unsigned int sessionID )
    {}
    virtual void NeedContextLoginMaster( unsigned int sessionID )
    {}
    virtual void NeedContextSendToClient( unsigned int id_client )
    {}
    virtual void NeedContextSynchroSlave( unsigned int sessionID )
    {}

    virtual void EndDisconnectClient( IScenario* p )
    {}
    virtual void EndDisconnectSlave( IScenario* p )
    {}
    virtual void EndLoginClient( IScenario* p )
    {}
    virtual void EndLoginSlave( IScenario* p )
    {}
    virtual void EndLoginMaster( IScenario* p )
    {}
    virtual void EndRcm( IScenario* p )
    {}
    virtual void EndSynchroSlave( IScenario* p )
    {}
  private:
    TScContextManager* AddManagerContextSc();
    void RemoveManagerContextSc( TScContextManager* pMCSc );
  protected:
    friend class TDelegateManagerContextSc;
    void SetupScForContext( TContainerContextSc* pCCSc );
    void DelayDeleteContainerScenario( TContainerContextSc* pCCSc );
  private:
    void HandleTryConnectDownList();
    void HandleListDisconnect();
    void HandleListRecv();

    void DeleteContainerScenario();
  private:
    void SetDefualtContextForScenario();
    void RegisterOnScenarioEvent();
    void RegisterNeedForLoginClient();
    void RegisterNeedForRcmClient();
  protected:
    void SetupBP( char* p, int size );
  };
}
