/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "BaseScRecommutationClient.h"

namespace nsMMOEngine
{
  class TScRecommutationClient_SlaveImpl : public TBaseScRecommutationClient
  {
  protected:
    enum
    {
      eTimeWait = 10000,
    };
  public:
    TScRecommutationClient_SlaveImpl( IScenario* pSc );

    virtual void Work( unsigned int time_ms );

    void SaveContext( void* data, int size );

  protected:
    virtual void RecvInherit( TDescRecvSession* pDesc );

  private:
    void RecvFromMaster( TDescRecvSession* pDesc );
    void RecvFromClient( TDescRecvSession* pDesc );
  private:
    void BeginDonor( TDescRecvSession* pDesc );
    void InfoRecipientToDonor( TDescRecvSession* pDesc );
    void BeginRecipient( TDescRecvSession* pDesc );
    void DisconnectClientToSlave( TDescRecvSession* pDesc );
    void CheckBeginClient( TDescRecvSession* pDesc );
    void CheckInfoRecipient( TDescRecvSession* pDesc );
    void RequestConnect( TDescRecvSession* pDesc );
  };
}
