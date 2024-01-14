/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SyncProcess.h"
#include "Base/Zones/IContext.h"
#include "Base/Zones/Zone.h"

namespace nsTornadoEngine::nsInstantiate
{
    TSyncProcess::TSyncProcess()
    {
        AddZones<Zone>();

        //AddProcess<TAsyncProcess>(Process::ASYNC, Zone::INIT, Zone::ASYNCED);
    }
    //-------------------------------------------------------------------------------
    void TSyncProcess::Work(std::list<nsBase::nsZones::IContext*>& aciveCtx)
    {

    }
    //-------------------------------------------------------------------------------
}
