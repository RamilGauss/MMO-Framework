#pragma once

/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

namespace nsTornadoEngine
{
    class DllExport TStopAccessor
    {
        bool mNeedStop = false;
    public:
        void SetStop() { mNeedStop = true; }
        bool IsNeedStop() const { return mNeedStop; };
    };
}