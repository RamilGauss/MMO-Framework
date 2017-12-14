/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BreakPacketFast.h"

using namespace std;

TBreakPacketFast::TBreakPacketFast( int sizeBuffer )
{
  mSizeBuffer = sizeBuffer;
  mBackBuffer.SetData(NULL, mSizeBuffer);
  mFrontBuffer.SetData(NULL, mSizeBuffer);

  mBackOffset = 0;
  mFrontOffset = 0;
}
//-----------------------------------------------------------------
TBreakPacketFast::TBreakPacketFast(const TBreakPacketFast& bp)
{
  CopyFrom(bp);
}
//-----------------------------------------------------------------
TBreakPacketFast& TBreakPacketFast::operator =( const TBreakPacketFast& bp )
{
  CopyFrom(bp);
  return *this;
}
//-----------------------------------------------------------------
TBreakPacketFast::~TBreakPacketFast()
{

}
//-----------------------------------------------------------------
void TBreakPacketFast::PushBack( char* p,int size )
{
  char* dst = mBackBuffer.GetPtr();
  memcpy( dst + mBackOffset, p, size);
  mBackOffset += size;
}
//-----------------------------------------------------------------
void TBreakPacketFast::PushFront( char* p, int size )
{
  char* dst = mFrontBuffer.GetPtr();
  int offset = mFrontBuffer.GetSize() - mFrontOffset;
  memcpy( dst + offset, p, size);
  mFrontOffset += size;
}
//-----------------------------------------------------------------
void TBreakPacketFast::Collect()
{
  int size = mBackOffset + mFrontOffset;
  mCollect.SetData(NULL,size);
  char* dst = mCollect.GetPtr();

  char* src = mFrontBuffer.GetPtr();
  int offset = mFrontBuffer.GetSize() - mFrontOffset;
  memcpy( dst, src + offset, mFrontOffset);

  src = mBackBuffer.GetPtr();
  memcpy( dst + mFrontOffset, src, mBackOffset);
}
//-----------------------------------------------------------------
void* TBreakPacketFast::GetCollectPtr()
{
  return mCollect.GetPtr();
}
//-----------------------------------------------------------------
int TBreakPacketFast::GetSize()
{
  return mCollect.GetSize();
}
//-----------------------------------------------------------------
void TBreakPacketFast::UnlinkCollect()
{
  mCollect.Unlink();
}
//-----------------------------------------------------------------
void TBreakPacketFast::UnlinkPart()
{
  mBackOffset = 0;
  mFrontOffset = 0;
}
//-----------------------------------------------------------------
void TBreakPacketFast::CopyFrom(const TBreakPacketFast& bp)
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
