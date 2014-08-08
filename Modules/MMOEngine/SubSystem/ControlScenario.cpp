/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/


#include "ControlScenario.h"
#include "BL_Debug.h"
#include "DescRecvSession.h"

#include "ScenarioDisconnectClient.h"
#include "ScenarioFlow.h"
#include "ScenarioLoginClient.h"
#include "ScenarioLoginSlave.h"
#include "ScenarioLoginMaster.h"
#include "ScenarioRecommutationClient.h"
#include "ScenarioSendToClient.h"
#include "ScenarioSynchroSlave.h"

using namespace nsMMOEngine;

TControlScenario::TControlScenario()
{
  mDisClient    = (TScenarioDisconnectClient*   )mMakerScenario.New(TMakerScenario::eDisconnectClient);
  mFlow         = (TScenarioFlow*               )mMakerScenario.New(TMakerScenario::eFlow);
  mLoginClient  = (TScenarioLoginClient*        )mMakerScenario.New(TMakerScenario::eLoginClient);
  mLoginSlave   = (TScenarioLoginSlave*         )mMakerScenario.New(TMakerScenario::eLoginSlave);
  mLoginMaster  = (TScenarioLoginMaster*        )mMakerScenario.New(TMakerScenario::eLoginMaster);
  mRcm          = (TScenarioRecommutationClient*)mMakerScenario.New(TMakerScenario::eRecommutationClient);
  mSendToClient = (TScenarioSendToClient*       )mMakerScenario.New(TMakerScenario::eSendToClient);
  mSynchroSlave = (TScenarioSynchroSlave*       )mMakerScenario.New(TMakerScenario::eSynchroSlave);

  Add(mDisClient   );
  Add(mFlow        );
  Add(mLoginClient );
  Add(mLoginSlave  );
  Add(mLoginMaster );
  Add(mRcm         );
  Add(mSendToClient);
  Add(mSynchroSlave);
}
//----------------------------------------------------------------------
TControlScenario::~TControlScenario()
{

}
//----------------------------------------------------------------------
void TControlScenario::Add(IScenario* pSc)
{
  mMapTypeSc.insert(TMapIntPtr::value_type(pSc->GetType(),pSc));
}
//----------------------------------------------------------------------
void TControlScenario::Work(TDescRecvSession* pDesc)
{
  IScenario::TBaseHeader* pPacket = (IScenario::TBaseHeader*)pDesc->data;
  TMapIntPtrIt fit = mMapTypeSc.find(pPacket->type);
  if(fit!=mMapTypeSc.end())
  {
    // защита от получения незащищенных UDP пакетов
    if(pDesc->type==INetTransport::eUdp)
      if(fit->second!=mFlow)// только Flow использует UDP, остальным нельзя
        return;

    fit->second->Recv(pDesc);
  }
  else
    BL_FIX_BUG();
}
//----------------------------------------------------------------------
