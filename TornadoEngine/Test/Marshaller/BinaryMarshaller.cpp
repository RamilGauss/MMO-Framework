/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BinaryMarshaller.h"
#include "UnpackHandler.h"

using namespace nsBinary;
//-----------------------------------------------------------------------------
void TBinaryMarshaller::SetLimitForCompression( int binarySize )
{
  mSetLimitForCompression = binarySize;
}
//-----------------------------------------------------------------------------
void TBinaryMarshaller::Unpack( char* packedData, int size )
{
  int headerSize = sizeof( THeader );
  THeader header;
  memcpy( &header, packedData, headerSize );
  char* pObj = packedData + headerSize;
  int objSize = size - headerSize;

  // decompression
  if ( header.useCompression )
  {
    mBuffer.Clear();
    mBuffer.Shift( objSize * header.ratio );// расширить для запаса под декомпрессию
    int decompressedRes = LZ4_decompress_safe( pObj, mBuffer.GetPtr(), objSize, mBuffer.GetSize() );
    mBuffer.Clear();
    mBuffer.Shift( decompressedRes );
  }

  mPopMaster.SetBuffer( &mBuffer, 0 );
  switch ( header.type )
  {
    case eTBaseStruct:
    {
      auto p = Allocate<TBaseStruct>();
      _Deserialize( p );
      TUnpackHandler::Handle( p );
    }
      break;
    case eTTestStruct:
    {
      auto p = Allocate<TTestStruct>();
      _Deserialize( p );
      TUnpackHandler::Handle( p );
    }
      break;
  }
}
//-----------------------------------------------------------------------------
TBinaryMarshaller::TypeID TBinaryMarshaller::GetID( char* packedData, int size )
{
  auto pHeader = (THeader*) packedData;
  return pHeader->type;
}
//-----------------------------------------------------------------------------
void TBinaryMarshaller::PushIsNotNullptr( void* p )
{
  unsigned char isNullptr = p == nullptr ? 0 : 1;
  mPushMaster.PushNum( isNullptr );
}
//-----------------------------------------------------------------------------
bool TBinaryMarshaller::PopIsNotNullptr()
{
  unsigned char isNullptr;
  mPopMaster.PopNum( isNullptr );
  return ( isNullptr != 0 );
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void TBinaryMarshaller::_Serialize( TBaseStruct* p )
{
  mPushMaster.PushStr( p->s );
}
//-----------------------------------------------------------------------------
void TBinaryMarshaller::_Deserialize( TBaseStruct* p )
{
  mPopMaster.PopStr( p->s );
}
//-----------------------------------------------------------------------------
TBinaryMarshaller::TypeID TBinaryMarshaller::_GetTypeID( TBaseStruct* p )
{
  return SerializableUniqueID::eTBaseStruct;
}
//-----------------------------------------------------------------------------
void TBinaryMarshaller::_Serialize( TTestStruct* p )
{
  // doesn't check inheritance
  _Serialize( (TBaseStruct*) p );

  auto baseStruct_p = &p->baseStruct;
  PushIsNotNullptr( baseStruct_p );
  if( baseStruct_p )
    _Serialize( baseStruct_p );

  auto pBaseStruct_p = p->pBaseStruct;
  PushIsNotNullptr( pBaseStruct_p );
  if ( pBaseStruct_p )
    _Serialize( pBaseStruct_p );

  auto spBaseStruct_p = p->spBaseStruct.get();
  PushIsNotNullptr( spBaseStruct_p );
  if( spBaseStruct_p )
    _Serialize( p->spBaseStruct.get() );

  mPushMaster.PushStr( p->password );
  mPushMaster.PushNum( p->port );
  mPushMaster.PushBool( p->flag );
  mPushMaster.PushBoolArray( p->boolList );
  mPushMaster.PushNumArray<int>( p->numList );
  mPushMaster.PushStrArray( p->strSet );
  mPushMaster.PushNumArray<int>( p->numVector );
  mPushMaster.PushNumArray<int>( p->intSet );
  mPushMaster.PushSerObjArray<TBaseStruct>( p->baseVec, [this]( TBaseStruct* p ) { _Serialize( p ); } );
  mPushMaster.PushSerPtrArray<TBaseStruct>( p->basePtrVec , [this]( TBaseStruct* p ) { _Serialize( p ); } );
  mPushMaster.PushSerSmartPtrArray<TBaseStruct,std::shared_ptr<TBaseStruct>>( p->baseSPVec, [this]( TBaseStruct* p ) { _Serialize( p ); } );

  mPushMaster.PushNumNumMap<int, int>( p->intIntMap );
  mPushMaster.PushNumStrMap<int>( p->intStrMap );
  mPushMaster.PushNumBoolMap<int>( p->intBoolMap );
  mPushMaster.PushStrNumMap<int>( p->strIntMap );
  mPushMaster.PushStrStrMap( p->strStrMap );
  mPushMaster.PushStrBoolMap( p->strBoolMap );
  mPushMaster.PushStrSerObjMap<TBaseStruct>( p->strBaseMap, [this]( TBaseStruct* p ) { _Serialize( p ); } );
  mPushMaster.PushStrSerPtrMap<TBaseStruct>( p->strBasePtrMap, [this]( TBaseStruct* p ) { _Serialize( p ); } );
  mPushMaster.PushStrSerSmartPtrMap<TBaseStruct, std::shared_ptr<TBaseStruct>>( p->strBaseSPMap, [this]( TBaseStruct* p ) { _Serialize( p ); } );
  mPushMaster.PushNumSerObjMap<int, TBaseStruct>( p->intBaseMap, [this]( TBaseStruct* p ) { _Serialize( p ); } );
  mPushMaster.PushNumSerPtrMap<int, TBaseStruct>( p->intBasePtrMap, [this]( TBaseStruct* p ) { _Serialize( p ); } );
  mPushMaster.PushNumSerSmartPtrMap<int, TBaseStruct, std::shared_ptr<TBaseStruct>>( p->intBaseSPMap, [this]( TBaseStruct* p ) { _Serialize( p ); } );
}
//-----------------------------------------------------------------------------
void TBinaryMarshaller::_Deserialize( TTestStruct* p )
{
  _Deserialize( (TBaseStruct*) p );

  if ( PopIsNotNullptr() ) // на той стороне возможно другой язык и там этот member является указателем.
  {
    _Deserialize( &(p->baseStruct) );
  }
  if( PopIsNotNullptr() )
  {
    if ( p->pBaseStruct == nullptr )
      p->pBaseStruct = new TBaseStruct();
    _Deserialize( p->pBaseStruct );
  }
  if ( PopIsNotNullptr() )
  {
    if ( p->spBaseStruct.get() == nullptr )
      p->spBaseStruct.reset( new TBaseStruct() );
    _Deserialize( p->spBaseStruct.get() );
  }
  mPopMaster.PopStr( p->password );
  mPopMaster.PopNum( p->port );
  mPopMaster.PopBool( p->flag );
  mPopMaster.PopBoolArray( p->boolList );
  mPopMaster.PopNumArray<int>( p->numList );
  mPopMaster.PopStrSet( p->strSet );
  mPopMaster.PopNumArray<int>( p->numVector );
  mPopMaster.PopNumSet<int>( p->intSet );
  mPopMaster.PopSerObjArray<TBaseStruct>( p->baseVec, [this]( TBaseStruct* p ) { _Deserialize( p ); } );
  mPopMaster.PopSerPtrArray<TBaseStruct>( p->basePtrVec, [this]( TBaseStruct* p ) { _Deserialize( p ); } );
  mPopMaster.PopSerSmartPtrArray<TBaseStruct, std::shared_ptr<TBaseStruct>>( p->baseSPVec, [this]( TBaseStruct* p ) { _Deserialize( p ); } );

  mPopMaster.PopNumNumMap<int, int>( p->intIntMap );
  mPopMaster.PopNumStrMap<int>( p->intStrMap );
  mPopMaster.PopNumBoolMap<int>( p->intBoolMap );
  mPopMaster.PopStrNumMap<int>( p->strIntMap );
  mPopMaster.PopStrStrMap( p->strStrMap );
  mPopMaster.PopStrBoolMap( p->strBoolMap );
  mPopMaster.PopStrSerObjMap<TBaseStruct>( p->strBaseMap, [this]( TBaseStruct* p ) { _Deserialize( p ); } );
  mPopMaster.PopStrSerPtrMap<TBaseStruct>( p->strBasePtrMap, [this]( TBaseStruct* p ) { _Deserialize( p ); } );
  mPopMaster.PopStrSerSmartPtrMap<TBaseStruct, std::shared_ptr<TBaseStruct>>( p->strBaseSPMap, [this]( TBaseStruct* p ) { _Deserialize( p ); } );
  mPopMaster.PopNumSerObjMap<int, TBaseStruct>( p->intBaseMap, [this]( TBaseStruct* p ) { _Deserialize( p ); } );
  mPopMaster.PopNumSerPtrMap<int, TBaseStruct>( p->intBasePtrMap, [this]( TBaseStruct* p ) { _Deserialize( p ); } );
  mPopMaster.PopNumSerSmartPtrMap<int, TBaseStruct, std::shared_ptr<TBaseStruct>>( p->intBaseSPMap, [this]( TBaseStruct* p ) { _Deserialize( p ); } );
}
//-----------------------------------------------------------------------------
TBinaryMarshaller::TypeID TBinaryMarshaller::_GetTypeID( TTestStruct* p )
{
  return SerializableUniqueID::eTTestStruct;
}
//-----------------------------------------------------------------------------
