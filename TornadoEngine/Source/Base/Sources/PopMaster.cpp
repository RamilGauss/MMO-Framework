/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PopMaster.h"
#include "ISerializable.h"

void TPopMaster::SetBuffer( TContainer* pC, int offset )
{
  mPtrData = pC->GetPtr();
  mSizeData = pC->GetSize();
  mOffset = offset;
}
//------------------------------------------------------------------------
int TPopMaster::GetOffset()
{
  return mOffset;
}
//------------------------------------------------------------------------
void TPopMaster::PopSize( int& size)
{
  Pop( size );
}
//------------------------------------------------------------------------
void TPopMaster::PopStr( std::string& str )
{
  int len = 0;
  PopSize( len );
  if( len == 0 )
    return;
  char* pStr = mPtrData + mOffset;
  str.assign( pStr, len );
  mOffset += len;
}
//------------------------------------------------------------------------
void TPopMaster::PopStrByInsert( std::set<std::string>* pSetStr )
{
  int size;
  PopSize( size );
  for( int i = 0 ; i < size ; i++ )
  {
    std::string str;
    PopStr( str );
    pSetStr->insert( str );
  }
}
//------------------------------------------------------------------------
