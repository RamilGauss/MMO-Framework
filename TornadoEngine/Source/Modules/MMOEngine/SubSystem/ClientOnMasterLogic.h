/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "BaseMasterLogic.h"

namespace nsMMOEngine
{
  class IScenario;
  class TClientOnMasterLogic : public TBaseMasterLogic
  {
  public:
    TClientOnMasterLogic( TBase* p );

    void SetResultLogin( bool res, unsigned int clientSessionID,
      unsigned int clientKey, void* resForClient, int sizeResClient );

    void EndLoginClient( IScenario* pSc );

    void NeedContextLoginClientBySessionAfterAuthorised( unsigned int sessionID );

    void NeedContextLoginClientBySessionLeaveQueue( unsigned int sessionID );
    void NeedContextLoginClientBySession( unsigned int sessionID );
    void NeedContextLoginClientByClientKey( unsigned int clientKey );
    void NeedNumInQueueLoginClient( unsigned int sessionID );
    void NeedContextDisconnectClient( unsigned int clientKey );
    void NeedContextSendToClient( unsigned int clientKey );

    bool DisconnectClientWait( unsigned int sessionID );
  private:

    bool TryAddClient( unsigned int clientKey );
    bool TryAddClientByGroup( unsigned int clientKey );
  };
}
