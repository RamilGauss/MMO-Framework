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
        pCtx->SetActiveProcess(this);

        mWaitingCtx.push_back(pCtx);

        TryActivate();
    }
    //------------------------------------------------------------------------------
    void TProcess::Stop(IContext* pCtx)
    {
        pCtx->SetActiveProcess(nullptr);

        mWaitingCtx.remove(pCtx);
        mAciveCtx.remove(pCtx);

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

        pCtx->SetActiveProcess(nullptr);
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
        auto activeCtx = mAciveCtx;

        Work(activeCtx);

        TryActivate();
    }
    //------------------------------------------------------------------------------
}
