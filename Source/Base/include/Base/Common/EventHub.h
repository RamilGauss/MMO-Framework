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

#include "Base/Common/DataExchange2Thread.h"
#include "Base/Common/HiTimer.h"
#include "Base/Common/TypeDef.h"

namespace nsBase::nsCommon
{
    class TThreadIndexator;
    class DllExport TEventHub
    {
    protected:
        using TStringList = TDataExchange2Thread<std::string>;
        using TStringListPtr = std::shared_ptr<TStringList>;

        std::array<TStringListPtr, 1024> mEventPipes;
        std::array<std::source_location, 1024> mSrcLocations;

        TThreadIndexator* mThreadIndexator = nullptr;
    public:
        TEventHub();

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

        TStringListPtr GetPipForThisThread();
    };
    //------------------------------------------------------------------------------------------------
    template <typename ... Args>
    void TEventHub::AddEvent(const std::string& level, const std::string& format, Args ... args)
    {
        auto& loc = GetSourceLocationForThisThread();

        auto message = std::vformat(format, std::make_format_args(args...));

        auto sourceLocationStr = std::format("{} - {}, {}", 
            loc.file_name(), loc.line(), loc.function_name());

        auto timeStr = ht_GetTimeStr();
        auto pEvent = new std::string();
        *pEvent = std::move(std::format("{}|{}: {} ({})", timeStr, level, message, sourceLocationStr));

        GetPipForThisThread()->Add(pEvent);
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
