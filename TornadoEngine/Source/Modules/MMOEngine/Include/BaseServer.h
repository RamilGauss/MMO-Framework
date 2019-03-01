/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "Base.h"

namespace nsMMOEngine
{
  class DllExport TBaseServer : public TBase
  {
  public:
    TBaseServer();
    virtual ~TBaseServer();

    void Accept( int sessionID, std::string& password );
    void Reject( int sessionID );

    // this method will be realize in future
    virtual void DisconnectByClientKey( unsigned int clientKey );// = 0;

    // всегда с гарантией доставки, т.к. тогда не имеет смысла так долго пересылать (слишком много затрат сил, а гарантии нет?)
    virtual void SendByClientKey( std::list<unsigned int>& clientKeyList, char* p, int size ) = 0;

    virtual void SendDown( unsigned int sessionID, char* p, int size, bool check = true ) = 0;

    virtual void GetDescDown( std::list<unsigned int>& sessionIDList ) = 0;
  protected:

  private:
  };
}
