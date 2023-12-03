#pragma once

#include <list>

#include "TypeDef.h"

namespace nsZones
{
    class TZone;
    class IContext;

    class DllExport TContextZone
    {
        IContext* mCtx = nullptr;
        TZone* mZone = nullptr;

    public:
        TContextZone(IContext* pCtx, TZone* pZone);

        void BeginProcess(TProcess* pProcess);

    };
}
