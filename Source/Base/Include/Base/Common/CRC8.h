/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

class DllExport TCRC8
{
public:
    TCRC8();
    ~TCRC8();

    void Calc(void* pIn, int sizeIn, unsigned char& crc);
};
