/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/ZoneProcess.h"

#include "Base/Zones/ZoneManager.h"
#include "Base/Zones/Zone.h"
#include "Base/Zones/IContext.h"

#include "Base/Common/BL_Debug.h"

namespace nsBase::nsZones
{
    TProcess::TProcess()
    {
        mZoneMng.reset(new TZoneManager());
    }
    //------------------------------------------------------------------------------
    void TProcess::Setup(const std::string& name, TZone* fromZone, TZone* toZone, int maxActiveCount)
    {
        mName = name;
        mFromZone = fromZone;
        mToZone = toZone;
        mMaxActiveCount = maxActiveCount;

        mFromZone->AddProcess(this);

        mZoneMng->SetRank(GetNextRank());

        SetupEvent();
    }
    //------------------------------------------------------------------------------
    TProcess::~TProcess()
    {

    }
    //------------------------------------------------------------------------------
    std::string TProcess::GetName() const
    {
        return mName;
    }
    //------------------------------------------------------------------------------
    void TProcess::Start(IContext* pCtx)
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
    void TProcess::Stop(IContext* pCtx)
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
    void TProcess::Finish(IContext* pCtx)
    {
        if (!IsActive(pCtx)) {
            BL_FIX_BUG();
        }

        mAciveCtx.remove(pCtx);

        pCtx->PopActiveProcess();

        mFinishEvent.Notify(this, mToZone, pCtx);

        TryActivate();
    }
    //------------------------------------------------------------------------------
    int TProcess::GetMaxActiveCount() const
    {
        return mMaxActiveCount;
    }
    //------------------------------------------------------------------------------
    TZone* TProcess::GetFromZone() const
    {
        return mFromZone;
    }
    //------------------------------------------------------------------------------
    TZone* TProcess::GetToZone() const
    {
        return mToZone;
    }
    //------------------------------------------------------------------------------
    bool TProcess::IsActive(IContext* pCtx) const
    {
        auto fit = std::find(mAciveCtx.begin(), mAciveCtx.end(), pCtx);
        return fit != mAciveCtx.end();
    }
    //------------------------------------------------------------------------------
    void TProcess::TryActivate()
    {
        if (mAciveCtx.size() >= GetMaxActiveCount() || mWaitingCtx.empty())
            return;

        auto pCtx = mWaitingCtx.front();
        mWaitingCtx.pop_front();

        mAciveCtx.push_back(pCtx);
    }
    //------------------------------------------------------------------------------
    void TProcess::Work()
    {
        mZoneMng->Work();

        auto activeCtx = mAciveCtx;

        Work(activeCtx);

        TryActivate();
    }
    //------------------------------------------------------------------------------
    uint32_t TProcess::GetActiveContextCount() const
    {
        return mAciveCtx.size();
    }
    //------------------------------------------------------------------------------
    void TProcess::SetupEvent()
    {

    }
    //------------------------------------------------------------------------------
    void TProcess::StartEvent(IContext* pCtx)
    {

    }
    //------------------------------------------------------------------------------
    void TProcess::StopEvent(IContext* pCtx)
    {

    }
    //------------------------------------------------------------------------------
    uint64_t TProcess::GetTotalCount(IContext* pCtx) const
    {
        return 1;
    }
    //------------------------------------------------------------------------------
    uint64_t TProcess::GetProgressCount(IContext* pCtx) const
    {
        return 0;
    }
    //------------------------------------------------------------------------------
    float TProcess::GetProgressValue(IContext* pCtx) const
    {
        if (GetTotalCount(pCtx) == 0) {
            return 1.0f;
        }

        return (GetProgressCount(pCtx) * 1.0f / GetTotalCount(pCtx));
    }
    //------------------------------------------------------------------------------
}
