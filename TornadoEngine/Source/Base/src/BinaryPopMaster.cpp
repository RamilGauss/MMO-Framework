/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "BinaryPopMaster.h"

void TBinaryPopMaster::SetBuffer( TContainerRise* pC, int offset )
{
  mPtrData = pC->GetPtr();
  mSizeData = pC->GetSize();
  mOffset = offset;
}
//------------------------------------------------------------------------
void TBinaryPopMaster::SetBuffer( char* pData, int size, int offset )
{
  mPtrData = pData;
  mSizeData = size;
  mOffset = offset;
}
//------------------------------------------------------------------------
int TBinaryPopMaster::GetOffset()
{
  return mOffset;
}
//------------------------------------------------------------------------
void TBinaryPopMaster::PopBool( bool& t )
{
  BoolType v;
  PopNum( v );
  t = v;
}
//------------------------------------------------------------------------
void TBinaryPopMaster::PopStr( std::string& str )
{
  StrSizeType len = 0;
  PopNum( len );
  if ( len == 0 )
    return;
  char* pStr = mPtrData + mOffset;
  str.assign( pStr, len );
  mOffset += len;
}
//------------------------------------------------------------------------
