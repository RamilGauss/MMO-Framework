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

namespace nsBase::nsZones
{
    class TZone;
    struct IContext;
    class TProcess;

    class DllExport TContextZone
    {
        IContext* mCtx = nullptr;
        TZone* mZone = nullptr;

    public:
        TContextZone(IContext* pCtx, TZone* pZone);

        bool StartProcess(const std::string& processName);
    };
}
