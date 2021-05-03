/*
	ReflectionCodeGenerator
*/
// ReflectionCodeGenerator version 2.0.0, build 47, info Json, Binary, EntMng, Reflection
// File has been generated at 2021_05_03 21:31:47.878
	
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
    class DllExport TBinaryMarshaller
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
        // upper use LZ4 for compression
        int mSetLimitForCompression = 0x40;
    
        TContainerRise mBuffer;
        // collectors
        TBinaryPushMaster mPushMaster;
        TBinaryPopMaster mPopMaster;
    public:
        enum SerializableUniqueID : TypeID
        {
            e_nsReflectionCodeGenerator_TClassDesc = 666,
            e_nsReflectionCodeGenerator_TConfig,
            e_nsReflectionCodeGenerator_TExternalSource,
            e_nsReflectionCodeGenerator_TExternalSources,
            e_nsReflectionCodeGenerator_TFilter,
            e_nsReflectionCodeGenerator_TSerializer,
            e_nsReflectionCodeGenerator_TTargetForCodeGeneration,
            e_nsReflectionCodeGenerator_TTargetForParsing,
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
        void _Serialize( nsReflectionCodeGenerator::TClassDesc* p );
        void _Deserialize( nsReflectionCodeGenerator::TClassDesc* p );
        TypeID _GetTypeID( nsReflectionCodeGenerator::TClassDesc* p );
        static void _Deallocate(nsReflectionCodeGenerator::TClassDesc* p );
        
        void _Serialize( nsReflectionCodeGenerator::TConfig* p );
        void _Deserialize( nsReflectionCodeGenerator::TConfig* p );
        TypeID _GetTypeID( nsReflectionCodeGenerator::TConfig* p );
        static void _Deallocate(nsReflectionCodeGenerator::TConfig* p );
        
        void _Serialize( nsReflectionCodeGenerator::TExternalSource* p );
        void _Deserialize( nsReflectionCodeGenerator::TExternalSource* p );
        TypeID _GetTypeID( nsReflectionCodeGenerator::TExternalSource* p );
        static void _Deallocate(nsReflectionCodeGenerator::TExternalSource* p );
        
        void _Serialize( nsReflectionCodeGenerator::TExternalSources* p );
        void _Deserialize( nsReflectionCodeGenerator::TExternalSources* p );
        TypeID _GetTypeID( nsReflectionCodeGenerator::TExternalSources* p );
        static void _Deallocate(nsReflectionCodeGenerator::TExternalSources* p );
        
        void _Serialize( nsReflectionCodeGenerator::TFilter* p );
        void _Deserialize( nsReflectionCodeGenerator::TFilter* p );
        TypeID _GetTypeID( nsReflectionCodeGenerator::TFilter* p );
        static void _Deallocate(nsReflectionCodeGenerator::TFilter* p );
        
        void _Serialize( nsReflectionCodeGenerator::TSerializer* p );
        void _Deserialize( nsReflectionCodeGenerator::TSerializer* p );
        TypeID _GetTypeID( nsReflectionCodeGenerator::TSerializer* p );
        static void _Deallocate(nsReflectionCodeGenerator::TSerializer* p );
        
        void _Serialize( nsReflectionCodeGenerator::TTargetForCodeGeneration* p );
        void _Deserialize( nsReflectionCodeGenerator::TTargetForCodeGeneration* p );
        TypeID _GetTypeID( nsReflectionCodeGenerator::TTargetForCodeGeneration* p );
        static void _Deallocate(nsReflectionCodeGenerator::TTargetForCodeGeneration* p );
        
        void _Serialize( nsReflectionCodeGenerator::TTargetForParsing* p );
        void _Deserialize( nsReflectionCodeGenerator::TTargetForParsing* p );
        TypeID _GetTypeID( nsReflectionCodeGenerator::TTargetForParsing* p );
        static void _Deallocate(nsReflectionCodeGenerator::TTargetForParsing* p );
        
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
