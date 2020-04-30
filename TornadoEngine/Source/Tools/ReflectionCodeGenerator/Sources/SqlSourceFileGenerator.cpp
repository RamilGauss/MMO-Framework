/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "SqlSourceFileGenerator.h"
#include "fmt/core.h"
#include "BL_Debug.h"

using namespace nsReflectionCodeGenerator;

void TSqlSourceFileGenerator::Work()
{
  AddHeader();
  AddTimeHeader();

  AddInclude( mSqlConfig->fileName + ".h" );
  AddInclude( "fmt/core.h" );
  //AddInclude( "JsonPopMaster.h" );
  //AddInclude( "JsonPushMaster.h" );
  AddEmptyLine();

  auto namespaceName = mSqlConfig->nameSpaceName;
  if ( namespaceName.length() )
    AddUsingNamespace( namespaceName );

  AddEmptyLine();

  //AddUsing( s_POM + " = TJsonPopMaster" );
  //AddUsing( s_PUM + " = TJsonPushMaster" );

  AddEmptyLine();
  //AddImplementations();
}
//-----------------------------------------------------------------------------------------------------------
