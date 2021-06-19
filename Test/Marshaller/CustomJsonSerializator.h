#pragma once

#include <string>

namespace nsCustomJsonSerializator
{
    class TCustomJsonSerializator
    {
    public:

        template <typename Type>
        static void Serialize(Type* p, std::string& str) {}
        template <typename Type>
        static bool Deserialize(Type*& p, const std::string& str, std::string& err) {}
        template <typename Type>
        static bool Fill(Type* p, const std::string& str, std::string& err) {}

        static void Serialize(void* p, std::string& str, const std::string& typeName) {}
        static bool Deserialize(void*& p, const std::string& str, const std::string& typeName, std::string& err) {}
        static bool Fill(void* p, const std::string& str, const std::string& typeName, std::string& err) {}

        static void Serialize(void* p, std::string& str, int typeIdentifier) {}
        static bool Deserialize(void*& p, const std::string& str, int typeIdentifier, std::string& err) {}
        static bool Fill(void* p, const std::string& str, int typeIdentifier, std::string& err) {}
    };
}