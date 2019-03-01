/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "EntityManager.h"
#include "BaseLogic.h"
#include "EnumMMO.h"

namespace nsMMOEngine
{
  class TBase;
  class TBaseMasterLogic : public TBaseLogic
  {
  protected:
    // если на Slave нет клиентов, то считать нагрузку на одного клиента равным этому значению
    const float DefaultLoadPerClientIfClientCountZero = 1.0f;

    const float LimitLoadPercentOnSlaveForAdd = 70.0f;
    // для Клиента, состоящего в Группе процент другой
    const float LimitLoadPercentOnSlaveForAdd_ClientInGroup = 75.0f;
    // максимальный размер очереди ожидающих
    const int LimitCountClientWaitFreeSpace = 10000;
  public:
    TBaseMasterLogic( TBase* p );
  protected:

    void AddError( nsMMOEngine::ErrorCode err );

    void OnDestroy( nsMappedComponents::TEntityManager::EntityID entity );

    float CalculateFutureLoadOnSlave( nsMappedComponents::TEntityManager::EntityID slaveEntity, int addedClientCount );

    void GetClientWithoutGroup( unsigned int slaveSession, 
      std::list<nsMappedComponents::TEntityManager::EntityID>& clientEntityList );
  };
}
