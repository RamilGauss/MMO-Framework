/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <string>

#include "Base/Common/CoroInThread.h"
#include "Base/Common/StrandHolder.h"
#include "Base/Common/TypeDef.h"

#include "Base/Zones/Types.h"

namespace nsBase::nsZones
{
    class DllExport TZone
    {
    public:
        TZone(const std::string& name);

        void Init(nsBase::nsCommon::TStrandHolder::Ptr strandHolder, 
            nsBase::nsCommon::TCoroInThread::Ptr coroInThread);

        std::string GetName() const;

        void AddProcess(SharedPtrHopProcess pProcess);
        SharedPtrHopProcess GetProcess(const std::string& processName);

        void AddContext(SharedPtrHopProcessContext pCtx);
        void RemoveContext(SharedPtrHopProcessContext pCtx);

    private:
        std::list<SharedPtrHopProcess> mProcesses;

        std::list<SharedPtrHopProcessContext> mContexts;

        std::string mName;// For debugging

        nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;
        nsBase::nsCommon::TCoroInThread::Ptr mCoroInThread;
    };
}
