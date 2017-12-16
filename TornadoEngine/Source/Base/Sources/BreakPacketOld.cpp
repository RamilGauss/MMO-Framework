/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#include "BreakPacketOld.h"
#include <algorithm>
#include <boost/foreach.hpp>

using namespace std;

TBreakPacketOld::TBreakPacketOld()
{

}
//-----------------------------------------------------------------
TBreakPacketOld::TBreakPacketOld(const TBreakPacketOld& bp)
{
  CopyFrom(bp);
}
//-----------------------------------------------------------------
TBreakPacketOld& TBreakPacketOld::operator =( const TBreakPacketOld& bp )
{
  CopyFrom(bp);
  return *this;
}
//-----------------------------------------------------------------
TBreakPacketOld::~TBreakPacketOld()
{
  Reset();
  DeleteCache();
}
//-----------------------------------------------------------------
TBreakPacketOld::TDescContainer* TBreakPacketOld::GetDescContainer( bool copyData )
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
TBreakPacketOld::TDescContainer* TBreakPacketOld::FindInCache( bool copyData )
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
TBreakPacketOld::TDescContainer* TBreakPacketOld::PushData( char* p,int size, bool copyData )
{
  TDescContainer* pDesc = GetDescContainer( copyData );
  pDesc->pC->SetDataByCount(p, size);
  return pDesc;
}
//-----------------------------------------------------------------
void TBreakPacketOld::PushBack( char* p,int size )
{
  TDescContainer* pDesc = PushData(p, size, true);
  mList.push_back(pDesc);
}
//-----------------------------------------------------------------
void TBreakPacketOld::PushFront( char* p,int size )
{
  TDescContainer* pDesc = PushData(p, size, true);
  mList.push_front(pDesc);
}
//-----------------------------------------------------------------
void TBreakPacketOld::Collect()
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
void* TBreakPacketOld::GetCollectPtr()
{
  return mCollect.GetPtr();
}
//-----------------------------------------------------------------
int TBreakPacketOld::GetSize()
{
  int size = 0;
  BOOST_FOREACH( TDescContainer*& pDesc, mList )
    size += pDesc->pC->GetSize();

  return size;
}
//-----------------------------------------------------------------
void TBreakPacketOld::AddInCache( TDescContainer* pDesc )
{
  if( pDesc->type == TDescContainer::eContainer)
    mCacheContainerList.push_back(pDesc);
  else
    mCacheContainerPtrList.push_back(pDesc);
}
//-----------------------------------------------------------------
void TBreakPacketOld::Reset()
{
  BOOST_FOREACH( TDescContainer*& pDesc, mList )
    AddInCache( pDesc );

  mList.clear();
}
//-----------------------------------------------------------------  
void TBreakPacketOld::UnlinkCollect()
{
  mCollect.Unlink();
}
//-----------------------------------------------------------------
void TBreakPacketOld::CopyFrom(const TBreakPacketOld& bp)
{
  Reset();
  BOOST_FOREACH( TDescContainer* pDesc, bp.mList )
  {
    bool copyData = bool(pDesc->type==TDescContainer::eContainer);
    TDescContainer* pDescCopy = PushData(pDesc->pC->GetPtr(), pDesc->pC->GetSize(), copyData);
    mList.push_back(pDescCopy);
  }
}
//-----------------------------------------------------------------
void TBreakPacketOld::DeleteCache()
{
  BOOST_FOREACH( TDescContainer*& pDesc, mCacheContainerList )
    delete pDesc;
  BOOST_FOREACH( TDescContainer*& pDesc, mCacheContainerPtrList )
    delete pDesc;
}
//-----------------------------------------------------------------