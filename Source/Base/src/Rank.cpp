/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "Base/Zones/Rank.h"

namespace nsBase::nsZones
{
    void TRank::SetRank(uint32_t value)
    {
        mRank = value;
    }
    //-------------------------------------------------------------------------
    uint32_t TRank::GetRank() const
    {
        return mRank;
    }
    //-------------------------------------------------------------------------
    uint32_t TRank::GetNextRank() const
    {
        return mRank + 1;
    }
    //-------------------------------------------------------------------------
}
