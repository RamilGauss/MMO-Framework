/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once


#include <cstdint>

#include "Base/Common/TypeDef.h"

namespace nsBase::nsZones
{
    class DllExport TRank
    {
        uint32_t mRank = 0;
    public:
        void SetRank(uint32_t value);
        uint32_t GetRank() const;

        uint32_t GetNextRank() const;
    };
}
