/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include "SqlGenerator.h"
#include "SqlHeaderFileGenerator.h"
#include "SqlSourceFileGenerator.h"

using namespace nsReflectionCodeGenerator;

void TSqlGenerator::Work()
{
  GenerateHeader();
  GenerateSource();
}
//----------------------------------------------------------------------------------
void TSqlGenerator::GenerateHeader()
{
  TSqlHeaderFileGenerator fileGenerator;

  mPairList->push_back( TStrListPair() );

  auto& pair = mPairList->back();

  pair.first = GeneratedFileFullPath( mConfig->targetForCodeGeneration.implementation.sql->fileName + ".h" );

  fileGenerator.Init( pair );
  fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void TSqlGenerator::GenerateSource()
{
  TSqlSourceFileGenerator fileGenerator;

  mPairList->push_back( TStrListPair() );

  auto& pair = mPairList->back();

  pair.first = GeneratedFileFullPath( mConfig->targetForCodeGeneration.implementation.sql->fileName + ".cpp" );

  fileGenerator.Init( pair );
  fileGenerator.Work();
}
//----------------------------------------------------------------------------------

