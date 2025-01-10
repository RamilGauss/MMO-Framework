/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/SaveToFile.h"
#include "Base/Common/TypeDef.h"

#include "TimeSliceEngine/ProjectConfig.h"

namespace nsTornadoEngine
{
    class DllExport TLogDumper
    {
        TLoggerConfig mLoggerConfig;

        unsigned int mLastTimeDump = 0;

        nsBase::nsCommon::TSaveToFile mFile;

    public:
        TLogDumper(const TLoggerConfig& loggerConfig);

        void Work();
    };
}
