/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "ContainerTypes.h"

namespace nsWinApiHelper
{
    class DllExport TPageInfo
    {
        uint8_t* mBaseAddress = nullptr;

        size_t mSize = 0;

        TContainer mBuffer;

        size_t mShift = 0;

        bool mIsCopyToBuffer = true;

    public:
        TPageInfo();

        TPageInfo(uint8_t* baseAddress, size_t size, bool doCopyToBuffer = true);

        void Reset();

        void IncrementShift(size_t shift = 1);
        
        uint8_t* GetCurrentAddress() const;
        uint8_t* GetCurrentBuffer() const;

        size_t GetRemain() const;
    };
}