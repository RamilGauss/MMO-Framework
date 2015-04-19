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

#include <algorithm>


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
  sort(mVecIDAbonent.begin(), mVecIDAbonent.end());

  int cntAbonent = mVecIDAbonent.size();
  int cntID = mVecIDAbonent[cntAbonent-1] + 1;
  // матрица всех возможных комбинаций
  int IndexRecver = 0;
  for(int id_recver = 0 ; id_recver < cntID ; id_recver++ )
  {
    TVecPtr vectorRecvList;
    if(mVecIDAbonent[IndexRecver]==id_recver)
    {
      int IndexSender = 0;
      for(int id_sender = 0 ; id_sender < cntID ; id_sender++ )
      {
        if(mVecIDAbonent[IndexSender]==id_sender)
        {
          vectorRecvList.push_back(new TListContainer);
          IndexSender++;
        }
        else
          vectorRecvList.push_back(NULL);
      }
      IndexRecver++;
    }

    mVec_Recv_Sender_ListEvent.push_back(vectorRecvList);
  }
}
//-----------------------------------------------------------------------------------------
IContainer* TSynchroPoint::GetEvent(int id_reciver, int& id_sender)
{
  if(id_reciver >= int(mVec_Recv_Sender_ListEvent.size()))
  {
    BL_FIX_BUG();
    return NULL;
  }

  TVecPtr& vecList = mVec_Recv_Sender_ListEvent[id_reciver];
  for(id_sender = 0 ; id_sender < int(vecList.size()) ; id_sender++)
  {
    TListContainer* ptrList = vecList[id_sender];
    if(ptrList==NULL)
      continue;

    IContainer** ppC = ptrList->GetFirst();
    if(ppC)
    {
      IContainer* pC = *ppC;
      ptrList->ZeroPointerElement(ppC);
      ptrList->Remove(ppC);
      return pC;
    }
  }
  return NULL;
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::Done()
{
  BOOST_FOREACH(TVecPtr& vecPtr, mVec_Recv_Sender_ListEvent)
  {
    BOOST_FOREACH(TListContainer*& ptrList, vecPtr)
    {
      delete ptrList;
    }
  }
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::AddEventCopy(int id_sender, int id_recv, void* data, int size)
{
  if(id_recv >= int(mVec_Recv_Sender_ListEvent.size()))
  {
    BL_FIX_BUG();
    return;
  }

  TVecPtr& vecList = mVec_Recv_Sender_ListEvent[id_recv];

  IContainer* pC = new TContainer;
  pC->SetData((char*)data,size);
  vecList[id_sender]->Add(pC);
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::AddEventWithoutCopy(int id_sender, int id_recv, IContainer* pC)
{
  if(id_recv >= int(mVec_Recv_Sender_ListEvent.size()))
  {
    BL_FIX_BUG();
    return;
  }

  TVecPtr& vecList = mVec_Recv_Sender_ListEvent[id_recv];
  vecList[id_sender]->Add(pC);
}
//-----------------------------------------------------------------------------------------
