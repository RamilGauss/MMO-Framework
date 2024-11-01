/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <string>

#include "Base/Common/StrandHolder.h"
#include "Base/Common/TypeDef.h"

#include "Base/Zones/Types.h"

namespace nsBase::nsZones
{
    class TZoneManager;
    class IHopProcess;
    struct IHopProcessContext;

    class DllExport TZone
    {
        TZoneManager* mZoneMng = nullptr;

        std::list<SharedPtrHopProcess> mProcesses;

        std::list<IHopProcessContext*> mContexts;

        std::string mName;// For debugging

        nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;

    public:
        TZone(const std::string& name);

        void SetStrand(nsBase::nsCommon::TStrandHolder::Ptr strandHolder);

        const std::string& GetName() const;

        void AddProcess(SharedPtrHopProcess pProcess);
        IHopProcess* GetProcess(const std::string& processName);

        void AddContext(IHopProcessContext* pCtx);
        void RemoveContext(IHopProcessContext* pCtx);

    protected:

    private:
        void OnStopProcess(IHopProcess* pProcess, IHopProcessContext* pCtx);
        void OnFinishProcess(IHopProcess* pProcess, TZone* pZone, IHopProcessContext* pCtx);
    };
}
