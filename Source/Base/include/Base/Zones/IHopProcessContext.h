/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include <string>

#include "Base/Common/TypeDef.h"
#include "Base/Common/ProgressValue.h"
#include "Base/Common/StrandHolder.h"

namespace nsBase::nsZones
{
    class IHopProcess;
    class TZone;

    struct DllExport IHopProcessContext
    {
        IHopProcess* GetActiveProcess() const;
        TZone* GetOwnerZone() const;

        void StartProcess(const std::string& processName);

        void SetStrand(nsBase::nsCommon::TStrandHolder::Ptr strandHolder);

    private:
        IHopProcess* mActiveProcess = nullptr;
        TZone* mOwnerZone = nullptr;

        nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;
    };
}
