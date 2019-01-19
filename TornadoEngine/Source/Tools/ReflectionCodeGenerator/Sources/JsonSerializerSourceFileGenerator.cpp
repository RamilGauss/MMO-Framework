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
  auto namespaceWithType = p->GetTypeNameWithNameSpace();
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
  auto namespaceWithType = p->GetTypeNameWithNameSpace();
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
    // TODO: найти родителя - TypeInfo
    auto pParentInfo = mTypeMng->FindTypeInfo( inheritanceInfo.mParentTypeName );
    if ( pParentInfo == nullptr )
      continue;
    func( pParentInfo->GetTypeNameWithNameSpace() );
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
void TJsonSerializerSourceFileGenerator::AddPushByMemberInfo( TMemberInfo* pMemberInfo )
{
  switch ( pMemberInfo->mExtendedInfo.mCategory )
  {
    case TMemberTypeExtendedInfo::BuiltIn:
    case TMemberTypeExtendedInfo::String:
      AddPush( pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::Vector:
    case TMemberTypeExtendedInfo::List:
    case TMemberTypeExtendedInfo::Set:
      HandleArrayForPush( pMemberInfo );
      break;
    case TMemberTypeExtendedInfo::Map:
      HandleMapForPush( pMemberInfo );
      break;
    case TMemberTypeExtendedInfo::Reflection:
      HandleReflectionForPush( pMemberInfo );
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
  std::list<std::string> argList =
  {
    s_Obj,
    fmt::format( "\"{}\"", objectName ),
    fmt::format( "{}->{}", sTypeObject, objectName )
  };
  std::list<std::string> templateList;

  AddCallFunction( s_PUM, s_Push, templateList, argList );
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
void TJsonSerializerSourceFileGenerator::HandleArrayForPush( TMemberInfo* pMemberInfo )
{
  auto& templateType = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
  auto templateCategory = templateType.mCategory;
  if ( templateCategory == TMemberTypeExtendedInfo::BuiltIn || templateCategory == TMemberTypeExtendedInfo::String )
    AddPush( pMemberInfo->mName );
  else if ( templateCategory == TMemberTypeExtendedInfo::Reflection )
  {
    switch ( templateType.mAccessMethod )
    {
      case TMemberTypeExtendedInfo::Object:
        AddPushSerObjArray( templateType.mType, pMemberInfo->mName );
        break;
      case TMemberTypeExtendedInfo::Pointer:
        AddPushSerPtrArray( templateType.mType, pMemberInfo->mName );
        break;
      case TMemberTypeExtendedInfo::SmartPointer:
        AddPushSerSmartPtrArray( templateType.mType, templateType.mSmartPtrType, pMemberInfo->mName );
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

  std::list<std::string> argList =
  {
    s_Obj,
    fmt::format( "\"{}\"", name ),
    fmt::format( "{}->{}", sTypeObject, name ),
    fmt::format( "[]( {0} ) {{ {1}( {2}, {3} ); }}", paramStr, sSerialzeMethod, sTypeObject, s_Obj )
  };
  std::list<std::string> templateList = {type, type};

  AddCallFunction( s_PUM, s_PushSerObjArray, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushSerPtrArray( const std::string& type, const std::string& name )
{
  auto strList = GetParamListForSerialize( type );
  auto paramStr = EnumerateParamToStr( strList );

  std::list<std::string> argList =
  {
    s_Obj,
    fmt::format( "\"{}\"", name ),
    fmt::format( "{}->{}", sTypeObject, name ),
    fmt::format( "[]( {0} ) {{ {1}( {2}, {3} ); }}", paramStr, sSerialzeMethod, sTypeObject, s_Obj )
  };
  std::list<std::string> templateList = {type, type + "*"};

  AddCallFunction( s_PUM, s_PushSerPtrArray, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushSerSmartPtrArray( const std::string& type, const std::string& smartPtrType, const std::string& name )
{
  auto fullType = fmt::format( "{}{}<{}>", s_STD_, smartPtrType, type );

  auto strList = GetParamListForSerialize( type );
  auto paramStr = EnumerateParamToStr( strList );

  std::list<std::string> argList =
  {
    s_Obj,
    fmt::format( "\"{}\"", name ),
    fmt::format( "{}->{}", sTypeObject, name ),
    fmt::format( "[]( {0} ) {{ {1}( {2}, {3} ); }}", paramStr, sSerialzeMethod, sTypeObject, s_Obj )
  };
  std::list<std::string> templateList = {type, fullType};

  AddCallFunction( s_PUM, s_PushSerSmartPtrArray, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandleMapForPush( TMemberInfo* pMemberInfo )
{
  auto& templateList = pMemberInfo->mExtendedInfo.mTemplateChildArr;
  auto& keyInfo = templateList[0];
  auto& valueInfo = templateList[1];

  auto keyCategory = keyInfo.mCategory;
  auto valueCategory = valueInfo.mCategory;
  if ( ( keyCategory == TMemberTypeExtendedInfo::BuiltIn || keyCategory == TMemberTypeExtendedInfo::String ) &&
    ( valueCategory == TMemberTypeExtendedInfo::BuiltIn || valueCategory == TMemberTypeExtendedInfo::String ) )
  {
    AddPushMap( pMemberInfo->mName );
    return;
  }

  if ( ( keyCategory == TMemberTypeExtendedInfo::BuiltIn || keyCategory == TMemberTypeExtendedInfo::String ) &&
    valueCategory == TMemberTypeExtendedInfo::Reflection )
  {
    HandleSerMap( pMemberInfo );
    return;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandleReflectionForPush( TMemberInfo* pMemberInfo )
{
  auto objName = fmt::format( "{}_obj", pMemberInfo->mName );

  AddVarDeclaration( s_Jobj, objName );
  std::string getAddrOfMember;
  switch( pMemberInfo->mExtendedInfo.mAccessMethod )
  {
    case TMemberTypeExtendedInfo::Object:
      getAddrOfMember = fmt::format( "&({}->{})", sTypeObject, pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::Pointer:
      getAddrOfMember = fmt::format( "{}->{}", sTypeObject, pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::SmartPointer:
      getAddrOfMember = fmt::format( "{}->{}.get()", sTypeObject, pMemberInfo->mName );
      break;
    default:
      break;
  }

  std::list<std::string> argList = {getAddrOfMember, objName};
  std::list<std::string> templateList;

  AddCallFunction( "", sSerialzeMethod, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushMap( const std::string& objectName )
{
  std::list<std::string> argList =
  {
    s_Obj,
    fmt::format( "\"{}\"", objectName ),
    fmt::format( "{}->{}", sTypeObject, objectName )
  };
  std::list<std::string> templList;

  AddCallFunction( s_PUM, s_PushMap, templList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandleSerMap( TMemberInfo* pMemberInfo )
{
  //std::list<std::string> argList =
  //{
  //  s_Obj,
  //  fmt::format( "\"{}\"", objectName ),
  //  fmt::format( "{}->{}", sTypeObject, objectName )
  //};
  //std::list<std::string> templList;

  //AddCallFunction( s_PUM, s_PushMap, templList, argList );
}
//-----------------------------------------------------------------------------------------------------------
