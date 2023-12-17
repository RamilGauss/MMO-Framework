/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>

#include "TypeDef.h"

namespace nsZones
{
    class TZone;
    class DllExport TZoneManager
    {
        std::list<TZone*> mZones;

    public:
        void AddZone(TZone* pZone);

        void Work();

        void BeginProcess();
    };
}
