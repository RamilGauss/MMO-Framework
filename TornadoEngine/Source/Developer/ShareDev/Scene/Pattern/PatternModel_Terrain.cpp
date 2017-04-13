/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternModel_Terrain.h"
#include "BL_Debug.h"
#include "TerrainItem.h"
#include "FactoryGameItem.h"
#include "ModuleLogic.h"
#include "BuilderTerrain_Ogre.h"

namespace nsPatternModel_Terrain
{
	const char* sNameGameItem = "NameGameItem";

	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPatternModel_Terrain;

TPatternModel_Terrain::TPatternModel_Terrain() :
	TBehaviourPatternModel(&g_DefaultParameterMap)
{
	flgIsLoad_Bullet = false;
	flgIsLoad_Ogre = false;
	mNeedLoadX_Ogre = 0;
	mNeedLoadY_Ogre = 0;
}
//---------------------------------------------------------------------------
TPatternModel_Terrain::~TPatternModel_Terrain()
{

}
//---------------------------------------------------------------------------
bool TPatternModel_Terrain::LoadByModule_Graphic(bool fast)
{
	if( IsLoad_Ogre()==false )
		BeginLoad_Ogre();

	return TryLoad_Ogre();
}
//---------------------------------------------------------------------------
bool TPatternModel_Terrain::LoadByModule_Physic(bool fast)
{
	if( IsLoad_Bullet()==false )
		BeginLoad_Bullet();

	return TryLoad_Bullet();
}
//---------------------------------------------------------------------------
void TPatternModel_Terrain::BeginLoad_Bullet()
{
	std::string nameTerrainItem = GetNameTerrainItem();
	TTerrainItem* pTerrainItem = 
		(TTerrainItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Terrain, nameTerrainItem);
	TMapItem* pMapItem = 
		(TMapItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Map, GetNameMapItem());

	GetBuilderTerrain_Bullet()->Setup(GetPhysicWorld(),NULL,NULL);
	GetBuilderTerrain_Bullet()->Begin(pMapItem, pTerrainItem);
	SetIsLoad_Bullet(true);
	SetLoad_X_Bullet(pTerrainItem->mX.min);
	SetLoad_Y_Bullet(pTerrainItem->mY.min);
}
//---------------------------------------------------------------------------
void TPatternModel_Terrain::BeginLoad_Ogre()
{
	std::string nameTerrainItem = GetNameTerrainItem();
	TTerrainItem* pTerrainItem = 
		(TTerrainItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Terrain, nameTerrainItem);
	TMapItem*     pMapItem     = 
		(TMapItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Map, GetNameMapItem());
	Ogre::Vector3 originOgre = GetOrigin();

	GetBuilderTerrain_Ogre()->Begin(pMapItem, pTerrainItem, originOgre);
	SetIsLoad_Ogre(true);
	SetLoad_X_Ogre(pTerrainItem->mX.min);
	SetLoad_Y_Ogre(pTerrainItem->mY.min);
}
//---------------------------------------------------------------------------
bool TPatternModel_Terrain::TryLoad_Bullet()
{
	std::string nameTerrainItem = GetNameTerrainItem();
	TTerrainItem* pTerrainItem = 
		(TTerrainItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Terrain, nameTerrainItem);

	int minX = pTerrainItem->mX.min;
	int maxX = pTerrainItem->mX.max;
	int minY = pTerrainItem->mY.min;
	int maxY = pTerrainItem->mY.max;
	int x = GetLoad_X_Bullet();
	int y = GetLoad_Y_Bullet();
	
	GetBuilderTerrain_Bullet()->Load(x,y);
	x++;
	if( x > maxX)
	{
		x = minX;
		y++;
	}

	if( y > maxY )
	{
		GetBuilderTerrain_Bullet()->End();
		SetIsLoad_Bullet(false);
		return true;
	}
	SetLoad_X_Bullet(x);
	SetLoad_Y_Bullet(y);
	return false;
}
//---------------------------------------------------------------------------
bool TPatternModel_Terrain::TryLoad_Ogre()
{
	std::string nameTerrainItem = GetNameTerrainItem();
	TTerrainItem* pTerrainItem = 
		(TTerrainItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Terrain, nameTerrainItem);

	int minX = pTerrainItem->mX.min;
	int maxX = pTerrainItem->mX.max;
	int minY = pTerrainItem->mY.min;
	int maxY = pTerrainItem->mY.max;
	int x = GetLoad_X_Ogre();
	int y = GetLoad_Y_Ogre();

	GetBuilderTerrain_Ogre()->Load(x,y);
	x++;
	if( x > maxX)
	{
		x = minX;
		y++;
	}

	if( y > maxY )
	{
		GetBuilderTerrain_Ogre()->End();
		SetIsLoad_Ogre(false);
		return true;
	}
	SetLoad_X_Ogre(x);
	SetLoad_Y_Ogre(y);
	return false;
}
//---------------------------------------------------------------------------
void TPatternModel_Terrain::SetIsLoad_Bullet(bool v)
{
	flgIsLoad_Bullet = v;
}
//---------------------------------------------------------------------------
bool TPatternModel_Terrain::IsLoad_Bullet()
{
	return flgIsLoad_Bullet;
}
//---------------------------------------------------------------------------
void TPatternModel_Terrain::SetIsLoad_Ogre(bool v)
{
	flgIsLoad_Ogre = v;
}
//---------------------------------------------------------------------------
bool TPatternModel_Terrain::IsLoad_Ogre()
{
	return flgIsLoad_Ogre;
}
//---------------------------------------------------------------------------
void TPatternModel_Terrain::SetLoad_X_Bullet(int v)
{
	mNeedLoadX_Bullet = v;
}
//---------------------------------------------------------------------------
int TPatternModel_Terrain::GetLoad_X_Bullet()
{
	return mNeedLoadX_Bullet;
}
//---------------------------------------------------------------------------
void TPatternModel_Terrain::SetLoad_Y_Bullet(int v)
{
	mNeedLoadY_Bullet = v;
}
//---------------------------------------------------------------------------
int TPatternModel_Terrain::GetLoad_Y_Bullet()
{
	return mNeedLoadY_Bullet;
}
//---------------------------------------------------------------------------
void TPatternModel_Terrain::SetLoad_X_Ogre(int v)
{
	mNeedLoadX_Ogre = v;
}
//---------------------------------------------------------------------------
int TPatternModel_Terrain::GetLoad_X_Ogre()
{
	return mNeedLoadX_Ogre;
}
//---------------------------------------------------------------------------
void TPatternModel_Terrain::SetLoad_Y_Ogre(int v)
{
	mNeedLoadY_Ogre = v;
}
//---------------------------------------------------------------------------
int TPatternModel_Terrain::GetLoad_Y_Ogre()
{
	return mNeedLoadY_Ogre;
}
//---------------------------------------------------------------------------
std::string TPatternModel_Terrain::GetNameTerrainItem()
{
	std::string name;
	GetFromParameterMap<std::string>(sNameGameItem, name);
	return name;
}
//---------------------------------------------------------------------------
Ogre::Vector3 TPatternModel_Terrain::GetOrigin()
{
	Ogre::Vector3 originOgre = Ogre::Vector3::ZERO;

	nsMathTools::TVector3 pos;
	if( GetPosition(pos)==false )
	{
		BL_FIX_BUG();
		return originOgre;
	}

	originOgre.x = pos.x;
	originOgre.y = pos.y;
	originOgre.z = pos.z;
	return originOgre;
}
//---------------------------------------------------------------------------
TBuilderTerrain_Bullet* TPatternModel_Terrain::GetBuilderTerrain_Bullet()
{
	return &mBuilderTerrain_Bullet;
}
//---------------------------------------------------------------------------
TBuilderTerrain_Ogre* TPatternModel_Terrain::GetBuilderTerrain_Ogre()
{
	return &mBuilderTerrain_Ogre;
}
//---------------------------------------------------------------------------
void TPatternModel_Terrain::ModifyExtent()
{
	
}
//---------------------------------------------------------------------------
void TPatternModel_Terrain::ModifyBlend()
{

}
//---------------------------------------------------------------------------
void TPatternModel_Terrain::ModifyPaint()
{

}
//---------------------------------------------------------------------------
