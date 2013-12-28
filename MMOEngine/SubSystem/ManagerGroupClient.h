/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef MANAGER_GROUP_CLIENT_H
#define MANAGER_GROUP_CLIENT_H

#include <map>
#include <set>

namespace nsMMOEngine
{
  class TManagerGroupClient
  {
    typedef std::map<unsigned int,unsigned int> TMapUintUint;
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
    bool FindSessionByID(unsigned int id_group, unsigned int& id_session);
    bool FindIDByClientKey(unsigned int id_client, unsigned int& id_group);
    
    int GetCountID();
    bool GetIDByIndex( int index, unsigned int& id_group);

    int GetCountClientKey(unsigned int id_group);
    bool GetClientKeyByIndex(unsigned int id_group, 
                             int index, 
                             unsigned int& id_client);

    // добавление/удаление
    unsigned int AddGroup(unsigned int id_session);
    // добавить в группу клиента
    bool AddClientKey(unsigned int id_group, unsigned int id_client);
    // для данной группы установить сессию
    bool SetSessionByID(unsigned int id_group, unsigned int id_session);

    // удаление
    void DeleteClientKey(unsigned int id_client);
    void DeleteByID(unsigned int id_group);
  private:
    // добавление/удаление
    void AddGroup(unsigned int id_group, unsigned int id_session);
  };
}

#endif

