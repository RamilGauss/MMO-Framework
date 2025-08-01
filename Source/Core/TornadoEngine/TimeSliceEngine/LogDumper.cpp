/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Common/HiTimer.h"

#include "TornadoEngine/TimeSliceEngine/LogDumper.h"
#include "TornadoEngine/Modules/Common/Modules.h"

namespace nsTornadoEngine
{
    TLogDumper::TLogDumper(std::string&& source, nsBase::nsCommon::TEventHub* eventHub, const TLoggerConfig& loggerConfig)
    {
        mSource = std::move(source);
        mEventHub = eventHub;
        mRegisterDstId = mEventHub->RegisterDestination();
        mLoggerConfig = loggerConfig;
        if (mLoggerConfig.enabled) {
            mFile.ReOpen((char*)mLoggerConfig.logFileName.c_str());
            mLastTimeDump = ht_GetMSCount();
        }
    }
    //-------------------------------------------------------------------------------------
    void TLogDumper::TryFlushToFile()
    {
        if (mLoggerConfig.enabled) {
            auto now = ht_GetMSCount();
            if (now - mLastTimeDump < mLoggerConfig.intervalTimeMs) {
                return;
            }
            mLastTimeDump = now;

            FlushToFile();
        }
    }
    //-------------------------------------------------------------------------------------
    void TLogDumper::FlushToFile()
    {
        auto events = mEventHub->TakeEvents(mRegisterDstId);

        for (auto&& event : events) {
            if (event->source == mSource) {
                auto str = std::format("{} [{}|{}]:{} -> {}", 
                    event->time, event->level, event->source, event->message, event->fileLocation);
                mFile.WriteF("%s\n", str.c_str());
            }
        }
    }
    //-------------------------------------------------------------------------------------
}
