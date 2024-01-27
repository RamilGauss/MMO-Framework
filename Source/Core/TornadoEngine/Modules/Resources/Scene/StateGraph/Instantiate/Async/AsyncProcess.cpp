/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "AsyncProcess.h"
#include "Base/Zones/IContext.h"
#include "Base/Zones/Zone.h"

namespace nsTornadoEngine
{
    TAsyncProcess::TAsyncProcess()
    {
        mThread = std::jthread(&TAsyncProcess::ThreadFunc, this);

        AddZones<Zone>();

        //AddProcess<TAsyncProcess>(Process::ASYNC, Zone::INIT, Zone::ASYNCED);
    }
    //-------------------------------------------------------------------------------
    void TAsyncProcess::Work(std::list<nsBase::nsZones::IContext*>& aciveCtx)
    {

    }
    //-------------------------------------------------------------------------------
    void TAsyncProcess::ThreadFunc()
    {
        while (true) {

        }
    }
    //-------------------------------------------------------------------------------
}
