/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerContextDownConnection.h"

#include <boost/foreach.hpp>

#include "Logger.h"
#include "ContainerContextSc.h"
#include "Base.h"

using namespace nsMMOEngine;

TManagerContextDownConnection::TManagerContextDownConnection(TBase* pBase):
TDelegateManagerContextSc(pBase)
{

}
//-----------------------------------------------------------------------------------
TManagerContextDownConnection::~TManagerContextDownConnection()
{
  Clear();
}
//-----------------------------------------------------------------------------------
TContainerContextSc* TManagerContextDownConnection::FindContextBySession(unsigned int id_session)
{
  TMapUintPtrIt fit = mMapSessionContext.find(id_session);
  if(fit==mMapSessionContext.end())
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TManagerContextDownConnection::FindContextBySession(id_session=%u) not found.\n",id_session);
    return NULL;
  }
  return fit->second;
}
//-----------------------------------------------------------------------------------
int TManagerContextDownConnection::GetCountSession()
{
  return mMapSessionContext.size();
}
//-----------------------------------------------------------------------------------
bool TManagerContextDownConnection::GetSessionByIndex( int index, unsigned int& id_session)
{
  if(GetCountSession()<=index)
    return false;
  TMapUintPtrIt it = mMapSessionContext.begin();
  for(int i = 0 ; i < index ; i++)
    it++;
  id_session = it->first;
  return true; 
}
//-----------------------------------------------------------------------------------
bool TManagerContextDownConnection::GetCountClientKey(unsigned int id_session, 
                                                      int &count)
{
  TMapUintSetUintIt fit = mMapSessionKey.find(id_session);
  if(fit==mMapSessionKey.end())
    return false;
  count = fit->second.size();
  return true;
}
//-----------------------------------------------------------------------------------
bool TManagerContextDownConnection::GetClientKeyByIndex(unsigned int id_session, 
                                                   int index, 
                                                   unsigned int& id_client)
{
  TMapUintSetUintIt fit = mMapSessionKey.find(id_session);
  if(fit==mMapSessionKey.end())
    return false;

  TSetUintIt it = fit->second.begin();
  int count;
  if(GetCountClientKey(id_session, count)==false)
    return false;
  if(count<=index)
    return false;
  for(int i = 0 ; i < index ; i++)
    it++;
  id_client = *it;
  return true;
}
//-----------------------------------------------------------------------------------
TContainerContextSc* TManagerContextDownConnection::AddContext(unsigned int id_session)
{
  BL_ASSERT(id_session!=INVALID_HANDLE_SESSION);

  TContainerContextSc* pC = FindContextBySession(id_session);
  if(pC==NULL)
  {
    pC = AddContainer();
    mMapSessionContext.insert(TMapUintPtr::value_type(id_session,pC));
    mMapSessionKey.insert(TMapUintSetUint::value_type(id_session,TSetUint()));

		AddSessionEvent(id_session);
  }
  return pC;
}
//-----------------------------------------------------------------------------------
bool TManagerContextDownConnection::AddClientKey(unsigned int id_session, 
                                                 unsigned int id_client)
{
  // проверка на существование такого мастера
  TContainerContextSc* pC = FindContextBySession(id_session);
  if(pC==NULL)
    return false;
  
  TMapUintSetUintIt fit = mMapSessionKey.find(id_session);
  // создать
  if(fit==mMapSessionKey.end())
  {
    //mMapSessionKey.insert(TMapUintSetUint::value_type(id_session,TSetUint()));
    //fit = mMapSessionKey.find(id_session);
    BL_FIX_BUG();
  }

  fit->second.insert(TSetUint::value_type(id_client));
  return true;
}
//-----------------------------------------------------------------------------------
void TManagerContextDownConnection::DeleteByClientKey(unsigned int id_session,
                                                      unsigned int id_client)
{
  TMapUintSetUintIt fit = mMapSessionKey.find(id_session);
  if(fit==mMapSessionKey.end())
    return;
  fit->second.erase(id_client);
}
//-----------------------------------------------------------------------------------
void TManagerContextDownConnection::DeleteContextBySession(unsigned int id_session)
{
  TContainerContextSc* pC = FindContextBySession(id_session);
  if(pC==NULL)
    return;

  DeleteContainer(pC);
  mMapSessionContext.erase(id_session);
  mMapSessionKey.erase(id_session);

	DeleteSessionEvent(id_session);
}
//-----------------------------------------------------------------------------------
void TManagerContextDownConnection::Clear()
{
  BOOST_FOREACH(TMapUintPtr::value_type& it, mMapSessionContext)
    DeleteContainer(it.second);

  mMapSessionKey.clear();
  mMapSessionContext.clear();
}
//-----------------------------------------------------------------------------------
bool TManagerContextDownConnection::FindSessionByClientKey(unsigned int id_client, unsigned int &id_session_slave)
{
	BOOST_FOREACH(TMapUintSetUint::value_type& it, mMapSessionKey)
	{
		TSetUintIt fit = it.second.find(id_client);
		if(fit!=it.second.end())
		{
			id_session_slave = it.first;
			return true;
		}
	}
	return false;
}
//-----------------------------------------------------------------------------------
