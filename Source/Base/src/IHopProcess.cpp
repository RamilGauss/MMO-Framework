/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/IHopProcess.h"

namespace nsBase::nsZones
{
    IHopProcess::IHopProcess(nsBase::nsCommon::TCoroInThread::Ptr coroInThread,
        nsBase::nsCommon::TStrandHolder::Ptr strandHolder) :
        mStrandHolder(std::move(strandHolder)),
        mCoroInThread(std::move(coroInThread))
    {
    }
    //---------------------------------------------------------------------------------------------------
    IHopProcess::~IHopProcess() 
    {
    }
    //---------------------------------------------------------------------------------------------------
    std::optional<SharedPtrContextState> IHopProcess::GetState(IHopProcessContext* pCtx) const
    {
        auto fit = mCtxStateMap.find(pCtx);
        if (fit == mCtxStateMap.end())
            return std::nullopt;
        return fit->second;
    }
    //---------------------------------------------------------------------------------------------------
}
