/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include <stddef.h>
#include <memory.h>

#include "ContainerRise.h"
#include "BL_Debug.h"

TContainerRise::TContainerRise()
{
  mSizeUse = 0;
}
//----------------------------------------------------------
TContainerRise::TContainerRise( const TContainerRise& c )
{
  mSizeUse = 0;
  *this = c;
}
//----------------------------------------------------------
TContainerRise& TContainerRise::operator = ( const TContainerRise& c )
{
  mC = c.mC;
  mSizeUse = c.mSizeUse;
  return *this;
}
//----------------------------------------------------------
char* TContainerRise::GetPtr() const
{
  return (char*) mC.GetPtr();
}
//----------------------------------------------------------
int TContainerRise::GetSize() const
{
  return mSizeUse;
}
//----------------------------------------------------------
void TContainerRise::Alloc( int new_size )
{
  if ( mC.GetSize() < new_size )
    mC.SetDataByCount( nullptr, new_size );
  mSizeUse = new_size;
}
//----------------------------------------------------------
void TContainerRise::Realloc( int new_size )
{
  if ( mC.GetSize() < new_size )
  {
    int oldSize = mC.GetSize();
    if ( oldSize )
    {
      void* pOld = mC.GetPtr();
      mC.Unlink();
      mC.SetDataByCount( nullptr, new_size );
      void* pNew = mC.GetPtr();
      memcpy( pNew, pOld, mSizeUse );
      if ( oldSize == 1 )
        delete  (char*) pOld;
      else
        delete[]( char* )pOld;
    }
    else
      mC.SetDataByCount( nullptr, new_size );
  }
  mSizeUse = new_size;
}
//----------------------------------------------------------
void TContainerRise::Clear()
{
  mSizeUse = 0;
}
//----------------------------------------------------------
void TContainerRise::Shift( int offset )
{
  int newSize = mSizeUse + offset;
  Realloc( newSize );
}
//----------------------------------------------------------
void TContainerRise::Append( int size, char* p )
{
  int oldSize = mSizeUse;
  int newSize = mSizeUse + size;
  Realloc( newSize );
  memcpy( GetPtr() + oldSize, p, size );
}
//----------------------------------------------------------
bool TContainerRise::operator == ( const TContainerRise& other )
{
  if ( mSizeUse != other.mSizeUse )
    return false;
  auto p = mC.GetPtr();
  auto pOther = other.mC.GetPtr();
  bool isEqual = true;
  for ( int i = 0; i < mSizeUse; i++ )
  {
    if ( p[i] != pOther[i] )
    {
      isEqual = false;
      break;
    }
  }
  return isEqual;
}
//----------------------------------------------------------
