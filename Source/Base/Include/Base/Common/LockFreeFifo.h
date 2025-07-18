/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <cstdint>
#include <atomic>

#include "Base/Common/TypeDef.h"

namespace nsBase
{
    class DllExport TLockFreeFifo
    {
        uint8_t* mData = nullptr;
        uint32_t mSize = 0;

        //std::atomic_uint mBegin = 0;
        //std::atomic_uint mEnd = 0;
        uint32_t mBegin = 0;
        uint32_t mEnd = 0;

    public:
        TLockFreeFifo(uint32_t size);

        virtual ~TLockFreeFifo();

        uint32_t GetFreeSize() const;// Producer
        uint32_t GetBusySize() const;// Consumer

        template <typename T>
        void Enqueue(T* p, uint32_t count = 1)// Producer
        {
            Enqueue((uint8_t*)p, count * sizeof(T));
        }

        void Enqueue(uint8_t* p, uint32_t size);// Producer

        template <typename T>
        void Dequeue(T* p, uint32_t count = 1)// Consumer
        {
            Dequeue((uint8_t*)p, count * sizeof(T));
        }

        void Dequeue(uint8_t* p, uint32_t size);// Consumer
    };
}