/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <memory>
#include <list>
#include <string>

#include "Base/Common/TypeDef.h"
#include "Base/Common/CallbackPool.h"

// Имя файла Process.h занято системным, поэтому называется ZoneProcess.h, а сам класс TProcess.

namespace nsBase::nsZones
{
    struct IContext;
    class TZone;
    class TZoneManager;

    class DllExport TProcess
    {
    protected:
        std::shared_ptr<TZoneManager> mZoneMng;

        std::list<IContext*> mAciveCtx;

        std::list<IContext*> mWaitingCtx;

        int mMaxActiveCount = 1;

        TZone* mFromZone = nullptr;
        TZone* mToZone = nullptr;

        std::string mName;

    public:
        TProcess();
        virtual ~TProcess();

        void Setup(const std::string& name, TZone* fromZone, TZone* toZone, int maxActiveCount = 1);

        void Start(IContext* pCtx);
        void Stop(IContext* pCtx);
        
        void Work();

        std::string GetName() const;

        int GetMaxActiveCount() const;
        TZone* GetFromZone() const;
        TZone* GetToZone() const;

        // Events
        using ProcessStopEvent = TCallbackPool<TProcess*, IContext*>;
        using ProcessFinishEvent = TCallbackPool<TProcess*, TZone*, IContext*>;

        ProcessStopEvent mStopEvent;
        ProcessFinishEvent mFinishEvent;

    protected:
        template <typename T>
        T* Ctx(IContext* pCtx) const
        {
            return dynamic_cast<T*>(pCtx);
        }

        void Finish(IContext* pCtx);

        void TryActivate();

        virtual void Work(std::list<IContext*>& aciveCtx) = 0;

    private:
        bool IsActive(IContext* pCtx) const;
    };
}
