/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <list>
#include <map>

namespace nsSimpleEnum
{
    enum A0
    {
        _0 = 0,
        _1
    };

    enum class A1
    {
        _0 = 0,
        _1
    };

    struct X
    {
        enum E0
        {
            _0 = 0,
            _1
        };

        enum class E1
        {
            _0 = 0,
            _1
        };

        nsSimpleEnum::A0 a0 = A0::_0;
        nsSimpleEnum::A1 a1 = A1::_0;

        E0 e0 = E0::_0;
        E1 e1 = E1::_0;

        std::list<A0> a0_l;
        std::list<A1> a1_l;
        std::list<E0> e0_l;
        std::list<E1> e1_l;

        std::map<int, A0> a0_m;
        std::map<int, A1> a1_m;
        std::map<int, E0> e0_m;
        std::map<int, E1> e1_m;

        std::list<std::list<std::list<A0>>> a0_lll;

        void Fill();

        bool operator == (const X& other) const;

        bool IsSimpleEqual(const X& other) const;
        bool IsContainerEqual(const X& other) const;
    };
}