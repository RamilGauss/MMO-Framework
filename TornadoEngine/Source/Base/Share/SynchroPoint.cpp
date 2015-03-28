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
	mListIDAbonent.push_back(id_abonent);
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::SetupAfterRegister()
{
	// матрица всех возможных комбинаций
	BOOST_FOREACH(int& id_recv, mListIDAbonent)
	{
		TMapIntPtr mapID_RecvList;
		BOOST_FOREACH(int& id_sender, mListIDAbonent)
		{
			if(id_recv!=id_sender)
				mapID_RecvList.insert(TMapIntPtrVT(id_sender, new TListContainer));
		}
		mMap_Recv_Sender_ListEvent.insert(TMapIntMapVT(id_recv,mapID_RecvList));
	}
}
//-----------------------------------------------------------------------------------------
IContainer* TSynchroPoint::GetEvent(int id_reciver, int& id_sender)
{
	TMapIntMapIt fitSender_List = mMap_Recv_Sender_ListEvent.find(id_reciver);
	if(fitSender_List==mMap_Recv_Sender_ListEvent.end())
	{
		BL_FIX_BUG();
		return NULL;
	}

	BOOST_FOREACH(TMapIntPtrVT& vtSenderList, fitSender_List->second)
	{
		IContainer** ppC = vtSenderList.second->GetFirst();
		if(ppC)
		{
			id_sender = vtSenderList.first;
			IContainer* pC = *ppC;
			vtSenderList.second->ZeroPointerElement(ppC);
			vtSenderList.second->Remove(ppC);
			return pC;
		}
	}
	return NULL;
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::Done()
{
  BOOST_FOREACH(TMapIntMapVT& vtRecvSend, mMap_Recv_Sender_ListEvent)
  {
    BOOST_FOREACH(TMapIntPtrVT& vtSendList, vtRecvSend.second)
    {
      delete vtSendList.second;
    }
  }
}
//-----------------------------------------------------------------------------------------
bool TSynchroPoint::FindListEvents(int id_sender, int id_recv, TMapIntPtrIt& fitSendList)
{
	TMapIntMapIt fitRecvSend = mMap_Recv_Sender_ListEvent.find(id_recv);
	if(fitRecvSend==mMap_Recv_Sender_ListEvent.end())
	{
		BL_FIX_BUG();
		return false;
	}

	fitSendList = fitRecvSend->second.find(id_sender);
	if(fitRecvSend->second.end()==fitSendList)
	{
		BL_FIX_BUG();
		return false;
	}

	return true;
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::AddEventCopy(int id_sender, int id_recv, void* data, int size)
{
	TMapIntPtrIt fitSendList;
	if(FindListEvents(id_sender, id_recv, fitSendList)==false)
		return;

  IContainer* pC = new TContainer;
  pC->SetData((char*)data,size);
  fitSendList->second->Add(pC);
}
//-----------------------------------------------------------------------------------------
void TSynchroPoint::AddEventWithoutCopy(int id_sender, int id_recv, IContainer* pC)
{
	TMapIntPtrIt fitSendList;
	if(FindListEvents(id_sender, id_recv, fitSendList)==false)
		return;

	fitSendList->second->Add(pC);
}
//-----------------------------------------------------------------------------------------
