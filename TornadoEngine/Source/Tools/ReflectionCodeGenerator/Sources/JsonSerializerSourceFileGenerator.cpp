/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "JsonSerializerSourceFileGenerator.h"
#include "fmt/core.h"

using namespace nsReflectionCodeGenerator;

void TJsonSerializerSourceFileGenerator::Work()
{
  auto& jsonSerializer = mConfig->targetForCodeGeneration.implementation.jsonSerializer;

  AddHeader();
  AddTimeHeader();

  AddEmptyLine();
  AddInclude( mConfig->targetForCodeGeneration.implementation.jsonSerializer->fileName + ".h" );
  AddInclude( "fmt/core.h" );
  AddInclude( "JsonPopMaster.h" );
  AddInclude( "JsonPushMaster.h" );
  AddEmptyLine();

  auto namespaceName = jsonSerializer->nameSpaceName;
  if ( namespaceName.length() )
    AddUsingNamespace( namespaceName );

  AddEmptyLine();

  AddUsing( s_POM + " = TJsonPopMaster" );
  AddUsing( s_PUM + " = TJsonPushMaster" );

  AddEmptyLine();
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
  AddMethodImplementationBegin( "void", className, sSerialzeMethod, strList );
  AddLeftBrace();
  IncrementTabs();

  AddCallingMethodForParent( p, [this]( const std::string& s ) {AddCallingSerializeParent( s ); } );

  AddCallingMethod( p, [this]( TMemberInfo* mi ) {AddPushByMemberInfo( mi ); } );

  DecrementTabs();
  AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddDeserializeMethodImplementation( TTypeInfo* p )
{
  auto className = mConfig->targetForCodeGeneration.implementation.jsonSerializer->className;
  auto namespaceWithType = p->GetNameSpace() + "::" + p->mName;
  auto strList = GetParamListForDeserialize( namespaceWithType );
  AddMethodImplementationBegin( "void", className, sDeserialzeMethod, strList );
  AddLeftBrace();
  IncrementTabs();

  AddCallingMethodForParent( p, [this]( const std::string& s ) { AddCallingDeserializeParent( s ); } );

  AddCallingMethod( p, [this]( TMemberInfo* mi ) {AddPopByMemberInfo( mi ); } );

  DecrementTabs();
  AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddCallingMethodForParent( TTypeInfo* p, std::function<void( const std::string& )> func )
{
  for ( auto& inheritanceInfo : p->mInheritanceVec )
  {
    if ( inheritanceInfo.mInheritanceAccessLevel != TMemberInfo::ePublic )
      continue;
    func( p->GetNameSpace() + "::" + inheritanceInfo.mParentTypeName );
  }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddCallingMethod( TTypeInfo* p, std::function<void( TMemberInfo* )> func )
{
  auto fit = p->mMemberMap.find( TMemberInfo::AccessLevel::ePublic );
  if ( fit != p->mMemberMap.end() )
    for ( auto memberInfo : fit->second )
      func( memberInfo.get() );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushByMemberInfo( TMemberInfo* memberInfo )
{
  switch ( memberInfo->mExtendedInfo.mCategory )
  {
    case TMemberTypeExtendedInfo::BuiltIn:
    case TMemberTypeExtendedInfo::String:
      AddPush( memberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::Vector:
    case TMemberTypeExtendedInfo::List:
    case TMemberTypeExtendedInfo::Set:
      HandleArrayForPush( memberInfo );
      break;
    case TMemberTypeExtendedInfo::Map:
      break;
    case TMemberTypeExtendedInfo::Reflection:
      break;
    default:
      break;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopByMemberInfo( TMemberInfo* memberInfo )
{
  switch ( memberInfo->mExtendedInfo.mCategory )
  {
    case TMemberTypeExtendedInfo::BuiltIn:
      //AddPush( memberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::Vector:
      break;
    case TMemberTypeExtendedInfo::List:
      break;
    case TMemberTypeExtendedInfo::Set:
      break;
    case TMemberTypeExtendedInfo::Map:
      break;
    case TMemberTypeExtendedInfo::String:
      break;
    case TMemberTypeExtendedInfo::Reflection:
      break;
    default:
      break;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPush( const std::string& objectName )
{
  auto s = fmt::format( "{0}Push( {1}, \"{2}\", p->{2} );", s_PUM_, s_Obj, objectName );
  Add( s );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddCallingSerializeParent( const std::string& parentTypeName )
{
  auto str = fmt::format( "{}( ({}*){}, {});", sSerialzeMethod, parentTypeName, sTypeObject, s_Obj );
  Add( str );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddCallingDeserializeParent( const std::string& parentTypeName )
{
  auto str = fmt::format( "{}( ({}*){}, {});", sDeserialzeMethod, parentTypeName, sTypeObject, s_Json );
  Add( str );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandleArrayForPush( TMemberInfo* memberInfo )
{
  auto& templateType = memberInfo->mExtendedInfo.mTemplateChildArr[0];
  auto templateCategory = templateType.mCategory;
  if ( templateCategory == TMemberTypeExtendedInfo::BuiltIn || templateCategory == TMemberTypeExtendedInfo::String )
    AddPush( memberInfo->mName );
  else if ( templateCategory == TMemberTypeExtendedInfo::Reflection )
  {
    switch ( templateType.mAccessMethod )
    {
      case TMemberTypeExtendedInfo::Object:
        AddPushSerObjArray( templateType.mType, memberInfo->mName );
        break;
      case TMemberTypeExtendedInfo::Pointer:
        AddPushSerPtrArray( templateType.mType, memberInfo->mName );
        break;
      case TMemberTypeExtendedInfo::SmartPointer:
        AddPushSerSmartPtrArray();
        break;
      default:
        break;
    }
  }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushSerObjArray( const std::string& type, const std::string& name )
{
  auto strList = GetParamListForSerialize( type );
  auto paramStr = EnumerateParamToStr( strList );
  auto str = fmt::format( "{0}{1}<{2}, {2}>( {3}, \"{4}\", {5}->{4}, []( {6} ) {{ {7}( {5}, {3} ); }} );", 
    s_PUM_, "PushSerObjArray", type, s_Obj, name, sTypeObject, paramStr, sSerialzeMethod );
  Add( str );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushSerPtrArray( const std::string& type, const std::string& name )
{

}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushSerSmartPtrArray()
{

}
//-----------------------------------------------------------------------------------------------------------
