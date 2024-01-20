/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Zones/ZoneProcess.h"

namespace nsBase::nsZones
{
    struct IContext;
};

namespace nsTornadoEngine
{
    class DllExport TDummyAsyncProcess : public nsBase::nsZones::TProcess
    {
        enum class Zone
        {
            INIT,
            ASYNCED,
            SYNCED,
        };

        enum class Process
        {
            FILE_LOADING,
            SCENE_DESERIALIZING,     // in one step
            PREPARE_TREE_ENTITY,
            SORTING_ENTITIES_BY_RANK,
            COMPONENT_DESERIALIZING,
        };
    public:
        TDummyAsyncProcess();

        void Work(std::list<nsBase::nsZones::IContext*>& aciveCtx) override;
    };
}
