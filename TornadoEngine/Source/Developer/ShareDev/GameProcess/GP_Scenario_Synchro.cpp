/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "GP_Scenario_Synchro.h"
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
TGameObject* TGP_Scenario_SynchroClient::AddGameObject(TMapItem::TObject* pObject)
{
	return NULL;
}
//----------------------------------------------------------------------------------
void TGP_Scenario_SynchroClient::UpdateGameObjectByGameItem(int id, bool force)
{

}
//----------------------------------------------------------------------------------
void TGP_Scenario_SynchroClient::UpdateGameMapParam()
{

}
//----------------------------------------------------------------------------------
bool TGP_Scenario_SynchroClient::DeleteGameObject(int id)
{
	return false;
}
//----------------------------------------------------------------------------------
void TGP_Scenario_SynchroClient::WorkByModule_Physic()
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
void TGP_Scenario_SynchroClient::WorkByModule_Graphic()
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
void TGP_Scenario_SynchroClient::WorkByModule_Logic()
{
  
}
//----------------------------------------------------------------------------------
void TGP_Scenario_SynchroClient::WorkByModule_Sound()
{
  
}
//----------------------------------------------------------------------------------
nsGameProcess::GP_TypeScenario TGP_Scenario_SynchroClient::GetType()
{
  return nsGameProcess::eSynchro;
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
