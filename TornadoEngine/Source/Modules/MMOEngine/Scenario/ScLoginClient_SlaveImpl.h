/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "BaseScLoginClient.h"

namespace nsMMOEngine
{
  class TScLoginClient_SlaveImpl : public TBaseScLoginClient
  {
    enum{
      eTimeWait = 20000,
    };
  public:
    TScLoginClient_SlaveImpl( IScenario* pSc );

    virtual void Work( unsigned int time_ms );
  protected:
    virtual void RecvInherit( TDescRecvSession* pDesc );

    void RecvFromClient( TDescRecvSession* pDesc );
    void RecvFromMaster( TDescRecvSession* pDesc );

    void ConnectToSlaveC2S( TDescRecvSession* pDesc );
    void InfoClientM2S( TDescRecvSession* pDesc );
    void CheckClientConnectM2S( TDescRecvSession* pDesc );
    void DisconnectClientM2S( TDescRecvSession* pDesc );

  };
  //---------------------------------------------------------------------------------
  //---------------------------------------------------------------------------------
}
