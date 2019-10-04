/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once
#include "ContainerContextSc.h"
#include "EnumMMO.h"

namespace nsMMOEngine
{
  struct TContextContainerComponent : nsECSFramework::IComponent
  {
    TContainerContextSc* v = nullptr;
  };
  // identity
  struct TClientIdentityComponent : nsECSFramework::IComponent
  {
    unsigned int v = 0;

    bool IsLess( const IComponent* pOther ) const override
    {
      return v < ( (TClientIdentityComponent*)pOther )->v;
    }
    bool IsEqual( const IComponent* pOther ) const override
    {
      return v == ( (TClientIdentityComponent*)pOther )->v;
    }
  };
  struct TClientSessionIdentityComponent : nsECSFramework::IComponent
  {
    unsigned int v = INVALID_HANDLE_SESSION;

    bool IsLess( const IComponent* pOther ) const override
    {
      return v < ( (TClientSessionIdentityComponent*)pOther )->v;
    }
    bool IsEqual( const IComponent* pOther ) const override
    {
      return v == ( (TClientSessionIdentityComponent*)pOther )->v;
    }
  };
  struct TGroupIdentityComponent : nsECSFramework::IComponent
  {
    unsigned int v = 0;

    bool IsLess( const IComponent* pOther ) const override
    {
      return v < ( (TGroupIdentityComponent*)pOther )->v;
    }
    bool IsEqual( const IComponent* pOther ) const override
    {
      return v == ( (TGroupIdentityComponent*)pOther )->v;
    }
  };
  struct TSlaveSessionIdentityComponent : nsECSFramework::IComponent
  {
    unsigned int v = INVALID_HANDLE_SESSION;

    bool IsLess( const IComponent* pOther ) const override
    {
      return v < ( (TSlaveSessionIdentityComponent*)pOther )->v;
    }
    bool IsEqual( const IComponent* pOther ) const override
    {
      return v == ( (TSlaveSessionIdentityComponent*)pOther )->v;
    }
  };
  // multi
  struct TClientStateComponent : nsECSFramework::IComponent
  {
    typedef enum
    {
      Init,
      InQueue,
      Logining,
      RCM,
      OnSlave,
      LostFromGroup,

      Count
    }State;
    State v = Init;

    bool IsLess( const IComponent* pOther ) const override
    {
      return v < ( (TClientStateComponent*)pOther )->v;
    }
    bool IsEqual( const IComponent* pOther ) const override
    {
      return v == ( (TClientStateComponent*)pOther )->v;
    }
  };
  struct TGroupIDComponent : nsECSFramework::IComponent
  {
    unsigned int v = 0;

    bool IsLess( const IComponent* pOther ) const override
    {
      return v < ( (TGroupIDComponent*)pOther )->v;
    }
    bool IsEqual( const IComponent* pOther ) const override
    {
      return v == ( (TGroupIDComponent*)pOther )->v;
    }
  };
  struct TSlaveSessionByClientComponent : nsECSFramework::IComponent
  {
    unsigned int v = INVALID_HANDLE_SESSION;

    bool IsLess( const IComponent* pOther ) const override
    {
      return v < ( (TSlaveSessionByClientComponent*)pOther )->v;
    }
    bool IsEqual( const IComponent* pOther ) const override
    {
      return v == ( (TSlaveSessionByClientComponent*)pOther )->v;
    }
  };
  struct TSlaveSessionByGroupComponent : nsECSFramework::IComponent
  {
    unsigned int v = INVALID_HANDLE_SESSION;

    bool IsLess( const IComponent* pOther ) const override
    {
      return v < ( (TSlaveSessionByGroupComponent*)pOther )->v;
    }
    bool IsEqual( const IComponent* pOther ) const override
    {
      return v == ( (TSlaveSessionByGroupComponent*)pOther )->v;
    }
  };
  struct TDonorSessionComponent : nsECSFramework::IComponent
  {
    unsigned int v = INVALID_HANDLE_SESSION;

    bool IsLess( const IComponent* pOther ) const override
    {
      return v < ( (TDonorSessionComponent*)pOther )->v;
    }
    bool IsEqual( const IComponent* pOther ) const override
    {
      return v == ( (TDonorSessionComponent*)pOther )->v;
    }
  };
  struct TSlaveLoadInfoComponent : nsECSFramework::IComponent
  {
    float v;
  };
}
