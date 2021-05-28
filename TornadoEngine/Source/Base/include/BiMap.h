/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <map>

template <typename Key, typename Value>
class DllExport TBiMap
{
public:
    using TKeyValueMap = std::map<Key, Value>;
    using TValueKeyMap = std::map<Value, Key>;

    TKeyValueMap left;
    TValueKeyMap right;

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
};