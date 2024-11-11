/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <optional>
#include <list>
#include <memory>

#include "Base/Common/TypeDef.h"

#include "Base/Zones/ZoneManager.h"
#include "Base/Zones/Zone.h"

namespace nsTornadoEngine
{
    struct TSceneContext;

    class DllExport TSceneStateGraph
    {
        nsBase::nsZones::TZoneManager mZoneMng;

        enum class Zone
        {
            INIT,
            INSTANTIATED,
            DESTROYED,
            DEAD,
        };

    public:
        enum class Process
        {
            INSTANTIATE,
            CANCEL_INSTANTIATE,
            DESTROY,
            SAVE,
        };

        TSceneStateGraph();

        void Init();

        // If the method spent a quant, then the method returns true, else returns false.
        void Work(int maxDuration);

        void StartProcess(Process process, TSceneContext* pCtx);
        void StopProcess(TSceneContext* pCtx);

        std::optional<std::string> GetZoneName(TSceneContext* pCtx) const;

        // Mainly for the progress value
        //nsBase::nsZones::IHopProcess* GetProcess(TSceneContext* pCtx) const;

    private:
        boost::asio::io_context mIoContext;

        nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;
        nsBase::nsCommon::TCoroInThread::Ptr mCoroInThread;
    };
}
