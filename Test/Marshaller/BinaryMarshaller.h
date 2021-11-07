/*
	ReflectionCodeGenerator for Marshaller
*/
// File has been generated by ReflectionCodeGenerator version 1.18 build 46, at 2020_10_18 14:38:07.353
	
#pragma once

#include <functional>
#include "ContainerRise.h"
#include "TypeDef.h"
#include "BinaryPushMaster.h"
#include "BinaryPopMaster.h"
#include "MemoryObjectPoolAllocator.h"
#include "BL_Debug.h"
#include "lz4.h"

#include "IncludeList.h"

namespace nsBinary
{
    class TBinaryMarshaller
    {
    public:
        typedef unsigned short TypeID;
    private:
    #pragma pack(push, 1)
        struct THeader
        {
            TypeID type : 15;
            TypeID useCompression : 1;
            unsigned char ratio = 0;
        };
    #pragma pack(pop)
        // upper use LZ4 for compression
        int mSetLimitForCompression = 0x40;
    
        TContainerRise mBuffer;
        // collectors
        TBinaryPushMaster mPushMaster;
        TBinaryPopMaster mPopMaster;
    public:
        enum SerializableUniqueID : TypeID
        {
            e_TFloat3 = 666,
            e_TFloat4,
            e_TParamClass,
            e_TSimpleComponent,
            e_TTestClass,
            e_nsBS_TBaseStruct,
            e_nsBS_TTestStruct,
        };
    
        void SetLimitForCompression(int binarySize);
    
        // serialize / deserialize
        template <typename Type>
        void Serialize(Type* p, TContainerRise& c);
        template <typename Type>
        void Deserialize(Type*& p, char* serData, int size);
        template <typename Type>
        void Fill(Type* p, char* serData, int size);
    
        // pack / unpack
        template <typename Type>
        void Pack(Type* p, TContainerRise& c);
        // WARNING! handle in {} определяется настройками генератора
        void Unpack(char* packedData, int size);
    
        TypeID GetID(char* packedData, int size);
        template <typename Type>
        Type* HandleUnpack(char* packedData, int size);
        template <typename Type>
        void FillUnpack(Type* p, char* packedData, int size, bool check = false);
    
        template <typename Type>
      static void Deallocate(Type* p);
    private:
        void PushIsNotNullptr(void* p);
        bool PopIsNotNullptr();
    
        template <typename Type>
      static Type* Allocate();
        template <typename Type>
        void _Deserialize(Type*& p, char* serData, int size, bool checkPtr);
      TypeID PrepareForUnpackPopMaster(char* packedData, int size);
    private:
        void _Serialize( TFloat3* p );
        void _Deserialize( TFloat3* p );
        TypeID _GetTypeID( TFloat3* p );
        static void _Deallocate( TFloat3* p );
        
        void _Serialize( TFloat4* p );
        void _Deserialize( TFloat4* p );
        TypeID _GetTypeID( TFloat4* p );
        static void _Deallocate( TFloat4* p );
        
        void _Serialize( TParamClass* p );
        void _Deserialize( TParamClass* p );
        TypeID _GetTypeID( TParamClass* p );
        static void _Deallocate( TParamClass* p );
        
        void _Serialize( TSimpleComponent* p );
        void _Deserialize( TSimpleComponent* p );
        TypeID _GetTypeID( TSimpleComponent* p );
        static void _Deallocate( TSimpleComponent* p );
        
        void _Serialize( TTestClass* p );
        void _Deserialize( TTestClass* p );
        TypeID _GetTypeID( TTestClass* p );
        static void _Deallocate( TTestClass* p );
        
        void _Serialize( nsBS::TBaseStruct* p );
        void _Deserialize( nsBS::TBaseStruct* p );
        TypeID _GetTypeID( nsBS::TBaseStruct* p );
        static void _Deallocate( nsBS::TBaseStruct* p );
        
        void _Serialize( nsBS::TTestStruct* p );
        void _Deserialize( nsBS::TTestStruct* p );
        TypeID _GetTypeID( nsBS::TTestStruct* p );
        static void _Deallocate( nsBS::TTestStruct* p );
        
    };
    //-----------------------------------------------------------------------------
    template <typename Type>
    void TBinaryMarshaller::Serialize(Type* p, TContainerRise& c)
    {
        mPushMaster.Clear();
        _Serialize(p);
        mPushMaster.CopyInBuffer(c, 0);
    }
    //-----------------------------------------------------------------------------
    template <typename Type>
    void TBinaryMarshaller::Deserialize(Type*& p, char* serData, int size)
    {
        _Deserialize(p, serData, size, true);
    }
    //-----------------------------------------------------------------------------
    template <typename Type>
    void TBinaryMarshaller::Fill(Type* p, char* serData, int size)
    {
        _Deserialize(p, serData, size, false);
    }
    //-----------------------------------------------------------------------------
    template <typename Type>
    void TBinaryMarshaller::Pack(Type* p, TContainerRise& c)
    {
        Serialize( p, c );
    
        const int headerSize = sizeof(THeader);
        THeader header;
        header.type = _GetTypeID( p );
        header.useCompression = 0;
        header.ratio = 0;
        if ( c.GetSize() - headerSize > mSetLimitForCompression )
        {
            header.useCompression = 1;
            // compression
            mBuffer.Clear();
            mBuffer.Shift(LZ4_compressBound(c.GetSize()));
            int compressedSize = LZ4_compress_default(c.GetPtr(), mBuffer.GetPtr(),
              c.GetSize(), mBuffer.GetSize());
            header.ratio = c.GetSize() / compressedSize + 1;
    
            c.Clear();
            c.Shift(headerSize + compressedSize);
            memcpy(c.GetPtr() + headerSize, mBuffer.GetPtr(), compressedSize);
        }
        else
        {
            auto size = c.GetSize();
            c.Shift(headerSize);
            memmove(c.GetPtr() + headerSize, c.GetPtr(), size);
        }
        memcpy(c.GetPtr(), &header, headerSize);
    }
    //-----------------------------------------------------------------------------
    template <typename Type>
    Type* TBinaryMarshaller::HandleUnpack(char* packedData, int size)
    {
        Type* p = nullptr;
        auto typeFromBinary = PrepareForUnpackPopMaster(packedData, size);
        auto typeByUserGuest = _GetTypeID(p);
        BL_Assert(typeFromBinary == typeByUserGuest);
        p = Allocate<Type>();
        _Deserialize(p);
        return p;
    }
    //-----------------------------------------------------------------------------
    template <typename Type>
    void TBinaryMarshaller::FillUnpack(Type* p, char* packedData, int size, bool check)
    {
        auto typeFromBinary = PrepareForUnpackPopMaster( packedData, size );
        auto typeByUserGuest = _GetTypeID(p);
        if ( check ) {
            BL_Assert(typeFromBinary == typeByUserGuest);
        }
        _Deserialize(p);
    }
    //-----------------------------------------------------------------------------
    template <typename Type>
    void TBinaryMarshaller::Deallocate(Type* p)
    {
        _Deallocate(p);
        TMemoryObjectPoolAllocator::DeallocateFunc(p);
    }
    //-----------------------------------------------------------------------------
    template <typename Type>
    static Type* TBinaryMarshaller::Allocate()
    {
        return TMemoryObjectPoolAllocator::AllocateFunc<Type>();
    }
    //-----------------------------------------------------------------------------
    template <typename Type>
    void TBinaryMarshaller::_Deserialize(Type*& p, char* serData, int size, bool checkPtr)
    {
        if ( checkPtr ) {
            p = p ? p : new Type();
    }
    
        mPopMaster.SetBuffer(serData, size, 0);
        _Deserialize( p );
    }
}
