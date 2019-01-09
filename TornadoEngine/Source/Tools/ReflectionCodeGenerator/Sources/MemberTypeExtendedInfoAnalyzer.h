/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <string>
#include <map>
#include <list>
#include "MemberTypeExtendedInfo.h"
#include "MemberTypeExtendedInfoCache.h"

class TTypeManager;
struct TTypeInfo;

class TMemberTypeExtendedInfoAnalyzer
{
  enum TokenType
  {
    // separators
    ColonColon,
    Less,
    Greater,
    Comma,
    // std
    Std,
    String,
    Vector,
    List,
    Set,
    Map,
    // reference
    Ampersand,
    // pointer
    Asterisk,
    // smart pointers
    SharedPtr,
    WeakPtr,
    UniquePtr,
    AutoPtr,
    // built-in types
    Bool,
    Char,
    UnsignedChar,
    Short,
    UnsignedShort,
    Int,
    UnsignedInt,
    Long,
    LongLong,
    UnsignedLong,
    Float,
    Double,

    ReflectionType
  };

  // separators
  const std::string s_ColonColon = "::";
  const std::string s_Less = "<";
  const std::string s_Greater = ">";
  const std::string s_Comma = ",";

  // std
  const std::string s_Std = "std";
  const std::string s_String = "string";
  const std::string s_Vector = "vector";
  const std::string s_List = "list";
  const std::string s_Set = "set";
  const std::string s_Map = "map";

  // reference 
  const std::string s_Ampersand = "&";
  // pointer
  const std::string s_Asterisk = "*";

  // smart pointers
  const std::string s_SharedPtr = "shared_ptr";
  const std::string s_WeakPtr = "weak_ptr";
  const std::string s_UniquePtr = "unique_ptr";
  const std::string s_AutoPtr = "auto_ptr";

  // built-in types
  const std::string s_Bool = "bool";
  const std::string s_Char = "char";
  const std::string s_UnsignedChar = "unsigned char";
  const std::string s_Short = "short";
  const std::string s_UnsignedShort = "unsigned short";
  const std::string s_Int = "int";
  const std::string s_UnsignedInt = "unsigned int";
  const std::string s_Long = "long";
  const std::string s_LongLong = "long long";
  const std::string s_UnsignedLong = "unsigned long";
  const std::string s_Float = "float";
  const std::string s_Double = "double";

  TTypeManager* mTypeMng;

  typedef std::map<TokenType, std::string> TIntStrMap;
  TIntStrMap mTokenStrMap;

  struct TTokenDesc
  {
    TokenType type;
    std::string value;
  };

  typedef std::vector<TTokenDesc> TTokenDescVector;

  TMemberTypeExtendedInfoCache mMemberCache;

public:
  TMemberTypeExtendedInfoAnalyzer();
  ~TMemberTypeExtendedInfoAnalyzer();

  void Work();
private:
  void InitMap();

  void HandleType( TTypeInfo* typeInfo );
  void GetTokenList( std::string& typeName, TMemberTypeExtendedInfo& memberTypeInfo );

  void MakeTokenList( std::string& typeName, TTokenDescVector& tokenList );
  int FillInfo( TTokenDescVector& tokenList, TMemberTypeExtendedInfo& memberTypeInfo, int index = 0 );
};

