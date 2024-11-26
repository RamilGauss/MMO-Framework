/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/IHopProcess.h"
#include "Base/Zones/ContextState.h"

namespace nsBase::nsZones
{
    IHopProcess::IHopProcess(std::string name)
    {
        mName = std::move(name);
    }
    //--------------------------------------------------------------------------------------------------
    std::string IHopProcess::GetName() const
    {
        return mName;
    }
    //--------------------------------------------------------------------------------------------------
    void IHopProcess::Init(nsBase::nsCommon::TStrandHolder::Ptr strandHolder,
        nsBase::nsCommon::TCoroInThread::Ptr coroInThread)
    {
        mStrandHolder = std::move(strandHolder);
        mCoroInThread = std::move(coroInThread);

        InitSubProcesses(mStrandHolder, mCoroInThread);
    }
    //--------------------------------------------------------------------------------------------------
    void IHopProcess::SetCurrentSubProcess(SharedPtrHopProcessContext pCtx, ISubProcess* pCurrentSubvProcess)
    {
        if (pCurrentSubvProcess)
            mCurrentSubProcess.insert_or_assign(pCtx, pCurrentSubvProcess);
        else
            mCurrentSubProcess.erase(pCtx);
    }
    //--------------------------------------------------------------------------------------------------
    ISubProcess* IHopProcess::GetCurrentSubProcess(SharedPtrHopProcessContext pCtx) const
    {
        auto fit = mCurrentSubProcess.find(pCtx);
        if (fit == mCurrentSubProcess.end()) {
            return nullptr;
        }
        return fit->second;
    }
    //--------------------------------------------------------------------------------------------------

}

