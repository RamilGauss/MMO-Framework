/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "IScenario.h"
#include "DescRecvSession.h"
#include "BaseScLoginClient_Struct.h"
#include "DescCallBack.h"
#include "MapCallBack.h"

namespace nsMMOEngine
{
  class TContextScLoginClient;
  class TBaseScLoginClient
  {
  protected:
    IScenario * mScenario;

    TBreakPacket mBP;
  public:
    TBaseScLoginClient( IScenario* pSc );
    virtual ~TBaseScLoginClient();

    void Recv( TDescRecvSession* pDesc );
    virtual void Work( unsigned int time_ms ) = 0;

  protected:
    TContextScLoginClient * Context();
    void SetContext( TContextScLoginClient* pContext );

    unsigned int GetID_SessionClientMaster();
    void SetClientSessionID_Master( unsigned int id );
    unsigned int GetID_SessionClientSlave();
    void SetID_SessionClientSlave( unsigned int id );
    unsigned int GetID_SessionMasterSlave();
    void SetID_SessionMasterSlave( unsigned int id );
    unsigned int GetID_SessionMasterSS();
    void SetID_SessionMasterSS( unsigned int id );
  protected:
    virtual void RecvInherit( TDescRecvSession* pDesc ) = 0;
  protected:
    //void SetTimeWaitForNow();
  protected:
    // от Scenario
    bool Begin();
    void End();
  protected:
    // запрос на новую сессию, кто зарегистрировался выставит контекст с помощью SetContext()
    void NeedContextBySessionLeaveQueue( unsigned int sessionID );
    void NeedContextBySession( unsigned int sessionID );
    void NeedContextByClientKey( unsigned int clientID );
    void NeedContextByClientKey_SecondCallSlave( unsigned int clientID );
    void NeedContextByMasterSessionByClientKey( unsigned int id_session_master, unsigned int clientID );
    void NeedNumInQueueByClientKey( unsigned int clientID );
    void EventSetClientKey( unsigned int clientID );
    void NeedContextByClientSessionByClientKey( unsigned int id_session_client, unsigned int clientID );
    void NeedContextBySessionAfterAuthorised( unsigned int id_session_client );
  };
}
