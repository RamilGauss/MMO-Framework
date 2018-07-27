/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include "IScenario.h"
#include "ContextScLoginSlave.h"
#include "MakerScenario.h"
#include "ScenarioBaseHeader.h"

#ifdef WIN32
#pragma pack(push, 1)
#endif

namespace nsMMOEngine
{
  class TScenarioLoginSlave : public IScenario
  {
    enum{eFromSlave,eAnswerMaster,};
    struct THeaderLoginSlave : public TScenarioBaseHeader
    {
      THeaderLoginSlave(){type=TMakerScenario::eLoginSlave;} 
    }_PACKED;
    //-------------------------------------------------
    struct THeaderFromSlave : public THeaderLoginSlave
    {
      THeaderFromSlave(){subType=eFromSlave;}
    }_PACKED;
    //-------------------------------------------------
    struct THeaderAnswerMaster : public THeaderLoginSlave
    {
      THeaderAnswerMaster(){subType=eAnswerMaster;}
    }_PACKED;
    //-------------------------------------------------
    enum{
      eTimeoutWait_ms = 20000,
    };

  public:
    TScenarioLoginSlave();

    virtual void Recv(TDescRecvSession* pDesc);

    void ConnectToMaster( TIP_Port& ip_port, std::string& login, std::string& password, unsigned char subNet );
  protected:
    virtual void Work();

    void RecvFromMaster(TDescRecvSession* pDesc);
    void RecvFromSlave(TDescRecvSession* pDesc);
  private:
    TContextScLoginSlave* Context(){return (TContextScLoginSlave*)mCurContext;}

    void ConnectToMasterAfterConnect( int sessionID );
  };
}

#ifdef WIN32
#pragma pack(pop)
#endif
