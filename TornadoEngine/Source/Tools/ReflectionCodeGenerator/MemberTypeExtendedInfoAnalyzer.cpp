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
    auto pMemberInfo = accessLevel_memberInfo.second.get();
    auto tokenList = GetTokenList( pMemberInfo->mTypeName );
  }
}
//------------------------------------------------------------------------------
TMemberTypeExtendedInfoAnalyzer::TTokenList* TMemberTypeExtendedInfoAnalyzer::GetTokenList( std::string& typeName )
{
  auto tokenList = TryGetFromCache( typeName );
  if ( tokenList )
    return tokenList;

  TTokenList cacheList;
  MakeTokenList( typeName, cacheList );

  AddToCache( typeName, cacheList );

  tokenList = TryGetFromCache( typeName );
  return tokenList;
}
//------------------------------------------------------------------------------
void TMemberTypeExtendedInfoAnalyzer::InitMap()
{
  ADD( ColonColon );
  ADD( Less );
  ADD( Greater );
  ADD( Space );
  ADD( Std );
  ADD( String );
  ADD( Vector );
  ADD( List );
  ADD( Set );
  ADD( Map );
  ADD( Asterisk );
  ADD( SharedPtr );
  ADD( WeakPtr );
  ADD( UniquePtr );
  ADD( AutoPtr );
  ADD( Bool );
  ADD( Unsigned );
  ADD( Signed );
  ADD( Char );
  ADD( Short );
  ADD( Int );
  ADD( Long );
  ADD( Float );
  ADD( Double );
}
//------------------------------------------------------------------------------
TMemberTypeExtendedInfoAnalyzer::TTokenList* TMemberTypeExtendedInfoAnalyzer::TryGetFromCache( std::string& memberName )
{
  auto fit = mTokenCache.find( memberName );
  if ( fit == mTokenCache.end() )
    return nullptr;
  return &( fit->second );
}
//------------------------------------------------------------------------------
void TMemberTypeExtendedInfoAnalyzer::AddToCache( std::string& memberName, TTokenList& tokenList )
{
  mTokenCache.insert( TStrTokenMap::value_type( memberName, tokenList ) );
}
//------------------------------------------------------------------------------
void TMemberTypeExtendedInfoAnalyzer::MakeTokenList( std::string& typeName, TTokenList& cacheList )
{

}
//------------------------------------------------------------------------------
