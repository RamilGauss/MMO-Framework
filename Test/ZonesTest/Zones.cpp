/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "Base/Zones/ZoneManager.h"
#include "Base/Zones/Zone.h"
#include "Base/Zones/ZoneProcess.h"

class A_process : public nsBase::nsZones::TZoneProcess
{
public:
    void Work() override {}
};

TEST(Json, Complex)
{
    nsBase::nsZones::TZoneManager zoneMgr;

    nsBase::nsZones::TZone a;
    nsBase::nsZones::TZone b;

    zoneMgr.AddZone(&a);
    zoneMgr.AddZone(&b);

    A_process a_process;

    a.AddProcess(&a_process);
}
