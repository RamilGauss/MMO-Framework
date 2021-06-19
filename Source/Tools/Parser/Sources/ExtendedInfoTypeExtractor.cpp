/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ExtendedInfoTypeExtractor.h"

#include <cassert>
#include "BL_Debug.h"

using namespace nsCppParser;

TExtendedInfoTypeExtractor::TExtendedInfoTypeExtractor()
{
    mNameTypeMap =
    {
        {"bool", TypeCategory::BOOL},

        {"int8_t", TypeCategory::CEIL_NUMBER},
        {"uint8_t", TypeCategory::CEIL_NUMBER},
        {"int16_t", TypeCategory::CEIL_NUMBER},
        {"uint16_t", TypeCategory::CEIL_NUMBER},
        {"int32_t", TypeCategory::CEIL_NUMBER},
        {"uint32_t", TypeCategory::CEIL_NUMBER},
        {"int64_t", TypeCategory::CEIL_NUMBER},
        {"uint64_t", TypeCategory::CEIL_NUMBER},
        {"char", TypeCategory::CEIL_NUMBER},
        {"unsigned char", TypeCategory::CEIL_NUMBER},
        {"short", TypeCategory::CEIL_NUMBER},
        {"unsigned short", TypeCategory::CEIL_NUMBER},
        {"int", TypeCategory::CEIL_NUMBER},
        {"unsigned int", TypeCategory::CEIL_NUMBER},
        {"long", TypeCategory::CEIL_NUMBER},
        {"unsigned long", TypeCategory::CEIL_NUMBER},
        {"long long", TypeCategory::CEIL_NUMBER},
        {"signed long long", TypeCategory::CEIL_NUMBER},
        {"unsigned long long", TypeCategory::CEIL_NUMBER},

        {"float", TypeCategory::NUMBER},
        {"double", TypeCategory::NUMBER},

        {"std::string", TypeCategory::STRING},
        {"std::vector", TypeCategory::VECTOR},
        {"std::list", TypeCategory::LIST},
        {"std::array", TypeCategory::ARRAY},

        {"std::map", TypeCategory::MAP},
        {"std::set", TypeCategory::SET},

        {"std::auto_ptr", TypeCategory::SMART_POINTER},
        {"std::shared_ptr", TypeCategory::SMART_POINTER},
        {"std::weak_ptr", TypeCategory::SMART_POINTER},
        {"std::unique_ptr", TypeCategory::SMART_POINTER},
    };
}
//-----------------------------------------------------------------------------------------------------------------------
void TExtendedInfoTypeExtractor::Setup(std::map<std::string, TypeCategory>& nameTypeMap, bool append)
{
    if (append) {
        mNameTypeMap.insert(nameTypeMap.begin(), nameTypeMap.end());
    } else {
        mNameTypeMap = nameTypeMap;
    }
}
//-----------------------------------------------------------------------------------------------------------------------
void TExtendedInfoTypeExtractor::RemoveSpaces(std::string& str) const
{
    str.erase(std::remove_if(str.begin(), str.end(), mIsSpace), str.end());
}
//-----------------------------------------------------------------------------------------------------------------------
void TExtendedInfoTypeExtractor::RemoveFromBeginSpaces(std::string& str) const
{
    while (true) {
        if (str.size() == 0) {
            return;
        }
        if (mIsSpace(str[0])) {
            str.erase(0, 1);
        } else {
            return;
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------------
void TExtendedInfoTypeExtractor::RemoveFromEndSpaces(std::string& str) const
{
    while (true) {
        if (str.size() == 0) {
            return;
        }
        if (mIsSpace(str[str.size() - 1])) {
            str.erase(str.size() - 1, 1);
        } else {
            return;
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------------
void TExtendedInfoTypeExtractor::SplitString(std::string& str, std::list<TStringPart>& parts)
{
    TStringPart part;
    size_t index = 0;
    for (auto& c : str) {
        auto stringType = part.stringType;
        switch (c) {
            case ':':
                stringType = StringType::COLON_COLON;
                break;
            case '<':
                stringType = StringType::LEFT_CORNER;
                break;
            case '>':
                stringType = StringType::RIGHT_CORNER;
                break;
            case ',':
                stringType = StringType::COMMA;
                break;
            case '*':
                stringType = StringType::ASTERISK;
                break;
            default:
                stringType = StringType::IDENTIFIER;
        }
        if (stringType != part.stringType ||
            part.stringType == StringType::RIGHT_CORNER) {

            part.end = index;
            if (part.GetSize() > 0) {
                part.value = str.substr(part.begin, part.GetSize());
                parts.push_back(part);
            }
            part.begin = index;
            part.stringType = stringType;
        }

        index++;
    }

    part.end = index;
    part.value = str.substr(part.begin, part.GetSize());
    parts.push_back(part);
}
//-----------------------------------------------------------------------------------------------------------------------
void TExtendedInfoTypeExtractor::NormalizeTypeName(std::list<TStringPart>& parts)
{
    for (auto& part : parts) {
        RemoveFromBeginSpaces(part.value);
        RemoveFromEndSpaces(part.value);

        std::string valueCopy = part.value;
        part.value = "";
        bool isSpace = false;
        for (auto& c : valueCopy) {
            if (mIsSpace(c)) {
                if (!isSpace) {
                    part.value.insert(part.value.end(), c);
                    isSpace = true;
                }
            } else {
                part.value.insert(part.value.end(), c);
                isSpace = false;
            }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------------
void TExtendedInfoTypeExtractor::ConvertPartsToSimpleHierarchy(std::list<TStringPart>& parts, TSimple* simple,
    std::list<TStringPart>::iterator* pIt, TSimple* parent)
{
    if (parts.size() == 0) {
        return;
    }

    auto it = parts.begin();
    if (pIt == nullptr) {
        pIt = &it;
    } else if (*pIt == parts.end()) {
        return;
    }

    simple->children.clear();

    while (*pIt != parts.end()) {
        auto& part = pIt->operator*();

        switch (part.stringType) {
            case StringType::IDENTIFIER:
            case StringType::COLON_COLON:
            case StringType::ASTERISK:
                simple->parts.push_back(part);
                break;
            case StringType::COMMA:
                parent->children.push_back(TSimple());
                simple = &(parent->children.back());
                break;
            case StringType::LEFT_CORNER:
                {
                    simple->children.push_back(TSimple());
                    auto child = &(simple->children.back());
                    pIt->operator++();
                    ConvertPartsToSimpleHierarchy(parts, child, pIt, simple);
                }
                break;
            case StringType::RIGHT_CORNER:
                return;
            default: assert(0);
        }
        pIt->operator++();
    }
}
//-----------------------------------------------------------------------------------------------------------------------
void TExtendedInfoTypeExtractor::ConvertSimpleHierarchyToExtended(TSimple* simple, TMemberExtendedTypeInfo* meti)
{
    auto isPointer = (simple->parts.back().stringType==StringType::ASTERISK);
    auto isSmartPointer = false;

    // Forms long, short types
    if (isPointer) {
        auto rbegin = simple->parts.rbegin();
        rbegin++;
        meti->mShortType = rbegin->value;
        meti->mAccessMethod = AccessMethod::POINTER;
    } else {
        meti->mShortType = simple->parts.back().value;
    }

    int cnt = (int)(simple->parts.size());
    cnt -= 2;
    if (isPointer) {
        cnt--;
    }
    auto bit = simple->parts.begin();
    for (int i = 0; i < cnt; i++) {
        meti->mNameSpace += bit->value;
        bit++;
    }
    if (meti->mNameSpace.size() == 0) {
        meti->mLongType = meti->mShortType;
    } else {
        meti->mLongType = meti->mNameSpace + "::" + meti->mShortType;
    }

    // Detect type category
    auto fit = mNameTypeMap.find(meti->mLongType);
    if (fit != mNameTypeMap.end()) {
        if (fit->second == TypeCategory::SMART_POINTER) {
            if (isPointer) {
                BL_FIX_BUG();
                return;
            }
            isSmartPointer = true;
            if (simple->children.size() != 1) {
                BL_FIX_BUG();
                return;
            }
        }
        meti->mCategory = fit->second;
    } else {
        meti->mCategory = TypeCategory::REFLECTION;
    }

    // Smart pointer case
    if (isSmartPointer) {
        for (auto& part : simple->parts) {
            meti->mSmartPtrType += part.value;
        }
        meti->mAccessMethod = AccessMethod::SMART_POINTER;
        meti->mShortType = "";
        meti->mLongType = "";
        meti->mNameSpace = "";

        auto& child = simple->children.front();
        ConvertSimpleHierarchyToExtended(&child, meti);
        return;
    }

    for (auto& child : simple->children) {
        TMemberExtendedTypeInfo metiChild;
        ConvertSimpleHierarchyToExtended(&child, &metiChild);
        meti->mTemplateChildArr.push_back(metiChild);
    }
}
//-----------------------------------------------------------------------------------------------------------------------
void TExtendedInfoTypeExtractor::RemoveEmptyParts(std::list<TStringPart>& parts)
{
    std::list<TStringPart> copyParts = parts;
    parts.clear();

    for (const auto& part : copyParts) {
        if (part.value.size() != 0) {
            parts.push_back(part);
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------------
void TExtendedInfoTypeExtractor::Convert(std::string& str, TMemberExtendedTypeInfo* meti)
{
    std::list<TStringPart> parts;
    SplitString(str, parts);

    NormalizeTypeName(parts);
    RemoveEmptyParts(parts);

    TSimple simple;
    ConvertPartsToSimpleHierarchy(parts, &simple);

    meti->Reset();
    ConvertSimpleHierarchyToExtended(&simple, meti);
}
//-----------------------------------------------------------------------------------------------------------------------
