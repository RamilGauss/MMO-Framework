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
  class IScenario;
  class DllExport TClient : public TBase
  {
    unsigned char mSubNet;

    unsigned int mID;// назначенный Мастером
  public:
    TClient();
    virtual ~TClient();

    virtual bool Open( TDescOpen* pDesc, int count = 1 );

    void Login( TIP_Port& ip_port, std::string& login, std::string& password );
    void LeaveQueue();
  protected:
    // Base
    virtual void DisconnectInherit( unsigned int id );

    virtual void EventSetClientKeyLoginClient( unsigned int clientID );
  private:
    virtual void EndLoginClient( IScenario* );
    virtual void EndRcm( IScenario* );

  };
}
