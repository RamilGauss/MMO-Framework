/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "BinaryMarshallerFileGenerator.h"
#include "fmt/core.h"

namespace nsReflectionCodeGenerator
{
  class TBinaryMarshallerSourceFileGenerator : public TBinaryMarshallerFileGenerator
  {
    const std::string s_BinaryMaster = "TBinaryMaster";
    const std::string s_SizeType = "SizeType";
    const std::string s_BinaryMaster_SizeType = fmt::format( "{}{}{}", s_BinaryMaster, s_CC, s_SizeType );

    const std::list<std::string> s_BinaryImplementation =
    {
      fmt::format( "void {}::{}( int binarySize )", mBinaryMarshaller->className, s_SetLimitForCompression ),
      "{",
      "  mSetLimitForCompression = binarySize;",
      "}",
      "//-----------------------------------------------------------------------------",
      fmt::format( "{0}::{1} {0}::{2}( char* packedData, int size )", mBinaryMarshaller->className, s_TypeID, s_GetID ),
      "{",
      fmt::format( "  auto pHeader = ({}*) packedData;", s_THeader ),
      "  return pHeader->type;",
      "}",
      "//-----------------------------------------------------------------------------",
      fmt::format( "void {}::{}( void* p )", mBinaryMarshaller->className, s_PushIsNotNullptr ),
      "{",
      "  unsigned char isNullptr = p == nullptr ? 0 : 1;",
      fmt::format( "  {}.PushNum( isNullptr );", s_PushMaster ),
      "}",
      "//-----------------------------------------------------------------------------",
      fmt::format( "bool {}::{}()", mBinaryMarshaller->className, s_PopIsNotNullptr ),
      "{",
      "  unsigned char isNullptr;",
      fmt::format( "  {}.PopNum( isNullptr );", s_PopMaster ),
      "  return ( isNullptr != 0 );",
      "}",
      "//-----------------------------------------------------------------------------",
      fmt::format( "{0}::{1} {0}::{2}( char* packedData, int size )", mBinaryMarshaller->className, s_TypeID, s_PrepareForUnpackPopMaster ),
      "{",
      fmt::format( "  int headerSize = sizeof( {} );", s_THeader ),
      fmt::format( "  {} header;", s_THeader ),
      "  memcpy( &header, packedData, headerSize );",
      "  char* pObj = packedData + headerSize;",
      "  int objSize = size - headerSize;",
      "",
      "  // decompression",
      "  if ( header.useCompression )",
      "  {",
      "    mBuffer.Clear();",
      "    mBuffer.Shift( objSize * header.ratio );// расширить для запаса под декомпрессию",
      "    int decompressedRes = LZ4_decompress_safe( pObj, mBuffer.GetPtr(), objSize, mBuffer.GetSize() );",
      "    mBuffer.Clear();",
      "    mBuffer.Shift( decompressedRes );",
      "  }",
      "  else",
      "  {",
      "    mBuffer.Clear();",
      "    mBuffer.Append( objSize, pObj );",
      "  }",
      fmt::format( "  {}.SetBuffer( &mBuffer, 0 );", s_PopMaster ),
      "  return header.type;",
      "}",
      "//-----------------------------------------------------------------------------",
    };

  public:
    virtual void Work() override;

  private:
    void AddPackImplentation();
    void AddImplementations();

    void AddCase( TTypeInfo* p );

    void AddImplementation( TTypeInfo* p );

    void AddSerializeImplementation( TTypeInfo* p );
    void AddDeserializeImplementation( TTypeInfo* p );
    void AddGetTypeIDImplementation( TTypeInfo* p );

    void AddCallingSerializeParent( const std::string& parentTypeName );
    void AddCallingDeserializeParent( const std::string& parentTypeName );


    void AddPushByMemberInfo( TMemberInfo* pMemberInfo );
    void AddPopByMemberInfo( TMemberInfo* pMemberInfo );

    // Push XXX
    void AddPushStr( const std::string& name );
    void AddPushBool( const std::string& name );
    void AddPushNum( const std::string& name );

    void AddPushBoolArray( const std::string& name );
    void AddPushNumArray( const std::string& type, const std::string& name );
    void AddPushStrArray( const std::string& name );

    void AddPushSerObjArray( const std::string& type, const std::string& name );
    void AddPushSerPtrArray( const std::string& type, const std::string& name );
    void AddPushSerSmartPtrArray( const std::string& type, const std::string& smartPtrType, const std::string& name );

    void AddPushSerObjMap( const std::string& keyType, const std::string& valueType, const std::string& name );
    void AddPushSerPtrMap( const std::string& keyType, const std::string& valueType, const std::string& name );
    void AddPushSerSmartPtrMap( const std::string& keyType, const std::string& valueType,
      const std::string& smartPtrType, const std::string& name );

    void AddPushSerObj( const std::string& type, const std::string& name );
    void AddPushSerPtr( const std::string& type, const std::string& name );
    void AddPushSerSmartPtr( const std::string& type, const std::string& name );


    void AddPopStr( const std::string& name );
    void AddPopBool( const std::string& name );
    void AddPopNum( const std::string& name );

    void AddPopNumSet( const std::string& type, const std::string& name );
    void AddPopStrSet( const std::string& name );

    void AddPopStrArray( const std::string& name );
    void AddPopBoolArray( const std::string& name );
    void AddPopNumArray( const std::string&type, const std::string& name );

    void AddPopSerObj( const std::string& name );
    void AddPopSerPtr( const std::string& type, const std::string& name );
    void AddPopSerSmartPtr( const std::string& type, const std::string& name );

    void AddPopSerObjArray( const std::string& type, const std::string& name );
    void AddPopSerPtrArray( const std::string& type, const std::string& name );
    void AddPopSerSmartPtrArray( const std::string& type, const std::string& smartPtrType, const std::string& name );

    void AddPopSerObjMap( const std::string& keyType, const std::string& valueType, const std::string& name );
    void AddPopSerPtrMap( const std::string& keyType, const std::string& valueType, const std::string& name );
    void AddPopSerSmartPtrMap( const std::string& keyType, const std::string& valueType, const std::string& smartPointer, const std::string& name );

    // Handlers
    void HandlePushBuiltIn( TMemberInfo* pMemberInfo );
    void HandlePushArray( TMemberInfo* pMemberInfo );
    void HandlePushMap( TMemberInfo* pMemberInfo );
    void HandleReflectionForPush( TMemberInfo* pMemberInfo );

    void HandleAddPushBuiltInArray( TMemberInfo* pMemberInfo );
    void HandlePushSerArray( TMemberInfo* pMemberInfo );
    void HandleAddPushValueAsReflectionMap( TMemberInfo* pMemberInfo );
    void HandleAddPushNotReflectionMap( TMemberInfo* pMemberInfo );

    void HandlePopBuiltIn( TMemberInfo* pMemberInfo );
    void HandlePopArray( TMemberInfo* pMemberInfo );
    void HandlePopSet( TMemberInfo* pMemberInfo );
    void HandlePopMap( TMemberInfo* pMemberInfo );
    void HandlePopReflection( TMemberInfo* pMemberInfo );

    void HandlePopBuiltInArray( TMemberInfo* pMemberInfo );
    void HandlePopReflectionArray( TMemberInfo* pMemberInfo );

    void HandleAddPopValueAsReflectionMap( TMemberInfo* pMemberInfo );
    void HandleAddPopNotReflectionMap( TMemberInfo* pMemberInfo );

    void HandleComplexPushZeroDepth( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name );
    void HandleComplexPush( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth );
    void General_ComplexPush( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth );

    void AddPushKey( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth );
    void AddPushValue( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth );

    void AddPushElement( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth );

    void AddPushSerializeValue( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth );
    void AddPushSerializeElement( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth );
    std::string GetTemplateForGetAddress( TMemberTypeExtendedInfo::AccessMethod accessMethod );

    std::string GetIsElementNotNull( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth );


    void HandleBuiltInComplexPush( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth );
    void HandleStringComplexPush( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth );
    void HandleReflectionComplexPush( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth );

    void AddCleanerArrayOrMap( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name );
    void HandleComplexPopZeroDepth( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name );
    void HandleComplexPop( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth );
    void General_ComplexPop( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth );
    void HandleBuiltInComplexPop( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth );
    void HandleReflectionComplexPop( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth );


    std::string ElementName( const std::string& name, int depth );
    std::string SizeName( const std::string& name, int depth );
    std::string IndexName( const std::string& name, int depth );
    std::string KeyName( const std::string& name, int depth );
    std::string ValueName( const std::string& name, int depth );
    std::string CollectorName( const std::string& name, int depth );

    std::string GetAddMethodByCategory( TMemberTypeExtendedInfo::TypeCategory& category );
    std::string GetPushMethodBy( TMemberTypeExtendedInfo& ext );
    std::string GetAccessName( std::vector<TMemberTypeExtendedInfo>& extArr, const std::string& name, int depth );
    std::string GetFusionForAdd( TMemberTypeExtendedInfo& ext, const std::string& name, int depth );

    std::string GetPopMethodBy( TMemberTypeExtendedInfo& ext );
    std::string GetInitExpression( TMemberTypeExtendedInfo& ext );

    // general
    void General_AddPushSerArray( const std::string& keyType,
      const std::string& smartPtrType, const std::string& name, const std::string& methodName );
    void General_AddPushSerMap( const std::string& keyType,
      const std::string& valueType, const std::string& smartPtrType,
      const std::string& name, const std::string& methodName );
    void General_AddPushSerArrayOrMap( const std::string& keyType,
      const std::string& valueType, const std::string& smartPtrType,
      const std::string& name, const std::string& methodName, bool arrayOrMap );

    void General_AddPushReflection( const std::string& ptrName, const std::string& getAddress );

    void General_AddPopSerArray( const std::string& keyType,
      const std::string& smartPtrType, const std::string& name, const std::string& methodName );
    void General_AddPopSerMap( const std::string& keyType,
      const std::string& valueType, const std::string& smartPtrType,
      const std::string& name, const std::string& methodName );
    void General_AddPopSerArrayOrMap( const std::string& keyType,
      const std::string& valueType, const std::string& smartPtrType,
      const std::string& name, const std::string& methodName, bool arrayOrMap );
    void General_AddPopReflection( const std::string& ptrName,
      const std::string& checkOnNullCondition, const std::string& newPtrExpression );

  };
}

