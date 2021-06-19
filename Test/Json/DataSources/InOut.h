/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

namespace nsInOut
{
#pragma FIRST
#pragma SECOND
    struct A
    {
        int x = 42;
    };
#pragma SECOND
    struct B
    {
        int x = 42;

        A a;
    };
}