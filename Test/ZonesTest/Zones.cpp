/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "ZoneManager.h"
#include "Zone.h"
#include "ZoneProcess.h"

class A_process : public nsZones::TZoneProcess
{
public:
    void Work() override {}
};

TEST(Json, Complex)
{
    nsZones::TZoneManager zoneMgr;

    nsZones::TZone a;
    nsZones::TZone b;

    zoneMgr.AddZone(&a);
    zoneMgr.AddZone(&b);

    A_process a_process;

    a.AddProcess(&a_process);
}
