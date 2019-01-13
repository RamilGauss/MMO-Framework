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

  AddList( s_JsonDecl );

  AddPrivateSection();

  AddDeclarations();

  AddClassEnd();

  DecrementTabs();

  if ( namespaceName.length() )
    AddNamespaceEnd();
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
      auto typeName = filenameType.second->mName;
      auto namespaceWithType = namespaceName + "::" + typeName;
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
  std::list<std::string> strList =
  {
    namespaceWithType + "* p",
    "Jobj& obj"
  };
  AddStaticMethodDeclaration( sSerialzeMethod, "void", strList );
}
//-----------------------------------------------------------------------------------
void TJsonSerializerHeaderFileGenerator::AddDeserializeMethodDeclaration( std::string& namespaceWithType )
{
  // D - Type* p, const json11::Json& json 
  std::list<std::string> strList =
  {
    namespaceWithType + "* p",
    "const json11::Json& json"
  };
  AddStaticMethodDeclaration( sDeserialzeMethod, "void", strList );
}
//-----------------------------------------------------------------------------------

