/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

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

    struct ComponentPtrLess
    {
        bool operator()(const IComponent* lhs, const IComponent* rhs) const
        {
            return lhs->IsLess(rhs);
        }
    };
    // usage: std::map<T*, second, ptr_less<T*>> mMap;

    struct ComponentPtrHasher
    {
        size_t operator()(const IComponent* p) const
        {
            return p->GetHash();
        }
    };

    struct ComponentPtrEqual
    {
        bool operator()(const IComponent* lhs, const IComponent* rhs) const
        {
            return lhs->IsEqual(rhs);
        }
    };
    // usage: std::map<IComponent*, second, ComponentPtrHasher, ComponentPtrEqual> mMap;
}