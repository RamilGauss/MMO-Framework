/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "gtest/gtest.h"

#include "ZoneManager.h"

TEST(Json, Complex)
{
    nsZones::TZoneManager zoneMgr;

    nsZones::TZone a;
    nsZones::TZone b;

    zoneMgr.AddZone(&a);
    zoneMgr.AddZone(&b);

    nsZones::TProcess process;

    a.AddProcess(&process);
}
