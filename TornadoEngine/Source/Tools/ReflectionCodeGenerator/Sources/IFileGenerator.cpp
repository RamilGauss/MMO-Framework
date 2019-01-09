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
  for( auto& str : s_Header )
    Add( str );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddTimeHeader()
{
  auto s = s_TimeHeader;

  s = fmt::format( s, nsProgramInfo::NAME, nsProgramInfo::VERSION, nsProgramInfo::COUNTER_BUILD, ht_GetTimeStr() );

  Add( s );
}
//----------------------------------------------------------------------------------
void IFileGenerator::AddEmptyLine()
{
  auto s = "";
  Add( s );
}
//----------------------------------------------------------------------------------
void nsReflectionCodeGenerator::IFileGenerator::AddPragmaOnce()
{
  auto s = "#pragma once";
  Add( s );
}
//----------------------------------------------------------------------------------
void nsReflectionCodeGenerator::IFileGenerator::AddInclude( const std::string& fileName )
{
  auto s = fmt::format( "#include \"{}\"", fileName );
  Add( s );
}
//----------------------------------------------------------------------------------
void nsReflectionCodeGenerator::IFileGenerator::Add( const std::string& str )
{
  pStrListPair->second.push_back( str );
}
//----------------------------------------------------------------------------------