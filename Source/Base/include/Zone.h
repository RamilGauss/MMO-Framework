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
    class TProcess;
    class IContext;

    class DllExport TZone
    {
        TZoneManager* mZoneMng = nullptr;

        std::list<TProcess*> mProcesses;

        std::list<IContext*> mContexts;

    public:
        void AddProcess(TProcess* pProcess);
        void AddContext(IContext* pCtx);
        void RemoveContext(IContext* pCtx);
        void Work();
    };
}
