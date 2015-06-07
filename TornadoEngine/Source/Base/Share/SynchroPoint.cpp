/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SynchroPoint.h"
#include <boost/foreach.hpp>
#include "BL_Debug.h"
#include "ContainerTypes.h"

TSynchroPoint::TSynchroPoint()
{

}
//-----------------------------------------------------------------------------------------
TSynchroPoint::~TSynchroPoint()
{
  Done();
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::Register(int id_abonent)
{
  mVecIDAbonent.push_back(id_abonent);
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::SetupAfterRegister()
{
  BOOST_FOREACH(int& id_recv, mVecIDAbonent)
  {
    TDescRecv descRecv;
    descRecv.id = id_recv;
    BOOST_FOREACH( int& id_sender, mVecIDAbonent)
    {
      TDescSender descSender;
      descSender.id = id_sender;
      descSender.pList = new TListContainer;
      descRecv.vec.push_back(descSender);
    }
    mVecRecv.push_back(descRecv);
  }
}
//-----------------------------------------------------------------------------------------
IContainer* TSynchroPoint::GetEvent(int id_recv, int& id_sender)
{
  TDescRecv* pDescRecv = NULL;
  pDescRecv = FindByRecv(id_recv);
  if(pDescRecv)
  {
    int cnt = pDescRecv->vec.size();
    for( int i = 0 ; i < cnt ; i++ )
    {
      TDescSender* pDescSender = &(pDescRecv->vec[i]);
      TListContainer* pList = pDescSender->pList;
      IContainer** ppC = pList->GetFirst();
      if(ppC)
      {
        id_sender = pDescSender->id;
        IContainer* pC = *ppC;
        pList->ZeroPointerElement(ppC);
        pList->Remove(ppC);
        return pC;
      }
    }
  }
  return NULL;
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::Done()
{
  BOOST_FOREACH(TDescRecv& descRecv, mVecRecv)
  {
    BOOST_FOREACH(TDescSender& descSender, descRecv.vec)
    {
      delete descSender.pList;
    }
  }
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::AddEventCopy(int id_sender, int id_recv, void* data, int size)
{
  TDescSender* pDescSender = NULL;
  pDescSender = Find(id_recv, id_sender);
  if(pDescSender)
  {
    IContainer* pC = new TContainer;
    pC->SetData((char*)data,size);
    pDescSender->pList->Add(pC);
  }
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::AddEventWithoutCopy(int id_sender, int id_recv, IContainer* pC)
{
  TDescSender* pDescSender = NULL;
  pDescSender = Find(id_recv, id_sender);
  if(pDescSender)
    pDescSender->pList->Add(pC);
}
//-----------------------------------------------------------------------------------------
TSynchroPoint::TDescRecv* TSynchroPoint::FindByRecv(int id_recv)
{
  int cnt = mVecRecv.size();
  for(int i = 0 ; i < cnt ; i++ )
  {
    TDescRecv* pDescRecv = &mVecRecv[i];
    if(pDescRecv->id==id_recv)
      return pDescRecv;
  }
  BL_FIX_BUG();
  return NULL;
}
//-----------------------------------------------------------------------------------------
TSynchroPoint::TDescSender* TSynchroPoint::Find(int id_recv, int id_sender)
{
  TDescRecv* pDescRecv = NULL;
  pDescRecv = FindByRecv(id_recv);
  if(pDescRecv)
  {
    int cnt = pDescRecv->vec.size();
    for( int i = 0 ; i < cnt ; i++ )
    {
      TDescSender* pDescSender = &pDescRecv->vec[i];
      if(pDescSender->id==id_sender)
        return pDescSender;
    }
  }

  BL_FIX_BUG();
  return NULL;
}
//-----------------------------------------------------------------------------------------

