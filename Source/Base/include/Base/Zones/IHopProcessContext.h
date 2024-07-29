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
    class THopProcess;
    class TZone;

    struct DllExport IHopProcessContext
    {
        void PushActiveProcess(THopProcess* pProcess);
        void PopActiveProcess();

        void PushOwnerZone(TZone* pZone);
        void PopOwnerZone();

        THopProcess* GetActiveProcess(uint32_t rank = 0) const;
        TZone* GetOwnerZone(uint32_t rank = 0) const;

        uint32_t GetRankCount() const;

        void StartProcess(const std::string& processName, uint32_t rank = 0);

        void SetStrand(nsBase::nsCommon::TStrandHolder::Ptr strandHolder);

    private:
        std::vector<THopProcess*> mActiveProcesses;
        std::vector<TZone*> mOwnerZones;

        nsBase::nsCommon::TStrandHolder::Ptr mStrandHolder;
    };
}
