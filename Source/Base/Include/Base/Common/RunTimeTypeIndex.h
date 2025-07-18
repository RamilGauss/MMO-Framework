/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <algorithm>
#include <assert.h>
#include <atomic>
#include <cstddef>
#include <functional>
#include <list>
#include <map>
#include <mutex>
#include <set>
#include <type_traits>
#include <typeinfo>
#include <typeindex>

#include "Base/Common/TypeDef.h"

// The idea has been taken from https://github.com/skypjack/entt/blob/master/src/entt/core/family.hpp
// Remove static from type(). Static values are the evil! In different Dll different id exists.

// use: SingletonManager()->Get<TRunTimeTypeIndex<ClassSpace>>()
// ClassSpace - space for unique identity

// Thread-safe

template<typename...>
class DllExport TRunTimeTypeIndex
{
protected:
    friend class TSingletonManager;
    TRunTimeTypeIndex() {}
public:
    using TypeCounter = int;
    using AtomicTypeCounter = std::atomic<TypeCounter>;
private:
    std::mutex mMutex;
    AtomicTypeCounter mCounter = 0;

    struct MultiType
    {
        std::set<std::type_index> types;

        bool operator <(const MultiType& rhs) const
        {
            return types < rhs.types;
        }
    };

    std::map<MultiType, TypeCounter> mTypeCounters;

    template <typename T>
    void Fill(MultiType& multiType)
    {
        multiType.types.insert(std::type_index(typeid(T)));
    }

    template <typename T0, typename T1, typename ... Args>
    void Fill(MultiType& multiType)
    {
        Fill<T0>(multiType);
        Fill<T1, Args...>(multiType);
    }
public:
    template <typename T, typename ... Args>
    TypeCounter Type()
    {
        static AtomicTypeCounter innerCounter = -1;
        if (innerCounter == -1) {
            MultiType multiType;
            Fill<T, Args...>(multiType);

            std::lock_guard<std::mutex> guard(mMutex);

            auto fit = mTypeCounters.find(multiType);
            if (mTypeCounters.end() == fit) {
                mTypeCounters[multiType] = mCounter++;
            }
            innerCounter = mTypeCounters[multiType];

        }
        return innerCounter;
    }
};
