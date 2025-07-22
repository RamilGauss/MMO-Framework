/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "Base/Common/TypeDef.h"

#include <functional>
#include <set>

#include "Base/Common/JsonMaster.h"

class DllExport TJsonPopMaster : public TJsonMaster
{
    static void ThrowException(const char* sKey, const char* caseDesc)
    {
        std::string what = "Unpack JSON error, member \"" + std::string(sKey) + "\", ";
        what += std::string(caseDesc);
        throw std::runtime_error(what.data());
    }

    static void GetMemberList(const Jobj& jobj, std::string& memberList)
    {
        const int MAX_COUNT = 10;
        int index = 0;
        for ( auto& member : jobj ) {
            if ( index > MAX_COUNT ) {
                break;
            }
            memberList += member.name.GetString();
            memberList += ", ";
            index++;
        }
    }

    static std::string GetStr(rapidjson::Type t)
    {
        switch ( t ) {
            case rapidjson::Type::kNullType:
                return "null";
            case rapidjson::Type::kFalseType:
            case rapidjson::Type::kTrueType:
                return "bool";
            case rapidjson::Type::kObjectType:
                return "object";
            case rapidjson::Type::kArrayType:
                return "array";
            case rapidjson::Type::kStringType:
                return "string";
            case rapidjson::Type::kNumberType:
                return "number";
        }
        return "";
    }

    static bool IsDigital(Value& value)
    {
        return value.IsInt() || value.IsUint() || value.IsInt64() || value.IsUint64();
    }

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
        auto it = jobj.FindMember(sKey);
        if ( it == jobj.MemberEnd() ) {
            std::string caseDesc = "expected from member list: ";
            GetMemberList(jobj, caseDesc);
            ThrowException(sKey, caseDesc.data());
        }
        return it->value;
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
        auto& contentValue = Find(jobj, sKey);
        if ( contentValue.IsBool() ) {
            value = contentValue.GetBool();
        } else if ( contentValue.IsInt() ) {
            value = (bool) contentValue.GetInt();
        } else {
            auto realType = GetStr(contentValue.GetType());
            std::string caseDesc = "expected bool, but is " + realType;
            ThrowException(sKey, caseDesc.data());
        }
    }
    template <typename ValueType, typename std::enable_if<std::is_integral<ValueType>::value>::type* = nullptr>
    static void PopNum(const Jobj& jobj, const char* sKey, ValueType& value)
    {
        auto& guessInt64 = Find(jobj, sKey);
        if ( !guessInt64.IsInt64() ) {
            auto expected = typeid(ValueType).name();
            auto realType = GetStr(guessInt64.GetType());
            std::string caseDesc = "expected " + std::string(expected) + " ,but is " + realType;
            ThrowException(sKey, caseDesc.data());
        }

        value = guessInt64.GetInt64();
    }
    template <typename ValueType, typename std::enable_if<std::is_floating_point<ValueType>::value>::type* = nullptr>
    static void PopNum(const Jobj& jobj, const char* sKey, ValueType& value)
    {
        auto& guessDouble = Find(jobj, sKey);
        if ( !guessDouble.IsDouble() ) {
            auto realType = IsDigital(guessDouble) ? "integer" : GetStr(guessDouble.GetType());
            std::string caseDesc = "expected double, but is " + realType;
            ThrowException(sKey, caseDesc.data());
        }

        value = guessDouble.GetDouble();
    }
    static void PopStr(const Jobj& jobj, const char* sKey, std::string& value)
    {
        auto& guessString = Find(jobj, sKey);
        if ( !guessString.IsString() ) {
            auto realType = GetStr(guessString.GetType());
            std::string caseDesc = "expected string, but is " + realType;
            ThrowException(sKey, caseDesc.data());
        }

        value = guessString.GetString();
    }
};
