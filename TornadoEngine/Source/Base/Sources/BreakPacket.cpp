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
  UnlinkPart();
  DeleteCache();
}
//-----------------------------------------------------------------
TBreakPacket::TDescContainer* TBreakPacket::GetDescContainer( bool copyData )
{
  TDescContainer* pDesc = FindInCache(copyData);
  if( pDesc )
    return pDesc;

  pDesc = new TDescContainer();
  if( copyData )
    pDesc->Init(TDescContainer::eContainer);
  else
    pDesc->Init(TDescContainer::eContainerPtr);
  return pDesc;
}
//-----------------------------------------------------------------
TBreakPacket::TDescContainer* TBreakPacket::FindInCache( bool copyData )
{
  TDescContainer* pDesc = NULL;
  if( copyData )
  {
    if( mCacheContainerList.size() > 0 )
    {
      pDesc = mCacheContainerList.back();
      mCacheContainerList.pop_back();
    }
  }
  else
  {
    if( mCacheContainerPtrList.size() > 0 )
    {
      pDesc = mCacheContainerPtrList.back();
      mCacheContainerPtrList.pop_back();
    }
  }
  return pDesc;
}
//-----------------------------------------------------------------
TBreakPacket::TDescContainer* TBreakPacket::PushData( char* p,int size, bool copyData )
{
  TDescContainer* pDesc = GetDescContainer( copyData );
  pDesc->pC->SetDataByCount(p, size);
  return pDesc;
}
//-----------------------------------------------------------------
void TBreakPacket::PushBack( char* p,int size, bool copyData )
{
  TDescContainer* pDesc = PushData(p, size, copyData);
  mList.push_back(pDesc);
}
//-----------------------------------------------------------------
void TBreakPacket::PushFront( char* p,int size, bool copyData )
{
  TDescContainer* pDesc = PushData(p, size, copyData);
  mList.push_front(pDesc);
}
//-----------------------------------------------------------------
void TBreakPacket::Collect()
{
  int size = GetSize();

  mCollect.SetDataByCount(NULL, size);// выделить память
  char* pCollect = (char*)mCollect.GetPtr();

  // копируем все в одну область памяти
  BOOST_FOREACH( TDescContainer*& pDesc, mList )
  {
    int sizePart  =        pDesc->pC->GetSize();
    char* ptrPart = (char*)pDesc->pC->GetPtr(); 
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

  BOOST_FOREACH( TDescContainer*& pDesc, mList )
    size += pDesc->pC->GetSize();

  return size;
}
//-----------------------------------------------------------------
void TBreakPacket::AddInCache( TDescContainer* pDesc )
{
  if( pDesc->type == TDescContainer::eContainer)
    mCacheContainerList.push_back(pDesc);
  else
    mCacheContainerPtrList.push_back(pDesc);
}
//-----------------------------------------------------------------
void TBreakPacket::UnlinkPart()
{
  BOOST_FOREACH( TDescContainer*& pDesc, mList )
    AddInCache( pDesc );

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
  UnlinkPart();
  BOOST_FOREACH( TDescContainer* pDesc, bp.mList )
  {
    bool copyData = bool(pDesc->type==TDescContainer::eContainer);
    TDescContainer* pDescCopy = PushData(pDesc->pC->GetPtr(), pDesc->pC->GetSize(), copyData);
    mList.push_back(pDescCopy);
  }
}
//-----------------------------------------------------------------
void TBreakPacket::DeleteCache()
{
  BOOST_FOREACH( TDescContainer*& pDesc, mCacheContainerList )
    delete pDesc;
  BOOST_FOREACH( TDescContainer*& pDesc, mCacheContainerPtrList )
    delete pDesc;
}
//-----------------------------------------------------------------