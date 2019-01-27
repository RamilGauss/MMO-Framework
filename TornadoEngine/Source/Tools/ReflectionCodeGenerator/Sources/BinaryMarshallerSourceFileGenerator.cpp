/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BinaryMarshallerSourceFileGenerator.h"

using namespace nsReflectionCodeGenerator;

void TBinaryMarshallerSourceFileGenerator::Work()
{
  auto& binaryMarshaller = mConfig->targetForCodeGeneration.implementation.binaryMarshaller;

  AddHeader();
  AddTimeHeader();

  AddInclude( binaryMarshaller->fileName + ".h" );
  AddInclude( binaryMarshaller->unpackHandler.fileName + ".h" );
  AddEmptyLine();

  auto namespaceName = binaryMarshaller->nameSpaceName;
  if ( namespaceName.length() )
    AddUsingNamespace( namespaceName );

  auto namespaceUnpackHandler = binaryMarshaller->unpackHandler.nameSpaceName;
  if ( namespaceName != namespaceUnpackHandler &&
    namespaceUnpackHandler.length() )
    AddUsingNamespace( namespaceUnpackHandler );

  AddEmptyLine();

  AddList( s_BinaryImplementation );
  AddCommentedLongLine();

  AddPackImplentation();
  AddImplementations();
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPackImplentation()
{
  auto s = fmt::format( "void {}::{}( char* packedData, int size )", mBinaryMarshaller->className, s_Unpack );
  Add( s );
  AddLeftBrace();
  IncrementTabs();

  s = fmt::format( "auto type = {}( packedData, size );", s_PrepareForUnpackPopMaster );
  Add( s );
  Add( "switch( type )" );
  AddLeftBrace();
  IncrementTabs();

  for ( auto& namespaceTypeInfo : mTypeMng->mNameSpaceTypesMap )
  {
    auto namespaceName = namespaceTypeInfo.first;
    auto& filenameTypeMap = *( namespaceTypeInfo.second.get() );
    for ( auto filenameType : filenameTypeMap )
    {
      auto p = filenameType.second.get();
      AddCase( p );
    }
  }

  DecrementTabs();
  AddRightBrace();

  DecrementTabs();
  AddRightBrace();

  AddCommentedLongLine();
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddImplementations()
{
  for ( auto& namespaceTypeInfo : mTypeMng->mNameSpaceTypesMap )
  {
    auto namespaceName = namespaceTypeInfo.first;
    auto& filenameTypeMap = *( namespaceTypeInfo.second.get() );
    for ( auto filenameType : filenameTypeMap )
    {
      auto p = filenameType.second.get();
      AddImplementation( p );
    }
  }
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddCase( TTypeInfo* p )
{
  auto enumName = MakeEnumName( p );
  IFileGenerator::AddCase( enumName );
  AddLeftBrace();
  IncrementTabs();

  auto sAllocate = fmt::format( "auto p = Allocate<{}>();", p->GetTypeNameWithNameSpace() );
  Add( sAllocate );
  auto sDeser = fmt::format( "{}( p );", s_Deserialize );
  Add( sDeser );

  auto sHandle = fmt::format( "{}::{}( p );", mBinaryMarshaller->unpackHandler.className, mBinaryMarshaller->unpackHandler.method );
  Add( sHandle );

  DecrementTabs();
  AddRightBrace();

  AddBreak();
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddImplementation( TTypeInfo* p )
{
  AddSerializeImplementation( p );
  AddCommentedLongLine();
  AddDeserializeImplementation( p );
  AddCommentedLongLine();
  AddGetTypeIDImplementation( p );
  AddCommentedLongLine();
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddSerializeImplementation( TTypeInfo* p )
{
  auto className = mBinaryMarshaller->className;
  auto namespaceWithType = p->GetTypeNameWithNameSpace();
  auto strList = GetParamListForSerialize( namespaceWithType );
  AddMethodImplementationBegin( "void", className, s_Serialize, strList );
  AddLeftBrace();
  IncrementTabs();

  AddCallingMethodForParent( p, [this]( const std::string& s ) { AddCallingSerializeParent( s ); } );

  AddCallingMethod( p, [this]( TMemberInfo* mi ) { AddPushByMemberInfo( mi ); } );

  DecrementTabs();
  AddRightBrace();
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddDeserializeImplementation( TTypeInfo* p )
{
  auto className = mBinaryMarshaller->className;
  auto namespaceWithType = p->GetTypeNameWithNameSpace();
  auto strList = GetParamListForDeserialize( namespaceWithType );
  AddMethodImplementationBegin( "void", className, s_Deserialize, strList );
  AddLeftBrace();
  IncrementTabs();

  AddCallingMethodForParent( p, [this]( const std::string& s ) { AddCallingDeserializeParent( s ); } );

  AddCallingMethod( p, [this]( TMemberInfo* mi ) {AddPopByMemberInfo( mi ); } );

  DecrementTabs();
  AddRightBrace();
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddGetTypeIDImplementation( TTypeInfo* p )
{
  auto className = mBinaryMarshaller->className;
  auto namespaceWithType = p->GetTypeNameWithNameSpace();
  auto strList = GetParamListForGetID( namespaceWithType );
  AddMethodImplementationBegin( className + s_CC + s_TypeID, className, s_GetTypeID, strList );
  AddLeftBrace();
  IncrementTabs();

  auto enumName = MakeEnumName( p );
  auto s = fmt::format( "return {};", enumName );
  Add( s );

  DecrementTabs();
  AddRightBrace();
}
//-------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddCallingSerializeParent( const std::string& parentTypeName )
{
  auto str = fmt::format( "{}( ({}*){} );", s_Serialize, parentTypeName, s_TypeObject );
  Add( str );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddCallingDeserializeParent( const std::string& parentTypeName )
{
  auto str = fmt::format( "{}( ({}*){} );", s_Deserialize, parentTypeName, s_TypeObject );
  Add( str );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushByMemberInfo( TMemberInfo* pMemberInfo )
{
  switch ( pMemberInfo->mExtendedInfo.mCategory )
  {
    case TMemberTypeExtendedInfo::BuiltIn:
      HandlePushBuiltIn( pMemberInfo );
      break;
    case TMemberTypeExtendedInfo::String:
      AddPushStr( pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::Vector:
    case TMemberTypeExtendedInfo::List:
    case TMemberTypeExtendedInfo::Set:
      HandlePyshArray( pMemberInfo );
      break;
    case TMemberTypeExtendedInfo::Map:
      HandlePushMap( pMemberInfo );
      break;
    case TMemberTypeExtendedInfo::Reflection:
      HandleReflectionForPush( pMemberInfo );
      break;
    default:
      break;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopByMemberInfo( TMemberInfo* pMemberInfo )
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
void TBinaryMarshallerSourceFileGenerator::HandlePushBuiltIn( TMemberInfo* pMemberInfo )
{
  if ( pMemberInfo->mExtendedInfo.mType == s_Bool )
    AddPushBool( pMemberInfo->mName );
  else
    AddPushNum( pMemberInfo->mName );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushBool( const std::string& name )
{
  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, name )
  };
  std::list<std::string> templateList;

  AddCallObjMethod( s_PushMaster, s_PushBool, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushNum( const std::string& name )
{
  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, name )
  };
  std::list<std::string> templateList;

  AddCallObjMethod( s_PushMaster, s_PushNum, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushStr( const std::string& name )
{
  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, name )
  };
  std::list<std::string> templateList;

  AddCallObjMethod( s_PushMaster, s_PushStr, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePyshArray( TMemberInfo* pMemberInfo )
{
  auto& templateType = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
  auto templateCategory = templateType.mCategory;
  switch ( templateCategory )
  {
    case TMemberTypeExtendedInfo::BuiltIn:
      HandleAddPushBuiltInArray( pMemberInfo );
      break;
    case TMemberTypeExtendedInfo::String:
      AddPushStrArray( pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::Reflection:
      HandlePushSerArray( pMemberInfo );
      break;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePushMap( TMemberInfo* pMemberInfo )
{
  auto& valueType = pMemberInfo->mExtendedInfo.mTemplateChildArr[1];
  auto valueCategory = valueType.mCategory;
  if ( valueCategory == TMemberTypeExtendedInfo::Reflection )
    HandleAddPushValueAsReflectionMap( pMemberInfo );
  else
    HandleAddPushNotReflectionMap( pMemberInfo );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleReflectionForPush( TMemberInfo* pMemberInfo )
{
  auto& type = pMemberInfo->mExtendedInfo.mType;
  switch ( pMemberInfo->mExtendedInfo.mAccessMethod )
  {
    case TMemberTypeExtendedInfo::Object:
      AddPushSerObj( type, pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::Pointer:
      AddPushSerPtr( type, pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::SmartPointer:
      AddPushSerSmartPtr( type, pMemberInfo->mName );
      break;
    default:
      break;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleAddPushBuiltInArray( TMemberInfo* pMemberInfo )
{
  auto type = pMemberInfo->mExtendedInfo.mTemplateChildArr[0].mType;
  if ( type == s_Bool )
    AddPushBoolArray( pMemberInfo->mName );
  else
    AddPushNumArray( type, pMemberInfo->mName );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushBoolArray( const std::string& name )
{
  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, name )
  };
  std::list<std::string> templateList;

  AddCallObjMethod( s_PushMaster, s_PushBoolArray, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushNumArray( const std::string& type, const std::string& name )
{
  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, name )
  };
  std::list<std::string> templateList = {type};

  AddCallObjMethod( s_PushMaster, s_PushNumArray, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushStrArray( const std::string& name )
{
  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, name )
  };
  std::list<std::string> templateList;

  AddCallObjMethod( s_PushMaster, s_PushStrArray, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePushSerArray( TMemberInfo* pMemberInfo )
{
  auto& templateType = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
  auto templateCategory = templateType.mCategory;

  auto typeName = templateType.mType;
  auto pTypeInfo = mTypeMng->FindTypeInfo( typeName );
  if ( pTypeInfo == nullptr )
    return;

  auto type = pTypeInfo->GetTypeNameWithNameSpace();
  switch ( templateType.mAccessMethod )
  {
    case TMemberTypeExtendedInfo::Object:
      AddPushSerObjArray( type, pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::Pointer:
      AddPushSerPtrArray( type, pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::SmartPointer:
      AddPushSerSmartPtrArray( type, templateType.mSmartPtrType, pMemberInfo->mName );
      break;
    default:
      break;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerObjArray( const std::string& type, const std::string& name )
{
  General_AddPushSerArray( type, "", name, s_PushSerObjArray );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerPtrArray( const std::string& type, const std::string& name )
{
  General_AddPushSerArray( type, "", name, s_PushSerPtrArray );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerSmartPtrArray( const std::string& type, const std::string& smartPtrType, const std::string& name )
{
  auto fullType = fmt::format( "{}{}<{}>", s_STD_, smartPtrType, type );
  General_AddPushSerArray( type, fullType, name, s_PushSerSmartPtrArray );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleAddPushNotReflectionMap( TMemberInfo* pMemberInfo )
{
  std::string methodName;
  std::string type[2];

  auto& templateArr = pMemberInfo->mExtendedInfo.mTemplateChildArr;
  auto keyType = templateArr[0].mType;
  auto valueType = templateArr[1].mType;
  auto keyCategory = templateArr[0].mCategory;
  auto valueCategory = templateArr[1].mCategory;

  if ( keyCategory == TMemberTypeExtendedInfo::BuiltIn &&
    valueCategory == TMemberTypeExtendedInfo::BuiltIn )
  {
    type[0] = keyType;
    if ( valueType == s_Bool )
      methodName = s_PushNumBoolMap;
    else
    {
      methodName = s_PushNumNumMap;
      type[1] = valueType;
    }
  }
  if ( keyCategory == TMemberTypeExtendedInfo::BuiltIn &&
    valueCategory == TMemberTypeExtendedInfo::String )
  {
    type[0] = keyType;
    methodName = s_PushNumStrMap;
  }
  if ( keyCategory == TMemberTypeExtendedInfo::String &&
    valueCategory == TMemberTypeExtendedInfo::String )
    methodName = s_PushStrStrMap;
  if ( keyCategory == TMemberTypeExtendedInfo::String &&
    valueCategory == TMemberTypeExtendedInfo::BuiltIn )
  {
    if ( valueType == s_Bool )
      methodName = s_PushStrBoolMap;
    else
    {
      methodName = s_PushStrNumMap;
      type[0] = valueType;
    }
  }

  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, pMemberInfo->mName )
  };
  std::list<std::string> templateList = {type[0],type[1]};

  AddCallObjMethod( s_PushMaster, methodName, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleAddPushValueAsReflectionMap( TMemberInfo* pMemberInfo )
{
  auto& keyExtType = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
  auto& valueExtType = pMemberInfo->mExtendedInfo.mTemplateChildArr[1];

  std::string keyType;
  if ( keyExtType.mCategory == TMemberTypeExtendedInfo::BuiltIn )
    keyType = keyExtType.mType;

  auto typeName = valueExtType.mType;
  auto pTypeInfo = mTypeMng->FindTypeInfo( typeName );
  if ( pTypeInfo == nullptr )
    return;

  auto valueType = pTypeInfo->GetTypeNameWithNameSpace();

  switch ( valueExtType.mAccessMethod )
  {
    case TMemberTypeExtendedInfo::Object:
      AddPushSerObjMap( keyType, valueType, pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::Pointer:
      AddPushSerPtrMap( keyType, valueType, pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::SmartPointer:
      AddPushSerSmartPtrMap( keyType, valueType, valueExtType.mSmartPtrType, pMemberInfo->mName );
      break;
    default:
      break;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerObjMap( const std::string& keyType, const std::string& valueType, const std::string& name )
{
  std::string methodName = s_PushStrSerObjMap;
  if ( keyType.length() )
    methodName = s_PushNumSerObjMap;

  General_AddPushSerMap( keyType, valueType, "", name, methodName );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerPtrMap( const std::string& keyType, const std::string& valueType, const std::string& name )
{
  std::string methodName = s_PushStrSerPtrMap;
  if ( keyType.length() )
    methodName = s_PushNumSerPtrMap;

  General_AddPushSerMap( keyType, valueType, "", name, methodName );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerSmartPtrMap( const std::string& keyType, const std::string& valueType,
  const std::string& smartPtrType, const std::string& name )
{
  std::string methodName = s_PushStrSerSmartPtrMap;
  if ( keyType.length() )
    methodName = s_PushNumSerSmartPtrMap;

  auto smartPtrTypeWithType = fmt::format( "{}{}<{}>", s_STD_, smartPtrType, valueType );
  General_AddPushSerMap( keyType, valueType, smartPtrTypeWithType, name, methodName );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerObj( const std::string& type, const std::string& name )
{
  auto ptrName = fmt::format( "{}_p", name );
  auto getAddress = fmt::format( "&({}->{})", s_TypeObject, name );
  General_AddPushReflection( ptrName, getAddress );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerPtr( const std::string& type, const std::string& name )
{
  auto ptrName = fmt::format( "{}_p", name );
  auto getAddress = fmt::format( "{}->{}", s_TypeObject, name );
  General_AddPushReflection( ptrName, getAddress );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPushSerSmartPtr( const std::string& type, const std::string& name )
{
  auto ptrName = fmt::format( "{}_p", name );
  auto getAddress = fmt::format( "{}->{}.get()", s_TypeObject, name );
  General_AddPushReflection( ptrName, getAddress );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePopBuiltIn( TMemberInfo* pMemberInfo )
{
  if ( pMemberInfo->mExtendedInfo.mType == s_Bool )
    AddPopBool( pMemberInfo->mName );
  else
    AddPopNum( pMemberInfo->mName );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopBool( const std::string& name )
{
  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, name )
  };
  std::list<std::string> templateList;

  AddCallObjMethod( s_PopMaster, s_PopBool, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopNum( const std::string& name )
{
  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, name )
  };
  std::list<std::string> templateList;

  AddCallObjMethod( s_PopMaster, s_PopNum, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopStr( const std::string& name )
{
  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, name )
  };
  std::list<std::string> templateList;

  AddCallObjMethod( s_PopMaster, s_PopStr, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePopArray( TMemberInfo* pMemberInfo )
{
  switch ( pMemberInfo->mExtendedInfo.mTemplateChildArr[0].mCategory )
  {
    case TMemberTypeExtendedInfo::BuiltIn:
      HandlePopBuiltInArray( pMemberInfo );
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
void TBinaryMarshallerSourceFileGenerator::HandlePopSet( TMemberInfo* pMemberInfo )
{
  switch ( pMemberInfo->mExtendedInfo.mTemplateChildArr[0].mCategory )
  {
    case TMemberTypeExtendedInfo::BuiltIn:
      AddPopNumSet( pMemberInfo->mExtendedInfo.mType, pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::String:
      AddPopStrSet( pMemberInfo->mName );
      break;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePopMap( TMemberInfo* pMemberInfo )
{
  auto& valueType = pMemberInfo->mExtendedInfo.mTemplateChildArr[1];
  auto valueCategory = valueType.mCategory;
  if ( valueCategory == TMemberTypeExtendedInfo::Reflection )
    HandleAddPopValueAsReflectionMap( pMemberInfo );
  else
    HandleAddPopNotReflectionMap( pMemberInfo );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleAddPopValueAsReflectionMap( TMemberInfo* pMemberInfo )
{
  auto& keyExtType = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
  auto& valueExtType = pMemberInfo->mExtendedInfo.mTemplateChildArr[1];

  std::string keyType;
  if ( keyExtType.mCategory == TMemberTypeExtendedInfo::BuiltIn )
    keyType = keyExtType.mType;

  auto typeName = valueExtType.mType;
  auto pTypeInfo = mTypeMng->FindTypeInfo( typeName );
  if ( pTypeInfo == nullptr )
    return;
  auto valueType = pTypeInfo->GetTypeNameWithNameSpace();

  switch ( valueExtType.mAccessMethod )
  {
    case TMemberTypeExtendedInfo::Object:
      AddPopSerObjMap( keyType, valueType, pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::Pointer:
      AddPopSerPtrMap( keyType, valueType, pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::SmartPointer:
      AddPopSerSmartPtrMap( keyType, valueType, valueExtType.mSmartPtrType, pMemberInfo->mName );
      break;
    default:
      break;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandleAddPopNotReflectionMap( TMemberInfo* pMemberInfo )
{
  std::string methodName;
  std::string type[2];

  auto& templateArr = pMemberInfo->mExtendedInfo.mTemplateChildArr;
  auto keyType = templateArr[0].mType;
  auto valueType = templateArr[1].mType;
  auto keyCategory = templateArr[0].mCategory;
  auto valueCategory = templateArr[1].mCategory;

  if ( keyCategory == TMemberTypeExtendedInfo::BuiltIn &&
    valueCategory == TMemberTypeExtendedInfo::BuiltIn )
  {
    type[0] = keyType;
    if ( valueType == s_Bool )
      methodName = s_PopNumBoolMap;
    else
    {
      methodName = s_PopNumNumMap;
      type[1] = valueType;
    }
  }
  if ( keyCategory == TMemberTypeExtendedInfo::BuiltIn &&
    valueCategory == TMemberTypeExtendedInfo::String )
  {
    type[0] = keyType;
    methodName = s_PopNumStrMap;
  }
  if ( keyCategory == TMemberTypeExtendedInfo::String &&
    valueCategory == TMemberTypeExtendedInfo::String )
    methodName = s_PopStrStrMap;
  if ( keyCategory == TMemberTypeExtendedInfo::String &&
    valueCategory == TMemberTypeExtendedInfo::BuiltIn )
  {
    if ( valueType == s_Bool )
      methodName = s_PopStrBoolMap;
    else
    {
      methodName = s_PopStrNumMap;
      type[0] = valueType;
    }
  }

  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, pMemberInfo->mName )
  };
  std::list<std::string> templateList = {type[0],type[1]};

  AddCallObjMethod( s_PopMaster, methodName, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerObjMap( const std::string& keyType, const std::string& valueType, const std::string& name )
{
  std::string methodName = s_PopStrSerObjMap;
  if ( keyType.length() )
    methodName = s_PopNumSerObjMap;

  General_AddPopSerMap( keyType, valueType, "", name, methodName );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerPtrMap( const std::string& keyType, const std::string& valueType, const std::string& name )
{
  std::string methodName = s_PopStrSerPtrMap;
  if ( keyType.length() )
    methodName = s_PopNumSerPtrMap;

  General_AddPopSerMap( keyType, valueType, "", name, methodName );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerSmartPtrMap( const std::string& keyType, const std::string& valueType, 
  const std::string& smartPtrType, const std::string& name )
{
  std::string methodName = s_PopStrSerSmartPtrMap;
  if ( keyType.length() )
    methodName = s_PopNumSerSmartPtrMap;

  auto smartPtrTypeWithType = fmt::format( "{}{}<{}>", s_STD_, smartPtrType, valueType );
  General_AddPopSerMap( keyType, valueType, smartPtrTypeWithType, name, methodName );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePopReflection( TMemberInfo* pMemberInfo )
{
  auto typeName = pMemberInfo->mExtendedInfo.mType;
  auto pTypeInfo = mTypeMng->FindTypeInfo( typeName );
  if ( pTypeInfo == nullptr )
    return;

  auto type = pTypeInfo->GetTypeNameWithNameSpace();

  switch ( pMemberInfo->mExtendedInfo.mAccessMethod )
  {
    case TMemberTypeExtendedInfo::Object:
      AddPopSerObj( pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::Pointer:
      AddPopSerPtr( type, pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::SmartPointer:
      AddPopSerSmartPtr( type, pMemberInfo->mName );
      break;
    default:
      break;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerObj( const std::string& name )
{
  auto ptrName = fmt::format( "&({}->{})", s_TypeObject, name );
  General_AddPopReflection( ptrName, "", "" );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerPtr( const std::string& type, const std::string& name )
{
  auto ptrName = fmt::format( "{}->{}", s_TypeObject, name );
  auto checkOnNullCondition = fmt::format( "{}->{} == nullptr ", s_TypeObject, name );
  auto newPtrExpression = fmt::format( "{}->{} = new {}();", s_TypeObject, name, type );
  General_AddPopReflection( ptrName, checkOnNullCondition, newPtrExpression );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerSmartPtr( const std::string& type, const std::string& name )
{
  auto ptrName = fmt::format( "{}->{}.get()", s_TypeObject, name );
  auto checkOnNullCondition = fmt::format( "{}->{}.get() == nullptr ", s_TypeObject, name );
  auto newPtrExpression = fmt::format( "{}->{}.reset( new {}() );", s_TypeObject, name, type );
  General_AddPopReflection( ptrName, checkOnNullCondition, newPtrExpression );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopNumSet( const std::string& type, const std::string& name )
{
  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, name )
  };
  std::list<std::string> templateList = {type};

  AddCallObjMethod( s_PopMaster, s_PopNumSet, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopStrSet( const std::string& name )
{
  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, name )
  };
  std::list<std::string> templateList;

  AddCallObjMethod( s_PopMaster, s_PopStrSet, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePopBuiltInArray( TMemberInfo* pMemberInfo )
{
  auto type = pMemberInfo->mExtendedInfo.mTemplateChildArr[0].mType;
  if ( type == s_Bool )
    AddPopBoolArray( pMemberInfo->mName );
  else
    AddPopNumArray( type, pMemberInfo->mName );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopBoolArray( const std::string& name )
{
  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, name )
  };
  std::list<std::string> templateList;

  AddCallObjMethod( s_PopMaster, s_PopBoolArray, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopNumArray( const std::string&type, const std::string& name )
{
  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, name )
  };
  std::list<std::string> templateList = {type};

  AddCallObjMethod( s_PopMaster, s_PopNumArray, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopStrArray( const std::string& name )
{
  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, name )
  };
  std::list<std::string> templateList;

  AddCallObjMethod( s_PopMaster, s_PopStrArray, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::HandlePopReflectionArray( TMemberInfo* pMemberInfo )
{
  auto& templateType = pMemberInfo->mExtendedInfo.mTemplateChildArr[0];
  auto pTypeInfo = mTypeMng->FindTypeInfo( templateType.mType );
  if ( pTypeInfo == nullptr )
    return;
  auto type = pTypeInfo->GetTypeNameWithNameSpace();

  auto templateCategory = templateType.mCategory;
  switch ( templateType.mAccessMethod )
  {
    case TMemberTypeExtendedInfo::Object:
      AddPopSerObjArray( type, pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::Pointer:
      AddPopSerPtrArray( type, pMemberInfo->mName );
      break;
    case TMemberTypeExtendedInfo::SmartPointer:
      AddPopSerSmartPtrArray( type, templateType.mSmartPtrType, pMemberInfo->mName );
      break;
    default:
      break;
  }
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerObjArray( const std::string& type, const std::string& name )
{
  General_AddPopSerArray( type, "", name, s_PopSerObjArray );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerPtrArray( const std::string& type, const std::string& name )
{
  General_AddPopSerArray( type, "", name, s_PopSerPtrArray );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::AddPopSerSmartPtrArray( const std::string& type, const std::string& smartPtrType, const std::string& name )
{
  auto fullType = fmt::format( "{}{}<{}>", s_STD_, smartPtrType, type );
  General_AddPopSerArray( type, fullType, name, s_PopSerSmartPtrArray );
}
//-----------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_AddPushSerArray( const std::string& keyType,
  const std::string& smartPtrType, const std::string& name, const std::string& methodName )
{
  General_AddPushSerArrayOrMap( keyType, "", smartPtrType, name, methodName, true );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_AddPushSerMap( const std::string& keyType,
  const std::string& valueType, const std::string& smartPtrType,
  const std::string& name, const std::string& methodName )
{
  General_AddPushSerArrayOrMap( keyType, valueType, smartPtrType, name, methodName, false );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_AddPushSerArrayOrMap( const std::string& keyType,
  const std::string& valueType, const std::string& smartPtrType,
  const std::string& name, const std::string& methodName, bool arrayOrMap )
{
  auto strList = GetParamListForSerialize( arrayOrMap ? keyType : valueType );
  auto paramStr = EnumerateParamToStr( strList );

  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, name ),
    fmt::format( "[this]( {0} ) {{ {1}( {2} ); }}", paramStr, s_Serialize, s_TypeObject )
  };
  std::list<std::string> templateList = {keyType, valueType, smartPtrType};

  AddCallObjMethod( s_PushMaster, methodName, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_AddPushReflection( const std::string& ptrName, const std::string& getAddress )
{
  auto getAddressExp = fmt::format( "auto {} = {};", ptrName, getAddress );
  Add( getAddressExp );

  auto pushIsNotNullptr = fmt::format( "{}( {} );", s_PushIsNotNullptr, ptrName );
  Add( pushIsNotNullptr );

  AddIf( ptrName );
  IncrementTabs();

  auto ser = fmt::format( "{}( {} );", s_Serialize, ptrName );
  Add( ser );

  DecrementTabs();
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_AddPopSerArray( const std::string& keyType,
  const std::string& smartPtrType, const std::string& name, const std::string& methodName )
{
  General_AddPopSerArrayOrMap( keyType, "", smartPtrType, name, methodName, true );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_AddPopSerMap( const std::string& keyType,
  const std::string& valueType, const std::string& smartPtrType,
  const std::string& name, const std::string& methodName )
{
  General_AddPopSerArrayOrMap( keyType, valueType, smartPtrType, name, methodName, false );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_AddPopSerArrayOrMap( const std::string& keyType,
  const std::string& valueType, const std::string& smartPtrType,
  const std::string& name, const std::string& methodName, bool arrayOrMap )
{
  auto strList = GetParamListForSerialize( arrayOrMap ? keyType : valueType );
  auto paramStr = EnumerateParamToStr( strList );

  std::list<std::string> argList =
  {
    fmt::format( "{}->{}", s_TypeObject, name ),
    fmt::format( "[this]( {0} ) {{ {1}( {2} ); }}", paramStr, s_Deserialize, s_TypeObject )
  };
  std::list<std::string> templateList = {keyType, valueType, smartPtrType};

  AddCallObjMethod( s_PopMaster, methodName, templateList, argList );
}
//-----------------------------------------------------------------------------------------------------------
void TBinaryMarshallerSourceFileGenerator::General_AddPopReflection( const std::string& ptrName, const std::string& checkOnNullCondition, const std::string& newPtrExpression )
{
  auto conditionIsNotNullptr = fmt::format( "{}()", s_PopIsNotNullptr );
  AddIf( conditionIsNotNullptr );

  AddLeftBrace();
  IncrementTabs();

  if ( checkOnNullCondition.length() )
  {
    AddIf( checkOnNullCondition );
    IncrementTabs();
    Add( newPtrExpression );
    DecrementTabs();
  }

  auto ser = fmt::format( "{}( {} );", s_Deserialize, ptrName );
  Add( ser );

  DecrementTabs();
  AddRightBrace();
}
//-----------------------------------------------------------------------------------------------------------