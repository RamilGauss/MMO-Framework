/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
√удаков –амиль —ергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MANAGER_CONTEXT_CLIENT_SLAVE_H
#define MANAGER_CONTEXT_CLIENT_SLAVE_H

#include <map>
#include "DelegateManagerContextSc.h"

namespace nsMMOEngine
{
  class TContainerContextSc;
  class TManagerContextClient_slave : public TDelegateManagerContextSc
  {
    typedef std::map<unsigned int, TContainerContextSc*> TMapUintPtr;
    typedef TMapUintPtr::iterator TMapUintPtrIt;

    typedef std::map<unsigned int, unsigned int> TMapUintUint;
    typedef TMapUintUint::iterator TMapUintUintIt;
    
    TMapUintPtr  mMapKeyContext;    
    TMapUintUint mMapKeySession;// 
    
    // содержит отличные от INVALID_HANDLE_SESSION значени€
    TMapUintUint mMapSessionKey;// размер может быть меньше чем mMapKeySession

  public:
    TManagerContextClient_slave();
    ~TManagerContextClient_slave();
    
    // навигаци€
    bool FindSessionByKey(unsigned int id,         unsigned int& id_session);
    bool FindKeyBySession(unsigned int id_session, unsigned int& id);
    TContainerContextSc* FindContextByKey(unsigned int id);
    TContainerContextSc* FindContextBySession(unsigned int id_session);
    
    bool GetSessionByIndex(int index, unsigned int& id_session);
    int  GetCountSession();

    bool GetFirstKey(unsigned int& id);
    int GetCountKey();

    // добавление/удаление
    TContainerContextSc* AddContextByKey(unsigned int key);
    
    // изменение
    void AddSessionByKey(unsigned int key, unsigned int id_session);

    // удаление
    void DeleteByKey(unsigned int key);
	private:
    void Clear();

    bool FindInMapUintUint(TMapUintUint& map, 
                           unsigned int key, 
                           unsigned int& value);
  };
}

#endif

