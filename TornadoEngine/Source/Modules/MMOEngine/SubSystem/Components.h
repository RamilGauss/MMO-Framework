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
  struct TClientIdentityComponent : nsMappedComponents::IUniqueComponent
  {
    unsigned int v = 0;
  };
  struct TGroupIdentityComponent : nsMappedComponents::IUniqueComponent
  {
    unsigned int v = 0;
  };
  struct TSessionIDComponent : nsMappedComponents::IUniqueComponent
  {
    unsigned int v = INVALID_HANDLE_SESSION;
  };
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
  };
  struct TGroupIDComponent : nsMappedComponents::IMultiComponent
  {
    unsigned int v = 0;
  };
  struct TSlaveSessionIDComponent : nsMappedComponents::IMultiComponent
  {
    unsigned int v = INVALID_HANDLE_SESSION;
  };
  struct TRCMInfoComponent : nsMappedComponents::IComponent
  {
    unsigned int donorSessionID = INVALID_HANDLE_SESSION;
    unsigned int recipientSessionID = INVALID_HANDLE_SESSION;
  };
  struct TSlaveLoadInfoComponent : nsMappedComponents::IComponent
  {
    unsigned char v;
  };
}
