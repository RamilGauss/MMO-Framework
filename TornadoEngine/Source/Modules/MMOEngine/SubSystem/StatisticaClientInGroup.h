/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <map>
#include <set>
#include <vector>

namespace nsMMOEngine
{
  class TStatisticaClientInGroup
  {
    struct TDesc
    {
      unsigned int countClient;
      unsigned int sessionID;

      TDesc( unsigned int cc, unsigned int is )
      {
        countClient = cc;
        sessionID = is;
      }
      bool operator <( const TDesc& right ) const
      {
        if ( countClient < right.countClient )
          return true;
        return false;
      }
    };

    typedef std::vector<TDesc> TVectorDesc;
    typedef TVectorDesc::iterator TVectorDescIt;

    TVectorDesc mVecDesc;

    typedef std::set<unsigned int> TSetUint;
    typedef TSetUint::iterator TSetUintIt;

    typedef std::map<unsigned int, TSetUint > TMapUintSetUint;
    typedef TMapUintSetUint::iterator TMapUintSetUintIt;

    TMapUintSetUint mMapSlaveSessionClientKey;

  public:
    TStatisticaClientInGroup();
    ~TStatisticaClientInGroup();

    // навигация
    bool FindSlaveSessionByMinimumClient( unsigned int &id_session_slave );
    bool FindCountClientBySlaveSession( unsigned int id_session_slave, int& countClient );
    // добавление
    void AddSlave( unsigned int sessionID );
    // добавить в группу клиента
    void AddBySlaveSessionClientKey( unsigned int id_session_slave, unsigned int clientID );

    // удаление
    void DeleteBySlaveSession( unsigned int id_session_slave );
    void DeleteByClientKey( unsigned int id_session_slave, unsigned int key );
  private:
  };
}
