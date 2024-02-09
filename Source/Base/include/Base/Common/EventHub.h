/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <mutex>
#include <string>
#include <vector>
#include <source_location>

#include "Base/Common/TypeDef.h"

namespace nsBase::nsCommon
{
    class DllExport TEventHub
    {
    protected:
        std::mutex mMutex;
        std::vector<std::string> mEvents;
    public:
        void AddEvent(const std::string& level, const std::string& message, const std::source_location loc = std::source_location::current());
        void AddInfoEvent(const std::string& message, const std::source_location loc = std::source_location::current());
        void AddWarningEvent(const std::string& message, const std::source_location loc = std::source_location::current());
        void AddErrorEvent(const std::string& message, const std::source_location loc = std::source_location::current());
       
        void TakeEvents(std::vector<std::string>& events);
    };

    extern DllExport TEventHub* GetEventHub();
}
