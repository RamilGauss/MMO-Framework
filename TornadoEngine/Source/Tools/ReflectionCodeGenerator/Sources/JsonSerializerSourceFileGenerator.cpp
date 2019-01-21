/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "JsonSerializerSourceFileGenerator.h"
#include "fmt/core.h"
#include "BL_Debug.h"

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
    // найти родителя - TypeInfo
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
void TJsonSerializerSourceFileGenerator::AddPopByMemberInfo( TMemberInfo* pMemberInfo )
{
  switch ( pMemberInfo->mExtendedInfo.mCategory )
  {
    case TMemberTypeExtendedInfo::BuiltIn:
      HandlePopBuiltIn( pMemberInfo );
      break;
    case TMemberTypeExtendedInfo::Vector:
    case TMemberTypeExtendedInfo::List:
      HandlePopArray( pMemberInfo );
      break;
    case TMemberTypeExtendedInfo::Set:
      HandlePopSet( pMemberInfo );
      break;
    case TMemberTypeExtendedInfo::Map:
      HandlePopMap( pMemberInfo );
      break;
    case TMemberTypeExtendedInfo::String:
      AddPopStr( pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::Reflection:
      HandlePopReflection( pMemberInfo );
      break;
    default:
      break;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPush( const std::string& name )
{
  std::list<std::string> argList =
  {
    s_Obj,
    fmt::format( "\"{}\"", name ),
    fmt::format( "{}->{}", sTypeObject, name )
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
  General_AddPushSerArrayOrMap( type, type, name, s_PushSerObjArray );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushSerPtrArray( const std::string& type, const std::string& name )
{
  auto fullType = fmt::format( "{}*", type );
  General_AddPushSerArrayOrMap( type, fullType, name, s_PushSerPtrArray );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushSerSmartPtrArray( const std::string& type, const std::string& smartPtrType, const std::string& name )
{
  auto fullType = fmt::format( "{}{}<{}>", s_STD_, smartPtrType, type );
  General_AddPushSerArrayOrMap( type, fullType, name, s_PushSerSmartPtrArray );
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
    HandlePushBuiltInOrStringSerMap( pMemberInfo );
    return;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandleReflectionForPush( TMemberInfo* pMemberInfo )
{
  auto objName = fmt::format( "{}_obj", pMemberInfo->mName );

  AddVarDeclaration( s_Jobj, objName );
  std::string getAddrOfMember;
  switch ( pMemberInfo->mExtendedInfo.mAccessMethod )
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

  argList =
  {
    s_Obj,
    fmt::format( "\"{}\"", pMemberInfo->mName, objName ),
    fmt::format( "{}", objName )
  };
  AddCallFunction( s_PUM, s_Push, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushMap( const std::string& name )
{
  std::list<std::string> argList =
  {
    s_Obj,
    fmt::format( "\"{}\"", name ),
    fmt::format( "{}->{}", sTypeObject, name )
  };
  std::list<std::string> templList;

  AddCallFunction( s_PUM, s_PushMap, templList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePushBuiltInOrStringSerMap( TMemberInfo* pMemberInfo )
{
  auto& keyType = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
  auto& valueType = pMemberInfo->mExtendedInfo.mTemplateChildArr[1];
  switch ( valueType.mAccessMethod )
  {
    case TMemberTypeExtendedInfo::Object:
      AddPushSerObjMap( valueType.mType, pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::Pointer:
      AddPushSerPtrMap( valueType.mType, pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::SmartPointer:
      AddPushSerSmartPtrMap( valueType.mType, valueType.mSmartPtrType, pMemberInfo->mName );
      break;
    default:
      break;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushSerObjMap( const std::string& type, const std::string& name )
{
  General_AddPushSerArrayOrMap( type, type, name, s_PushSerObjMap );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushSerPtrMap( const std::string& type, const std::string& name )
{
  auto fullType = fmt::format( "{}*", type );
  General_AddPushSerArrayOrMap( type, fullType, name, s_PushSerPtrMap );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPushSerSmartPtrMap( const std::string& type, const std::string& smartPtrType, const std::string& name )
{
  auto fullType = fmt::format( "{}{}<{}>", s_STD_, smartPtrType, type );
  General_AddPushSerArrayOrMap( type, fullType, name, s_PushSerSmartPtrMap );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopBuiltIn( TMemberInfo* pMemberInfo )
{
  if ( pMemberInfo->mExtendedInfo.mType == s_Bool )
    AddPopBool( pMemberInfo->mName );
  else
    AddPopNum( pMemberInfo->mName );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopStr( const std::string& name )
{
  General_AddPop( name, s_PopStr );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopBool( const std::string& name )
{
  General_AddPop( name, s_PopBool );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopNum( const std::string& name )
{
  General_AddPop( name, s_PopNum );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopArray( TMemberInfo* pMemberInfo )
{
  auto& templateInfo = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
  switch ( templateInfo.mCategory )
  {
    case TMemberTypeExtendedInfo::BuiltIn:
      if ( templateInfo.mType == s_Bool )
        AddPopBoolArray( pMemberInfo->mName );
      else
        AddPopNumArray( pMemberInfo->mName, templateInfo.mType );
      break;
    case TMemberTypeExtendedInfo::String:
      AddPopStrArray( pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::Reflection:
      HandlePopReflectionArray( pMemberInfo );
      break;
    default:
      break;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopSet( TMemberInfo* pMemberInfo )
{
  auto& templateInfo = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
  switch ( templateInfo.mCategory )
  {
    case TMemberTypeExtendedInfo::BuiltIn:
      if ( templateInfo.mType == s_Bool )
        AddPopBoolSet( pMemberInfo->mName );
      else
        AddPopNumSet( pMemberInfo->mName, templateInfo.mType );
      break;
    case TMemberTypeExtendedInfo::String:
      AddPopStrSet( pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::Reflection:
      HandlePopReflectionSet( pMemberInfo );
      break;
    default:
      break;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopMap( TMemberInfo* pMemberInfo )
{
  auto& templateList = pMemberInfo->mExtendedInfo.mTemplateChildArr;
  auto& keyInfo = templateList[0];
  auto& valueInfo = templateList[1];

  auto keyCategory = keyInfo.mCategory;
  auto valueCategory = valueInfo.mCategory;
  if ( ( keyCategory == TMemberTypeExtendedInfo::BuiltIn || keyCategory == TMemberTypeExtendedInfo::String ) &&
    ( valueCategory == TMemberTypeExtendedInfo::BuiltIn || valueCategory == TMemberTypeExtendedInfo::String ) )
  {
    HandlePopBuiltInOrStringMap( pMemberInfo );
    return;
  }

  if ( ( keyCategory == TMemberTypeExtendedInfo::BuiltIn || keyCategory == TMemberTypeExtendedInfo::String ) &&
    valueCategory == TMemberTypeExtendedInfo::Reflection )
  {
    HandlePopBuiltInOrStringSerMap( pMemberInfo );
    return;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopReflection( TMemberInfo* pMemberInfo )
{
  auto typeName = pMemberInfo->mExtendedInfo.mType;
  auto pTypeInfo = mTypeMng->FindTypeInfo( typeName );
  if ( pTypeInfo == nullptr )
    return;

  auto jsonName = fmt::format( "{}_{}", pMemberInfo->mName, s_Json );
  auto expression = fmt::format( "auto& {} = {}[\"{}\"];", jsonName, s_Json, pMemberInfo->mName );
  Add( expression );

  std::string checkForNewObject;
  std::string newObject;
  std::string getAddrOfMember;
  switch ( pMemberInfo->mExtendedInfo.mAccessMethod )
  {
    case TMemberTypeExtendedInfo::Object:
      getAddrOfMember = fmt::format( "&({}->{})", sTypeObject, pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::Pointer:
      getAddrOfMember = fmt::format( "{}->{}", sTypeObject, pMemberInfo->mName );

      checkForNewObject = fmt::format( "if( {}->{} == nullptr )", sTypeObject, pMemberInfo->mName );
      newObject = fmt::format( "{}->{} = new {}();", sTypeObject, pMemberInfo->mName, pTypeInfo->GetTypeNameWithNameSpace() );
      break;
    case TMemberTypeExtendedInfo::SmartPointer:
      getAddrOfMember = fmt::format( "{}->{}.get()", sTypeObject, pMemberInfo->mName );
      checkForNewObject = fmt::format( "if( {}->{}.get() == nullptr )", sTypeObject, pMemberInfo->mName );
      newObject = fmt::format( "{}->{}.reset( new {}() );", sTypeObject, pMemberInfo->mName, pTypeInfo->GetTypeNameWithNameSpace() );
      break;
    default:
      break;
  }

  if ( checkForNewObject.length() )
  {
    Add( checkForNewObject );
    IncrementTabs();
    Add( newObject );
    DecrementTabs();
  }

  std::list<std::string> argList =
  {
    getAddrOfMember,
    fmt::format( "{}", jsonName )
  };
  std::list<std::string> templateList;

  AddCallFunction( "", sDeserialzeMethod, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopNumArray( const std::string& name, const std::string& type )
{
  General_AddPopArrayOrSet( name, type, s_PopNumArray );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopBoolArray( const std::string& name )
{
  General_AddPopArrayOrSet( name, "", s_PopBoolArray );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopStrArray( const std::string& name )
{
  General_AddPopArrayOrSet( name, "", s_PopStrArray );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopNumSet( const std::string& name, const std::string& type )
{
  General_AddPopArrayOrSet( name, type, s_PopNumSet );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopBoolSet( const std::string& name )
{
  General_AddPopArrayOrSet( name, "", s_PopBoolSet );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopStrSet( const std::string& name )
{
  General_AddPopArrayOrSet( name, "", s_PopStrSet );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopReflectionArray( TMemberInfo* pMemberInfo )
{
  auto& extMemberInfo = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
  auto typeName = extMemberInfo.mType;
  auto pTypeInfo = mTypeMng->FindTypeInfo( typeName );
  if ( pTypeInfo == nullptr )
    return;
  auto keyType = pTypeInfo->GetTypeNameWithNameSpace();

  std::string fullType;
  std::string methodName;
  std::string retNewSmartPtrFunc;
  switch ( extMemberInfo.mAccessMethod )
  {
    case TMemberTypeExtendedInfo::Object:
      methodName = s_PopSerObjArray;
      break;
    case TMemberTypeExtendedInfo::Pointer:
      methodName = s_PopSerPtrArray;
      break;
    case TMemberTypeExtendedInfo::SmartPointer:
      methodName = s_PopSerSmartPtrArray;
      fullType = fmt::format( "{}{}<{}>", s_STD_,extMemberInfo.mSmartPtrType ,keyType );
      retNewSmartPtrFunc = fmt::format( "[](){{ return {}( new {}() );}}", fullType, keyType );
      break;
    default:
      break;
  }
  General_AddPopSerArrayOrMap( keyType, "", keyType, fullType, pMemberInfo->mName, methodName, retNewSmartPtrFunc );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopReflectionSet( TMemberInfo* pMemberInfo )
{
  auto str = fmt::format( "Prohibition of use of type {}!", pMemberInfo->mTypeName );
  BL_MessageBug( str.data() );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopBuiltInOrStringMap( TMemberInfo* pMemberInfo )
{
  auto name = pMemberInfo->mName;
  auto& templateList = pMemberInfo->mExtendedInfo.mTemplateChildArr;
  auto& keyInfo = templateList[0];
  auto& valueInfo = templateList[1];

  auto keyCategory = keyInfo.mCategory;
  auto valueCategory = valueInfo.mCategory;

  if ( keyCategory == TMemberTypeExtendedInfo::BuiltIn )
  {
    if ( valueCategory == TMemberTypeExtendedInfo::BuiltIn )
    {
      if ( valueInfo.mType == s_Bool )
        AddPopNumBoolMap( name );
      else
        AddPopNumNumMap( name );
    }
    if ( valueCategory == TMemberTypeExtendedInfo::String )
      AddPopNumStrMap( name );
  }
  else if ( keyCategory == TMemberTypeExtendedInfo::String )
  {
    if ( valueCategory == TMemberTypeExtendedInfo::BuiltIn )
    {
      if ( valueInfo.mType == s_Bool )
        AddPopStrBoolMap( name );
      else
        AddPopStrNumMap( name );
    }
    if ( valueCategory == TMemberTypeExtendedInfo::String )
      AddPopStrStrMap( name );
  }
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::HandlePopBuiltInOrStringSerMap( TMemberInfo* pMemberInfo )
{
  auto& keyExtMemberInfo = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
  auto& valueExtMemberInfo = pMemberInfo->mExtendedInfo.mTemplateChildArr[1];
  auto pValueTypeInfo = mTypeMng->FindTypeInfo( valueExtMemberInfo.mType );
  if ( pValueTypeInfo == nullptr )
    return;
  auto valueType = pValueTypeInfo->GetTypeNameWithNameSpace();

  std::string fullType;
  std::string methodName;
  std::string retNewSmartPtrFunc;
  switch ( valueExtMemberInfo.mAccessMethod )
  {
    case TMemberTypeExtendedInfo::Object:
      if ( keyExtMemberInfo.mCategory == TMemberTypeExtendedInfo::String )
        methodName = s_PopStrSerObjMap;
      else
        methodName = s_PopNumSerObjMap;
      break;
    case TMemberTypeExtendedInfo::Pointer:
      if ( keyExtMemberInfo.mCategory == TMemberTypeExtendedInfo::String )
        methodName = s_PopStrSerPtrMap;
      else
        methodName = s_PopNumSerPtrMap;
      break;
    case TMemberTypeExtendedInfo::SmartPointer:
      if( keyExtMemberInfo.mCategory == TMemberTypeExtendedInfo::String )
        methodName = s_PopStrSerSmartPtrMap;
      else
        methodName = s_PopNumSerSmartPtrMap;
      fullType = fmt::format( "{}{}<{}>", s_STD_, valueExtMemberInfo.mSmartPtrType, valueType );
      retNewSmartPtrFunc = fmt::format( "[](){{ return {}( new {}() );}}", fullType, valueType );
      break;
    default:
      break;
  }
  std::string keyType;
  if ( keyExtMemberInfo.mCategory == TMemberTypeExtendedInfo::BuiltIn )
    keyType = keyExtMemberInfo.mType;

  General_AddPopSerArrayOrMap( keyType, valueType, valueType, fullType, pMemberInfo->mName, methodName, retNewSmartPtrFunc );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopNumBoolMap( const std::string& name )
{
  AddPopMap( s_PopNumBoolMap, name );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopNumNumMap( const std::string& name )
{
  AddPopMap( s_PopNumNumMap, name );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopNumStrMap( const std::string& name )
{
  AddPopMap( s_PopNumStrMap, name );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopStrBoolMap( const std::string& name )
{
  AddPopMap( s_PopStrBoolMap, name );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopStrNumMap( const std::string& name )
{
  AddPopMap( s_PopStrNumMap, name );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopStrStrMap( const std::string& name )
{
  AddPopMap( s_PopStrStrMap, name );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::AddPopMap( const std::string& methodName, const std::string& name )
{
  std::list<std::string> argList =
  {
    s_Json,
    fmt::format( "\"{}\"", name ),
    fmt::format( "{}->{}", sTypeObject, name ),
  };
  std::list<std::string> templateList;

  AddCallFunction( s_POM, methodName, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::General_AddPushSerArrayOrMap( const std::string& type, const std::string& fullType,
  const std::string& name, const std::string& methodName )
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
  std::list<std::string> templateList = {type, fullType};

  AddCallFunction( s_PUM, methodName, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::General_AddPop( const std::string& name, const std::string& methodName )
{
  std::list<std::string> argList =
  {
    s_Json,
    fmt::format( "\"{}\"", name ),
    fmt::format( "{}->{}", sTypeObject, name )
  };
  std::list<std::string> templateList;

  AddCallFunction( s_POM, methodName, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------    
void TJsonSerializerSourceFileGenerator::General_AddPopArrayOrSet( const std::string& name, const std::string& type, const std::string& methodName )
{
  std::list<std::string> argList =
  {
    s_Json,
    fmt::format( "\"{}\"", name ),
    fmt::format( "{}->{}", sTypeObject, name )
  };
  std::list<std::string> templateList;
  if ( type.length() > 0 )
    templateList = {type};

  AddCallFunction( s_POM, methodName, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TJsonSerializerSourceFileGenerator::General_AddPopSerArrayOrMap( const std::string& keyType, const std::string& valueType,
  const std::string& typeForLambda,
  const std::string& fullType, const std::string& name, const std::string& methodName, const std::string& retNewSmartPtrFunc )
{
  auto strList = GetParamListForDeserialize( typeForLambda );
  auto paramStr = EnumerateParamToStr( strList );

  std::list<std::string> argList =
  {
    s_Json,
    fmt::format( "\"{}\"", name ),
    fmt::format( "{}->{}", sTypeObject, name ),
    fmt::format( "[]( {0} ) {{ {1}( {2}, {3} ); }}", paramStr, sDeserialzeMethod, sTypeObject, s_Json )
  };

  if ( retNewSmartPtrFunc.length() )
    argList.push_back( retNewSmartPtrFunc );

  std::list<std::string> templateList;
  if ( keyType.length() )
    templateList.push_back( keyType );
  if( valueType.length() )
    templateList.push_back( valueType );
  if ( fullType.length() )
    templateList.push_back( fullType );

  AddCallFunction( s_POM, methodName, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
