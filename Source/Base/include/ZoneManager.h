#pragma once

#include <list>

#include "TypeDef.h"

#include "Zone.h"

namespace nsZones
{
    class DllExport TZoneManager
    {
        std::list<TZone*> mZones;

    public:
        void AddZone(TZone* pZone);

        void Work()
        {
            for (auto& pZone : mZones) {
                pZone->Work();
            }
        }

        void BeginProcess();
    };
}


// Usage
void Test()
{
    nsZones::TZoneManager zoneMgr;

    nsZones::TZone a;
    nsZones::TZone b;

    zoneMgr.AddZone(&a);
    zoneMgr.AddZone(&b);

    TProcess process;

    a.AddProcess(&process);


}