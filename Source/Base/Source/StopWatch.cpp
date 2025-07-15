/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/StopWatch.h"
#include "Base/Common/HiTimer.h"

namespace nsBase
{
    void TStopWatch::Start()
    {
        mBegin = ht_GetUSCount();
        mStamp = mBegin;
    }
    //------------------------------------------------------------------------------------------
    uint64_t TStopWatch::Stamp(std::string name)
    {
        if (name.empty()) {
            name = "stamp_" + std::to_string(mStampCounter);
        }

        mStampCounter++;

        auto now = ht_GetUSCount();
        mDuration = now - mBegin;
        auto delta = now - mStamp;

        mStamp = now;

        mDeltas.push_back({ delta, name });

        return delta;
    }
    //------------------------------------------------------------------------------------------
    std::string TStopWatch::ToString(bool toMs) const
    {
        std::string str;

        for (auto delta : mDeltas) {

            if (toMs) {
                delta.first /= 1000;
            }
            str += delta.second + ": " + std::to_string(delta.first) + "\n";
        }

        uint64_t duration = mDuration;
        if (toMs) {
            duration /= 1000;
        }

        str += "duration = " + std::to_string(duration) + "\n";

        return str;
    }
    //------------------------------------------------------------------------------------------
}
