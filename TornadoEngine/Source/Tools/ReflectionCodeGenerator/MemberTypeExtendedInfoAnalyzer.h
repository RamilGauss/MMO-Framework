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
    Space,
    // std
    Std,
    String,
    Vector,
    List,
    Set,
    Map,
    // pointer
    Asterisk,
    // smart pointers
    SharedPtr,
    WeakPtr,
    UniquePtr,
    AutoPtr,
    // built-in types
    Bool,
    Unsigned,
    Signed,
    Char,
    Short,
    Int,
    Long,
    Float,
    Double,

    Reflection
  };

  // separators
  const std::string s_ColonColon = "::";
  const std::string s_Less = "<";
  const std::string s_Greater = ">";
  const std::string s_Space = " ";

  // std
  const std::string s_Std = "std";
  const std::string s_String = "string";
  const std::string s_Vector = "vector";
  const std::string s_List = "list";
  const std::string s_Set = "set";
  const std::string s_Map = "map";

  // pointer
  const std::string s_Asterisk = "*";

  // smart pointers
  const std::string s_SharedPtr = "shared_ptr";
  const std::string s_WeakPtr = "weak_ptr";
  const std::string s_UniquePtr = "unique_ptr";
  const std::string s_AutoPtr = "auto_ptr";

  // built-in types
  const std::string s_Bool = "bool";
  const std::string s_Unsigned = "unsigned";
  const std::string s_Signed = "signed";
  const std::string s_Char = "char";
  const std::string s_Short = "short";
  const std::string s_Int = "int";
  const std::string s_Long = "long";
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

  typedef std::list<TTokenDesc> TTokenList;
  typedef std::map<std::string,TTokenList> TStrTokenMap;

  TStrTokenMap mTokenCache;
public:
  TMemberTypeExtendedInfoAnalyzer();
  ~TMemberTypeExtendedInfoAnalyzer();

  void Work();
private:
  void HandleType( TTypeInfo* typeInfo );
  TTokenList* GetTokenList( std::string& typeName );
  void InitMap();

  TTokenList* TryGetFromCache( std::string& memberName );
  void AddToCache( std::string& memberName, TTokenList& tokenList );
  void MakeTokenList( std::string& typeName, TTokenList& cacheList );
};

