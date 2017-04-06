/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Light.h"
#include "PatternContext_Light.h"
#include "GraphicEngine_Ogre_MyGUI.h"
#include "ModuleLogic.h"
#include "ModuleGraphicEngine.h"

TPatternModel_Light::TPatternModel_Light()
{

}
//---------------------------------------------------------------------------
TPatternModel_Light::~TPatternModel_Light()
{

}
//---------------------------------------------------------------------------
TBehaviourPatternContext* TPatternModel_Light::MakeNewConext()
{
	return new TPatternContext_Light(this);
}
//---------------------------------------------------------------------------
bool TPatternModel_Light::LoadByModule_Graphic(bool fast)
{
	TPatternContext_Light* pLightContext = (TPatternContext_Light*)mContext;

	TGraphicEngine_Ogre_MyGUI* pGE = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE();
	Ogre::SceneManager* mSceneMgr = pGE->GetSceneManager();

	Ogre::String nameLight = pLightContext->GetNameLight();
	Ogre::Light* pLight = NULL;
	if( mSceneMgr->hasLight(nameLight) )
		pLight = mSceneMgr->getLight(nameLight);
	else
		pLight = mSceneMgr->createLight(nameLight);

	pLight->setType((Ogre::Light::LightTypes)pLightContext->GetType());
	pLight->setCastShadows(pLightContext->GetIsCastShadow());
	pLight->setVisible(pLightContext->GetIsVisible());
	nsMathTools::TVector3 pos;
	pLightContext->GetPosition(pos);
	Ogre::Vector3 posLight;
	posLight.x = pos.x;
	posLight.y = pos.y;
	posLight.z = pos.z;
	pLight->setPosition(posLight);
	nsMathTools::TVector3 dir = pLightContext->GetDirVector();
	Ogre::Vector3 dirLight;
	dirLight.x = dir.x;
	dirLight.y = dir.y;
	dirLight.z = dir.z;
	dirLight.normalise();
	pLight->setDirection(dirLight);

	nsMathTools::TVector3 diffuseColour = pLightContext->GetDiffuseColour();
	pLight->setDiffuseColour(diffuseColour.x, diffuseColour.y, diffuseColour.z);
	
	nsMathTools::TVector3 specularColour = pLightContext->GetSpecularColour();
	pLight->setSpecularColour(specularColour.x, specularColour.y, specularColour.z);

	return true;
}
//---------------------------------------------------------------------------
