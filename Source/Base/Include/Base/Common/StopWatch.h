/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <string>
#include <cstdint>

#include "Base/Common/TypeDef.h"

namespace nsBase
{
    class DllExport TStopWatch
    {
        uint64_t mBegin = 0;
        uint64_t mStamp = 0;

        uint64_t mDuration = 0;

        unsigned int mStampCounter = 0;

        std::list<std::pair<uint64_t, std::string>> mDeltas;
    public:
        void Start();
        uint64_t Stamp(std::string name = "");

        std::string ToString(bool toMs = false) const;
    };
}
