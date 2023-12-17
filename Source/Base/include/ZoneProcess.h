/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <memory>
#include <list>

#include "TypeDef.h"

namespace nsZones
{
    class IContext;
    class TZone;
    class TZoneManager;

    class DllExport TZoneProcess
    {
    protected:
        std::shared_ptr<TZoneManager> mZoneMng;

        std::list<IContext*> mAciveCtx;

        std::list<IContext*> mWaitingCtx;

        int mMaxActiveCount = 1;

    public:
        TZoneProcess();
        virtual ~TZoneProcess();

        void AddZone(TZone* pZone);
        void Begin(IContext* pCtx);
        
        virtual void Work() = 0;

        void SetMaxActiveCount(int value);
        int GetMaxActiveCount() const;
    };
}
