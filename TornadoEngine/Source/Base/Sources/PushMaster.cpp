/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PushMaster.h"
#include "ISerializable.h"

void TPushMaster::Clear()
{
  mCollectorMember.Reset();
}
//-----------------------------------------------------------------------
TContainer TPushMaster::GetBuffer()
{
  mCollectorMember.Collect();
  char* p = (char*)mCollectorMember.GetCollectPtr();
  int size = mCollectorMember.GetSize();

  TContainer c;
  c.Entrust( p, size);

  mCollectorMember.UnlinkCollect();
  return c;
}
//-----------------------------------------------------------------------
void TPushMaster::PushSize( int& size )
{
  Push( size );
}
//-----------------------------------------------------------------------
void TPushMaster::PushStr( std::string& str )
{
  int len = str.length();
  PushSize( len );
  if( len )
    mCollectorMember.PushBack( (char*)str.data(), len);
}
//-----------------------------------------------------------------------
void TPushMaster::PushPtrSer( ISerializable* ser )
{
  unsigned char isNotNULL = 1;
  if( ser == NULL )
    isNotNULL = 0;
  Push( isNotNULL );
  if( ser )
    ser->Serialize( this );
}
//-----------------------------------------------------------------------
