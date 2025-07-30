/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Zones/IHopProcess.h"

#include "TornadoEngine/Modules/Resources/Scene/StateGraph/Instantiate/Async/ComponentDeserializingProcess.h"
#include "TornadoEngine/Modules/Resources/Scene/StateGraph/Instantiate/Async/SceneDeserializingProcess.h"
#include "TornadoEngine/Modules/Resources/Scene/StateGraph/Instantiate/Async/SceneFileLoadingProcess.h"

#include "TornadoEngine/Modules/Resources/Scene/StateGraph/Instantiate/Sync/EntityInstantiatingProcess.h"
#include "TornadoEngine/Modules/Resources/Scene/StateGraph/Instantiate/Sync/PrefabInstantiatingProcess.h"
#include "TornadoEngine/Modules/Resources/Scene/StateGraph/Instantiate/Sync/UniverseIndexCreatingProcess.h"

namespace nsBase::nsZones
{
    struct IContext;
};

namespace nsTornadoEngine
{
    class DllExport TInstantiateProcess : public nsBase::nsZones::IHopProcess
    {
    public:
        TInstantiateProcess(std::string name) : nsBase::nsZones::IHopProcess(std::move(name)) {}
        boost::asio::awaitable<bool> Start(nsBase::nsZones::SharedPtrHopProcessContext pCtx) override;
        boost::asio::awaitable<void> Stop(nsBase::nsZones::SharedPtrHopProcessContext pCtx) override;
        nsBase::nsZones::TContextStateInProcess GetState(nsBase::nsZones::SharedPtrHopProcessContext pCtx) const override;
    protected:
        void InitSubProcesses(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
            nsBase::nsCommon::TCoroInThread::Ptr coroInThread) override;

        TSceneFileLoadingProcess mSceneFileLoadingProcess;
        TSceneDeserializingProcess mSceneDeserializingProcess;
        TComponentDeserializingProcess mComponentDeserializingProcess;

        TUniverseIndexCreatingProcess mUniverseIndexCreatingProcess;
        TPrefabInstantiatingProcess mPrefabInstantiatingProcess;
        TEntityInstantiatingProcess mEntityInstantiatingProcess;
    };
}
