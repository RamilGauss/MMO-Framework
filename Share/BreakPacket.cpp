/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#include "BreakPacket.h"
#include <algorithm>
#include <boost/foreach.hpp>

using namespace std;

TBreakPacket::TBreakPacket()
{

}
//-----------------------------------------------------------------
TBreakPacket::~TBreakPacket()
{
  DeleteCollect();
}
//-----------------------------------------------------------------
void TBreakPacket::PushBack(char* p,int size)
{
  TContainerPtr cPtr;
  cPtr.SetData(p, size);

  mList.push_back(cPtr);
}
//-----------------------------------------------------------------
void TBreakPacket::PushFront(char* p,int size)
{
  TContainerPtr cPtr;
  cPtr.SetData(p, size);

  mList.push_front(cPtr);
}
//-----------------------------------------------------------------
void TBreakPacket::Collect()
{
  DeleteCollect();
  int size = GetSize();

  mCollect.SetData(NULL, size);// выделить память
  char* pCollect = (char*)mCollect.GetPtr();

  // копируем все в одну область памяти
  BOOST_FOREACH( TContainerPtr& c, mList )
  {
    int sizePart  =        c.GetSize();
    char* ptrPart = (char*)c.GetPtr(); 
    memcpy(pCollect, ptrPart, sizePart);
    pCollect += sizePart;
  }
}
//-----------------------------------------------------------------
void* TBreakPacket::GetCollectPtr()
{
  return mCollect.GetPtr();
}
//-----------------------------------------------------------------
int TBreakPacket::GetSize()
{
  if(mCollect.GetPtr())
    return mCollect.GetSize();
  int size = 0;

  BOOST_FOREACH( TContainerPtr& c, mList )
    size += c.GetSize();

  return size;
}
//-----------------------------------------------------------------
int TBreakPacket::GetCountPart()
{
  return mList.size();
}
//-----------------------------------------------------------------
void TBreakPacket::DeleteCollect()
{
  mCollect.Done();
}
//-----------------------------------------------------------------
void TBreakPacket::UnlinkPart()
{
  mList.clear();
}
//-----------------------------------------------------------------	
const TBreakPacket& TBreakPacket::operator =( const TBreakPacket& b )
{
	mList = b.mList;
	return *this;
}
//-----------------------------------------------------------------
void TBreakPacket::UnlinkCollect()
{
  mCollect.Unlink();
}
//-----------------------------------------------------------------
