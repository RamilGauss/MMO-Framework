/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BinaryPushMaster.h"

void TBinaryPushMaster::CopyInBuffer( TContainerRise& receiveBuffer, int offset )
{
  mCollectorMember.CopyInBuffer( receiveBuffer, offset );
}
//-----------------------------------------------------------------------
void TBinaryPushMaster::Clear()
{
  mCollectorMember.Reset();
}
//-----------------------------------------------------------------------
void TBinaryPushMaster::PushSize( const int& size )
{
  Push( size );
}
//-----------------------------------------------------------------------
void TBinaryPushMaster::PushStr( const std::string& str )
{
  int len = str.length();
  PushSize( len );
  if( len )
    mCollectorMember.PushBack( (char*) str.data(), len );
}
//-----------------------------------------------------------------------
