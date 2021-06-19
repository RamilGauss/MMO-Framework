#pragma once

#include <list>
#include <string>
#include <map>

#include "TypeDef.h"

namespace nsTypeInformation
{
    class TTypeInformation
    {
        static std::list<std::string> mTypeNameList;
        static std::list<int> mTypeIdentifierList;

        static std::map<int, std::string> mIdentifierNameMap;
        static std::map<std::string, int> mNameIdentifierMap;

        static void Init();

    public:
        static const std::list<std::string>* GetTypeNameList();
        static const std::list<int>* GetTypeIdentifierList();

        static bool ConvertTypeToName(int typeIdentifier, std::string& typeName);
        static bool ConvertNameToType(const std::string& typeName, int& typeIdentifier);
    };
}