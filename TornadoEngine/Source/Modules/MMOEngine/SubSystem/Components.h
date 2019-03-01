/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "ContainerContextSc.h"
#include "EnumMMO.h"
#include "IMappedComponent.h"

namespace nsMMOEngine
{
  struct TContextContainerComponent : nsMappedComponents::IComponent
  {
    TContainerContextSc* v = nullptr;
  };
  // identity
  struct TClientIdentityComponent : nsMappedComponents::IUniqueComponent
  {
    unsigned int v = 0;
    bool operator< ( const TClientIdentityComponent& other ) const
    {
      return other.v > this->v;
    }
  };
  struct TClientSessionIdentityComponent : nsMappedComponents::IUniqueComponent
  {
    unsigned int v = INVALID_HANDLE_SESSION;
    bool operator< ( const TClientSessionIdentityComponent& other ) const
    {
      return other.v > this->v;
    }
  };
  struct TGroupIdentityComponent : nsMappedComponents::IUniqueComponent
  {
    unsigned int v = 0;
    bool operator< ( const TGroupIdentityComponent& other ) const
    {
      return other.v > this->v;
    }
  };
  struct TSlaveSessionIdentityComponent : nsMappedComponents::IUniqueComponent
  {
    unsigned int v = INVALID_HANDLE_SESSION;
    bool operator< ( const TSlaveSessionIdentityComponent& other ) const
    {
      return other.v > this->v;
    }
  };
  // multi
  struct TClientStateComponent : nsMappedComponents::IMultiComponent, nsMappedComponents::IGroupedComponent
  {
    typedef enum
    {
      Init,
      InQueue,
      Logining,
      RCM,
      OnSlave,
      Lost,
      Count
    }State;
    State v = Init;
    virtual int GetGroupCount()
    {
      return State::Count;
    }
    virtual int GetGroupNumber()
    {
      return v;
    }
    bool operator< ( const TClientStateComponent& other ) const
    {
      return other.v > this->v;
    }
  };
  struct TGroupIDComponent : nsMappedComponents::IMultiComponent
  {
    unsigned int v = 0;
    bool operator< ( const TGroupIDComponent& other ) const
    {
      return other.v > this->v;
    }
  };
  struct TSlaveSessionByClientComponent : nsMappedComponents::IMultiComponent
  {
    unsigned int v = INVALID_HANDLE_SESSION;
    bool operator< ( const TSlaveSessionByClientComponent& other ) const
    {
      return other.v > this->v;
    }
  };
  struct TSlaveSessionByGroupComponent : nsMappedComponents::IMultiComponent
  {
    unsigned int v = INVALID_HANDLE_SESSION;
    bool operator< ( const TSlaveSessionByGroupComponent& other ) const
    {
      return other.v > this->v;
    }
  };
  struct TDonorSessionComponent : nsMappedComponents::IMultiComponent
  {
    unsigned int v = INVALID_HANDLE_SESSION;
    bool operator< ( const TDonorSessionComponent& other ) const
    {
      return other.v > this->v;
    }
  };
  struct TSlaveLoadInfoComponent : nsMappedComponents::IComponent
  {
    float v;
  };
}
