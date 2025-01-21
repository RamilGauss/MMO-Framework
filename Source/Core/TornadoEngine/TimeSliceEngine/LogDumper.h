/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/EventHub.h"
#include "Base/Common/SaveToFile.h"
#include "Base/Common/TypeDef.h"

#include "TimeSliceEngine/ProjectConfig.h"

namespace nsTornadoEngine
{
    class DllExport TLogDumper
    {
        nsBase::nsCommon::TEventHub* mEventHub = nullptr;

        TLoggerConfig mLoggerConfig;

        unsigned int mLastTimeDump = 0;

        nsBase::nsCommon::TSaveToFile mFile;

        int mRegisterDstId = 0;

        std::string mSource;

    public:
        TLogDumper(std::string&& source, nsBase::nsCommon::TEventHub* eventHub, const TLoggerConfig& loggerConfig);

        void TryFlushToFile();

        void FlushToFile();
    };
}
