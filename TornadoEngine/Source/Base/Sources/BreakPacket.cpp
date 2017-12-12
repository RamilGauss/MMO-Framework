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
TBreakPacket::TBreakPacket(const TBreakPacket& bp)
{
  CopyFrom(bp);
}
//-----------------------------------------------------------------
TBreakPacket& TBreakPacket::operator =( const TBreakPacket& bp )
{
  CopyFrom(bp);
  return *this;
}
//-----------------------------------------------------------------
TBreakPacket::~TBreakPacket()
{
  DeleteCollect();
  UnlinkPart();
}
//-----------------------------------------------------------------
TBreakPacket::TDescContainer TBreakPacket::PushData( char* p,int size, bool copyData )
{
  TDescContainer desc;
  if( copyData )
    desc.Init(TDescContainer::eContainer);
  else
    desc.Init(TDescContainer::eContainerPtr);

  desc.pC->SetDataByCount(p, size);
  return desc;
}
//-----------------------------------------------------------------
void TBreakPacket::PushBack( char* p,int size, bool copyData )
{
  TDescContainer desc = PushData(p, size, copyData);
  mList.push_back(desc);
}
//-----------------------------------------------------------------
void TBreakPacket::PushFront( char* p,int size, bool copyData )
{
  TDescContainer desc = PushData(p, size, copyData);
  mList.push_front(desc);
}
//-----------------------------------------------------------------
void TBreakPacket::Collect()
{
  DeleteCollect();
  int size = GetSize();

  mCollect.SetDataByCount(NULL, size);// выделить память
  char* pCollect = (char*)mCollect.GetPtr();

  // копируем все в одну область памяти
  BOOST_FOREACH( TDescContainer& desc, mList )
  {
    int sizePart  =        desc.pC->GetSize();
    char* ptrPart = (char*)desc.pC->GetPtr(); 
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

  BOOST_FOREACH( TDescContainer& desc, mList )
    size += desc.pC->GetSize();

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
  BOOST_FOREACH( TDescContainer& desc, mList )
    delete desc.pC;
  mList.clear();
}
//-----------------------------------------------------------------  
void TBreakPacket::UnlinkCollect()
{
  mCollect.Unlink();
}
//-----------------------------------------------------------------
void TBreakPacket::CopyFrom(const TBreakPacket& bp)
{
  DeleteCollect();
  UnlinkPart();
  BOOST_FOREACH( TDescContainer desc, bp.mList )
  {
    bool copyData = bool(desc.type==TDescContainer::eContainer);
    TDescContainer descCopy = PushData(desc.pC->GetPtr(), desc.pC->GetSize(), copyData);
    mList.push_back(descCopy);
  }
}
//-----------------------------------------------------------------