/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#include <stddef.h>
#include <memory.h>

#include "ReversedContainerRise.h"
#include "BL_Debug.h"

TReversedContainerRise::TReversedContainerRise()
{
  mSizeUse = 0;
}
//----------------------------------------------------------
TReversedContainerRise::TReversedContainerRise( const TReversedContainerRise& c )
{
  mSizeUse = 0;
  *this = c;
}
//----------------------------------------------------------
TReversedContainerRise& TReversedContainerRise::operator = ( const TReversedContainerRise& c )
{
  mC = c.mC;
  mSizeUse = c.mSizeUse;
  return *this;
}
//----------------------------------------------------------
char* TReversedContainerRise::GetPtr() const
{
  int offset = mC.GetSize() - mSizeUse;
  return (char*) mC.GetPtr() + offset;
}
//----------------------------------------------------------
int TReversedContainerRise::GetSize() const
{
  return mSizeUse;
}
//----------------------------------------------------------
void TReversedContainerRise::Alloc( int new_size )
{
  if( mC.GetSize() < new_size )
    mC.SetDataByCount( nullptr, new_size );
  mSizeUse = new_size;
}
//----------------------------------------------------------
void TReversedContainerRise::Realloc( int new_size )
{
  if( mC.GetSize() < new_size )
  {
    int oldSize = mC.GetSize();
    if( oldSize )
    {
      void* pOld = mC.GetPtr();
      mC.Unlink();
      mC.SetDataByCount( nullptr, new_size );
      char* pNew = mC.GetPtr();

      int offset = new_size - oldSize;
      memcpy( pNew + offset, pOld, mSizeUse );
      if( oldSize == 1 )
        delete  (char*) pOld;
      else
        delete []( char* )pOld;
    }
    else
      mC.SetDataByCount( nullptr, new_size );
  }
  mSizeUse = new_size;
}
//----------------------------------------------------------
void TReversedContainerRise::Clear()
{
  mSizeUse = 0;
}
//----------------------------------------------------------
void TReversedContainerRise::Shift( int offset )
{
  int newSize = mSizeUse + offset;
  Realloc( newSize );
}
//----------------------------------------------------------
void TReversedContainerRise::Append( int size, char* p )
{
  int oldSize = mSizeUse;
  int newSize = mSizeUse + size;
  Realloc( newSize );
  memcpy( GetPtr(), p, size );
}
//----------------------------------------------------------
