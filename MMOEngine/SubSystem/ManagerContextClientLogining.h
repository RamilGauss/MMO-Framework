/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MANAGER_CONTEXT_CLIENT_LOGINING_H
#define MANAGER_CONTEXT_CLIENT_LOGINING_H

#include <map>
#include <boost/bimap/bimap.hpp>
#include "DelegateManagerContextSc.h"

namespace nsMMOEngine
{
  class TContainerContextSc;
  class TManagerContextClientLogining : public TDelegateManagerContextSc
  {
    typedef std::map<unsigned int, TContainerContextSc*> TMapUintPtr;
    typedef TMapUintPtr::iterator TMapUintPtrIt;

    typedef boost::bimaps::bimap<unsigned int,unsigned int> bmUintUint;

    TMapUintPtr  mMapSessionContext;
    bmUintUint   mMapSessionKey;
    
  public:
    TManagerContextClientLogining();
    ~TManagerContextClientLogining();
    
    // навигация
    bool FindSessionByClientKey(unsigned int id, unsigned int& id_session);
    bool FindClientKeyBySession(unsigned int id_session, unsigned int& id);
    TContainerContextSc* FindContextBySession(unsigned int id_session);
    
    // добавление/удаление
    TContainerContextSc* AddContext(unsigned int id_session);
    bool AddKeyBySession(unsigned int id_session, unsigned int id_client);
    // удаление
    void DeleteBySession(unsigned int id_session);
	private:
    void Clear();
  };
}

#endif

