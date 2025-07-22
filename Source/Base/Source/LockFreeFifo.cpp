/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <cstring>

#include "Base/Common/LockFreeFifo.h"

namespace nsBase
{
    TLockFreeFifo::TLockFreeFifo(uint32_t size)
    {
        mSize = size;

        mData = new uint8_t[mSize];
    }
    //---------------------------------------------------------------------------------
    TLockFreeFifo::~TLockFreeFifo()
    {
        delete[] mData;
    }
    //---------------------------------------------------------------------------------
    uint32_t TLockFreeFifo::GetFreeSize() const// Producer
    {
        std::atomic_thread_fence(std::memory_order_acquire);

        uint32_t beginCopy = mBegin;
        uint32_t endCopy = mEnd;

        if (beginCopy == endCopy) {
            return mSize - 1;
        }

        if (beginCopy > endCopy) {
            return beginCopy - endCopy - 1;
        }

        return mSize - endCopy + beginCopy - 1;
    }
    //---------------------------------------------------------------------------------
    uint32_t TLockFreeFifo::GetBusySize() const// Consumer
    {
        std::atomic_thread_fence(std::memory_order_acquire);

        uint32_t beginCopy = mBegin;
        uint32_t endCopy = mEnd;

        if (beginCopy == endCopy) {
            return 0;
        }

        if (beginCopy < endCopy) {
            return endCopy - beginCopy;
        }

        return mSize - beginCopy + endCopy;
    }
    //---------------------------------------------------------------------------------
    void TLockFreeFifo::Enqueue(uint8_t* p, uint32_t size)// Producer
    {
        uint32_t endCopy = mEnd;

        uint32_t remain = mSize - endCopy;

        if (remain > size) {
            std::memcpy(mData + mEnd, p, size);

            std::atomic_thread_fence(std::memory_order_release);

            mEnd = endCopy + size;
            return;
        }

        std::memcpy(mData + endCopy, p, remain);
        std::memcpy(mData, p + remain, size - remain);

        std::atomic_thread_fence(std::memory_order_release);

        mEnd = size - remain;
    }
    //---------------------------------------------------------------------------------
    void TLockFreeFifo::Dequeue(uint8_t* p, uint32_t size)// Consumer
    {
        uint32_t beginCopy = mBegin;

        uint32_t remain = mSize - beginCopy;

        if (remain > size) {
            std::memcpy(p, mData + beginCopy, size);

            std::atomic_thread_fence(std::memory_order_release);
            mBegin = beginCopy + size;
            return;
        }

        std::memcpy(p, mData + beginCopy, remain);
        std::memcpy(p + remain, mData, size - remain);

        std::atomic_thread_fence(std::memory_order_release);

        mBegin = size - remain;
    }
    //---------------------------------------------------------------------------------
}