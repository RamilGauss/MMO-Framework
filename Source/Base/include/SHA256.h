/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"
#include "ContainerTypes.h"

class DllExport TSHA256
{
    void* mContext; // контекст хэша

public:
    TSHA256();
    ~TSHA256();

    void Begin();
    void Calc(void* pIn, int sizeIn);
    void End(TContainer& result);

    void FastCalc(void* pIn, int sizeIn, TContainer& result);
};
