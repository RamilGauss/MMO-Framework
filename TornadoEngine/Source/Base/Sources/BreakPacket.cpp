/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BreakPacket.h"

using namespace std;

TBreakPacket::TBreakPacket( int sizeBuffer )
{
  mSizeBuffer = sizeBuffer;
  mBackBuffer.SetData( NULL, mSizeBuffer );
  mFrontBuffer.SetData( NULL, mSizeBuffer );

  mBackOffset = 0;
  mFrontOffset = 0;
}
//-----------------------------------------------------------------
TBreakPacket::TBreakPacket( const TBreakPacket& bp )
{
  CopyFrom( bp );
}
//-----------------------------------------------------------------
TBreakPacket& TBreakPacket::operator =( const TBreakPacket& bp )
{
  CopyFrom( bp );
  return *this;
}
//-----------------------------------------------------------------
TBreakPacket::~TBreakPacket()
{

}
//-----------------------------------------------------------------
void TBreakPacket::PushBack( char* p, int size )
{
  char* dst = mBackBuffer.GetPtr();
  memcpy( dst + mBackOffset, p, size );
  mBackOffset += size;
}
//-----------------------------------------------------------------
void TBreakPacket::PushFront( char* p, int size )
{
  char* dst = mFrontBuffer.GetPtr();
  int offset = mFrontBuffer.GetSize() - mFrontOffset - size;
  memcpy( dst + offset, p, size );
  mFrontOffset += size;
}
//-----------------------------------------------------------------
void TBreakPacket::Collect()
{
  char* src = mFrontBuffer.GetPtr();
  int offset = mFrontBuffer.GetSize() - mFrontOffset;
  mCollect.Clear();
  mCollect.Append( mFrontOffset, src + offset );

  src = mBackBuffer.GetPtr();
  mCollect.Append( mBackOffset, src );

  //int size = mBackOffset + mFrontOffset;
  //mCollect.SetData( NULL, size );
  //char* dst = mCollect.GetPtr();

  //char* src = mFrontBuffer.GetPtr();
  //int offset = mFrontBuffer.GetSize() - mFrontOffset;
  //memcpy( dst, src + offset, mFrontOffset );

  //src = mBackBuffer.GetPtr();
  //memcpy( dst + mFrontOffset, src, mBackOffset );
}
//-----------------------------------------------------------------
void* TBreakPacket::GetCollectPtr()
{
  return mCollect.GetPtr();
}
//-----------------------------------------------------------------
int TBreakPacket::GetSize()
{
  return mFrontOffset + mBackOffset;
}
//-----------------------------------------------------------------
void TBreakPacket::CopyInBuffer( TContainerRise& receiveBuffer, int offset )
{
  Collect();

  receiveBuffer.Clear();
  receiveBuffer.Shift( offset );
  receiveBuffer.Append( GetSize(), (char*) GetCollectPtr() );
}
//-----------------------------------------------------------------
void TBreakPacket::Reset()
{
  mBackOffset = 0;
  mFrontOffset = 0;
}
//-----------------------------------------------------------------
void TBreakPacket::CopyFrom( const TBreakPacket& bp )
{
  mSizeBuffer = bp.mSizeBuffer;

  mBackOffset = bp.mBackOffset;
  mFrontOffset = bp.mFrontOffset;

  mBackBuffer.SetData( NULL, mSizeBuffer );
  mFrontBuffer.SetData( NULL, mSizeBuffer );

  memcpy( mBackBuffer.GetPtr(), bp.mBackBuffer.GetPtr(), mBackOffset );

  int offset = mFrontBuffer.GetSize() - mFrontOffset;
  memcpy( mFrontBuffer.GetPtr() + offset, bp.mFrontBuffer.GetPtr() + offset, mFrontOffset );
}
//-----------------------------------------------------------------
