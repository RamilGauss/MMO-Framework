/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerContextMoreDownClientConnection.h"

#include <boost/foreach.hpp>

#include "Logger.h"
#include "ContainerContextSc.h"
#include "Base.h"

using namespace nsMMOEngine;
using namespace std;

TManagerContextMoreDownClientConnection::TManagerContextMoreDownClientConnection()
{

}
//-------------------------------------------------------------------------
TManagerContextMoreDownClientConnection::~TManagerContextMoreDownClientConnection()
{
  Clear();
}
//-------------------------------------------------------------------------
bool TManagerContextMoreDownClientConnection::FindSessionByClientKey(unsigned int id_client, 
                                                                     unsigned int &id_session)
{
  TMapUintUintIt fit = mMapKeySession.find(id_client);
  if(fit==mMapKeySession.end())
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TManagerContextMoreDownClientConnection::FindSessionByClientKey(key=%u) not found.\n",id_client);
    return false;
  }
  id_session = fit->second;
  return true;
}
//-------------------------------------------------------------------------
TContainerContextSc* TManagerContextMoreDownClientConnection::FindContextByClientKey(unsigned int id_client)
{
  TMapUintPtrIt fit = mMapKeyContext.find(id_client);
  if(fit==mMapKeyContext.end())
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TManagerContextMoreDownClientConnection::FindContextByClientKey(key=%u) not found.\n",id_client);
    return NULL;
  }
  return fit->second;
}
//-------------------------------------------------------------------------
TContainerContextSc* TManagerContextMoreDownClientConnection::AddContext(unsigned int id_client, 
                                                                         unsigned int id_session)
{
  BL_ASSERT(id_session!=INVALID_HANDLE_SESSION);
  
  TContainerContextSc* pC = FindContextByClientKey(id_client);
  if(pC==NULL)
  {
    pC = AddContainer();

    mMapKeyContext.insert(TMapUintPtr::value_type(id_client,pC));
    mMapKeySession.insert(TMapUintUint::value_type(id_client,id_session));
  }
  return pC;
}
//-------------------------------------------------------------------------
void TManagerContextMoreDownClientConnection::DeleteByKey(unsigned int key)
{
  TContainerContextSc* pC = FindContextByClientKey(key);
  if(pC==NULL)
    return;

  DeleteContainer(pC);
  mMapKeyContext.erase(key);
  mMapKeySession.erase(key);
}
//-------------------------------------------------------------------------
void TManagerContextMoreDownClientConnection::Clear()
{
  BOOST_FOREACH(TMapUintPtr::value_type& bit,mMapKeyContext)
    DeleteContainer(bit.second);

  mMapKeyContext.clear();
  mMapKeySession.clear();
}
//-------------------------------------------------------------------------
bool TManagerContextMoreDownClientConnection::SetSessionByClientKey(unsigned int id_client, 
                                                                    unsigned int id_session)
{
  TMapUintUintIt fit = mMapKeySession.find(id_client);
  if(fit==mMapKeySession.end())
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TManagerContextMoreDownClientConnection::SetSessionByClientKey(key=%u) not found.\n",id_client);
    return false;
  }
  fit->second = id_session;
  return true;
}
//-------------------------------------------------------------------------