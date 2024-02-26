/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>

#include "Base/Common/TypeDef.h"
#include "Base/Common/ProgressValue.h"

namespace nsBase::nsZones
{
    class TProcess;
    class TZone;
    class TContextState;

    struct DllExport IContext
    {
        void PushActiveProcess(TProcess* pProcess);
        void PopActiveProcess();

        void PushOwnerZone(TZone* pZone);
        void PopOwnerZone();

        TProcess* GetActiveProcess(uint32_t rank = 0) const;
        TZone* GetOwnerZone(uint32_t rank = 0) const;

        uint32_t GetRankCount() const;

        TContextState GetContextState(uint32_t rank = 0);

        void StartProcess(const std::string& processName, uint32_t rank = 0);

    private:
        std::vector<TProcess*> mActiveProcesses;
        std::vector<TZone*> mOwnerZones;
    };
}
