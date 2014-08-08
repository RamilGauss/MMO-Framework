/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef SCENARIO_LOGIN_MASTER_H
#define SCENARIO_LOGIN_MASTER_H

#include "IScenario.h"
#include "ContextScLoginMaster.h"
#include "MakerScenario.h"

#if defined( TD_WINDOWS )
#pragma pack(push, 1)
#endif

namespace nsMMOEngine
{
  class TScenarioLoginMaster : public IScenario
  {
    enum{eFromMaster,eAnswerFromSS,};
    struct THeaderLoginMaster : public IScenario::TBaseHeader
    {
      THeaderLoginMaster(){type=TMakerScenario::eLoginMaster;}
    };
    //-------------------------------------------------
    struct THeaderFromMaster : public THeaderLoginMaster
    {
      THeaderFromMaster(){subType=eFromMaster;}
    };
    //-------------------------------------------------
    struct THeaderAnswerFromSS : public THeaderLoginMaster
    {
      THeaderAnswerFromSS(){subType=eAnswerFromSS;}
    };
    //-------------------------------------------------

    enum{
      eTimeoutWait_ms = 20000,
    };
  public:
    TScenarioLoginMaster();
    virtual ~TScenarioLoginMaster();
		virtual void Recv(TDescRecvSession* pDesc);

    void ConnectToSuperServer(unsigned int ip, unsigned short port, unsigned char subNet);
  protected:
    virtual void Work();

    void RecvFromSuperServer(TDescRecvSession* pDesc);
    void RecvFromMaster(TDescRecvSession* pDesc);

    TContextScLoginMaster* Context(){return (TContextScLoginMaster*)mCurContext;}
  };
}

#if defined( TD_WINDOWS )
#pragma pack(pop)
#endif

#endif