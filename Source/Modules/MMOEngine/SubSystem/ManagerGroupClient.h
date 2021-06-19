/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include <map>
#include <set>

namespace nsMMOEngine
{
  class TManagerGroupClient
  {
    typedef std::map<unsigned int, unsigned int> TMapUintUint;
    typedef TMapUintUint::iterator TMapUintUintIt;

    typedef std::set<unsigned int> TSetUint;
    typedef TSetUint::iterator TSetUintIt;

    typedef std::map<unsigned int, TSetUint > TMapUintSetUint;
    typedef TMapUintSetUint::iterator TMapUintSetUintIt;

    TMapUintUint    mMapID_SlaveSession;
    TMapUintSetUint mMapID_ClientKey;

    TMapUintUint    mMapClientKey_ID;

    unsigned int mNextID_createGroup;
  public:
    TManagerGroupClient();
    ~TManagerGroupClient();

    // навигация
    bool FindSessionByID( unsigned int groupID, unsigned int& sessionID );
    bool FindIDByClientKey( unsigned int clientKey, unsigned int& groupID );

    int GetCountID();
    bool GetIDByIndex( int index, unsigned int& groupID );

    int GetCountClientKey( unsigned int groupID );
    bool GetClientKeyByIndex( unsigned int groupID, int index, unsigned int& clientKey );

    // добавление/удаление
    unsigned int AddGroup( unsigned int sessionID );
    // добавить в группу клиента
    bool AddClientKey( unsigned int groupID, unsigned int clientKey );
    // для данной группы установить сессию
    bool SetSessionByID( unsigned int groupID, unsigned int sessionID );

    // удаление
    void DeleteClientKey( unsigned int clientKey );
    void DeleteByID( unsigned int groupID );
  private:
    // добавление/удаление
    void AddGroup( unsigned int groupID, unsigned int sessionID );
  };
}
