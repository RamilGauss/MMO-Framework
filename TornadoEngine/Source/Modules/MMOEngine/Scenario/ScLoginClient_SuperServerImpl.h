/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#pragma once

#include "BaseScLoginClient.h"
#include "CallBackRegistrator.h"

namespace nsMMOEngine
{
  class TScLoginClient_SuperServerImpl : public TBaseScLoginClient
  {
  public:
    TScLoginClient_SuperServerImpl(IScenario* pSc);

    virtual void Work(unsigned int time_ms);

    void SetFakeClient(bool val);
  protected:
    virtual void RecvInherit(TDescRecvSession* pDesc);
  private:
    void RecvFromMaster(TDescRecvSession* pDesc);

    void RequestM2SS(TDescRecvSession* pDesc);
  };
  //---------------------------------------------------------------------------
}
