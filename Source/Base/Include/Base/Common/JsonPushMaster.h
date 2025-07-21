/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <functional>

#include <numeric>
#include <type_traits>

#include "Base/Common/JsonMaster.h"

class DllExport TJsonPushMaster : public TJsonMaster
{
public:
    using Document = rapidjson::Document;

    static Document::AllocatorType& Allocator();

public:// methods
    static Jobj AddObject(Jobj& obj, const char* sKey)
    {
        obj.AddMember(Value(sKey, Allocator()), Value(rapidjson::kObjectType), Allocator());
        return obj.FindMember(sKey)->value.GetObject();
    }
    static void PushBack(Value& jarr, const std::string& value)
    {
        jarr.PushBack(Value(value.data(), Allocator()), Allocator());
    }
    template<typename ValueType,
        typename std::enable_if<std::is_integral<ValueType>::value ||
        std::is_floating_point<ValueType>::value>::type* = nullptr>
        static void PushBack(Value& jarr, ValueType& value)
    {
        jarr.PushBack(Value(value), Allocator());
    }
    static void PushBack(Value& jarr, Value& value)
    {
        jarr.PushBack(value, Allocator());
    }
    static void PushBackNull(Value& jarr)
    {
        jarr.PushBack(Value(), Allocator());
    }
    static void PushNull(Jobj& obj, const char* sKey)
    {
        obj.AddMember(Value(sKey, Allocator()), Value(), Allocator());
    }
    static void Push(Jobj& obj, const char* sKey, std::string& value)
    {
        obj.AddMember(Value(sKey, Allocator()), Value(value.data(), Allocator()), Allocator());
    }
    static void Push(Jobj& obj, const char* sKey, Value& value)
    {
        obj.AddMember(Value(sKey, Allocator()), value, Allocator());
    }
    // static void Push(Jobj& obj, const char* sKey, Jobj& addedObj)
    // {
    //     obj.AddMember(Value(sKey, Allocator()), addedObj, Allocator());
    // }
    template<typename ValueType,
        typename std::enable_if<std::is_integral<ValueType>::value ||
        std::is_floating_point<ValueType>::value>::type* = nullptr>
    static void Push(Jobj& obj, const char* sKey, ValueType& value)
    {
        constexpr bool isLong = std::is_same<long, ValueType>::value;
        constexpr bool isUnsignedLong = std::is_same<unsigned long, ValueType>::value;

        if constexpr (isLong) {
            obj.AddMember(Value(sKey, Allocator()), Value((int64_t) value), Allocator());
        } else if constexpr (isUnsignedLong) {
            obj.AddMember(Value(sKey, Allocator()), Value((uint64_t) value), Allocator());
        } else {
            obj.AddMember(Value(sKey, Allocator()), Value(value), Allocator());
        }
    }
public:
    template <typename T>
    static std::string ConvertToString(const T& t)
    {
        std::ostringstream stringStream;
        stringStream << t;
        std::string str = stringStream.str();
        return str;
    }
};
