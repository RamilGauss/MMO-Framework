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

#include "Base/Common/TypeDef.h"

namespace nsBase::nsCommon
{
    class DllExport TEventHub
    {
    protected:
        std::mutex mMutex;
        std::vector<std::string> mEvents;
    public:
        void AddEvent(const std::string& level, const std::string& message);
        void AddInfoEvent(const std::string& message);
        void AddWarningEvent(const std::string& message);
        void AddErrorEvent(const std::string& message);
       
        void TakeEvents(std::vector<std::string>& events);
    };

    extern DllExport TEventHub* GetEventHub();
}
