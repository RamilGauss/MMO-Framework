#pragma once

#include "TypeDef.h"

#include "Zone.h"
#include "IContext.h"

namespace nsZones
{
    class DllExport TProcess
    {
    protected:
        TZoneManager mZoneMng;

    public:
        void AddZone(TZone* pZone);

        void Begin(IContext* pCtx);
    };
}
