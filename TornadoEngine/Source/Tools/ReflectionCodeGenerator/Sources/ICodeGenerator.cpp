/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "ICodeGenerator.h"
#include "SingletonManager.h"
#include "ConfigContainer.h"
#include <filesystem>
#include "fmt/core.h"

namespace fs = std::filesystem;
using namespace nsReflectionCodeGenerator;

ICodeGenerator::ICodeGenerator( std::string name )
{
  mName = name;
}
//----------------------------------------------------------------------------------
void ICodeGenerator::Init( TPairList& result )
{
  mPairList = &result;

  fmt::print( "Begin code generator {}\n", mName );
}
//----------------------------------------------------------------------------------
std::string ICodeGenerator::GeneratedFileFullPath( std::string fileNameWithExt )
{
  fs::path dir( mConfig->targetForCodeGeneration.directory );
  auto path = dir.append( fileNameWithExt );
  return path.string();
}
//----------------------------------------------------------------------------------

