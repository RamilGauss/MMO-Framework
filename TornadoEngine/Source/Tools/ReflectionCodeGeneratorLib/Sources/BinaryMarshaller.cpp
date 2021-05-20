/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.1.0, build 50, info Json, Binary, EntMng, Reflection
// File has been generated at 2021_05_20 22:41:11.963
	
#include "BinaryMarshaller.h"

using namespace nsBinary;

void TBinaryMarshaller::SetLimitForCompression( int binarySize )
{
  mSetLimitForCompression = binarySize;
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
TBinaryMarshaller::TypeID TBinaryMarshaller::PrepareForUnpackPopMaster( char* packedData, int size )
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
  else
  {
    mBuffer.Clear();
    mBuffer.Append( objSize, pObj );
  }
  mPopMaster.SetBuffer( &mBuffer, 0 );
  return header.type;
}
//-----------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
void TBinaryMarshaller::Unpack( char* packedData, int size )
{
    auto type = PrepareForUnpackPopMaster( packedData, size );
    switch( type )
    {
    }
}
//---------------------------------------------------------------------------------------
