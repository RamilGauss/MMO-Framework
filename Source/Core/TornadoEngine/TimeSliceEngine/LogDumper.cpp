/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "TimeSliceEngine/LogDumper.h"

#include "Base/Common/HiTimer.h"

#include "Modules/Common/Modules.h"

namespace nsTornadoEngine
{
    TLogDumper::TLogDumper(const TLoggerConfig& loggerConfig)
    {
        mLoggerConfig = loggerConfig;
        if (mLoggerConfig.enabled) {
            mFile.ReOpen((char*)mLoggerConfig.logFileName.c_str());
            mLastTimeDump = ht_GetMSCount();
        }
    }
    //-------------------------------------------------------------------------------------
    void TLogDumper::Work()
    {
        if (mLoggerConfig.enabled) {
            auto now = ht_GetMSCount();
            if (now - mLastTimeDump < mLoggerConfig.intervalTimeMs) {
                return;
            }
            mLastTimeDump = now;

            std::list<std::string> events;
            Modules()->Log()->TakeEvents(events);
            
            for (auto&& event : events) {
                mFile.WriteF("%s\n", event.c_str());
            }
        }
    }
    //-------------------------------------------------------------------------------------
}
