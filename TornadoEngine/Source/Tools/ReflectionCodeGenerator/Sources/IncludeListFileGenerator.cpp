/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "IncludeListFileGenerator.h"
#include <set>

using namespace nsReflectionCodeGenerator;

void TIncludeListFileGenerator::Work()
{
  AddHeader(mConfig->targetForCodeGeneration.header);
  AddTimeHeader();

  AddPragmaOnce();
  AddEmptyLine();
  AddIncludes();
}
//-----------------------------------------------------------------------------------
void TIncludeListFileGenerator::AddIncludes()
{
  std::set<std::string> fileNameSet;

  for ( auto& nameSpaceName_Types : mTypeMng->mNameSpaceTypesMap )
  {
    auto types = nameSpaceName_Types.second.get();
    for ( auto name_typeInfo : types [0] )
    {
      auto& typeInfo = name_typeInfo.second;
      fileNameSet.insert( typeInfo->mFileName );
    }
  }
  for(auto& fileName : fileNameSet )
    AddInclude( fileName );
}
//-----------------------------------------------------------------------------------