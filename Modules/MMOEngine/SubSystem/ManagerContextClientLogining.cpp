/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "ManagerContextClientLogining.h"

#include <boost/foreach.hpp>

#include "Logger.h"
#include "ContainerContextSc.h"
#include "Base.h"

using namespace nsMMOEngine;
using namespace std;

TManagerContextClientLogining::TManagerContextClientLogining()
{

}
//-------------------------------------------------------------------------------------------
TManagerContextClientLogining::~TManagerContextClientLogining()
{
  Clear();
}
//-------------------------------------------------------------------------------------------
bool TManagerContextClientLogining::FindSessionByClientKey(unsigned int id, 
                                                           unsigned int& id_session)
{
  const bmUintUint::right_iterator fit = mMapSessionKey.right.find(id);
  if(fit==mMapSessionKey.right.end())
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TManagerContextClientLogining::FindSessionByClientKey(id=%u) not found.\n",id);
    return false;
  }
  id_session = fit->second;
  return true;
}
//-------------------------------------------------------------------------------------------
bool TManagerContextClientLogining::FindClientKeyBySession(unsigned int id_session, 
                                                           unsigned int& id)
{
  const bmUintUint::left_iterator fit = mMapSessionKey.left.find(id_session);
  if(fit==mMapSessionKey.left.end())
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TManagerContextClientLogining::FindClientKeyBySession(session=%u) not found.\n",id_session);
    return false;
  }
  id = fit->second;
  return true;
}
//-------------------------------------------------------------------------------------------
TContainerContextSc* TManagerContextClientLogining::FindContextBySession(unsigned int id_session)
{
  TMapUintPtrIt fit = mMapSessionContext.find(id_session);
  if(fit==mMapSessionContext.end())
  {
    GetLogger(STR_NAME_MMO_ENGINE)->
      WriteF_time("TManagerContextClientLogining::FindContextBySession(session=%u) not found.\n",id_session);
    return NULL;
  }
  return fit->second;
}
//-------------------------------------------------------------------------------------------
TContainerContextSc* TManagerContextClientLogining::AddContext(unsigned int id_session)
{
  BL_ASSERT(id_session!=INVALID_HANDLE_SESSION);

  TContainerContextSc* pC = FindContextBySession(id_session);
  if(pC==NULL)
  {
    pC = AddContainer();
    mMapSessionContext.insert(TMapUintPtr::value_type(id_session,pC));
  }
  return pC;
}
//-------------------------------------------------------------------------------------------
bool TManagerContextClientLogining::AddKeyBySession(unsigned int id_session, 
                                                    unsigned int id_client)
{
  if(FindContextBySession(id_session)==NULL)
  {
    BL_FIX_BUG();
    return false;
  }

  mMapSessionKey.insert(bmUintUint::value_type(id_session,id_client));
  return true;
}
//-------------------------------------------------------------------------------------------
void TManagerContextClientLogining::DeleteBySession(unsigned int id_session)
{
  TContainerContextSc* pC = FindContextBySession(id_session);
  if(pC==NULL)
    return;

  DeleteContainer(pC);
  mMapSessionContext.erase(id_session);
  mMapSessionKey.left.erase(id_session);
}
//-------------------------------------------------------------------------------------------
void TManagerContextClientLogining::Clear()
{
  BOOST_FOREACH(TMapUintPtr::value_type& bit,mMapSessionContext)
    DeleteContainer(bit.second);

  mMapSessionContext.clear();
  mMapSessionKey.clear();
}
//-------------------------------------------------------------------------------------------
