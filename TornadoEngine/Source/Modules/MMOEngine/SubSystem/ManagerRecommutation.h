/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <map>
#include <set>
#include <utility>

/*
  Просмотр клиентов начинается с Донора, потом Реципиент.
  Алфавитный порядок, "Д" стоит раньше "Р".
*/

namespace nsMMOEngine
{
  class TManagerRecommutation
  {
    typedef std::pair<unsigned int, unsigned int> TPairUintUint;
    // Клиент Map
    typedef std::map<unsigned int, TPairUintUint> TMapUintPair;
    typedef TMapUintPair::iterator TMapUintPairIt;
    // Slave типы
    typedef std::set<unsigned int> TSetUint;
    typedef TSetUint::iterator TSetUintIt;

    struct TSetClient
    {
      TSetUint donor;    // хозяин Slave относится к Клиенту как донор
      TSetUint recipient;// хозяин Slave относится к Клиенту как реципиент
    };
    typedef std::map<unsigned int, TSetClient> TMapUintSet;
    typedef TMapUintSet::iterator TMapUintSetIt;

    TMapUintPair mMapClientKey_Slaves;
    TMapUintSet  mMapSlave_SetClient;

    typedef enum
    {
      eDonor, eRecipient
    }Type;
  public:
    TManagerRecommutation();
    ~TManagerRecommutation();

    // навигация
    bool FindSessionByClientKey( unsigned int key, unsigned int& id_session_donor, unsigned int& id_session_recipient );

    int GetCountClientBySessionSlave( unsigned int sessionID );
    int GetCountClientBySessionSlave_Balance( unsigned int sessionID );
    bool GetClientKeyByIndex( unsigned int sessionID, int index, unsigned int& key );

    // добавить в группу клиента
    void AddClientKey( unsigned int key, unsigned int id_session_donor, unsigned int id_session_recipient );
    // удаление
    void DeleteByClientKey( unsigned int key );
  private:
    void AddClientKeyBySession( unsigned int key, unsigned int sessionID, Type type );
    void DeleteClientKeyBySession( unsigned int key, unsigned int sessionID, Type type );
  };
}
