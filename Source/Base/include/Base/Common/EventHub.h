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
#include <list>
#include <string>
#include <source_location>

#include "Base/Common/DataExchange2Thread.h"
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

    class DllExport TEventHub
    {
    protected:
        using TStringList = TDataExchange2Thread<TEventInfo>;
        using TStringListPtr = std::shared_ptr<TStringList>;

        std::array<TStringListPtr, 1024> mEventPipes;
        std::array<std::source_location, 1024> mSrcLocations;

        TThreadIndexator* mThreadIndexator = nullptr;

        std::function<std::string()> mTimerFunction = ht_GetTimeStr;

        int mRegisterCount = 0;

        std::vector<int> mDstOffsetInEvents;

        std::vector<TEventInfo*> mEvents;
    public:
        TEventHub(TThreadIndexator* threadIndexator);

        void SetupTimer(std::function<std::string()> timerFunction);
        void SetSourceLocation(std::source_location&& loc, int index = 0);

        // may call AddXXX in many (different) threads
        template <typename ... Args>
        void AddInfoEvent(std::string&& source, const std::string& format, Args ... args);

        template <typename ... Args>
        void AddWarningEvent(std::string&& source, const std::string& format, Args ... args);

        template <typename ... Args>
        void AddErrorEvent(std::string&& source, const std::string& format, Args ... args);
        
        // might call in only one thread
        int RegisterDestination();
        void TakeEvents(int dstId, std::list<TEventInfo>& events);
    private:
        template <typename ... Args>
        void AddEvent(std::string&& source, std::string&& level, const std::string& format, Args ... args);

        const std::source_location& GetSourceLocation(int index);
        const std::source_location& GetSourceLocationForThisThread();
        
        void RefreshEvents();
        int CalculateMinOffset();

        TStringListPtr GetPipForThisThread();
    };
    //------------------------------------------------------------------------------------------------
    template <typename ... Args>
    void TEventHub::AddEvent(std::string&& source, std::string&& level, const std::string& format, Args ... args)
    {
        auto& loc = GetSourceLocationForThisThread();

        auto message = std::vformat(format, std::make_format_args(args...));

        TEventInfo* pEventInfo = new TEventInfo();

        pEventInfo->time = std::move(mTimerFunction());
        pEventInfo->message = std::move(message);
        pEventInfo->source = std::move(source);
        pEventInfo->level = std::move(level);
        pEventInfo->fileLocation = std::move(std::format("{}:{}:{}", loc.file_name(), loc.line(), loc.column()));

        GetPipForThisThread()->Add(pEventInfo);
    }
    //------------------------------------------------------------------------------------------------
    template <typename ... Args>
    void TEventHub::AddInfoEvent(std::string&& source, const std::string& format, Args ... args)
    {
        AddEvent(std::move(source), "Info", format, args...);
    }
    //------------------------------------------------------------------------------------------------
    template <typename ... Args>
    void TEventHub::AddWarningEvent(std::string&& source, const std::string& format, Args ... args)
    {
        AddEvent(std::move(source), "Warning", format, args...);
    }
    //------------------------------------------------------------------------------------------------
    template <typename ... Args>
    void TEventHub::AddErrorEvent(std::string&& source, const std::string& format, Args ... args)
    {
        AddEvent(std::move(source), "Error", format, args...);
    }
    //------------------------------------------------------------------------------------------------
}
