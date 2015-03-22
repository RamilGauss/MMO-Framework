/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SynchroPoint.h"
#include <boost/foreach.hpp>
#include "BL_Debug.h"


TSynchroPoint::TSynchroPoint()
{

}
//-----------------------------------------------------------------------------------------
TSynchroPoint::~TSynchroPoint()
{
  Done();
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::Register(int id_reciver, int id_sender)
{
  TMapIntMapIt fitRecvList = mMap_Sender_Recv_ListEvent.find(id_sender);
  if(fitRecvList==mMap_Sender_Recv_ListEvent.end())
  {
    TMapIntPtr mapRecvList;
    TListContainer* pList = new TListContainer;
    mapRecvList[id_reciver] = pList;

    mMap_Sender_Recv_ListEvent[id_sender] = mapRecvList;
    return;
  }
    
  TMapIntPtrIt fitList = fitRecvList->second.find(id_reciver);
  if(fitList!=fitRecvList->second.end())
    return;

  TListContainer* pList = new TListContainer;
  fitRecvList->second[id_reciver] = pList;
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::AddEventCopy(int id_sender, void* data, int size)
{
  AddEvent(id_sender, data, size, true);
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::AddEventWithoutCopy(int id_sender, void* data, int size)
{
  AddEvent(id_sender, data, size, false);
}
//-----------------------------------------------------------------------------------------
bool TSynchroPoint::GetEvent(int id_reciver, int id_sender, TContainer* pC_out)
{
  TMapIntMapIt fitRecv_List = mMap_Sender_Recv_ListEvent.find(id_sender);
  if(fitRecv_List==mMap_Sender_Recv_ListEvent.end())
    return false;

  TMapIntPtrIt fitList = fitRecv_List->second.find(id_reciver);
  if(fitList==fitRecv_List->second.end())
    return false;

  TContainer** ppC = fitList->second->GetFirst();
  if(ppC==NULL)
    return false;

  TContainer* pC = *ppC;
  pC_out->Entrust(pC->GetPtr(), pC->GetSize());
  pC->Unlink();
  fitList->second->Remove(ppC);

  return true;
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::Done()
{
  BOOST_FOREACH(TMapIntMapVT& vtSendRecv, mMap_Sender_Recv_ListEvent)
  {
    BOOST_FOREACH(TMapIntPtrVT& vtRecvList, vtSendRecv.second)
    {
      delete vtRecvList.second;
    }
  }
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::AddEvent(int id_sender, void* data, int size, bool copy)
{
  TMapIntMapIt fitSendRecv = mMap_Sender_Recv_ListEvent.find(id_sender);
  if(fitSendRecv==mMap_Sender_Recv_ListEvent.end())
  {
    BL_FIX_BUG();
    return;
  }

  int i = 0;
  int count = fitSendRecv->second.size();
  BOOST_FOREACH(TMapIntPtrVT& vtRecvList, fitSendRecv->second)
  {
    TContainer* pC = new TContainer;

    if(i==count-1)
    {
      if(copy)
        pC->SetData((char*)data,size);
      else
        pC->Entrust((char*)data,size);
    }
    else
      pC->SetData((char*)data,size);

    vtRecvList.second->Add(pC);
    i++;
  }
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::AddEventCopy(int id_sender, int id_recv, void* data, int size)
{
  AddEvent(id_sender, id_recv, data, size, true);
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::AddEventWithoutCopy(int id_sender, int id_recv, void* data, int size)
{
  AddEvent(id_sender, id_recv, data, size, false);
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::AddEvent(int id_sender, int id_recv, void* data, int size, bool copy)
{
  TMapIntMapIt fitSendRecv = mMap_Sender_Recv_ListEvent.find(id_sender);
  if(fitSendRecv==mMap_Sender_Recv_ListEvent.end())
  {
    BL_FIX_BUG();
    return;
  }

  TMapIntPtrIt fitRecvList = fitSendRecv->second.find(id_recv);
  if(fitSendRecv->second.end()==fitRecvList)
  {
    BL_FIX_BUG();
    return;
  }

  TContainer* pC = new TContainer;
  if(copy)
    pC->SetData((char*)data,size);
  else
    pC->Entrust((char*)data,size);
  fitRecvList->second->Add(pC);
}
//-----------------------------------------------------------------------------------------
