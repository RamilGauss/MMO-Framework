/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "MemberTypeExtendedInfoAnalyzer.h"
#include "TypeManager.h"
#include "SingletonManager.h"
#include "magic_enum.hpp"

#define ADD(X) \
mTokenStrMap.insert( TIntStrMap::value_type( TokenType::X, s_##X ) ); \
mStrTokenMap.insert( TStrIntMap::value_type( s_##X, TokenType::X ) );

#define ADD_SEPARATOR(X) \
mSeparatorStrTokenMap.insert( TIntStrMap::value_type( TokenType::X, s_##X ) );


TMemberTypeExtendedInfoAnalyzer::TMemberTypeExtendedInfoAnalyzer()
{
    mConfigContainer = SingletonManager()->Get<nsReflectionCodeGenerator::TConfigContainer>();

    mTypeMng = SingletonManager()->Get<TTypeManager>();

    InitSeparatorTokenSet();

    InitMap();
}
//------------------------------------------------------------------------------
TMemberTypeExtendedInfoAnalyzer::~TMemberTypeExtendedInfoAnalyzer()
{

}
//------------------------------------------------------------------------------
void TMemberTypeExtendedInfoAnalyzer::Work()
{
    for ( auto nameSpaceName_Types : mTypeMng->mNameSpaceTypesMap ) {
        auto nameSpace = nameSpaceName_Types.first;
        auto types = nameSpaceName_Types.second.get();
        for ( auto nameTypeInfo : types[0] ) {
            auto pTypeInfo = nameTypeInfo.second.get();

            mCurrentTypeInfo = pTypeInfo;

            HandleType(pTypeInfo);

            mCurrentTypeInfo = nullptr;
        }
    }
}
//------------------------------------------------------------------------------
void TMemberTypeExtendedInfoAnalyzer::HandleType(TTypeInfo* typeInfo)
{
    for ( auto accessLevel_memberInfo : typeInfo->mMemberMap ) {
        auto accessLevel = accessLevel_memberInfo.first;
        if ( accessLevel != TMemberInfo::AccessLevel::ePublic ) {
            continue;
        }
        for ( auto pMemberInfo : accessLevel_memberInfo.second ) {
            GetTokenList(pMemberInfo->mTypeName, pMemberInfo->mExtendedInfo);
        }
    }
}
//------------------------------------------------------------------------------
void TMemberTypeExtendedInfoAnalyzer::GetTokenList(const std::string& typeName, TMemberTypeExtendedInfo& memberTypeInfo)
{
    auto pMemberTypeInfo = mMemberCache.TryGetFromCache(typeName);
    if ( pMemberTypeInfo ) {
        memberTypeInfo = *pMemberTypeInfo;
        return;
    }
    TTokenDescVector tokenVector;
    MakeTokenList(typeName, tokenVector);

    SearchTokenCatergory(tokenVector);

    FillInfo(tokenVector, memberTypeInfo);

    mMemberCache.AddToCache(typeName, memberTypeInfo);
}
//------------------------------------------------------------------------------
void TMemberTypeExtendedInfoAnalyzer::InitMap()
{
    ADD(ColonColon)
    ADD(Less)
    ADD(Greater)
    ADD(Comma)
    ADD(Std)
    ADD(String)
    ADD(Vector)
    ADD(List)
    ADD(Set)
    ADD(Map)
    ADD(Ampersand)
    ADD(Asterisk)
    ADD(SharedPtr)
    ADD(WeakPtr)
    ADD(UniquePtr)
    ADD(AutoPtr)
    ADD(Bool)
    ADD(Char)
    ADD(UnsignedChar)
    ADD(Short)
    ADD(UnsignedShort)
    ADD(Int)
    ADD(UnsignedInt)
    ADD(Long)
    ADD(LongLong)
    ADD(UnsignedLong)
    ADD(Float)
    ADD(Double)
}
//------------------------------------------------------------------------------
void TMemberTypeExtendedInfoAnalyzer::MakeTokenList(const std::string& typeName, TTokenDescVector& tokenVector)
{
    size_t off = 0;
    auto beginReflectionType = off;
    auto searchReflectionType = false;
    auto length = typeName.length();
    while ( off < length ) {
        auto found = false;

        for ( auto& tokenStr : mSeparatorStrTokenMap ) {
            auto subStr = tokenStr.second;
            auto pos = typeName.find(subStr, off);
            if ( pos == off ) {
                TTokenDesc tokenDesc;
                if ( searchReflectionType ) {
                    searchReflectionType = false;

                    tokenDesc.type = ReflectionType;
                    tokenDesc.value = typeName.substr(beginReflectionType, off - beginReflectionType);
                    tokenVector.push_back(tokenDesc);
                }
                tokenDesc.type = tokenStr.first;
                tokenDesc.value = subStr;

                tokenVector.push_back(tokenDesc);
                off += subStr.length();
                found = true;
                break;
            }
        }
        // не нашли токен
        if ( found == false ) {// переходим в поиск рефлексируеющего типа
            if ( searchReflectionType == false ) {
                beginReflectionType = off;
                searchReflectionType = true;
            }
            off++;
        }
    }

    // не закончили поиск
    if ( searchReflectionType ) {
        TTokenDesc tokenDesc;
        tokenDesc.type = ReflectionType;
        tokenDesc.value = typeName.substr(beginReflectionType, off - beginReflectionType);
        tokenVector.push_back(tokenDesc);
    }
}
//------------------------------------------------------------------------------
void TMemberTypeExtendedInfoAnalyzer::SearchTokenCatergory(TTokenDescVector& tokenVector)
{
    for ( auto& tokenInfo : tokenVector ) {
        auto tokenValue = tokenInfo.value;

        auto knownTokenFit = mStrTokenMap.find(tokenValue);
        if ( knownTokenFit != mStrTokenMap.end() )             {
            tokenInfo.type = knownTokenFit->second;
            continue;
        }

        auto& customizeMap = mConfigContainer->mConfig.targetForCodeGeneration.typeCustomizerMap;
        auto customizeType = customizeMap.find(tokenValue);
        if ( customizeType != customizeMap.end() ) {

            auto customizeTypeCategoryName = customizeType->second;

            auto typeFit = mStrTokenMap.find(customizeTypeCategoryName);
            if ( typeFit != mStrTokenMap.end() ) {
                tokenInfo.type = typeFit->second;
                continue;
            }
        }

        tokenInfo.type = TokenType::ReflectionType;
    }
}
//------------------------------------------------------------------------------
int TMemberTypeExtendedInfoAnalyzer::FillInfo(const TTokenDescVector& tokenVector, TMemberTypeExtendedInfo& memberTypeInfo, int index)
{
    std::string nameSpaceAccumulator;
    std::string canBeNameSpace;

    int cornerBalance = 0;
    for ( int i = index; i < tokenVector.size(); i++ ) {
        auto& tokenDesc = tokenVector[i];

        auto tokenDescType = tokenDesc.type;

        auto& customizeMap = mConfigContainer->mConfig.targetForCodeGeneration.typeCustomizerMap;
        auto customizeType = customizeMap.find(tokenDesc.value);
        if ( customizeType != customizeMap.end() ) {

            auto customizeTypeCategoryName = customizeType->second;

            auto typeFit = mStrTokenMap.find(customizeTypeCategoryName);
            if ( typeFit != mStrTokenMap.end() ) {
                tokenDescType = typeFit->second;
            }
        }

        switch ( tokenDescType ) {
            case Comma:
                if ( cornerBalance == 0 ) {
                    return i - 1;
                } else {
                    memberTypeInfo.mTemplateChildArr.push_back(TMemberTypeExtendedInfo());
                    i = FillInfo(tokenVector, memberTypeInfo.mTemplateChildArr.back(), i + 1);
                }
                break;
            case Less:
                cornerBalance++;
                if ( memberTypeInfo.mAccessMethod == TMemberTypeExtendedInfo::SmartPointer &&
                    !memberTypeInfo.IsContainer() ) {
                    i = FillInfo(tokenVector, memberTypeInfo, i + 1);
                } else {
                    memberTypeInfo.mTemplateChildArr.push_back(TMemberTypeExtendedInfo());
                    i = FillInfo(tokenVector, memberTypeInfo.mTemplateChildArr.back(), i + 1);
                }
                continue;
            case Greater:
                if ( cornerBalance > 0 ) {
                    cornerBalance--;
                }
                return i - 1;
            case Ampersand:
                break;
            case ColonColon:
                nameSpaceAccumulator += canBeNameSpace;
                nameSpaceAccumulator += tokenDesc.value;
                break;
            case Std:
                nameSpaceAccumulator += tokenDesc.value;
                break;
            case String:
                memberTypeInfo.mNameSpaceForReflection = s_Std;
                memberTypeInfo.mType = tokenDesc.value;
                memberTypeInfo.mCategory = TMemberTypeExtendedInfo::String;
                break;
            case Vector:
                memberTypeInfo.mNameSpaceForReflection = s_Std;
                memberTypeInfo.mType = tokenDesc.value;
                memberTypeInfo.mCategory = TMemberTypeExtendedInfo::Vector;
                break;
            case List:
                memberTypeInfo.mNameSpaceForReflection = s_Std;
                memberTypeInfo.mType = tokenDesc.value;
                memberTypeInfo.mCategory = TMemberTypeExtendedInfo::List;
                break;
            case Set:
                memberTypeInfo.mNameSpaceForReflection = s_Std;
                memberTypeInfo.mType = tokenDesc.value;
                memberTypeInfo.mCategory = TMemberTypeExtendedInfo::Set;
                break;
            case Map:
                memberTypeInfo.mNameSpaceForReflection = s_Std;
                memberTypeInfo.mType = tokenDesc.value;
                memberTypeInfo.mCategory = TMemberTypeExtendedInfo::Map;
                break;
            case Asterisk:
                memberTypeInfo.mAccessMethod = TMemberTypeExtendedInfo::Pointer;
                break;
            case SharedPtr:
            case WeakPtr:
            case UniquePtr:
            case AutoPtr:
                memberTypeInfo.mSmartPtrType = tokenDesc.value;
                memberTypeInfo.mAccessMethod = TMemberTypeExtendedInfo::SmartPointer;
                break;
            case Bool:
            case Char:
            case UnsignedChar:
            case Short:
            case UnsignedShort:
            case Int:
            case UnsignedInt:
            case Long:
            case LongLong:
            case UnsignedLong:
            case Float:
            case Double:
                memberTypeInfo.mCategory = TMemberTypeExtendedInfo::BuiltIn;
                memberTypeInfo.mType = tokenDesc.value;
                break;
            case ReflectionType:
                canBeNameSpace = tokenDesc.value;
                memberTypeInfo.mCategory = TMemberTypeExtendedInfo::Reflection;
                memberTypeInfo.mType = tokenDesc.value;

                auto withinClassTypename = mCurrentTypeInfo->GetTypeNameWithNameSpace();
                auto nameSpaceTarget = nameSpaceAccumulator + memberTypeInfo.mType;

                auto pTypeInfo = mTypeMng->FindTypeInfoBy(nameSpaceTarget, withinClassTypename);
                if ( pTypeInfo ) {
                    memberTypeInfo.mNameSpaceForReflection = pTypeInfo->GetNameSpace();
                }
                break;
        }
    }
    return tokenVector.size();
}
//------------------------------------------------------------------------------
void TMemberTypeExtendedInfoAnalyzer::InitSeparatorTokenSet()
{
    ADD_SEPARATOR(Std)
    ADD_SEPARATOR(ColonColon)
    ADD_SEPARATOR(Comma)
    ADD_SEPARATOR(Less)
    ADD_SEPARATOR(Greater)
    ADD_SEPARATOR(Asterisk)
    ADD_SEPARATOR(Ampersand)
}
//------------------------------------------------------------------------------
