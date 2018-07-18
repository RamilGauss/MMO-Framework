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
  mBackBuffer.Alloc( mSizeBuffer );
  mFrontBuffer.Alloc( mSizeBuffer );

  mBackBuffer.Clear();
  mFrontBuffer.Clear();
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
  mBackBuffer.Append( size, p );
}
//-----------------------------------------------------------------
void TBreakPacket::PushFront( char* p, int size )
{
  mFrontBuffer.Append( size, p );
}
//-----------------------------------------------------------------
void TBreakPacket::Collect()
{
  mCollect.Clear();
  mCollect.Append( mFrontBuffer.GetSize(), mFrontBuffer.GetPtr() );
  mCollect.Append( mBackBuffer.GetSize(), mBackBuffer.GetPtr() );
}
//-----------------------------------------------------------------
void* TBreakPacket::GetCollectPtr()
{
  return mCollect.GetPtr();
}
//-----------------------------------------------------------------
int TBreakPacket::GetSize()
{
  return mBackBuffer.GetSize() + mFrontBuffer.GetSize();
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
  mBackBuffer.Clear();
  mFrontBuffer.Clear();
}
//-----------------------------------------------------------------
void TBreakPacket::CopyFrom( const TBreakPacket& bp )
{
  mSizeBuffer = bp.mSizeBuffer;

  mBackBuffer.Append( bp.mBackBuffer.GetSize(), bp.mBackBuffer.GetPtr() );
  mFrontBuffer.Append( bp.mFrontBuffer.GetSize(), bp.mFrontBuffer.GetPtr() );
}
//-----------------------------------------------------------------
