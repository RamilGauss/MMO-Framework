/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GP_Scenario_SynchroClient.h"
#include "Scene.h"
#include "BL_Debug.h"
#include "GameObject.h"
#include "BehaviourPatternModel.h"

TGP_Scenario_SynchroClient::TGP_Scenario_SynchroClient()
{

}
//----------------------------------------------------------------------------------
TGP_Scenario_SynchroClient::~TGP_Scenario_SynchroClient()
{

}
//----------------------------------------------------------------------------------
void TGP_Scenario_SynchroClient::SetEnable(int id, bool v)
{
  
}
//----------------------------------------------------------------------------------
bool TGP_Scenario_SynchroClient::UpdateGameObjectFromGameItem(int id, std::string type, std::string name)
{
  return true;
}
//----------------------------------------------------------------------------------
bool TGP_Scenario_SynchroClient::UpdateGameObjectFromPattern(int id, TContainer internalState)
{
  return true;
}
//----------------------------------------------------------------------------------
void TGP_Scenario_SynchroClient::SetScene(TScene* pScene)
{
  mPtrScene = pScene;
}
//----------------------------------------------------------------------------------
void TGP_Scenario_SynchroClient::Thread_Bullet()
{
	int cnt = mPtrScene->GetCountUsing();
	for( int i = 0 ; i < cnt ; i++ )
	{
		TGameObject* pGO = mPtrScene->GetUsingByIndex(i);
		if( pGO==NULL )
		{
			BL_FIX_BUG();
			continue;
		}
		pGO->GetModel()->SynchroFromThread_Bullet(pGO->GetContext());
	}
}
//----------------------------------------------------------------------------------
void TGP_Scenario_SynchroClient::Thread_Ogre()
{
  int cnt = mPtrScene->GetCountUsing();
	for( int i = 0 ; i < cnt ; i++ )
	{
		TGameObject* pGO = mPtrScene->GetUsingByIndex(i);
		if( pGO==NULL )
		{
			BL_FIX_BUG();
			continue;
		}
		pGO->GetModel()->SynchroFromThread_Ogre(pGO->GetContext());
	}
}
//----------------------------------------------------------------------------------
void TGP_Scenario_SynchroClient::Thread_Logic()
{
  
}
//----------------------------------------------------------------------------------
void TGP_Scenario_SynchroClient::Thread_OpenAL()
{
  
}
//----------------------------------------------------------------------------------
nsGameProcess::GP_TypeScenario TGP_Scenario_SynchroClient::GetType()
{
  return nsGameProcess::eSynchroClient;
}
//-----------------------------------------------------------------------------
void TGP_Scenario_SynchroClient::Activate()
{

}
//-----------------------------------------------------------------------------
void TGP_Scenario_SynchroClient::Deactivate()
{

}
//-----------------------------------------------------------------------------
