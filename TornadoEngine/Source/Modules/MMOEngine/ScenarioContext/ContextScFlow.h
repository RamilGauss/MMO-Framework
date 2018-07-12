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

namespace nsMMOEngine
{
  // сценарии, содержащиеся в контейнере, взаимно блокируются
  class TContextScFlow : public IScenarioContext
  {
    struct TSavePacket
    {
      bool check;
      TContainerRise c;
    };

    typedef std::list<TMemoryPool<TSavePacket>::TDescPointer*> TListPtr;
    TListPtr mListSave;

  public:
    TContextScFlow();

    void Send( TBreakPacket& bp, bool check );
    void SaveBreakPacket( TBreakPacket& bp, bool check );
    void SendAndRemoveFirst();
  };
}
