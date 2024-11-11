/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "InstantiateProcess.h"
//#include "Base/Zones/IContext.h"
#include "Base/Zones/Zone.h"

#include "Modules/Resources/Scene/StateGraph/Instantiate/Async/AsyncProcess.h"
#include "Modules/Resources/Scene/StateGraph/Instantiate/DummyAsync/DummyAsyncProcess.h"
#include "Modules/Resources/Scene/StateGraph/Instantiate/Sync/SyncProcess.h"

namespace nsTornadoEngine
{
    std::string TInstantiateProcess::GetName() const
    {
        return "Instantiate";
    }
    //-------------------------------------------------------------------------------
    boost::asio::awaitable<bool> TInstantiateProcess::Start(nsBase::nsZones::SharedPtrHopProcessContext pCtx) { co_return true; }
    boost::asio::awaitable<void> TInstantiateProcess::Stop(nsBase::nsZones::SharedPtrHopProcessContext pCtx) { co_return; }
    nsBase::nsZones::TContextStateInProcess TInstantiateProcess::GetState(nsBase::nsZones::SharedPtrHopProcessContext pCtx) const { return {}; }
    void TInstantiateProcess::InitSubProcesses(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TCoroInThread::Ptr coroInThread)
    {
    }
    //-------------------------------------------------------------------------------
}
