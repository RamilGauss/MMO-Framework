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
  UnlinkPart();
}
//-----------------------------------------------------------------
IContainer* TBreakPacket::PushData(char* p,int size, bool copyData)
{
  IContainer* pC = NULL;
  if( copyData )
    pC = new TContainer;
  else
    pC = new TContainerPtr;

  pC->SetDataByCount(p, size);
  return pC;
}
//-----------------------------------------------------------------
void TBreakPacket::PushBack(char* p,int size, bool copyData)
{
  IContainer* pC = PushData(p, size, copyData);
  mList.push_back(pC);
}
//-----------------------------------------------------------------
void TBreakPacket::PushFront(char* p,int size, bool copyData)
{
  IContainer* pC = PushData(p, size, copyData);
  mList.push_front(pC);
}
//-----------------------------------------------------------------
void TBreakPacket::Collect()
{
  DeleteCollect();
  int size = GetSize();

  mCollect.SetDataByCount(NULL, size);// выделить память
  char* pCollect = (char*)mCollect.GetPtr();

  // копируем все в одну область памяти
  BOOST_FOREACH( IContainer* pC, mList )
  {
    int sizePart  =        pC->GetSize();
    char* ptrPart = (char*)pC->GetPtr(); 
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

  BOOST_FOREACH( IContainer* pC, mList )
    size += pC->GetSize();

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
  BOOST_FOREACH( IContainer* pC, mList )
    delete pC;
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
