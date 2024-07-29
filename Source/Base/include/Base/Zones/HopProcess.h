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

#include <boost/asio/awaitable.hpp>

#include "Base/Common/AsyncAwaitable.h"
#include "Base/Common/CallbackPool.h"
#include "Base/Common/TypeDef.h"

#include "Base/Zones/Rank.h"
#include "Base/Zones/ZoneManagerMaster.h"

namespace nsBase::nsZones
{
    struct IHopProcessContext;
    class TZone;
    class TZoneManager;

    class DllExport THopProcess : public TZoneManagerMaster, public TRank
    {
    protected:
        std::list<IHopProcessContext*> mAciveCtx;

        std::list<IHopProcessContext*> mWaitingCtx;

        int mMaxActiveCount = 1;

        TZone* mFinishZone = nullptr;

        std::string mName;

        nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;
        nsBase::nsCommon::TAsyncAwaitable::Ptr mCtxWaitingAwaitable;

    public:
        THopProcess();
        virtual ~THopProcess();

        void Setup(const std::string& name, TZone* finishZone, int maxActiveCount = 1);

        void SetStrand(nsBase::nsCommon::TStrandHolder::Ptr strandHolder);

        boost::asio::awaitable<void> Start(IHopProcessContext* pCtx);
        boost::asio::awaitable<void> Stop(IHopProcessContext* pCtx);

        std::string GetName() const;

        int GetMaxActiveCount() const;
        TZone* GetFinishZone() const;

        uint32_t GetActiveContextCount() const;

        // Events
        using ProcessStopEvent = TCallbackPool<THopProcess*, IHopProcessContext*>;
        using ProcessFinishEvent = TCallbackPool<THopProcess*, TZone*, IHopProcessContext*>;
        using ProcessErrorEvent = TCallbackPool<THopProcess*, IHopProcessContext*>;

        ProcessStopEvent mStopEvent;
        ProcessFinishEvent mFinishEvent;
        ProcessErrorEvent mErrorEvent;

        virtual uint64_t GetTotalCount(IHopProcessContext* pCtx) const;
        virtual uint64_t GetProgressCount(IHopProcessContext* pCtx) const;

        float GetProgressValue(IHopProcessContext* pCtx) const;

    protected:
        template <typename ToType>
        ToType* Ctx(IHopProcessContext* pCtx) const
        {
            if constexpr (std::is_polymorphic<ToType>()) {
                return dynamic_cast<ToType*>(pCtx);
            }
            return reinterpret_cast<ToType*>(pCtx);
        }

        void Finish(IHopProcessContext* pCtx);

        boost::asio::awaitable<void> TryActivate();
        boost::asio::awaitable<void> AsyncWork(IHopProcessContext* ctx);

        virtual void Work(IHopProcessContext* ctx) = 0;

        virtual void SetupEvent();
        
        virtual void StartEvent(IHopProcessContext* pCtx);
        virtual void StopEvent(IHopProcessContext* pCtx);

    private:
        bool IsActive(IHopProcessContext* pCtx) const;
    };
}
