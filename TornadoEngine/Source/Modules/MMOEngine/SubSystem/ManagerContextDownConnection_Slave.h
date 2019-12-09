/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "ManagerContextDownConnection.h"
#include <vector>

namespace nsMMOEngine
{
  class TManagerContextDownConnection_Slave : public TManagerContextDownConnection
  {
    typedef std::map<unsigned int, unsigned char> TMapUintUchar;
    typedef TMapUintUchar::iterator TMapUintUcharIt;

    TMapUintUchar mMapSessionLoadProcent;

    struct TDesc
    {
      unsigned char load_procent;
      unsigned int sessionID;

      TDesc( unsigned char lp, unsigned int is )
      {
        load_procent = lp;
        sessionID = is;
      }
      bool operator < ( const TDesc& right ) const
      {
        if ( load_procent < right.load_procent )
          return true;
        return false;
      }
    };

    typedef std::vector<TDesc> TVectorDesc;
    typedef TVectorDesc::iterator TVectorDescIt;

    TVectorDesc mVecDesc;
  public:
    TManagerContextDownConnection_Slave( TBase* pBase );
    virtual ~TManagerContextDownConnection_Slave();

    bool FindMinimumLoad( unsigned int& sessionID, unsigned char& load_procent );
    bool FindLoadBySession( unsigned int sessionID, unsigned char& load_procent );

    void SetLoadBySession( unsigned int id_Session, unsigned char load_procent );

  protected:
    virtual void AddSessionEvent( unsigned int sessionID );
    virtual void DeleteSessionEvent( unsigned int sessionID );
  private:
  };
}
