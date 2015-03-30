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
  mSynchroPoint->Register(mSelfID);
}
//------------------------------------------------------------------------------
void TSynchroAbonent::AddEventCopy(int id_recv, void* data, int size)
{
  mSynchroPoint->AddEventCopy(mSelfID, id_recv, data, size);
}
//------------------------------------------------------------------------------
IContainer* TSynchroAbonent::GetEvent(int& id_sender)
{
  // найти среди кеша
  IContainer* pC = mSynchroPoint->GetEvent(mSelfID, id_sender);
  if(pC)
    AddCache(pC, id_sender);
  return pC;
}
//------------------------------------------------------------------------------
void TSynchroAbonent::AddCache(IContainer* pC, int id_sender)
{
  TMapIntPtrIt fit = mMapID_LastEvent.find(id_sender);
  if(fit!=mMapID_LastEvent.end())
  {
    delete fit->second;// тип объекта может быть каждый разный, поэтому контейнер нужно каждый раз удалять
    mMapID_LastEvent[id_sender] = pC;
  }
  else
    mMapID_LastEvent.insert(TMapIntPtrVT(id_sender, pC));
}
//------------------------------------------------------------------------------
void TSynchroAbonent::AddEventWithoutCopy(int id_recv, IContainer* pC)
{
  mSynchroPoint->AddEventWithoutCopy(mSelfID, id_recv, pC);
}
//------------------------------------------------------------------------------
