/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Modules/Common/LogicWrapperModule.h"
#include "Modules/Common/FeatureManager.h"

namespace nsTornadoEngine
{
    class DllExport ILogicModule : public TLogicWrapperModule
    {
    public:
        virtual TFeatureManager* GetWorkSlots() = 0;
        virtual void SetWorkSlots(TFeatureManager* pLSM) = 0;
    };
}