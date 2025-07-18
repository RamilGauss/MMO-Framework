/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include <unordered_map>

template <typename Key, typename Value>
class DllExport TBiMap
{
public:
    using TKeyValueMap = std::unordered_map<Key, Value>;
    using TValueKeyMap = std::unordered_map<Value, Key>;

    TKeyValueMap left;
    TValueKeyMap right;

    TBiMap()
    {

    }

    TBiMap(const std::initializer_list<std::pair<const Key, const Value>>& il)
    {
        for (auto& el : il) {
            insert(el.first, el.second);
        }
    }

    void insert(const TBiMap<Key, Value>& other)
    {
        left.insert(other.left.begin(), other.left.end());
        right.insert(other.right.begin(), other.right.end());
    }

    void insert(const Key& key, const Value& value)
    {
        left.insert({key, value});
        right.insert({value, key});
    }

    void EraseByKey(const Key& key)
    {
        auto fitLeft = left.find(key);
        if (fitLeft == left.end()) {
            return;
        }
        right.erase(fitLeft->second);
        left.erase(fitLeft);
    }

    void EraseByValue(const Value& value)
    {
        auto fitRight = right.find(value);
        if (fitRight == right.end()) {
            return;
        }
        left.erase(fitRight->second);
        right.erase(fitRight);
    }

    void Clear()
    {
        right.clear();
        left.clear();
    }

    bool FindByKey(const Key& key, Value& value) const
    {
        auto fit = left.find(key);
        if (fit == left.end()) {
            return false;
        }

        value = fit->second;

        return true;
    }

    bool FindByValue(const Value& value, Key& key) const
    {
        auto fit = right.find(value);
        if (fit == right.end()) {
            return false;
        }

        key = fit->second;

        return true;
    }
};