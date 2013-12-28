/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerGroupClient.h"

#include <boost/foreach.hpp>

#include "Logger.h"
#include "Base.h"
#include <list>

using namespace nsMMOEngine;
using namespace std;

TManagerGroupClient::TManagerGroupClient()
{
  mNextID_createGroup = 0;
}
//------------------------------------------------------------------------------------
TManagerGroupClient::~TManagerGroupClient()
{

}
//------------------------------------------------------------------------------------
bool TManagerGroupClient::FindSessionByID(unsigned int id_group, 
                                          unsigned int& id_session)
{
  TMapUintUintIt fit = mMapID_SlaveSession.find(id_group);
  if(fit==mMapID_SlaveSession.end())
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TManagerGroupClient::FindSessionByID(id_group=%u) not found.\n",id_group);
    return false;
  }
  id_session = fit->second;
  return true;
}
//------------------------------------------------------------------------------------
bool TManagerGroupClient::FindIDByClientKey(unsigned int id_client, 
                                            unsigned int& id_group)
{
  TMapUintUintIt fit = mMapClientKey_ID.find(id_client);
  if(fit==mMapClientKey_ID.end())
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TManagerGroupClient::FindIDByClientKey(id_client=%u) not found.\n",id_client);
    return false;
  }
  id_group = fit->second;
  return true;
}
//------------------------------------------------------------------------------------
int TManagerGroupClient::GetCountID()
{
  return mMapID_SlaveSession.size();
}
//------------------------------------------------------------------------------------
bool TManagerGroupClient::GetIDByIndex( int index, unsigned int& id_group)
{
  if(GetCountID()<=index)
    return false;
  TMapUintUintIt it = mMapID_SlaveSession.begin();
  for(int i = 0 ; i < index ; i++)
    it++;
  id_group = it->first;
  return true; 
}
//------------------------------------------------------------------------------------
int TManagerGroupClient::GetCountClientKey(unsigned int id_group)
{
  TMapUintSetUintIt fit = mMapID_ClientKey.find(id_group);
  if(fit==mMapID_ClientKey.end())
    return 0;
  return fit->second.size();
}
//------------------------------------------------------------------------------------
bool TManagerGroupClient::GetClientKeyByIndex(unsigned int id_group, 
                                              int index, 
                                              unsigned int& id_client)
{
  TMapUintSetUintIt fit = mMapID_ClientKey.find(id_group);
  if(fit==mMapID_ClientKey.end())
    return false;

  TSetUintIt it = fit->second.begin();
  if(GetCountClientKey(id_group)<=index)
    return false;
  for(int i = 0 ; i < index ; i++)
    it++;
  id_client = *it;
  return true;
}
//------------------------------------------------------------------------------------
unsigned int TManagerGroupClient::AddGroup(unsigned int id_session)
{
  mNextID_createGroup++;
  AddGroup(mNextID_createGroup, id_session);
  return mNextID_createGroup;
}
//------------------------------------------------------------------------------------
void TManagerGroupClient::AddGroup(unsigned int id_group, unsigned int id_session)
{
  mMapID_SlaveSession.insert(TMapUintUint::value_type(id_group, id_session));
  mMapID_ClientKey.insert(TMapUintSetUint::value_type(id_group, TSetUint()));
}
//------------------------------------------------------------------------------------
bool TManagerGroupClient::AddClientKey(unsigned int id_group, unsigned int id_client)
{
  TMapUintSetUintIt fit = mMapID_ClientKey.find(id_group);
  if(fit==mMapID_ClientKey.end())
    return false;
  fit->second.insert(TSetUint::value_type(id_client));

  mMapClientKey_ID.insert(TMapUintUint::value_type(id_client,id_group));
  return true;
}
//------------------------------------------------------------------------------------
bool TManagerGroupClient::SetSessionByID(unsigned int id_group, unsigned int id_session)
{
  TMapUintUintIt fit = mMapID_SlaveSession.find(id_group);
  if(fit==mMapID_SlaveSession.end())
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TManagerGroupClient::SetSessionByID(id_group=%u) not found.\n",id_group);
    return false;
  }
  fit->second = id_session;
  return false;
}
//------------------------------------------------------------------------------------
void TManagerGroupClient::DeleteClientKey(unsigned int id_client)
{
  unsigned int id_group;
  if(FindIDByClientKey(id_client,id_group)==false)
    return;
  TMapUintSetUintIt fit = mMapID_ClientKey.find(id_group);
  if(fit==mMapID_ClientKey.end())
    return;
  // связка группа---множество клиентов
  fit->second.erase(id_client);
  // связка клиента---группа
  mMapClientKey_ID.erase(id_client);
}
//------------------------------------------------------------------------------------
void TManagerGroupClient::DeleteByID(unsigned int id_group)
{
  list<unsigned int> listClientOnErase;
  // поиск всех клиентов, связанных с данной группой
  int countClient = GetCountClientKey(id_group);
  // сформировать список ключей клиентов, которые содержаться в данной группе
  for( int i = 0 ; i < countClient ; i++ )
  {
    unsigned int id_client;
    GetClientKeyByIndex(id_group, i, id_client);
    listClientOnErase.push_back(id_client);
  }
  // удалить все упоминания о ключах
  BOOST_FOREACH(unsigned int id_client, listClientOnErase)
    DeleteClientKey(id_client);
  // группа---сессия Slave
  mMapID_SlaveSession.erase(id_group);
}
//------------------------------------------------------------------------------------
