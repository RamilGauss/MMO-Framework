#pragma once

#include <thread>
#include <concurrentqueue.h>

#include "Config.h"
#include "Common.h"

namespace nsBenchmark::nsCases
{

nsCommon::BenchmarkInfo MoodyCamelQueue(int producerCount, int consumerCount)
{
    moodycamel::ConcurrentQueue<nsBenchmark::nsConfig::PEvent> queue(nsConfig::QUEUE_CAPACITY);
    auto pushFunc = [&queue](nsBenchmark::nsConfig::PEvent event) {
        queue.try_enqueue(event);
        };
    auto popFunc = [&queue]()-> bool {
        nsBenchmark::nsConfig::PEvent event;
        return queue.try_dequeue(event);
        };

    nsCommon::BenchmarkInfo info;
    info.name = "MoodyCamelQueue";
    info.producerCount = producerCount;
    info.consumerCount = consumerCount;
    nsCommon::ExecuteBenchmark(info,
        std::move(pushFunc), std::move(popFunc));

    return info;
}

}
