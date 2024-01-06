/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <type_traits>
#include <memory>
#include <list>
#include <string>

#include "Base/Common/TypeDef.h"
#include "Base/Common/CallbackPool.h"

#include "Base/Zones/Rank.h"

// Имя файла Process.h занято системным, поэтому называется ZoneProcess.h, а сам класс TProcess.

namespace nsBase::nsZones
{
    struct IContext;
    class TZone;
    class TZoneManager;

    class DllExport TProcess : public TRank
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
        using ProcessErrorEvent = TCallbackPool<TProcess*, IContext*>;

        ProcessStopEvent mStopEvent;
        ProcessFinishEvent mFinishEvent;
        ProcessErrorEvent mErrorEvent;

        virtual uint64_t GetTotalCount(IContext* pCtx) const;
        virtual uint64_t GetProgressCount(IContext* pCtx) const;

        float GetProgressValue(IContext* pCtx) const;

    protected:
        template <typename ToType>
        ToType* Ctx(IContext* pCtx) const
        {
            if constexpr (std::is_polymorphic<ToType>()) {
                return dynamic_cast<ToType*>(pCtx);
            }
            return reinterpret_cast<ToType*>(pCtx);
        }

        void Finish(IContext* pCtx);

        void TryActivate();

        virtual void Work(std::list<IContext*>& aciveCtx) = 0;

        virtual void SetupEvent();
        
        virtual void StartEvent(IContext* pCtx);
        virtual void StopEvent(IContext* pCtx);

    private:
        bool IsActive(IContext* pCtx) const;
    };
}
