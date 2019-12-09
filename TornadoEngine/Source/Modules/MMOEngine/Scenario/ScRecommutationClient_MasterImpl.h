/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "BaseScRecommutationClient.h"

namespace nsMMOEngine
{
  class TScRecommutationClient_MasterImpl : public TBaseScRecommutationClient
  {
  protected:
    //enum{
    //  eTimeWait = 20000,
    //  eDeltaTimeNumInQueue = 1000,
    //};

  public:
    TScRecommutationClient_MasterImpl( IScenario* pSc );

    virtual void Work( unsigned int time_ms );
    void Start( unsigned int recipientSessionID, unsigned int clientKey );
    void DelayBegin();

    void DisconnectClient();

  protected:
    virtual void RecvInherit( TDescRecvSession* pDesc );
  private:
    void RecvFromSlaveDonor( TDescRecvSession* pDesc );
    void RecvFromSlaveRecipient( TDescRecvSession* pDesc );
  private:
    void CheckBeginDonor( TDescRecvSession* pDesc );
    void CheckBeginRecipient( TDescRecvSession* pDesc );
    void ClientConnect( TDescRecvSession* pDesc );
  private:
    void SendFirstPacket();
  };
}
