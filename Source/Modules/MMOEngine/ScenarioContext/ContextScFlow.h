/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IScenarioContext.h"
#include "Base/Common/BreakPacket.h"
#include <list>
#include "Base/Common/MemoryPool.h"
#include "Base/Common/SingletonManager.h"

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

        typedef std::list<TMemoryPool<TSavePacket>::TPointerDesc*> TListPtr;
        TListPtr mListSave;

        TMemoryPool<TSavePacket>* mSavePacketMemoryPool = nullptr;

    public:
        TContextScFlow()
        {
            mSavePacketMemoryPool = SingletonManager()->Get<TMemoryPool<TSavePacket>>();
        }

        void Send(TBreakPacket& bp, bool check);
        void SaveBreakPacket(TBreakPacket& bp, bool check);
        void SendAndRemoveFirst();
    };
}
