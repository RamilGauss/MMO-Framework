/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <iostream>

#include <readerwriterqueue/readerwriterqueue.h>
#include <boost/lockfree/spsc_queue.hpp>

#include "LockFreeFifo.h"
#include "DataExchange2Thread.h"
#include "HiTimer.h"

const uint32_t IN_COUNT = 512 * 1024 * 1024;

struct TTransform
{
    //double m[16];
    uint32_t x[1024] = { 0 };
};

uint8_t buffer[1024 * 1024];

#define METHOD_3

#if defined(METHOD_0)
TDataExchange2Thread<TTransform> pipeline;
#elif defined(METHOD_1)
moodycamel::ReaderWriterQueue<TTransform> pipeline(1024 * 1024);       // Reserve space for at least 100 elements up front
#elif defined(METHOD_2)
nsBase::TLockFreeFifo pipeline(1024 * 1024);
#elif defined(METHOD_3)
boost::lockfree::spsc_queue<TTransform> pipeline(1024 * 1024);
#endif


std::vector<TTransform> g_Objects;

std::vector<TTransform> g_GraphicObjects;

struct TReader
{
    uint64_t operator ()()
    {
        uint64_t cnt = 0;
#if defined(METHOD_0)
        auto pFirst = pipeline.GetFirst();
        while (pFirst) {
            g_GraphicObjects[0] = *(pFirst)[0];

            pipeline.RemoveFirst();
            pFirst = pipeline.GetFirst();

            cnt += sizeof(TTransform);
        }
#elif defined(METHOD_1)
        while (pipeline.try_dequeue(g_GraphicObjects[0])) {
            cnt += sizeof(TTransform);
        }
#elif defined(METHOD_2)
        auto busySize = pipeline.GetBusySize();
        if (busySize == 0) {
            return 0;
        }
        pipeline.Dequeue(&buffer[0], busySize);
        cnt = busySize;
#elif defined(METHOD_3)
        while (pipeline.pop(g_GraphicObjects[0])) {
            cnt += sizeof(TTransform);
        }
#endif
        return cnt;
    }
};

struct TWriter
{
    uint64_t operator ()()
    {
        uint64_t cnt = 0;
#if defined(METHOD_0)
        for (int i = 0; i < g_Objects.size(); i++) {
            pipeline.Add(&g_Objects[i]);
        }
#elif defined(METHOD_1)
        for (int i = 0; i < g_Objects.size(); i++) {
            while (!pipeline.try_enqueue(g_Objects[i])) {
            }
        }
#elif defined(METHOD_2)
        while (pipeline.GetFreeSize() < g_Objects.size() * sizeof(TTransform));
        pipeline.Enqueue(g_Objects.data(), g_Objects.size());

#elif defined(METHOD_3)
        for (int i = 0; i < g_Objects.size(); i++) {
            while (!pipeline.push(g_Objects[i])) {
            }
        }
#endif
        cnt += g_Objects.size() * sizeof(TTransform);
        return cnt;
    }
};

template <typename Functor>
void ThreadFunc(const std::string& name)
{
    uint64_t bytes = 0;
    Functor func;

    unsigned int cnt = 0;

    auto start = ht_GetMSCount();
    unsigned int delta = 0;

    while (true) {

        bytes += func();

        cnt++;

        if (cnt % 10000 == 0) {
            delta = ht_GetMSCount() - start;
        }

        if (delta > 1000) {// 5 s
            float dt = (delta * 1000000.0f) / cnt;
            float speed = (bytes * 0.001) / delta;
            printf("%s: %f, %f MB/s\n", name.c_str(), dt, speed);

            delta = 0;
            cnt = 0;
            bytes = 0;

            start = ht_GetMSCount();
        }
    }
}

void Send()
{
    for (uint32_t i = 0; i < IN_COUNT; i++) {
        TTransform transform;
        transform.x[0] = i;
#if defined(METHOD_0)
        auto p = new TTransform();
        p->x[0] = i;
        pipeline.Add(p);
#elif defined(METHOD_1)
        while (!pipeline.try_enqueue(transform)) {

        }
#elif defined(METHOD_2)
        uint32_t freeSize = 0;
        while (freeSize < sizeof(TTransform)) {
            freeSize = pipeline.GetFreeSize();
        }

        pipeline.Enqueue(&transform);
#elif defined(METHOD_3)
        while (!pipeline.push(transform)) {
        }
#endif
    }
}

void Recv()
{
    uint32_t i = 0;
    TTransform outValue;
    outValue.x[0] = 0;

    while (true) {

#if defined(METHOD_0)
        auto pFirst = pipeline.GetFirst();
        while (!pFirst) {
            pFirst = pipeline.GetFirst();
        }

        outValue = *(pFirst)[0];
        pipeline.RemoveFirst();

#elif defined(METHOD_1)
        while (!pipeline.try_dequeue(outValue)) {
        }
#elif defined(METHOD_2)
        uint32_t busySize = 0;
        while (busySize == 0) {
            busySize = pipeline.GetBusySize();
        }
        pipeline.Dequeue(&outValue); 
#elif defined(METHOD_3)
        while (!pipeline.pop(outValue)) {
        }
#endif
       
        if (outValue.x[0] != i) {
            printf("dismatch %d %d\n", i, outValue.x[0]);
        }
        i++;

        if (i == IN_COUNT) {
            return;
        }
    }
}

//#define CORRECT_TEST

int main(int argc, char** argv)
{
    std::string methodName =
#if defined(METHOD_0)
        "TDataExchange2Thread";
#elif defined(METHOD_1)
        "moodycamel::ReaderWriterQueue";
#elif defined(METHOD_2)
        "nsBase::TLockFreeFifo";
#elif defined(METHOD_3)
        "boost::lockfree::spsc_queue";
#endif
    printf("%s\n", methodName.c_str());


#if defined(METHOD_0)
    //TCallBackRegistrator1<void*> cbDelete;
    //pipeline.SetCB_DeleteData(&cbDelete);
#endif


#ifdef CORRECT_TEST
    std::thread consumer(Send);

    using namespace std::chrono_literals;
    std::this_thread::sleep_for(100ms);

    auto start = ht_GetMSCount();

    std::thread producer(Recv);

    producer.join();
    consumer.join();

    auto dt = ht_GetMSCount() - start;
    auto speed = (IN_COUNT * sizeof(TTransform) * 1.0) / dt;
    printf("%f MB/s, dt=%f s\n", speed / 1000.0, dt / 1000.0);
#else

   
    g_Objects.resize(1);
    g_GraphicObjects.resize(1024);
    
    std::thread consumer(ThreadFunc<TReader>, "R");
    
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(100ms);
    
    std::thread producer(ThreadFunc<TWriter>, "W");
    
    producer.join();
#endif
    return 0;
}

/*
TDataExchange2Thread - is very slow and ugly, is not using in benchmarks.

 
Release benchmarks

            Read thread (frame time, ns) / Write thread (frame time, ns) / (S, MB/s)
packet size ->      4         4k
moody          360/8/466   800/240/17000 
nsBase         65/35/113   1000/250/16000
boost          14/285/277   87/466/8700


speed MB/s
packet size ->  4         4k
moody          1516      13000
nsBase         99        12205
boost          448       8215


moodycamel::ReaderWriterQueue is best solution.

*/

