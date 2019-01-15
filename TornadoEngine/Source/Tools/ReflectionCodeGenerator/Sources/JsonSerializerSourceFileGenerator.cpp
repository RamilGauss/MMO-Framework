/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "JsonSerializerSourceFileGenerator.h"

using namespace nsReflectionCodeGenerator;

void TJsonSerializerSourceFileGenerator::Work()
{
  auto& jsonSerializer = mConfig->targetForCodeGeneration.implementation.jsonSerializer;

  AddHeader();
  AddTimeHeader();

  AddEmptyLine();
  AddInclude( mConfig->targetForCodeGeneration.implementation.jsonSerializer->fileName + ".h" );
  AddEmptyLine();

  auto namespaceName = jsonSerializer->nameSpaceName;
  if ( namespaceName.length() )
    AddUsingNamespace( namespaceName );

  AddImplementations();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddImplementations()
{
  for ( auto& namespaceTypeInfo : mTypeMng->mNameSpaceTypesMap )
  {
    auto namespaceName = namespaceTypeInfo.first;
    auto& filenameTypeMap = *( namespaceTypeInfo.second.get() );
    for ( auto filenameType : filenameTypeMap )
    {
      auto pTypeInfo = filenameType.second.get();
      AddSerializeMethodImplementation( pTypeInfo );
      AddCommentedLongLine();
      AddDeserializeMethodImplementation( pTypeInfo );
      AddCommentedLongLine();
    }
  }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddSerializeMethodImplementation( TTypeInfo* p )
{
  auto className = mConfig->targetForCodeGeneration.implementation.jsonSerializer->className;
  auto namespaceWithType = p->GetNameSpace() + "::" + p->mName;
  auto strList = GetParamListForSerialize( namespaceWithType );
  AddMethodImplementationBegin( "void", className, sSerialzeMethod, strList);
  AddLeftBrace();
  IncrementTabs();
  DecrementTabs();
  AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddDeserializeMethodImplementation( TTypeInfo* p )
{
  auto className = mConfig->targetForCodeGeneration.implementation.jsonSerializer->className;
  auto namespaceWithType = p->GetNameSpace() + "::" + p->mName;
  auto strList = GetParamListForDeserialize( namespaceWithType );
  AddMethodImplementationBegin( "void", className, sDeserialzeMethod, strList);  
  AddLeftBrace();
  IncrementTabs();
  DecrementTabs();
  AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
