/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once


#include <unordered_map>
#include <functional>
#include <typeindex>

#include "lz4.h"

#include "Base/Common/ContainerRise.h"
#include "Base/Common/TypeDef.h"


#define USE_LZ4_COMPRESSION

template< typename TSerializerClass >
class DllExport TMarshaller
{
public:
    typedef unsigned short TypeID;
private:
#pragma pack(push, 1)
    struct THeader
    {
        TypeID type : 7;
        TypeID useCompression : 1;
        unsigned char ratio = 0;
    }__PACKED;
#pragma pack(pop)

    TSerializerClass mSer;

    typedef std::unordered_map<std::type_index, TypeID> TMapTypeIndexShort;
    typedef TMapTypeIndexShort::value_type TMapTypeIndexShortVT;

    TMapTypeIndexShort mTypeIndexIDMap;

    using DeserializeFunc = std::function<void* (TContainerRise& c, int offset)>;

    typedef std::unordered_map<TypeID, DeserializeFunc> TMapShortLambda;
    typedef TMapShortLambda::value_type TMapShortLambdaVT;

    TMapShortLambda mID_FuncMap;

    int mSetLimitForCompression = 0x40;// upper use LZ4 for compression
public:

    void SetLimitForCompression(int binarySize)
    {
        mSetLimitForCompression = binarySize;
    }

    template<typename Type>
    inline void Serialize(Type* t, TContainerRise& c);
    inline void* Deserialize(TContainerRise& c, TypeID& type);

    using AllocateFunc = void* (*)();// allocator prototype

    template<typename Type>
    inline void Add(TypeID type, AllocateFunc allocatorFunc);
private:
    TContainerRise mBuffer;

    THeader mHeader;
    const int HeaderSize = sizeof(THeader);
};
//---------------------------------------------------------------------------------------------
template<typename TSerializerClass>
template<typename Type>
void TMarshaller<TSerializerClass>::Serialize(Type* t, TContainerRise& c)
{
    mHeader.type = mTypeIndexIDMap[std::type_index(typeid(Type))];
    mHeader.useCompression = 0;
    mHeader.ratio = 0;
    mSer.Serialize(t, c, HeaderSize);
#ifdef USE_LZ4_COMPRESSION
    if (c.GetSize() - HeaderSize > mSetLimitForCompression) {
        mHeader.useCompression = 1;

        // компрессия
        mBuffer.Clear();
        mBuffer.Shift(LZ4_compressBound(c.GetSize()));
        int compressedSize = LZ4_compress_default(c.GetPtr() + HeaderSize, mBuffer.GetPtr(),
            c.GetSize() - HeaderSize, mBuffer.GetSize());
        mHeader.ratio = (c.GetSize() - HeaderSize) / compressedSize + 1;

        memcpy(c.GetPtr() + HeaderSize, mBuffer.GetPtr(), compressedSize);
        c.Clear();
        c.Shift(HeaderSize + compressedSize);
    }
#endif
    memcpy(c.GetPtr(), &mHeader, HeaderSize);
}
//---------------------------------------------------------------------------------------------
template<typename TSerializerClass>
void* TMarshaller<TSerializerClass>::Deserialize(TContainerRise& c, TypeID& type)
{
    memcpy(&mHeader, c.GetPtr(), HeaderSize);
    type = mHeader.type;

    TContainerRise* pC = &c;
    int offset = HeaderSize;
#ifdef USE_LZ4_COMPRESSION
    if (mHeader.useCompression) {
        mBuffer.Clear();
        mBuffer.Shift(c.GetSize() * mHeader.ratio);// расширить для запаса под декомпрессию
        int decompressedRes = LZ4_decompress_safe(c.GetPtr() + HeaderSize, mBuffer.GetPtr(), c.GetSize() - HeaderSize, mBuffer.GetSize());
        mBuffer.Clear();
        mBuffer.Shift(decompressedRes);
        pC = &mBuffer;
        offset = 0;
    }
#endif
    DeserializeFunc deserializeFunc = mID_FuncMap[type];// search lambda in map {ID, func}
    return deserializeFunc(*pC, offset);
}
//---------------------------------------------------------------------------------------------
template<typename TSerializerClass>
template<typename Type>
void TMarshaller<TSerializerClass>::Add(TypeID id, AllocateFunc allocatorFunc)
{
    auto typeIndex = std::type_index(typeid(Type));
    mTypeIndexIDMap.insert(TMapTypeIndexShortVT(typeIndex, id));

    auto pSer = &mSer;
    DeserializeFunc func{ [allocatorFunc, pSer](TContainerRise& c, int offset)
    {
      Type* pObj = (Type*)allocatorFunc();
      pSer->Deserialize(pObj, c, offset);
      return pObj;
    } };
    mID_FuncMap.insert(TMapShortLambdaVT(id, func));
}
//---------------------------------------------------------------------------------------------
