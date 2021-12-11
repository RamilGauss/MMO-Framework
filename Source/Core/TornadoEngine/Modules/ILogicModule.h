/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "LogicWrapperModule.h"
#include "LogicSlotManager.h"

namespace nsTornadoEngine
{
    class DllExport ILogicModule : public TLogicWrapperModule
    {
    public:
        virtual TLogicSlotManager* GetWorkSlots() = 0;
        virtual void SetWorkSlots(TLogicSlotManager* pLSM) = 0;
    };
}