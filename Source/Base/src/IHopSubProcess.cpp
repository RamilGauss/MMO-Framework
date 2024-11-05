/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/IHopSubProcess.h"

namespace nsBase::nsZones
{
    IHopSubProcess::IHopSubProcess(nsBase::nsCommon::TCoroInThread::Ptr coroInThread,
        nsBase::nsCommon::TStrandHolder::Ptr strandHolder) :
        mStrandHolder(std::move(strandHolder)),
        mCoroInThread(std::move(coroInThread))
    {
    }
    //---------------------------------------------------------------------------------------------------
    IHopSubProcess::~IHopSubProcess()
    {
    }
    //---------------------------------------------------------------------------------------------------
    std::optional<SharedPtrContextState> IHopSubProcess::GetState(IHopProcessContext* pCtx) const
    {
        auto fit = mCtxStateMap.find(pCtx);
        if (fit == mCtxStateMap.end())
            return std::nullopt;
        return fit->second;
    }
    //---------------------------------------------------------------------------------------------------
}
