/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <format>
#include <string>
#include <list>
#include <source_location>
#include <array>

#include "Base/Common/TypeDef.h"
#include "Base/Common/HiTimer.h"

namespace nsBase::nsCommon
{
    class DllExport TEventHub
    {
    protected:
        std::list<std::string> mEvents;

        std::array<std::source_location, 1024> mSrcLocations;

    public:
        template <typename ... Args>
        void AddEvent(const std::string& level, const std::string& format, Args ... args);

        template <typename ... Args>
        void AddInfoEvent(const std::string& format, Args ... args);

        template <typename ... Args>
        void AddWarningEvent(const std::string& format, Args ... args);

        template <typename ... Args>
        void AddErrorEvent(const std::string& format, Args ... args);
        
        void TakeEvents(std::list<std::string>& events);

    protected:
        const std::source_location& GetSourceLocation(int index);
    private:
        const std::source_location& GetSourceLocationForThisThread();
    };
    //------------------------------------------------------------------------------------------------
    template <typename ... Args>
    void TEventHub::AddEvent(const std::string& level, const std::string& format, Args ... args)
    {
        auto& loc = GetSourceLocationForThisThread();

        auto message = std::vformat(format, std::make_format_args(args...));

        auto source_location_str = std::format("{} - {}, {}", 
            loc.file_name(), loc.line(), loc.function_name());

        auto str_time = ht_GetTimeStr();
        auto event = std::format("{}|{}: {} ({})", str_time, level, message, source_location_str);

        mEvents.push_back(event);
    }
    //------------------------------------------------------------------------------------------------
    template <typename ... Args>
    void TEventHub::AddInfoEvent(const std::string& format, Args ... args)
    {
        AddEvent("Info", format, args...);
    }
    //------------------------------------------------------------------------------------------------
    template <typename ... Args>
    void TEventHub::AddWarningEvent(const std::string& format, Args ... args)
    {
        AddEvent("Warning", format, args...);
    }
    //------------------------------------------------------------------------------------------------
    template <typename ... Args>
    void TEventHub::AddErrorEvent(const std::string& format, Args ... args)
    {
        AddEvent("Error", format, args...);
    }
    //------------------------------------------------------------------------------------------------
}
