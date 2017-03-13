/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BuilderTerrain_OgreH
#define BuilderTerrain_OgreH

#include "TypeDef.h"
#include <Ogre.h>
#include <OgreTerrain.h>
#include <OgreTerrainGroup.h>

struct TMapItem;
struct TTerrainItem;

// задача класса - загрузка графической составляющей TerrainItem

class DllExport TBuilderTerrain_Ogre
{
	TMapItem*     mMapItem;
	TTerrainItem* mTerrainItem;

	Ogre::Vector3 mTerrainOrigin;

	bool mTerrainsImported;

	Ogre::SceneManager* mSceneMgr;
	Ogre::TerrainGroup* mTerrainGroup;
	Ogre::TerrainGlobalOptions* mTerrainGlobals;
public:
	TBuilderTerrain_Ogre();
	~TBuilderTerrain_Ogre();

	void Begin(TMapItem* pMapItem, TTerrainItem* pTerrainItem, Ogre::Vector3& terrainOrigin);
	void Load( int x, int y );
	void End();

protected:
	void InitOgrePtr();

	void SetupShadow();

	void defineTerrain(long x, long y);
	void configureTerrainDefaults();
};

#endif
