/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "IModule.h"
#include "LogicSlotManager.h"
#include "DstEvent.h"

namespace nsTornadoEngine
{
    class DllExport TLogicWrapperModule : public IModule, public TDstEvent
    {
        TLogicSlotManager mBeginLogicSlotManager;
        TLogicSlotManager mEndLogicSlotManager;
    public:
        void Work() override final;

        TLogicSlotManager* GetBeginLogicSlotManager();
        TLogicSlotManager* GetEndLogicSlotManager();
    protected:
        virtual void ModuleWork() = 0;
    };
}