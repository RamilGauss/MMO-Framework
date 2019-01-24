/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "ContainerRise.h"
#include "TypeDef.h"
#include <functional>

#include "BinaryPushMaster.h"
#include "BinaryPopMaster.h"
#include "MemoryPoolAllocator.h"

#include "IncludeList.h"
#include "lz4.h"

namespace nsBinary
{
  // not static! Cause heavy push/pop masters constructors.
  // I'd want have push/pop masters in stack, but I want quickly marshallize.
  class TBinaryMarshaller
  {
  public:
    typedef unsigned short TypeID;
  private:
#ifdef WIN32
#pragma pack(push, 1)
#endif
    struct THeader
    {
      TypeID type : 15;
      TypeID useCompression : 1;
      unsigned char ratio = 0;
    }_PACKED;
#ifdef WIN32
#pragma pack(pop)
#endif
    int mSetLimitForCompression = 0x40;// upper use LZ4 for compression

    TContainerRise mBuffer;
    // collectors
    TBinaryPushMaster mPushMaster;
    TBinaryPopMaster mPopMaster;
  public:
    enum SerializableUniqueID : TBinaryMarshaller::TypeID
    {
      // begin id + 0
      eTBaseStruct = 1000,
      eTTestStruct,
    };

    void SetLimitForCompression( int binarySize );

    // serialize / deserialize
    template <typename Type>
    void Serialize( Type* p, TContainerRise& c );
    template <typename Type>
    void Deserialize( Type*& p, char* serData, int size );
    template <typename Type>
    void Fill( Type* p, char* serData, int size );

    // pack / unpack
    template <typename Type>
    void Pack( Type* p, TContainerRise& c );
    // WARNING! handle in {} определяется настройками генератора
    void Unpack( char* packedData, int size );

    TypeID GetID( char* packedData, int size );
    template <typename Type>
    Type* HandleUnpack( char* packedData, int size );
    template <typename Type>
    void FillUnpack( Type* p, char* packedData, int size );

    template <typename Type>
    static void Deallocate( Type* p );
  private:
    void PushIsNotNullptr( void* p );
    bool PopIsNotNullptr();

    template <typename Type>
    static Type* Allocate();
    template <typename Type>
    void _Deserialize( Type*& p, char* serData, int size, bool checkPtr );

    template<typename Type>
    using AllocateFunc = std::function<Type*()>;

    template<typename Type>
    Type* _Unpack( char* packedData, int size, AllocateFunc<Type> allocateFunc );
  private:
    void _Serialize( TBaseStruct* p );
    void _Deserialize( TBaseStruct* p );
    TypeID _GetTypeID( TBaseStruct* p );

    void _Serialize( TTestStruct* p );
    void _Deserialize( TTestStruct* p );
    TypeID _GetTypeID( TTestStruct* p );
  };
  //-----------------------------------------------------------------------------
  template <typename Type>
  void TBinaryMarshaller::Serialize( Type* p, TContainerRise& c )
  {
    mPushMaster.Clear();
    _Serialize( p );
    mPushMaster.CopyInBuffer( c, 0 );
  }
  //-----------------------------------------------------------------------------
  template <typename Type>
  void TBinaryMarshaller::Deserialize( Type*& p, char* serData, int size )
  {
    _Deserialize( p, serData, size, true );
  }
  //-----------------------------------------------------------------------------
  template <typename Type>
  void TBinaryMarshaller::Fill( Type* p, char* serData, int size )
  {
    _Deserialize( p, serData, size, false );
  }
  //-----------------------------------------------------------------------------
  template <typename Type>
  void TBinaryMarshaller::Pack( Type* p, TContainerRise& c )
  {
    Serialize( p, c );

    int headerSize = sizeof( THeader );
    THeader header;
    header.type = _GetTypeID( p );
    header.useCompression = 0;
    header.ratio = 0;
    if ( c.GetSize() - headerSize > mSetLimitForCompression )
    {
      header.useCompression = 1;
      // compression
      mBuffer.Clear();
      mBuffer.Shift( LZ4_compressBound( c.GetSize() ) );
      int compressedSize = LZ4_compress_default( c.GetPtr(), mBuffer.GetPtr(),
        c.GetSize(), mBuffer.GetSize() );
      header.ratio = c.GetSize() / compressedSize + 1;

      c.Clear();
      c.Shift( headerSize + compressedSize );
      memcpy( c.GetPtr() + headerSize, mBuffer.GetPtr(), compressedSize );
    }
    memcpy( c.GetPtr(), &header, headerSize );
  }
  //-----------------------------------------------------------------------------
  template <typename Type>
  Type* TBinaryMarshaller::HandleUnpack( char* packedData, int size )
  {
    return nullptr;
  }
  //-----------------------------------------------------------------------------
  template <typename Type>
  void TBinaryMarshaller::FillUnpack( Type* p, char* packedData, int size )
  {

  }
  //-----------------------------------------------------------------------------
  template <typename Type>
  Type* TBinaryMarshaller::Allocate()
  {
    return (Type*) TMemoryPoolAllocator::AllocateFunc<Type>();
  }
  //-----------------------------------------------------------------------------
  template <typename Type>
  void TBinaryMarshaller::Deallocate( Type* p )
  {
    TMemoryPoolAllocator::DeallocateFunc( p );
  }
  //-----------------------------------------------------------------------------
  template <typename Type>
  void TBinaryMarshaller::_Deserialize( Type*& p, char* serData, int size, bool checkPtr )
  {
    if ( checkPtr )
      p = p ? p : new Type();

    mPopMaster.SetBuffer( serData, size, 0 );
    _Deserialize( p );
  }
  //------------------------------------------------------------------------------------
}

