/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "PageInfo.h"

namespace nsWinApiHelper
{
    TPageInfo::TPageInfo()
    {
    }
    //------------------------------------------------------------------------------------------------------
    TPageInfo::TPageInfo(uint8_t* baseAddress, size_t size, bool doCopyToBuffer)
    {
        mBaseAddress = baseAddress;
        mSize = size;

        mIsCopyToBuffer = doCopyToBuffer;

        if (doCopyToBuffer) {
            mBuffer.SetData((char*)baseAddress, size);
        }
    }
    //------------------------------------------------------------------------------------------------------
    void TPageInfo::Reset()
    {
        mShift = 0;
    }
    //------------------------------------------------------------------------------------------------------
    void TPageInfo::IncrementShift(size_t shift)
    {
        mShift += shift;
    }
    //------------------------------------------------------------------------------------------------------
    uint8_t* TPageInfo::GetCurrentAddress() const
    {
        return mBaseAddress + mShift;
    }
    //------------------------------------------------------------------------------------------------------
    uint8_t* TPageInfo::GetCurrentBuffer() const
    {
        if (mIsCopyToBuffer) {
            return (uint8_t*)mBuffer.GetPtr() + mShift;
        }

        return GetCurrentAddress();
    }
    //------------------------------------------------------------------------------------------------------
    size_t TPageInfo::GetRemain() const
    {
        return mSize - mShift;
    }
    //------------------------------------------------------------------------------------------------------
}