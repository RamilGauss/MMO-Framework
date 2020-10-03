/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "TypeDef.h"

#include <functional>
#include <set>

#include "JsonMaster.h"

class DllExport TJsonPopMaster : public TJsonMaster
{
public:
    static bool IsNull(const Jobj& jobj, const char* sKey)
    {
        return Find(jobj, sKey).IsNull();
    }
    static bool IsExist(const Jobj& jobj, const char* sKey)
    {
        return jobj.HasMember(sKey);
    }
    static bool IsArray(const Jobj& jobj, const char* sKey)
    {
        return Find(jobj, sKey).IsArray();
    }
    static Value& Find(const Jobj& jobj, const char* sKey)
    {
        return jobj.FindMember(sKey)->value;
    }
    static Jobj FindObject(const Jobj& jobj, const char* sKey)
    {
        return Find(jobj, sKey).GetObject();
    }
    static Jarr FindArray(const Jobj& jobj, const char* sKey)
    {
        return Find(jobj, sKey).GetArray();
    }

    static void PopBool(const Jobj& jobj, const char* sKey, bool& value)
    {
        auto& contentValue = jobj.FindMember(sKey)->value;
        if ( contentValue.IsBool() ) {
            value = contentValue.GetBool();
        } else {
            value = (bool)contentValue.GetInt();
        }
    }
    template <typename ValueType, typename std::enable_if<std::is_integral<ValueType>::value>::type* = nullptr>
    static void PopNum(const Jobj& jobj, const char* sKey, ValueType& value)
    {
        value = jobj.FindMember(sKey)->value.GetInt64();
    }
    template <typename ValueType, typename std::enable_if<std::is_floating_point<ValueType>::value>::type* = nullptr>
    static void PopNum(const Jobj& jobj, const char* sKey, ValueType& value)
    {
        value = jobj.FindMember(sKey)->value.GetDouble();
    }
    static void PopStr(const Jobj& jobj, const char* sKey, std::string& value)
    {
        value = jobj.FindMember(sKey)->value.GetString();
    }
};
