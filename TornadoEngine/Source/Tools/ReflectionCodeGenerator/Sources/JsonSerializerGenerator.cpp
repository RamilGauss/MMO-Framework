/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "JsonSerializerGenerator.h"
#include "JsonSerializerHeaderFileGenerator.h"

using namespace nsReflectionCodeGenerator;

void TJsonSerializerGenerator::Work()
{
  GenerateHeader();
  GenerateSource();
}
//----------------------------------------------------------------------------------
void TJsonSerializerGenerator::GenerateHeader()
{
  TJsonSerializerHeaderFileGenerator fileGenerator;

  mPairList->push_back( TStrListPair() );

  auto& pair = mPairList->back();

  pair.first = GeneratedFileFullPath( mConfig->targetForCodeGeneration.implementation.jsonSerializer->fileName + ".h" );

  fileGenerator.Init( pair );
  fileGenerator.Work();
}
//----------------------------------------------------------------------------------
void nsReflectionCodeGenerator::TJsonSerializerGenerator::GenerateSource()
{

}
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------