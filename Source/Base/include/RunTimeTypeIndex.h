/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <type_traits>
#include <cstddef>
#include <atomic>
#include <map>
#include <vector>
#include <set>
#include <list>
#include <functional>
#include <algorithm>
#include <assert.h>

#include "TypeDef.h"
#include "RemoveIthType.h"

// The idea has been taken from https://github.com/skypjack/entt/blob/master/src/entt/core/family.hpp
// Remove static from type(). Static values are the evil! In different Dll different id exists.

// use: SingletonManager()->Get<TRunTimeTypeIndex<ClassSpace>>()
// ClassSpace - space for unique identity
template<typename...>
class DllExport TRunTimeTypeIndex
{
public:
    typedef unsigned int TypeCounter;
    typedef std::atomic<TypeCounter> AtomicTypeCounter;
private:
    AtomicTypeCounter atc;

    template<typename...>
    const TypeCounter UniqueByType(AtomicTypeCounter& global)
    {
        static const TypeCounter value = global.fetch_add(1);
        return value;
    }

    template<typename... Type>
    const TypeCounter _type()
    {
        return UniqueByType<std::decay_t<Type>...>(atc);
    }

    template<typename T0, typename T1, typename T2>
    TypeCounter TypeLm3(TypeCounter t1, TypeCounter t2)
    {
        if (t1 < t2)
            return _type<T0, T1, T2>();
        return _type<T0, T2, T1>();
    }

    template<typename T0, typename T1, typename T2, typename T3>
    TypeCounter TypeLm4(TypeCounter t1, TypeCounter t2, TypeCounter t3)
    {
        auto minT = std::min(std::min(t1, t2), std::min(t2, t3));
        if (minT == t1) {
            if (t2 < t3) {
                return _type<T0, T1, T2, T3>();
            }
            return _type<T0, T1, T3, T2>();
        }
        if (minT == t2) {
            if (t1 < t3) {
                return _type<T0, T2, T1, T3>();
            }
            return _type<T0, T2, T3, T1>();
        }
        // 3
        if (t1 < t2) {
            return _type<T0, T3, T1, T2>();
        }
        return _type<T0, T3, T2, T1>();
    }

    struct TComplexSet
    {
        std::set<TypeCounter> tcSet;
        TypeCounter tc;

        bool operator == (const TComplexSet& other)
        {
            if (other.tcSet.size() != tcSet.size()) {
                return false;
            }
            for (auto& tc : tcSet) {
                if (other.tcSet.find(tc) == other.tcSet.end()) {
                    return false;
                }
            }
            return true;
        }
    };

    std::list<TComplexSet> mComplexSetList;

    template<typename T>
    void AddToSet(TComplexSet& complexSet)
    {
        auto t = _type<T>();
        complexSet.tcSet.insert(t);
    }

    template<typename T0, typename T1, typename ... Args>
    void AddToSet(TComplexSet& complexSet)
    {
        AddToSet<T0>(complexSet);
        AddToSet<T1, Args...>(complexSet);
    }

public:
    template<typename T>// faster
    TypeCounter type()
    {
        return _type<T>();
    }

    template<typename T0, typename T1>// faster
    TypeCounter type()
    {
        static TypeCounter ret = -1;
        if (ret != -1) {
            return ret;
        }

        std::map<TypeCounter, std::function<TypeCounter()>> m;

        auto t0 = _type<T0>();
        auto t1 = _type<T1>();
        m.insert({t0, [this]()
        {
            return _type<T0, T1>();
        }});
        m.insert({t1, [this]()
        {
            return _type<T1, T0>();
        }});
        ret = m.begin()->second();
        assert(m.size() == 2);
        return ret;
    }

    template<typename T0, typename T1, typename T2>// faster
    TypeCounter type()
    {
        static TypeCounter ret = -1;
        if (ret != -1) {
            return ret;
        }

        std::map<TypeCounter, std::function<TypeCounter()>> m;

        auto t0 = _type<T0>();
        auto t1 = _type<T1>();
        auto t2 = _type<T2>();
        m.insert({t0, [this, t1, t2]()
        {
            return TypeLm3<T0, T1, T2>(t1, t2);
        }});
        m.insert({t1, [this, t0, t2]()
        {
            return TypeLm3<T1, T0, T2>(t0, t2);
        }});
        m.insert({t2, [this, t0, t1]()
        {
            return TypeLm3<T2, T0, T1>(t0, t1);
        }});
        ret = m.begin()->second();
        assert(m.size() == 3);
        return ret;
    }

    template<typename T0, typename T1, typename T2, typename T3>// faster
    TypeCounter type()
    {
        static TypeCounter ret = -1;
        if (ret != -1) {
            return ret;
        }

        std::map<TypeCounter, std::function<TypeCounter()>> m;

        auto t0 = _type<T0>();
        auto t1 = _type<T1>();
        auto t2 = _type<T2>();
        auto t3 = _type<T3>();
        m.insert({t0, [this, t1, t2, t3]()
        {
            return TypeLm4<T0, T1, T2, T3>(t1, t2, t3);
        }});
        m.insert({t1, [this, t0, t2, t3]()
        {
            return TypeLm4<T1, T0, T2, T3>(t0, t2, t3);
        }});
        m.insert({t2, [this, t0, t1, t3]()
        {
            return TypeLm4<T2, T0, T1, T3>(t0, t1, t3);
        }});
        m.insert({t3, [this, t0, t1, t2]()
        {
            return TypeLm4<T3, T0, T1, T2>(t0, t1, t2);
        }});
        ret = m.begin()->second();
        assert(m.size() == 4);
        return ret;
    }

    template<typename T0, typename T1, typename T2, typename T3, typename T4, typename ... Args>
    TypeCounter type()
    {
        static TypeCounter ret = -1;
        if (ret != -1) {
            return ret;// calculation once only
        }

        TComplexSet complexSet;
        AddToSet<T0, T1, T2, T3, T4, Args...>(complexSet);

        bool found = false;
        for (auto& cset : mComplexSetList)// slow with more collections!
        {
            if (cset == complexSet) {
                ret = cset.tc;
                found = true;
            }
        }
        if (found == false) {
            ret = atc.fetch_add(1);
            complexSet.tc = ret;
            mComplexSetList.push_back(complexSet);
        }
        return ret;
    }
};

typedef TRunTimeTypeIndex<struct GlobalTypeIdentifier> TGlobalTypeIdentifier;
extern DllExport TGlobalTypeIdentifier* GlobalTypeIdentifier();// for use in SingletonManager 
