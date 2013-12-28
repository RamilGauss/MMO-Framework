/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MANAGER_CONTEXT_DOWN_CONNECTION_H
#define MANAGER_CONTEXT_DOWN_CONNECTION_H

#include <map>
#include <set>
#include "DelegateManagerContextSc.h"

namespace nsMMOEngine
{
  class TContainerContextSc;
  class TManagerContextDownConnection : public TDelegateManagerContextSc
  {
    typedef std::map<unsigned int, TContainerContextSc*> TMapUintPtr;
    typedef TMapUintPtr::iterator TMapUintPtrIt;

    typedef std::set<unsigned int> TSetUint;
    typedef TSetUint::iterator TSetUintIt;

    typedef std::map<unsigned int, TSetUint > TMapUintSetUint;
    typedef TMapUintSetUint::iterator TMapUintSetUintIt;
    
    TMapUintPtr     mMapSessionContext;
    TMapUintSetUint mMapSessionKey;
    
  public:
    TManagerContextDownConnection();
    virtual ~TManagerContextDownConnection();
    
    // навигация
    TContainerContextSc* FindContextBySession(unsigned int id_session);
    
    int GetCountSession();
    bool GetSessionByIndex( int index, unsigned int& id_session);

    bool GetCountClientKey(unsigned int id_session, int &count);
    bool GetClientKeyByIndex(unsigned int id_session, 
                             int index, 
                             unsigned int& id_client);

    // добавление/удаление
    TContainerContextSc* AddContext(unsigned int id_session);
    bool AddClientKey(unsigned int id_session, 
                      unsigned int id_client);

    // удаление
    void DeleteByClientKey(unsigned int id_session, unsigned int id_client);
    void DeleteContextBySession(unsigned int id_session);
	protected:
		virtual void AddSessionEvent(unsigned int id_session){}
		virtual void DeleteSessionEvent(unsigned int id_session){}
	private:
    void Clear();
  };
}

#endif

