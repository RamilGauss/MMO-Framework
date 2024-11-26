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

#include <magic_enum/magic_enum.hpp>

#include "Base/Common/TypeDef.h"

#include "Base/Zones/ZoneManager.h"
#include "Base/Zones/Zone.h"

#include "Modules/Resources/Scene/StateGraph/SceneContext.h"

namespace nsTornadoEngine
{
    struct TSceneContext;

    class DllExport TSceneStateGraph
    {
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

        void StartProcess(Process process, TSceneContextPtr pCtx);
        void StopProcess(TSceneContextPtr pCtx);

        std::optional<std::string> GetZoneName(TSceneContextPtr pCtx) const;

        // Mainly for the progress value
        std::optional<nsBase::nsZones::TContextStateInProcess> GetSceneInstanceState(TSceneContextPtr pCtx);

    private:
        template <typename ENUM_NAME>
        std::string ToString(ENUM_NAME enumName)
        {
            return std::string(magic_enum::enum_name(enumName));
        }

        nsBase::nsZones::TZoneManager mZoneMng;

        enum class Zone
        {
            INIT,
            INSTANTIATED,
            DESTROYED,
            DEAD,
        };

        boost::asio::io_context mIoContext;

        nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;
        nsBase::nsCommon::TCoroInThread::Ptr mCoroInThread;

        nsBase::nsZones::SharedPtrZone mInitZone;
        nsBase::nsZones::SharedPtrZone mInstantiatedZone;
        nsBase::nsZones::SharedPtrZone mDestroyedZone;
        nsBase::nsZones::SharedPtrZone mDeadZone;

    };
}
