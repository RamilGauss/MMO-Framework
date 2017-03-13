/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#include "PatternContext_Terrain.h"
#include "ManagerNamePattern.h"
#include "BL_Debug.h"

TPatternContext_Terrain::TPatternContext_Terrain(TBehaviourPatternModel* pModel):
TBehaviourPatternContext(pModel)
{
	flgIsLoad_Ogre = false;
	mNeedLoadX_Ogre = 0;
	mNeedLoadY_Ogre = 0;
}
//---------------------------------------------------------------------------
TPatternContext_Terrain::~TPatternContext_Terrain()
{

}
//---------------------------------------------------------------------------
void TPatternContext_Terrain::SetIsLoad_Ogre(bool v)
{
	flgIsLoad_Ogre = v;
}
//---------------------------------------------------------------------------
bool TPatternContext_Terrain::IsLoad_Ogre()
{
	return flgIsLoad_Ogre;
}
//---------------------------------------------------------------------------
void TPatternContext_Terrain::SetLoad_X_Ogre(int v)
{
	mNeedLoadX_Ogre = v;
}
//---------------------------------------------------------------------------
int TPatternContext_Terrain::GetLoad_X_Ogre()
{
	return mNeedLoadX_Ogre;
}
//---------------------------------------------------------------------------
void TPatternContext_Terrain::SetLoad_Y_Ogre(int v)
{
	mNeedLoadY_Ogre = v;
}
//---------------------------------------------------------------------------
int TPatternContext_Terrain::GetLoad_Y_Ogre()
{
	return mNeedLoadY_Ogre;
}
//---------------------------------------------------------------------------
std::string TPatternContext_Terrain::GetNameTerrainItem()
{
	std::string name = "";
	TMapItem::TMapStrStr* pMap = (TMapItem::TMapStrStr*)GetParameterMap();
	if( pMap==NULL )
	{
		BL_FIX_BUG();
		return name;
	}

	TMapItem::TMapStrStrIt fit = pMap->find("NameGameItem");
	if( fit==pMap->end() )
	{
		BL_FIX_BUG();
		return name;
	}
	name = fit->second;
	return name;
}
//---------------------------------------------------------------------------
Ogre::Vector3 TPatternContext_Terrain::GetOrigin()
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
TBuilderTerrain_Ogre* TPatternContext_Terrain::GetBuilderTerrain_Ogre()
{
	return &mBuilderTerrain_Ogre;
}
//---------------------------------------------------------------------------
