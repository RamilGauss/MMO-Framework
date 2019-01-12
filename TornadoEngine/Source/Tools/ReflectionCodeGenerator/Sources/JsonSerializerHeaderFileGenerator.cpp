/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "JsonSerializerHeaderFileGenerator.h"
#include <set>

using namespace nsReflectionCodeGenerator;

void TJsonSerializerHeaderFileGenerator::Work()
{
  auto& jsonSerializer = mConfig->targetForCodeGeneration.implementation.jsonSerializer;

  AddHeader();
  AddTimeHeader();

  AddPragmaOnce();
  AddEmptyLine();
  AddStandartInclude( "string" );
  AddInclude( "JsonMaster.h" );
  AddInclude( "json11.h" );
  AddInclude( mConfig->targetForCodeGeneration.includeListFileName + ".h" );
  AddEmptyLine();

  auto namespaceName = jsonSerializer->nameSpaceName;
  if ( namespaceName.length() )
    AddNamespaceBegin( namespaceName );

  IncrementTabs();

  AddClassBegin( jsonSerializer->exportDeclaration, jsonSerializer->className );

  AddPublicSection();

  AddClassEnd();

  DecrementTabs();

  if ( namespaceName.length() )
    AddNamespaceEnd();
}
//-----------------------------------------------------------------------------------
