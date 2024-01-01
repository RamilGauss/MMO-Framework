/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#pragma pack(push, 1)

namespace nsMMOEngine
{
    struct DllExport TDescRequestConnectForRecipient
    {
        unsigned int key = 0;
        unsigned int random_num = 0;
        unsigned int sessionID = 0;
        void Generate();
    };
}

#pragma pack(pop)
