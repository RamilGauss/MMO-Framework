/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

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
    TManagerContextDownConnection( TBase* pBase );
    virtual ~TManagerContextDownConnection();

    // навигация
    TContainerContextSc* FindContextBySession( unsigned int sessionID );
    bool FindSessionByClientKey( unsigned int clientKey, unsigned int &id_session_slave );

    int GetCountSession();
    bool GetSessionByIndex( int index, unsigned int& sessionID );

    bool GetCountClientKey( unsigned int sessionID, int &count );
    bool GetClientKeyByIndex( unsigned int sessionID, int index, unsigned int& clientKey );

    // добавление/удаление
    TContainerContextSc* AddContext( unsigned int sessionID );
    bool AddClientKey( unsigned int sessionID, unsigned int clientKey );

    // удаление
    void DeleteByClientKey( unsigned int sessionID, unsigned int clientKey );
    void DeleteContextBySession( unsigned int sessionID );
  protected:
    virtual void AddSessionEvent( unsigned int sessionID )
    {}
    virtual void DeleteSessionEvent( unsigned int sessionID )
    {}
  private:
    void Clear();
  };
}
