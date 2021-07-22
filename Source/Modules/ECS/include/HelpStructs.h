/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

namespace nsECSFramework
{
    template<class T>
    struct ptr_less
    {
        bool operator()(const T& pLHS, const T& pRHS) const
        {
            return *pLHS < *pRHS;
        }
    };
    template<class T>
    struct component_ptr_less
    {
        bool operator()(const T& lhs, const T& rhs) const
        {
            auto pL = (const IComponent*) lhs;
            auto pR = (const IComponent*) rhs;
            return pL->IsLess(pR);
        }
    };
    // usage: std::map<T*,second,ptr_less<T*>> mMap;
}