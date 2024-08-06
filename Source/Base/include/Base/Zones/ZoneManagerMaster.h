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
#include "Base/Zones/Types.h"

namespace nsBase::nsZones
{
    class DllExport TZoneManagerMaster
    {
    public:
        TZoneManagerMaster() { mZoneMng.reset(new TZoneManager()); }

    protected:
        SharedPtrZoneManager mZoneMng;

        template <typename ZoneEnum>
        void AddZones()
        {
            constexpr auto zones = magic_enum::enum_names<ZoneEnum>();
            for (auto sv : zones) {
                std::string zoneName = std::string(sv);
                mZoneMng->AddZone(std::make_shared<TZone>(zoneName));
            }
        }

        template <typename ProcessType, typename ProcessEnum, typename ZoneEnum>
        void AddProcess(ProcessEnum process, ZoneEnum fromZone,
            ZoneEnum toZone, int maxActiveCount = 1)
        {
            TZone* pFromZone = GetZone(fromZone);
            TZone* pToZone = GetZone(toZone);

            auto p = std::make_shared<ProcessType>();
            pFromZone->AddProcess(p);

            auto processName = GetProcessName(process);
            p->Setup(processName, pToZone, maxActiveCount);
        }

        template <typename ZoneEnum>
        TZone* GetZone(ZoneEnum zone)
        {
            auto zoneName = std::string(magic_enum::enum_name(zone));
            return mZoneMng->GetZone(zoneName);
        }

        template <typename ProcessEnum>
        std::string GetProcessName(ProcessEnum process) const
        {
            return std::string(magic_enum::enum_name(process));
        }
    };
}
