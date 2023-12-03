/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <memory>

#include "TypeDef.h"

namespace nsZones
{
    class IContext;
    class TZoneManager;

    class DllExport TProcess
    {
    protected:
        std::shared_ptr<TZoneManager> mZoneMng;

        std::list<IContext*> mAciveCtx;

        std::list<IContext*> mWaitingCtx;

    public:
        TProcess();

        void AddZone(TZone* pZone);
        void Begin(IContext* pCtx);
        void Work();
    };
}
