/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "Pattern_Terrain.h"
#include "BL_Debug.h"
#include "TerrainItem.h"

#include "FactoryGameItem.h"
#include "ModuleLogic.h"


namespace nsPattern_Terrain
{
	const char* sNameGameItem = "NameGameItem";

	static TPatternConfigItem::TMapStrStr g_DefaultParameterMap;
}

using namespace nsPattern_Terrain;

TPattern_Terrain::TPattern_Terrain() :
	TBehaviourPattern(&g_DefaultParameterMap)
{
	g_DefaultParameterMap.insert(TPatternConfigItem::TMapStrStrVT(sNameGameItem,""));

	mBuilderBullet.SetPattern(this);
	mBuilderOgre	.SetPattern(this);

	mModifierBullet.SetPattern(this);
	mModifierOgre	 .SetPattern(this);

	//mUpdaterGameItemBullet.SetPattern(this);
	//mUpdaterGameItemOgre	.SetPattern(this);

  //mUpdaterByGameItemBullet.SetPattern(this);
  //mUpdaterByGameItemOgre	.SetPattern(this);

  //mSaverGameItemBullet.SetPattern(this);
  //mSaverGameItemOgre  .SetPattern(this);

  //mSaverOutDataBullet.SetPattern(this);
  //mSaverOutDataOgre  .SetPattern(this);

	mDestructorBullet.SetPattern(this);
	mDestructorOgre	 .SetPattern(this);
}
//---------------------------------------------------------------------------
TPattern_Terrain::~TPattern_Terrain()
{

}
//---------------------------------------------------------------------------
bool TPattern_Terrain::BuildByModule_Graphic(bool fast)
{
	if( mProgressOgre.flgIsBuild==false )
		BeginBuild_Ogre();

	return TryBuild_Ogre();
}
//---------------------------------------------------------------------------
bool TPattern_Terrain::BuildByModule_Physic(bool fast)
{
	if( mProgressBullet.flgIsBuild==false )
		BeginBuild_Bullet();

	return TryBuild_Bullet();
}
//---------------------------------------------------------------------------
void TPattern_Terrain::BeginBuild_Bullet()
{
	mBuilderBullet.Begin();

	TTerrainItem* pTerrainItem = GetTerrainItem();
	mProgressBullet.flgIsBuild = true;
	mProgressBullet.mNeedBuildX = pTerrainItem->mX.min;
	mProgressBullet.mNeedBuildY = pTerrainItem->mY.min;
}
//---------------------------------------------------------------------------
void TPattern_Terrain::BeginBuild_Ogre()
{
	mBuilderOgre.Begin();

	TTerrainItem* pTerrainItem = GetTerrainItem();
	mProgressOgre.flgIsBuild = true;
	mProgressOgre.mNeedBuildX = pTerrainItem->mX.min;
	mProgressOgre.mNeedBuildY = pTerrainItem->mY.min;
}
//---------------------------------------------------------------------------
bool TPattern_Terrain::TryBuild_Bullet()
{
	TTerrainItem* pTerrainItem = GetTerrainItem();

	int minX = pTerrainItem->mX.min;
	int maxX = pTerrainItem->mX.max;
	int minY = pTerrainItem->mY.min;
	int maxY = pTerrainItem->mY.max;

	int x = mProgressBullet.mNeedBuildX;
	int y = mProgressBullet.mNeedBuildY;
	
	mBuilderBullet.Load(x,y);
	x++;
	if( x > maxX)
	{
		x = minX;
		y++;
	}

	if( y > maxY )
	{
		mBuilderBullet.End();
	  mProgressBullet.flgIsBuild = false;
		return true;
	}
	mProgressBullet.mNeedBuildX = x;
	mProgressBullet.mNeedBuildY = y;
	return false;
}
//---------------------------------------------------------------------------
bool TPattern_Terrain::TryBuild_Ogre()
{
	TTerrainItem* pTerrainItem = GetTerrainItem();

	int minX = pTerrainItem->mX.min;
	int maxX = pTerrainItem->mX.max;
	int minY = pTerrainItem->mY.min;
	int maxY = pTerrainItem->mY.max;
	int x = mProgressOgre.mNeedBuildX;
	int y = mProgressOgre.mNeedBuildY;

	mBuilderOgre.Load(x,y);
	x++;
	if( x > maxX)
	{
		x = minX;
		y++;
	}

	if( y > maxY )
	{
		mBuilderOgre.End();
		mProgressOgre.flgIsBuild = false;
		return true;
	}
	mProgressOgre.mNeedBuildX = x;
	mProgressOgre.mNeedBuildY = y;
	return false;
}
//---------------------------------------------------------------------------
std::string TPattern_Terrain::GetNameTerrainItem()
{
	return GetFromParameterMap<std::string>(sNameGameItem);
}
//---------------------------------------------------------------------------
Ogre::Vector3 TPattern_Terrain::GetOrigin()
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
void TPattern_Terrain::ModifyExtent()
{
	//### берём простые входные данные
	TModifier_Terrain::TDescTarget descTarget;
	descTarget.diapX_Part.min = 0;
	descTarget.diapX_Part.max = 0;
	descTarget.diapY_Part.min = 0;
	descTarget.diapY_Part.max = 0;
	descTarget.worldSizePart  = 8.4;
	descTarget.sizePart       = 33;

	TModifier_Terrain::TLayer layer;
	layer.worldSize           = 2;
	layer.textureNames_Color  = "grass_green-01_diffusespecular.dds";
	layer.textureNames_Normal = "grass_green-01_normalheight.dds";
	descTarget.listLayer.push_back(layer);
	descTarget.listLayer.push_back(layer);
	//###

  mModifierBullet.SetFormat(descTarget);
	mModifierOgre.SetFormat(descTarget);
}
//---------------------------------------------------------------------------
void TPattern_Terrain::ModifyBlend()
{

}
//---------------------------------------------------------------------------
void TPattern_Terrain::ModifyPaint()
{

}
//---------------------------------------------------------------------------
TManagerNamePattern::eBaseType TPattern_Terrain::GetBaseType()
{
	return TManagerNamePattern::eTerrain;
}
//------------------------------------------------------------------------
TMapItem* TPattern_Terrain::GetMapItem()
{
	std::string nameMapItem = GetNameMapItem();
	TMapItem* pMapItem = 
		(TMapItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Map, nameMapItem);
	return pMapItem;
}
//---------------------------------------------------------------------------
TTerrainItem* TPattern_Terrain::GetTerrainItem()
{
	std::string nameTerrainItem = GetNameTerrainItem();
	TTerrainItem* pTerrainItem = 
		(TTerrainItem*)TModuleLogic::Get()->GetFGI()->Get(TFactoryGameItem::Terrain, nameTerrainItem);
	return pTerrainItem;
}
//---------------------------------------------------------------------------
