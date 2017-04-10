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
bool TPatternModel_Terrain::LoadByModule_Graphic(bool fast)
{
  TPatternContext_Terrain* pContextTerrain = (TPatternContext_Terrain*)mContext;
	if( pContextTerrain->IsLoad_Ogre()==false )
		BeginLoad_Ogre();

	return TryLoad_Ogre();
}
//---------------------------------------------------------------------------
bool TPatternModel_Terrain::LoadByModule_Physic(bool fast)
{
	TPatternContext_Terrain* pContextTerrain = (TPatternContext_Terrain*)mContext;
	if( pContextTerrain->IsLoad_Bullet()==false )
		BeginLoad_Bullet();

	return TryLoad_Bullet();
}
//---------------------------------------------------------------------------
void TPatternModel_Terrain::BeginLoad_Bullet()
{
	TPatternContext_Terrain* pContextTerrain = (TPatternContext_Terrain*)mContext;
	std::string nameTerrainItem = pContextTerrain->GetNameTerrainItem();
	TTerrainItem* pTerrainItem = 
		(TTerrainItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Terrain, nameTerrainItem);
	TMapItem*     pMapItem     = 
		(TMapItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Map, pContextTerrain->GetNameMapItem());

	pContextTerrain->GetBuilderTerrain_Bullet()->Setup(pContextTerrain->GetPhysicWorld(),NULL,NULL);
	pContextTerrain->GetBuilderTerrain_Bullet()->Begin(pMapItem, pTerrainItem);
	pContextTerrain->SetIsLoad_Bullet(true);
	pContextTerrain->SetLoad_X_Bullet(pTerrainItem->mX.min);
	pContextTerrain->SetLoad_Y_Bullet(pTerrainItem->mY.min);
}
//---------------------------------------------------------------------------
void TPatternModel_Terrain::BeginLoad_Ogre()
{
	TPatternContext_Terrain* pContextTerrain = (TPatternContext_Terrain*)mContext;
	std::string nameTerrainItem = pContextTerrain->GetNameTerrainItem();
	TTerrainItem* pTerrainItem = 
		(TTerrainItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Terrain, nameTerrainItem);
	TMapItem*     pMapItem     = 
		(TMapItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Map, pContextTerrain->GetNameMapItem());
	Ogre::Vector3 originOgre = pContextTerrain->GetOrigin();

	pContextTerrain->GetBuilderTerrain_Ogre()->Begin(pMapItem, pTerrainItem, originOgre);
	pContextTerrain->SetIsLoad_Ogre(true);
	pContextTerrain->SetLoad_X_Ogre(pTerrainItem->mX.min);
	pContextTerrain->SetLoad_Y_Ogre(pTerrainItem->mY.min);
}
//---------------------------------------------------------------------------
bool TPatternModel_Terrain::TryLoad_Bullet()
{
	TPatternContext_Terrain* pContextTerrain = (TPatternContext_Terrain*)mContext;
	std::string nameTerrainItem = pContextTerrain->GetNameTerrainItem();
	TTerrainItem* pTerrainItem = 
		(TTerrainItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Terrain, nameTerrainItem);

	int minX = pTerrainItem->mX.min;
	int maxX = pTerrainItem->mX.max;
	int minY = pTerrainItem->mY.min;
	int maxY = pTerrainItem->mY.max;
	int x = pContextTerrain->GetLoad_X_Bullet();
	int y = pContextTerrain->GetLoad_Y_Bullet();
	
	pContextTerrain->GetBuilderTerrain_Bullet()->Load(x,y);
	x++;
	if( x > maxX)
	{
		x = minX;
		y++;
	}

	if( y > maxY )
	{
		pContextTerrain->GetBuilderTerrain_Bullet()->End();
		pContextTerrain->SetIsLoad_Bullet(false);
		return true;
	}
	pContextTerrain->SetLoad_X_Bullet(x);
	pContextTerrain->SetLoad_Y_Bullet(y);
	return false;
}
//---------------------------------------------------------------------------
bool TPatternModel_Terrain::TryLoad_Ogre()
{
	TPatternContext_Terrain* pContextTerrain = (TPatternContext_Terrain*)mContext;

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