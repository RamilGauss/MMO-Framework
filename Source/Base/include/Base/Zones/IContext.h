/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"
#include "Base/Common/ProgressValue.h"

namespace nsBase::nsZones
{
    class TProcess;
    class TZone;
    class TContextZone;

    struct DllExport IContext
    {
        TProgressValue mProgress;

        void SetActiveProcess(TProcess* pProcess);
        void SetOwnerZone(TZone* pZone);

        TProcess* GetActiveProcess() const;
        TZone* GetOwnerZone() const;
        TContextZone GetContextZone();

    private:
        TProcess* mActiveProcess = nullptr;
        TZone* mOwnerZone = nullptr;
    };
}
