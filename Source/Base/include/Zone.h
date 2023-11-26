#pragma once

#include <list>

#include "TypeDef.h"

namespace nsZones
{
    class TZoneManager;

    class DllExport TZone
    {
        TZoneManager* mZoneMng = nullptr;

        std::list<TProcess*> mProcesses;

    public:
        void AddProcess(TProcess* pProcess);

        void AddProcess(IContext* pCtx);
        void RemoveProcess(IContext* pCtx);

        void Work();
    };
}
