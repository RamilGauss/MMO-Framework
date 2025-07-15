/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/ContextState.h"
#include "Base/Zones/ISubProcess.h"

namespace nsBase::nsZones
{
    void ISubProcess::Init(nsBase::nsCommon::TStrandHolder::Ptr strandHolder, 
        nsBase::nsCommon::TCoroInThread::Ptr coroInThread)
    {
        mStrandHolder = std::move(strandHolder);
        mCoroInThread = std::move(coroInThread);
    }
    //---------------------------------------------------------------------------------------------
    ISubProcess::~ISubProcess()
    {

    }
    //---------------------------------------------------------------------------------------------
    TContextStateInProcess ISubProcess::GetState(SharedPtrHopProcessContext pCtx) const
    {
        auto fit = mCtxStateMap.find(pCtx);
        if (fit == mCtxStateMap.end())
            return {};
        return fit->second->state;
    }
    //---------------------------------------------------------------------------------------------
}
