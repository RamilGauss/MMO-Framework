/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "MakerScenario.h"
#include "IScenario.h"

#include <stddef.h>
#include <boost/foreach.hpp>
#include "BL_Debug.h"

#include "ScenarioDisconnectClient.h"
#include "ScenarioFlow.h"
#include "ScenarioLoginClient.h"
#include "ScenarioLoginMaster.h"
#include "ScenarioLoginSlave.h"
#include "ScenarioSendToClient.h"
#include "ScenarioSynchroSlave.h"
#include "ScenarioRecommutationClient.h"

using namespace nsMMOEngine;

TMakerScenario::TMakerScenario()
{

}
//----------------------------------------------------------------------
TMakerScenario::~TMakerScenario()
{
  BOOST_FOREACH(IScenario* p, mSetMakeSc)
    delete p;
}
//----------------------------------------------------------------------
IScenario* TMakerScenario::New(unsigned int ID_Implementation)
{
  IScenario* pSc = NULL;
  switch(ID_Implementation)
  {
    case eDisconnectClient:
      pSc = new TScenarioDisconnectClient; 
      break;
    case eFlow:                     
      pSc = new TScenarioFlow; 
      break;
    case eLoginClient:              
      pSc = new TScenarioLoginClient;
      break;
    case eLoginMaster:              
      pSc = new TScenarioLoginMaster;
      break;
    case eLoginSlave:               
      pSc = new TScenarioLoginSlave;
      break;
    case eRecommutationClient:      
      pSc = new TScenarioRecommutationClient;
      break;
    case eSendToClient:             
      pSc = new TScenarioSendToClient;
      break;
    case eSynchroSlave:            
      pSc = new TScenarioSynchroSlave;
      break;
    default:BL_FIX_BUG();
  }
  if(pSc)
  {
    pSc->SetType(ID_Implementation);
    mSetMakeSc.insert(pSc);
  }
  return pSc;
}
//----------------------------------------------------------------------
void TMakerScenario::Delete(IScenario* p)
{
  mSetMakeSc.erase(p);
  delete p;
}
//----------------------------------------------------------------------
