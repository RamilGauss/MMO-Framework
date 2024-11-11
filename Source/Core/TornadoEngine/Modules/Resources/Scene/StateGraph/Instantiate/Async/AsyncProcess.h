/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

//#include <thread>

#include "Base/Zones/ISubProcess.h"

namespace nsBase::nsZones
{
    struct IContext;
};

namespace nsTornadoEngine
{
    class DllExport TAsyncProcess : public nsBase::nsZones::ISubProcess
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

        //std::jthread mThread;
    public:
        TAsyncProcess();

        //void Work(std::list<nsBase::nsZones::IContext*>& aciveCtx) override;

    private:
        //void ThreadFunc();
    };
}
