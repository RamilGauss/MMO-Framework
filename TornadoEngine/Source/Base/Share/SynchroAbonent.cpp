/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "SynchroAbonent.h"
#include <boost/foreach.hpp>
#include "SynchroPoint.h"

TSynchroAbonent::TSynchroAbonent()
{
	mSynchroPoint = NULL;
	mSelfID       = -1;
}
//------------------------------------------------------------------------------
TSynchroAbonent::~TSynchroAbonent()
{
	BOOST_FOREACH(TMapIntPtrVT& vt, mMapID_LastEvent)
		delete vt.second;
	mMapID_LastEvent.clear();
}
//------------------------------------------------------------------------------
void TSynchroAbonent::SetSynchroPoint(TSynchroPoint* p)
{
	mSynchroPoint = p;
}
//------------------------------------------------------------------------------
void TSynchroAbonent::SetSelfID(int id)
{
  mSelfID = id;
}
//------------------------------------------------------------------------------
void TSynchroAbonent::Register(int id_sender)
{
	mSynchroPoint->Register(mSelfID, id_sender);
  mVecID_Senders.push_back(id_sender);
}
//------------------------------------------------------------------------------
void TSynchroAbonent::AddEventCopy(void* data, int size)
{
	mSynchroPoint->AddEventCopy(mSelfID, data, size);
}
//------------------------------------------------------------------------------
void TSynchroAbonent::AddEventWithoutCopy(void* data, int size)
{
  mSynchroPoint->AddEventWithoutCopy(mSelfID, data, size);
}
//------------------------------------------------------------------------------
void TSynchroAbonent::AddEventCopy(int id_recv, void* data, int size)
{
  mSynchroPoint->AddEventCopy(mSelfID, id_recv, data, size);
}
//------------------------------------------------------------------------------
void TSynchroAbonent::AddEventWithoutCopy(int id_recv, void* data, int size)
{
  mSynchroPoint->AddEventWithoutCopy(mSelfID, id_recv, data, size);
}
//------------------------------------------------------------------------------
TContainer* TSynchroAbonent::GetEvent(int id_sender)
{
  // найти среди кеша
	TContainer* pC = FindContainerByID(id_sender);
	bool res = mSynchroPoint->GetEvent(mSelfID, id_sender, pC);
  if(res)
    return pC;

	return NULL;
}
//------------------------------------------------------------------------------
TContainer* TSynchroAbonent::FindContainerByID(int id)
{
	TMapIntPtrIt fit = mMapID_LastEvent.find(id);
	if(fit!=mMapID_LastEvent.end())
		return fit->second;

	TContainer* pC = new TContainer;
	mMapID_LastEvent.insert(TMapIntPtrVT(id, pC));
	return pC;
}
//------------------------------------------------------------------------------
int TSynchroAbonent::GetCountSenders()
{
  return mVecID_Senders.size();
}
//------------------------------------------------------------------------------
int TSynchroAbonent::GetID_SenderByIndex(int index)
{
  if(index >= GetCountSenders() || index < 0)
    return -1;
  return mVecID_Senders[index];
}
//------------------------------------------------------------------------------
