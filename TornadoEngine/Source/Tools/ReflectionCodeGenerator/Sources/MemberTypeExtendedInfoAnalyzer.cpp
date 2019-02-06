/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MemberTypeExtendedInfoAnalyzer.h"
#include "TypeManager.h"
#include "SingletonManager.h"

#define ADD(X) \
mTokenStrMap.insert( TIntStrMap::value_type( TokenType::X, s_##X ) );


TMemberTypeExtendedInfoAnalyzer::TMemberTypeExtendedInfoAnalyzer()
{
  mTypeMng = SingletonManager()->Get<TTypeManager>();

  InitMap();
}
//------------------------------------------------------------------------------
TMemberTypeExtendedInfoAnalyzer::~TMemberTypeExtendedInfoAnalyzer()
{

}
//------------------------------------------------------------------------------
void TMemberTypeExtendedInfoAnalyzer::Work()
{
  for ( auto nameSpaceName_Types : mTypeMng->mNameSpaceTypesMap )
  {
    auto nameSpace = nameSpaceName_Types.first;
    auto types = nameSpaceName_Types.second.get();
    for ( auto name_typeInfo : types [0] )
    {
      auto pTypeInfo = name_typeInfo.second.get();
      HandleType( pTypeInfo );
    }
  }
}
//------------------------------------------------------------------------------
void TMemberTypeExtendedInfoAnalyzer::HandleType( TTypeInfo* typeInfo )
{
  for ( auto accessLevel_memberInfo : typeInfo->mMemberMap )
  {
    auto accessLevel = accessLevel_memberInfo.first;
    if ( accessLevel != TMemberInfo::AccessLevel::ePublic )
      continue;
    for ( auto pMemberInfo : accessLevel_memberInfo.second )
      GetTokenList( pMemberInfo->mTypeName, pMemberInfo->mExtendedInfo );
  }
}
//------------------------------------------------------------------------------
void TMemberTypeExtendedInfoAnalyzer::GetTokenList( std::string& typeName, TMemberTypeExtendedInfo& memberTypeInfo )
{
  auto pMemberTypeInfo = mMemberCache.TryGetFromCache( typeName );
  if ( pMemberTypeInfo )
  {
    memberTypeInfo = *pMemberTypeInfo;
    return;
  }
  TTokenDescVector tokenVector;
  MakeTokenList( typeName, tokenVector );

  FillInfo( tokenVector, memberTypeInfo );

  mMemberCache.AddToCache( typeName, memberTypeInfo );
}
//------------------------------------------------------------------------------
void TMemberTypeExtendedInfoAnalyzer::InitMap()
{
  ADD( ColonColon );
  ADD( Less );
  ADD( Greater );
  ADD( Comma );
  ADD( Std );
  ADD( String );
  ADD( Vector );
  ADD( List );
  ADD( Set );
  ADD( Map );
  ADD( Ampersand );
  ADD( Asterisk );
  ADD( SharedPtr );
  ADD( WeakPtr );
  ADD( UniquePtr );
  ADD( AutoPtr );
  ADD( Bool );
  ADD( Char );
  ADD( UnsignedChar );
  ADD( Short );
  ADD( UnsignedShort );
  ADD( Int );
  ADD( UnsignedInt );
  ADD( Long );
  ADD( LongLong );
  ADD( UnsignedLong );
  ADD( Float );
  ADD( Double );
}
//------------------------------------------------------------------------------
void TMemberTypeExtendedInfoAnalyzer::MakeTokenList( std::string& typeName, TTokenDescVector& tokenVector )
{
  size_t off = 0;
  auto beginReflectionType = off;
  auto searchReflectionType = false;
  auto length = typeName.length();
  while ( off < length )
  {
    auto found = false;
    for ( auto& tokenStr : mTokenStrMap )
    {
      auto subStr = tokenStr.second;
      auto pos = typeName.find( subStr, off );
      if ( pos == off )
      {
        TTokenDesc tokenDesc;
        if ( searchReflectionType )
        {
          searchReflectionType = false;

          tokenDesc.type = ReflectionType;
          tokenDesc.value = typeName.substr( beginReflectionType, off - beginReflectionType );
          tokenVector.push_back( tokenDesc );
        }
        tokenDesc.type = tokenStr.first;
        tokenDesc.value = subStr;

        tokenVector.push_back( tokenDesc );
        off += subStr.length();
        found = true;
        break;
      }
    }
    // не нашли токен
    if ( found == false )
    {// переходим в поиск рефлексируеющего типа
      if ( searchReflectionType == false )
      {
        beginReflectionType = off;
        searchReflectionType = true;
      }
      off++;
    }
  }

  // не закончили поиск
  if ( searchReflectionType )
  {
    TTokenDesc tokenDesc;
    tokenDesc.type = ReflectionType;
    tokenDesc.value = typeName.substr( beginReflectionType, off - beginReflectionType );
    tokenVector.push_back( tokenDesc );
  }
}
//------------------------------------------------------------------------------
int TMemberTypeExtendedInfoAnalyzer::FillInfo( TTokenDescVector& tokenVector, TMemberTypeExtendedInfo& memberTypeInfo, int index )
{
  std::string nameSpaceAccumulator;
  std::string canBeNameSpace;

  int cornerBalance = 0;
  for ( int i = index ; i < tokenVector.size(); i++ )
  {
    auto& tokenDesc = tokenVector [i];
    switch ( tokenDesc.type )
    {
      case Comma:
        if ( cornerBalance == 0 )
          return i - 1;
        else
        {
          memberTypeInfo.mTemplateChildArr.push_back( TMemberTypeExtendedInfo() );
          i = FillInfo( tokenVector, memberTypeInfo.mTemplateChildArr.back(), i + 1 );
        }
        break;
      case Less:
        cornerBalance++;
        if( memberTypeInfo.mAccessMethod == TMemberTypeExtendedInfo::SmartPointer && 
          !memberTypeInfo.IsContainer() )
          i = FillInfo( tokenVector, memberTypeInfo, i + 1 );
        else
        {
          memberTypeInfo.mTemplateChildArr.push_back( TMemberTypeExtendedInfo() );
          i = FillInfo( tokenVector, memberTypeInfo.mTemplateChildArr.back(), i + 1 );
        }
        continue;
      case Greater:
        if( cornerBalance > 0 )
          cornerBalance--;
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
        auto pTypeInfo = mTypeMng->FindTypeInfo( memberTypeInfo.mType );
        if( pTypeInfo )
          memberTypeInfo.mNameSpaceForReflection = pTypeInfo->GetNameSpace();
        break;
    }
  }
  return tokenVector.size();
}
//------------------------------------------------------------------------------
