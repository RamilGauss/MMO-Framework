/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "IScenarioContext.h"
#include "BreakPacket.h"
#include <list>
#include "MemoryPool.h"
#include "SingletonManager.h"

namespace nsMMOEngine
{
  // сценарии, содержащиеся в контейнере взаимно блокируются
  class TContextScSendToClient : public IScenarioContext
  {
    struct TSavePacket
    {
      TContainerRise c;
    };

    typedef std::list<TMemoryPool<TSavePacket>::TDescPointer*> TListPtr;

    TListPtr mListSave;

    TMemoryPool<TSavePacket>* mSavePacket_MemoryPool = nullptr;

  public:
    TContextScSendToClient()
    {
      mSavePacket_MemoryPool = SingletonManager()->Get<TMemoryPool<TSavePacket>>();
    }

    void SaveBreakPacket( TBreakPacket& bp );
    void SendAndRemoveFirst();
  };
}

