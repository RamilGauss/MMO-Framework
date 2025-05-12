/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <array>
#include <format>
#include <functional>
#include <vector>
#include <string>
#include <source_location>

#include "Base/Common/MPMCQueue.h"
#include "Base/Common/HiTimer.h"
#include "Base/Common/TypeDef.h"

namespace nsBase::nsCommon
{
    class TThreadIndexator;

    struct TEventInfo
    {
        std::string time;
        std::string level;
        std::string message;
        std::string fileLocation;
        std::string source;

        bool operator == (const TEventInfo& other) const
        {
            return (time == other.time) &&
                (level == other.level) &&
                (message == other.message) &&
                (fileLocation == other.fileLocation) &&
                (source == other.source);
        }
    };

    using PEventInfo = std::shared_ptr<TEventInfo>;

    class DllExport TEventHub
    {
    protected:
        using TEventInfoQueue = rigtorp::MPMCQueue<PEventInfo>;
        using PEventInfoQueue = std::shared_ptr<TEventInfoQueue>;

        std::array<PEventInfoQueue, 1024> mEventPipes;
        std::array<std::source_location, 1024> mSrcLocations;
        std::array<std::string, 1024> mSources;

        std::function<std::string()> mTimerFunction = ht_GetTimeStr;

        std::atomic_int mRegisterCount = 0;
    public:
        TEventHub();

        void SetupTimer(std::function<std::string()> timerFunction);
        void SetSourceLocation(std::source_location&& loc, int index = 0);
        void SetSource(std::string&& source, int index = 0);

        // may call AddXXX in many (different) threads
        template <typename ... Args>
        void AddInfoEvent(const std::string& format, Args ... args);

        template <typename ... Args>
        void AddWarningEvent(const std::string& format, Args ... args);

        template <typename ... Args>
        void AddErrorEvent(const std::string& format, Args ... args);
        
        // might call in only one thread
        int RegisterDestination();
        std::vector<PEventInfo> TakeEvents(int dstId);
    private:
        template <typename ... Args>
        void AddEvent(std::string&& level, const std::string& format, Args ... args);

        void AddEvent(PEventInfo event);

        const std::source_location& GetSourceLocationForThisThread();
        const std::string& GetSourceForThisThread();
    };
    //------------------------------------------------------------------------------------------------
    template <typename ... Args>
    void TEventHub::AddEvent(std::string&& level, const std::string& format, Args ... args)
    {
        std::string source = GetSourceForThisThread();
        auto& loc = GetSourceLocationForThisThread();

        auto message = std::vformat(format, std::make_format_args(args...));

        auto pEventInfo = std::make_shared<TEventInfo>();

        pEventInfo->time = std::move(mTimerFunction());
        pEventInfo->message = std::move(message);
        pEventInfo->source = std::move(source);
        pEventInfo->level = std::move(level);
        pEventInfo->fileLocation = std::move(std::format("{}:{}:{}", loc.file_name(), loc.line(), loc.column()));

        AddEvent(pEventInfo);
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
