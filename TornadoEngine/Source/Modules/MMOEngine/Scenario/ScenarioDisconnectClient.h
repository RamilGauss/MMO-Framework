/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss
Гудаков Рамиль Сергеевич
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#pragma once

#include <vector>

#include "IScenario.h"
#include "ContextScDisconnectClient.h"
#include "MakerScenario.h"
#include "CallBackRegistrator.h"
#include "ScenarioBaseHeader.h"

#ifdef WIN32
#pragma pack(push, 1)
#endif

namespace nsMMOEngine
{
  class TScenarioDisconnectClient : public IScenario
  {
    enum{
      eFromMaster,
      eFromSlave,
    };

    struct THeaderDisconnectClient : public TScenarioBaseHeader
    {
      THeaderDisconnectClient(){ type = TMakerScenario::eDisconnectClient; }
    }_PACKED;
    //-------------------------------------------------
    struct THeaderFromMaster : public THeaderDisconnectClient
    {
      THeaderFromMaster(){ subType = eFromMaster; }
      int countID;// далее массив unsigned int
    }_PACKED;
    //-------------------------------------------------
    struct THeaderFromSlave : public THeaderDisconnectClient
    {
      THeaderFromSlave(){ subType = eFromSlave; }
      unsigned int clientID;
    }_PACKED;
    //-------------------------------------------------
  public:
    TScenarioDisconnectClient();

    virtual void Recv( TDescRecvSession* pDesc );

    void DisconnectFromSlave( unsigned int clientID );
    void DisconnectFromMaster( std::vector<unsigned int>& vecID_client );

  protected:
    virtual void Work();
  private:
    void RecvFromMaster( TDescRecvSession* pDesc );
    void RecvFromSlave( TDescRecvSession* pDesc );

  private:
    TContextScDisconnectClient * Context(){ return (TContextScDisconnectClient*) mCurContext; }
  };
}

#ifdef WIN32
#pragma pack(pop)
#endif
