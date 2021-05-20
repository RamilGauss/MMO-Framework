/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SimpleEnum.h"

using namespace nsSimpleEnum;

bool X::operator == (const X& other) const
{
    auto isSimpleEqual = IsSimpleEqual(other);
    auto isContainerEqual = IsContainerEqual(other);

    return isSimpleEqual && isContainerEqual;
}

void X::Fill()
{
    a0 = A0::_1;
    a1 = A1::_1;
    e0 = X::E0::_1;
    e1 = X::E1::_1;

    a0_l = {a0};
    a1_l = {a1};
    e0_l = {e0};
    e1_l = {e1};

    a0_m = {{42, a0}};
    a1_m = {{42, a1}};
    e0_m = {{42, e0}};
    e1_m = {{42, e1}};

    a0_lll = {{{a0}}};
}

bool X::IsSimpleEqual(const X& other) const
{
    return a0 == other.a0 &&
        a1 == other.a1 &&
        e0 == other.e0 &&
        e1 == other.e1;
}

bool X::IsContainerEqual(const X& other) const
{
    return
        a0_l == other.a0_l &&
        a1_l == other.a1_l &&
        e0_l == other.e0_l &&
        e1_l == other.e1_l &&

        a0_m == other.a0_m &&
        a1_m == other.a1_m &&
        e0_m == other.e0_m &&
        e1_m == other.e1_m &&
        a0_lll == other.a0_lll;
}



