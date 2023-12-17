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
    class TZoneManager;
    class TZoneProcess;
    class IContext;

    class DllExport TZone
    {
        TZoneManager* mZoneMng = nullptr;

        std::list<TZoneProcess*> mProcesses;

        std::list<IContext*> mContexts;

    public:
        void AddProcess(TZoneProcess* pProcess);
        void AddContext(IContext* pCtx);
        void RemoveContext(IContext* pCtx);
        void Work();
    };
}
