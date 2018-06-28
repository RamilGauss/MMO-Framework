/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

//Use => msgpack::object_handle!!!
template<typename MsgPack_ObjectHandle>
class TMessagePackSerializer
{
  MsgPack_ObjectHandle mObjectHandle;

  TContainerRise* mBuffer;
public:
  template<typename Type>
  inline void Serialize( Type* pObj, TContainerRise& c, int offset = 0 )
  {
    mBuffer = &c;
    mBuffer->Clear();
    mBuffer->Shift( offset );
    msgpack::pack( this, *pObj );
  }
  template<typename Type>
  inline void Deserialize( Type* pObj, TContainerRise& c, int offset = 0 )
  {
    msgpack::unpack( mObjectHandle, (const char*) c.GetPtr() + offset, (size_t) c.GetSize() );
    mObjectHandle.get().convert( *pObj );
  }
  inline void write( const char* buf, size_t len )
  {
    mBuffer->Append( len, (char*) buf );
  }
};