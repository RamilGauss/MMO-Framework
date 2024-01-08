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

namespace nsBase::nsZones
{
    class TZoneManager;
    class TProcess;
    struct IContext;

    class DllExport TZone : public TRank
    {
        TZoneManager* mZoneMng = nullptr;

        std::list<TProcess*> mProcesses;

        std::list<IContext*> mContexts;

        std::string mName;// For debugging

    public:
        TZone(const std::string& name);

        const std::string& GetName() const;

        void AddProcess(TProcess* pProcess);
        TProcess* GetProcess(const std::string& processName);
        
        void AddContext(IContext* pCtx);
        void RemoveContext(IContext* pCtx);

        bool Work();

    protected:

    private:
        void OnStopProcess(TProcess* pProcess, IContext* pCtx);
        void OnFinishProcess(TProcess* pProcess, TZone* pZone, IContext* pCtx);
    };
}
