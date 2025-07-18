/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

namespace nsMMOEngine
{
    struct DllExport TDescOpen
    {
        unsigned short port;
        unsigned char  subNet;
        TDescOpen();
        TDescOpen(unsigned short p, unsigned char  sN = 0);
    };
}
