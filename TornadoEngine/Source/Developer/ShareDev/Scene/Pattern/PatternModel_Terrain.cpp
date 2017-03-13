/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Terrain.h"
#include "PatternContext_Terrain.h"
#include "BL_Debug.h"
#include "TerrainItem.h"
#include "FactoryGameItem.h"
#include "ModuleLogic.h"
#include "BuilderTerrain_Ogre.h"

TPatternModel_Terrain::TPatternModel_Terrain()
{

}
//---------------------------------------------------------------------------
TPatternModel_Terrain::~TPatternModel_Terrain()
{

}
//---------------------------------------------------------------------------
TBehaviourPatternContext* TPatternModel_Terrain::MakeNewConext()
{
	return new TPatternContext_Terrain(this);
}
//---------------------------------------------------------------------------
bool TPatternModel_Terrain::LoadFromThread_Ogre(TBehaviourPatternContext* pContext, bool fast )
{
  TPatternContext_Terrain* pContextTerrain = (TPatternContext_Terrain*)pContext;
	if( pContextTerrain->IsLoad_Ogre()==false )
		Begin(pContextTerrain);

	return TryLoad(pContextTerrain);
}
//---------------------------------------------------------------------------
bool TPatternModel_Terrain::LoadFromThread_Bullet(TBehaviourPatternContext* pContext, bool fast)
{
	return true;
}
//---------------------------------------------------------------------------
void TPatternModel_Terrain::Begin(TPatternContext_Terrain* pContextTerrain)
{
	std::string nameTerrainItem = pContextTerrain->GetNameTerrainItem();
	TTerrainItem* pTerrainItem = 
		(TTerrainItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Terrain, nameTerrainItem);
	TMapItem*     pMapItem     = 
		(TMapItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Map, pContextTerrain->GetNameMap());
	Ogre::Vector3 originOgre = pContextTerrain->GetOrigin();

	pContextTerrain->GetBuilderTerrain_Ogre()->Begin(pMapItem, pTerrainItem, originOgre);
	pContextTerrain->SetIsLoad_Ogre(true);
	pContextTerrain->SetLoad_X_Ogre(pTerrainItem->mX.min);
	pContextTerrain->SetLoad_Y_Ogre(pTerrainItem->mY.min);
}
//---------------------------------------------------------------------------
bool TPatternModel_Terrain::TryLoad(TPatternContext_Terrain* pContextTerrain)
{
	std::string nameTerrainItem = pContextTerrain->GetNameTerrainItem();
	TTerrainItem* pTerrainItem = 
		(TTerrainItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Terrain, nameTerrainItem);

	int minX = pTerrainItem->mX.min;
	int maxX = pTerrainItem->mX.max;
	int minY = pTerrainItem->mY.min;
	int maxY = pTerrainItem->mY.max;
	int x = pContextTerrain->GetLoad_X_Ogre();
	int y = pContextTerrain->GetLoad_Y_Ogre();
	
	pContextTerrain->GetBuilderTerrain_Ogre()->Load(x,y);
	x++;
	if( x > maxX)
	{
		x = minX;
		y++;
	}

	if( y > maxY )
	{
		pContextTerrain->GetBuilderTerrain_Ogre()->End();
		pContextTerrain->SetIsLoad_Ogre(false);
		return true;
	}
	pContextTerrain->SetLoad_X_Ogre(x);
	pContextTerrain->SetLoad_Y_Ogre(y);
	return false;
}
//---------------------------------------------------------------------------
