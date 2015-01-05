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
}
//------------------------------------------------------------------------------
void TSynchroAbonent::AddEventCopy(void* data, int size)
{
  lock();
	mSynchroPoint->AddEventCopy(mSelfID, data, size);
  unlock();
}
//------------------------------------------------------------------------------
void TSynchroAbonent::AddEventWithoutCopy(void* data, int size)
{
  lock();
  mSynchroPoint->AddEventWithoutCopy(mSelfID, data, size);
  lock();
}
//------------------------------------------------------------------------------
TContainer* TSynchroAbonent::GetEvent(int id_sender)
{
  lock();
  // найти среди кеша
	TContainer* pC = FindContainerByID(id_sender);
	bool res = mSynchroPoint->GetEvent(mSelfID, id_sender, pC);
  lock();
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
