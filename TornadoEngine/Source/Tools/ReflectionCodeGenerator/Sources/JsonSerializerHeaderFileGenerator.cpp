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
  {
    AddNamespaceBegin( namespaceName );
    IncrementTabs();
  }

  AddClassBegin( jsonSerializer->exportDeclaration, jsonSerializer->className );

  AddList( s_JsonDecl );

  AddPrivateSection();

  AddDeclarations();

  AddClassEnd();

  AddList( s_JsonImplentation );

  if ( namespaceName.length() )
  {
    DecrementTabs();
    AddNamespaceEnd();
  }
}
//-----------------------------------------------------------------------------------
void TJsonSerializerHeaderFileGenerator::AddDeclarations()
{
  IncrementTabs();
  for ( auto& namespaceTypeInfo : mTypeMng->mNameSpaceTypesMap )
  {
    auto namespaceName = namespaceTypeInfo.first;
    auto& filenameTypeMap = *( namespaceTypeInfo.second.get() );
    for ( auto filenameType : filenameTypeMap )
    {
      auto namespaceWithType = filenameType.second->GetTypeNameWithNameSpace();
      AddSerializeMethodDeclaration( namespaceWithType );
      AddDeserializeMethodDeclaration( namespaceWithType );
      AddEmptyLine();
    }
  }
  DecrementTabs();
}
//-----------------------------------------------------------------------------------
void TJsonSerializerHeaderFileGenerator::AddSerializeMethodDeclaration( std::string& namespaceWithType )
{
  // S - Type* p, Jobj& obj
  auto strList = GetParamListForSerialize( namespaceWithType );
  AddStaticMethodDeclaration( "void", sSerialzeMethod, strList );
}
//-----------------------------------------------------------------------------------
void TJsonSerializerHeaderFileGenerator::AddDeserializeMethodDeclaration( std::string& namespaceWithType )
{
  // D - Type* p, const json11::Json& json 
  auto strList = GetParamListForDeserialize( namespaceWithType );
  AddStaticMethodDeclaration( "void", sDeserialzeMethod, strList );
}
//-----------------------------------------------------------------------------------

