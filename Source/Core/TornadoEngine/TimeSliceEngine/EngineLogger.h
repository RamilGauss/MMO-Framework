/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <string>

#include "TypeDef.h"
#include "Logger.h"

namespace nsTornadoEngine
{
    class DllExport TEngineLogger
    {
    public:
        static const std::string NAME;

        template<typename ... Args>
        void Log(const char* format, Args && ... args)
        {
            LogEvent();

            GetLogger(TEngineLogger::NAME)->WriteF_time(format, std::forward<Args>(args)...);
        }
    protected:
        virtual void LogEvent(const std::string& str) {}
    };
}