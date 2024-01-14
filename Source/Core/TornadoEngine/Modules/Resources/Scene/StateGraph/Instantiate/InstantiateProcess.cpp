/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InstantiateProcess.h"
#include "Base/Zones/IContext.h"
#include "Base/Zones/Zone.h"

#include "Modules/Resources/Scene/StateGraph/Instantiate/Async/AsyncProcess.h"
#include "Modules/Resources/Scene/StateGraph/Instantiate/DummyAsync/DummyAsyncProcess.h"
#include "Modules/Resources/Scene/StateGraph/Instantiate/Sync/SyncProcess.h"

namespace nsTornadoEngine::nsInstantiate
{
    TInstantiateProcess::TInstantiateProcess()
    {
        AddZones<Zone>();

        AddProcess<TAsyncProcess>(Process::ASYNC, Zone::INIT, Zone::ASYNCED);
        AddProcess<TDummyAsyncProcess>(Process::DUMMY_ASYNC, Zone::INIT, Zone::SYNCED);
        AddProcess<TSyncProcess>(Process::SYNC, Zone::ASYNCED, Zone::SYNCED);
    }
    //-------------------------------------------------------------------------------
    void TInstantiateProcess::Work(std::list<nsBase::nsZones::IContext*>& aciveCtx)
    {

    }
    //-------------------------------------------------------------------------------
}
