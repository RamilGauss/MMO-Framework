/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "DummyAsyncProcess.h"
#include "Base/Zones/IContext.h"
#include "Base/Zones/Zone.h"

namespace nsTornadoEngine
{
    TDummyAsyncProcess::TDummyAsyncProcess()
    {
        AddZones<Zone>();

        //AddProcess<TAsyncProcess>(Process::ASYNC, Zone::INIT, Zone::ASYNCED);
    }
    //-------------------------------------------------------------------------------
    void TDummyAsyncProcess::Work(std::list<nsBase::nsZones::IContext*>& aciveCtx)
    {

    }
    //-------------------------------------------------------------------------------
}
