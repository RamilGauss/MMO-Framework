/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/HopProcess.h"

#include "Base/Zones/ZoneManager.h"
#include "Base/Zones/Zone.h"
#include "Base/Zones/IHopProcessContext.h"

#include "Base/Common/BL_Debug.h"

namespace nsBase::nsZones
{
    void THopProcess::Setup(const std::string& name, TZone* finishZone, int maxActiveCount)
    {
        mName = name;
        mFinishZone = finishZone;
        mMaxActiveCount = maxActiveCount;

        mZoneMng->SetRank(GetNextRank());

        SetupEvent();
    }
    //------------------------------------------------------------------------------
    THopProcess::~THopProcess()
    {

    }
    //------------------------------------------------------------------------------
    std::string THopProcess::GetName() const
    {
        return mName;
    }
    //------------------------------------------------------------------------------
    void THopProcess::Start(IHopProcessContext* pCtx)
    {
        auto activeProcess = pCtx->GetActiveProcess(GetRank());
        if (activeProcess)
            activeProcess->Stop(pCtx);

        // 1. Push, 2. StartEvent
        pCtx->PushActiveProcess(this);
        StartEvent(pCtx);

        mWaitingCtx.push_back(pCtx);

        TryActivate();
    }
    //------------------------------------------------------------------------------
    void THopProcess::Stop(IHopProcessContext* pCtx)
    {
        mWaitingCtx.remove(pCtx);
        mAciveCtx.remove(pCtx);

        // 1. StopEvent, 2. Pop
        StopEvent(pCtx);
        pCtx->PopActiveProcess();

        mStopEvent.Notify(this, pCtx);

        TryActivate();
    }
    //------------------------------------------------------------------------------
    void THopProcess::Finish(IHopProcessContext* pCtx)
    {
        if (!IsActive(pCtx)) {
            BL_FIX_BUG();
        }

        mAciveCtx.remove(pCtx);

        pCtx->PopActiveProcess();

        mFinishEvent.Notify(this, mFinishZone, pCtx);

        TryActivate();
    }
    //------------------------------------------------------------------------------
    int THopProcess::GetMaxActiveCount() const
    {
        return mMaxActiveCount;
    }
    //------------------------------------------------------------------------------
    TZone* THopProcess::GetFinishZone() const
    {
        return mFinishZone;
    }
    //------------------------------------------------------------------------------
    bool THopProcess::IsActive(IHopProcessContext* pCtx) const
    {
        auto fit = std::find(mAciveCtx.begin(), mAciveCtx.end(), pCtx);
        return fit != mAciveCtx.end();
    }
    //------------------------------------------------------------------------------
    void THopProcess::TryActivate()
    {
        if (mAciveCtx.size() >= GetMaxActiveCount() || mWaitingCtx.empty())
            return;

        auto pCtx = mWaitingCtx.front();
        mWaitingCtx.pop_front();

        mAciveCtx.push_back(pCtx);
    }
    //------------------------------------------------------------------------------
    bool THopProcess::Work()
    {
        mZoneMng->Work();

        auto activeCtx = mAciveCtx;

        // Даже если ZoneMng потратил время, то значит есть активные задачи.
        bool wasSpent = (activeCtx.size() > 0);

        Work(activeCtx);

        TryActivate();

        return wasSpent;
    }
    //------------------------------------------------------------------------------
    uint32_t THopProcess::GetActiveContextCount() const
    {
        return mAciveCtx.size();
    }
    //------------------------------------------------------------------------------
    void THopProcess::SetupEvent()
    {

    }
    //------------------------------------------------------------------------------
    void THopProcess::StartEvent(IHopProcessContext* pCtx)
    {

    }
    //------------------------------------------------------------------------------
    void THopProcess::StopEvent(IHopProcessContext* pCtx)
    {

    }
    //------------------------------------------------------------------------------
    uint64_t THopProcess::GetTotalCount(IHopProcessContext* pCtx) const
    {
        return 1;
    }
    //------------------------------------------------------------------------------
    uint64_t THopProcess::GetProgressCount(IHopProcessContext* pCtx) const
    {
        return 0;
    }
    //------------------------------------------------------------------------------
    float THopProcess::GetProgressValue(IHopProcessContext* pCtx) const
    {
        if (GetTotalCount(pCtx) == 0) {
            return 1.0f;
        }

        return (GetProgressCount(pCtx) * 1.0f / GetTotalCount(pCtx));
    }
    //------------------------------------------------------------------------------
}
