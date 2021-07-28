/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <set>

#include "DstModule.h"

namespace nsTornadoEngine
{
    class DllExport TModuleLogic : public TDstModule
    {
    public:
        void StartEvent() override;
        bool Work() override;
        void StopEvent() override;
    };
}