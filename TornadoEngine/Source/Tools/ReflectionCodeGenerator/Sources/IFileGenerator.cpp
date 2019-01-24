/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "IFileGenerator.h"
#include "fmt/core.h"
#include "HiTimer.h"

using namespace nsReflectionCodeGenerator;

void IFileGenerator::Init( TStrListPair& strListPair )
{
  pStrListPair = &strListPair;
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddHeader()
{
  AddList( s_Header );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddTimeHeader()
{
  auto s = s_TimeHeader;

  s = fmt::format( s, nsProgramInfo::NAME, nsProgramInfo::VERSION, nsProgramInfo::COUNTER_BUILD, ht_GetTimeStr() );

  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddIf( const std::string& condition )
{
  auto s = fmt::format( "if ( {} )", condition );
  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddElse()
{
  auto s = "else";
  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddLeftBrace()
{
  auto s = "{";
  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddRightBrace()
{
  auto s = "}";
  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddEmptyLine()
{
  auto s = "";
  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddCommentedLongLine()
{
  auto s = "//---------------------------------------------------------------------------------------";
  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddPragmaOnce()
{
  auto s = "#pragma once";
  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddInclude( const std::string& fileName )
{
  AddIncludeExt( fileName, "\"", "\"" );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddStandartInclude( const std::string& fileName )
{
  AddIncludeExt( fileName, "<", ">" );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddNamespaceBegin( const std::string& namespaceName )
{
  auto s = fmt::format( "namespace {}", namespaceName );
  Add( s );
  s = "{";
  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddNamespaceEnd()
{
  auto s = "}";
  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddUsingNamespace( const std::string& namespaceName )
{
  auto s = fmt::format( "using namespace {};", namespaceName );
  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddUsing( const std::string& expression )
{
  auto s = fmt::format( "using {};", expression );
  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddClassBegin( const std::string& exportDeclaration, const std::string& className )
{
  auto sEexportDeclaration = fmt::format( " {}", exportDeclaration );
  auto s = fmt::format( "class{} {}", sEexportDeclaration, className );
  Add( s );
  s = "{";
  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddClassEnd()
{
  auto s = "};";
  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddIncludeExt( const std::string& fileName, const std::string& beginBrace, const std::string& endBrace )
{
  auto s = fmt::format( "#include {0}{1}{2}", beginBrace, fileName, endBrace );
  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::Add( const std::string& str )
{
  auto s = AddTabsToStr( str, mTabCounter );

  pStrListPair->second.push_back( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::IncrementTabs()
{
  mTabCounter++;
}
//----------------------------------------------------------------------------------
void IFileGenerator::DecrementTabs()
{
  mTabCounter--;
}
//----------------------------------------------------------------------------------
void IFileGenerator::ClearTabs()
{
  mTabCounter = 0;
}
//----------------------------------------------------------------------------------
std::string IFileGenerator::AddTabsToStr( const std::string& str, int tabCounter )
{
  std::string tabAcculumator;
  for ( auto i = 0; i < tabCounter; i++ )
    tabAcculumator += sTab;
  return tabAcculumator + str;
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddPublicSection()
{
  auto s = "public:";
  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddProtectedSection()
{
  auto s = "protected:";
  Add( s );

}
//----------------------------------------------------------------------------------
void IFileGenerator::AddPrivateSection()
{
  auto s = "private:";
  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddList( const std::list<std::string>& strList )
{
  for ( auto& str : strList )
    Add( str );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddStaticMethodDeclaration( const std::string& retName, const std::string& name, std::list<std::string>& paramList )
{
  std::string str = fmt::format( "static {} {}( ", retName, name );
  str += EnumerateParamToStr( paramList );
  str += " );";
  Add( str );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddMethodImplementationBegin( const std::string& retName, const std::string& className, const std::string& name, std::list<std::string>& paramList )
{
  std::string str = fmt::format( "{} {}::{}( ", retName, className, name );

  str += EnumerateParamToStr( paramList );
  str += " )";
  Add( str );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddCallFunction( const std::string& namespaceFunc, const std::string& funcName, std::list<std::string>& templateList, std::list<std::string>& argList )
{
  std::string namespacePredict;
  if ( namespaceFunc.length() )
    namespacePredict = namespaceFunc + "::";

  std::string str = fmt::format( "{}{}", namespacePredict, funcName );
  auto templ = EnumerateParamToStr( templateList );
  if ( templ.length() )
    str += fmt::format( "<{}>", templ );

  str += "(";
  auto args = EnumerateParamToStr( argList );
  if ( args.length() )
    str += " " + args;

  str += " );";
  Add( str );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddVarDeclaration( const std::string& typeName, const std::string& varName )
{
  auto str = fmt::format( "{} {};", typeName, varName );
  Add( str );
}
//----------------------------------------------------------------------------------
std::string IFileGenerator::EnumerateParamToStr( std::list<std::string>& paramList )
{
  std::string str;
  int cnt = paramList.size();
  int i = 0;
  for ( auto param : paramList )
  {
    str += param;
    if ( i != cnt - 1 )
      str += ", ";
    i++;
  }
  return str;
}
//----------------------------------------------------------------------------------
