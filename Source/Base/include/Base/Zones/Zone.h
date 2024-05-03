/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <string>

#include "Base/Common/TypeDef.h"

#include "Base/Zones/Rank.h"
#include "Base/Zones/Types.h"

namespace nsBase::nsZones
{
    class TZoneManager;
    class THopProcess;
    struct IHopProcessContext;

    class DllExport TZone : public TRank
    {
        TZoneManager* mZoneMng = nullptr;

        std::list<SharedPtrHopProcess> mProcesses;

        std::list<IHopProcessContext*> mContexts;

        std::string mName;// For debugging

    public:
        TZone(const std::string& name);

        const std::string& GetName() const;

        void AddProcess(SharedPtrHopProcess pProcess);
        THopProcess* GetProcess(const std::string& processName);
        
        void AddContext(IHopProcessContext* pCtx);
        void RemoveContext(IHopProcessContext* pCtx);

        bool Work();

    protected:

    private:
        void OnStopProcess(THopProcess* pProcess, IHopProcessContext* pCtx);
        void OnFinishProcess(THopProcess* pProcess, TZone* pZone, IHopProcessContext* pCtx);
    };
}
