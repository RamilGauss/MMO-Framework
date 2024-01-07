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

#include "Base/Zones/Zone.h"
#include "Base/Zones/ZoneManager.h"

namespace nsBase::nsZones
{
    class TProcess;
};

namespace nsTornadoEngine
{
    struct TSceneContext;

    class DllExport TSceneStateGraph
    {
        nsBase::nsZones::TZoneManager mZoneMng;

        nsBase::nsZones::TZone mInitZone;
        nsBase::nsZones::TZone mInstantiatedZone;
        nsBase::nsZones::TZone mDestroyedZone;
        nsBase::nsZones::TZone mDeadZone;

        using SharedPtrProcess = std::shared_ptr<nsBase::nsZones::TProcess>;

        std::list<SharedPtrProcess> mProcesses;

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

        void StartProcess(Process process, TSceneContext* pCtx);
        void StopProcess(TSceneContext* pCtx);

        std::optional<std::string> GetZoneName(TSceneContext* pCtx) const;

        // Mainly for the progress value
        nsBase::nsZones::TProcess* GetProcess(TSceneContext* pCtx) const;
    private:
        template <typename Process>
        void AddProcess(const std::string& name, nsBase::nsZones::TZone* fromZone, 
            nsBase::nsZones::TZone* toZone, int maxActiveCount = 1)
        {
            auto p = std::make_shared<Process>();
            fromZone->AddProcess(p.get());
            mProcesses.push_back(p);

            p->Setup(name, fromZone, toZone, maxActiveCount);
        }
    };
}
