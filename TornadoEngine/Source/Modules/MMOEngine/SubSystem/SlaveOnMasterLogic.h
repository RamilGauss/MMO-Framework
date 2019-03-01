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
  class TSlaveOnMasterLogic : public TBaseMasterLogic
  {
  public:
    TSlaveOnMasterLogic( TBase* p );

    void GetDescDown( std::list<unsigned int>& sessionIDList );

    void EndLoginSlave( IScenario* pSc );
    void SendDown( unsigned int sessionID, char* p, int size, bool check );

    void NeedContextLoginSlave( unsigned int sessionID );
    void NeedContextSynchroSlave( unsigned int sessionID );
    void EndSynchroSlave( IScenario* pSc );

    bool DisconnectSlave( unsigned int sessionID );

  private:
    void TryAddClientFromQueue( nsMappedComponents::TEntityManager::EntityID slaveEntity );

    void DestroyAllLostClientsBySlaveSession( unsigned int sessionID );

    void GetAllClientsBySlaveSession( unsigned int sessionID, std::vector<unsigned int>& clientKeyVector );
    void SendSuperServer( std::vector<unsigned int>& clientKeyVector );
    void SendRecipient( unsigned int sessionID );

    void DestroyAllClientsBySlaveSession( unsigned int sessionID );
    void DestroyAllGroupsBySlaveSession( unsigned int sessionID );

    void TryAddFromQueueGroupClients( nsMappedComponents::TEntityManager::EntityID slaveEntity, unsigned int sessionID );
    void TryAddFromQueue( nsMappedComponents::TEntityManager::EntityID slaveEntity, unsigned int sessionID );

    void TSlaveOnMasterLogic::AddClientBySlave( nsMappedComponents::TEntityManager::TSortedEntity& clientEntitySet, 
      unsigned int slaveSessionID, nsMappedComponents::TEntityManager::EntityID slaveEntity, float limit );

    void AddClientBySlaveSession( nsMappedComponents::TEntityManager::EntityID clientEntity, unsigned int slaveSessionID );
  };
}
