/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "Base/Common/BreakPacket.h"
#include "Base/Common/MemoryPool.h"
#include "Base/Common/SingletonManager.h"

#include "MMOEngine/SubSystem/IScenarioContext.h"

namespace nsMMOEngine
{
    // сценарии, содержащиеся в контейнере взаимно блокируются
    class TContextScSendToClient : public IScenarioContext
    {
        struct TSavePacket
        {
            TContainerRise c;
        };

        typedef std::list<TMemoryPool<TSavePacket>::TPointerDesc*> TListPtr;

        TListPtr mListSave;

        TMemoryPool<TSavePacket>* mSavePacket_MemoryPool = nullptr;

    public:
        TContextScSendToClient()
        {
            mSavePacket_MemoryPool = SingletonManager()->Get<TMemoryPool<TSavePacket>>();
        }

        void SaveBreakPacket(TBreakPacket& bp);
        void SendAndRemoveFirst();
    };
}

