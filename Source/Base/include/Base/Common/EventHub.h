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

#include "Base/Common/TypeDef.h"
#include "Base/Common/HiTimer.h"

namespace nsBase::nsCommon
{
    class DllExport TEventHub
    {
    protected:
        std::list<std::string> mEvents;

        std::source_location mCurrentSrcLocation;
    public:
        template <typename ... Args>
        void AddEvent(const std::string& level, const char* format, Args ... args);

        template <typename ... Args>
        void AddInfoEvent(const char* format, Args ... args);

        template <typename ... Args>
        void AddWarningEvent(const char* format, Args ... args);

        template <typename ... Args>
        void AddErrorEvent(const char* format, Args ... args);
        
        void TakeEvents(std::list<std::string>& events);

    protected:
        void SetSourceLocation(const std::source_location& loc);
    };
    //------------------------------------------------------------------------------------------------
    template <typename ... Args>
    void TEventHub::AddEvent(const std::string& level, const char* format, Args ... args)
    {
        auto message = std::format(format, std::make_format_args(args...));

        auto source_location_str = std::format("{}, [{}, {}], {}", 
            mCurrentSrcLocation.file_name(), mCurrentSrcLocation.line(), 
            mCurrentSrcLocation.column(), mCurrentSrcLocation.function_name());

        auto str_time = ht_GetTimeStr();
        auto event = std::format("{}|{}:{}({})", str_time, level, message, source_location_str);

        mEvents.push_back(event);
    }
    //------------------------------------------------------------------------------------------------
    template <typename ... Args>
    void TEventHub::AddInfoEvent(const char* format, Args ... args)
    {
        AddEvent("Info", format, args...);
    }
    //------------------------------------------------------------------------------------------------
    template <typename ... Args>
    void TEventHub::AddWarningEvent(const char* format, Args ... args)
    {
        AddEvent("Warning", format, args...);
    }
    //------------------------------------------------------------------------------------------------
    template <typename ... Args>
    void TEventHub::AddErrorEvent(const char* format, Args ... args)
    {
        AddEvent("Error", format, args...);
    }
    //------------------------------------------------------------------------------------------------

    extern DllExport TEventHub* GetEventHub(const std::source_location loc = std::source_location::current());
}
