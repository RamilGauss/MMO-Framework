/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <vector>
#include <string>
#include <list>
#include <map>
#include <functional>
#include "Types.h"
#include "MemberExtendedTypeInfo.h"

namespace nsCppParser
{
    enum class StringType
    {
        UNDEFINED, IDENTIFIER, COLON_COLON, LEFT_CORNER, RIGHT_CORNER, COMMA, ASTERISK
    };

    struct DllExport TStringPart
    {
        StringType stringType;
        std::string value;

        size_t begin = 0;
        size_t end = 0;

        size_t GetSize()
        {
            return end - begin;
        }
    };

    struct DllExport TSimple
    {
        std::list<TStringPart> parts;
        std::list<TSimple> children;
    };

    class DllExport TExtendedInfoTypeExtractor
    {
        void RemoveSpaces(std::string& str) const;
        void RemoveFromBeginSpaces(std::string& str) const;
        void RemoveFromEndSpaces(std::string& str) const;

        std::function<bool(unsigned char)> mIsSpace =
            [](unsigned char c)
        {
            return (c == ' ' || c == '\n' || c == '\r' ||
                c == '\t' || c == '\v' || c == '\f');
        };


        std::map<std::string, TypeCategory> mNameTypeMap;
    public:
        TExtendedInfoTypeExtractor();
        void Setup(std::map<std::string, TypeCategory>& nameTypeMap, bool append = false);

        void Convert(std::string& str, TMemberExtendedTypeInfo* meti);

    private:

        void SplitString(std::string& str, std::list<TStringPart>& parts);

        // "  unsigned       int    " => "unsigned int"
        void NormalizeTypeName(std::list<TStringPart>& parts);

        void RemoveEmptyParts(std::list<TStringPart>& parts);

        void ConvertPartsToSimpleHierarchy(std::list<TStringPart>& parts, TSimple* simple,
            std::list<TStringPart>::iterator* pIt = nullptr, TSimple* parent = nullptr);

        void ConvertSimpleHierarchyToExtended(TSimple* simple, TMemberExtendedTypeInfo* meti);
    };
}