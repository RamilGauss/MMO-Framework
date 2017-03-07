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

class DllExport TBuilderTerrain_Ogre
{
	Ogre::Root* mRoot;
	Ogre::SceneManager* mSceneMgr;
	Ogre::RenderWindow* mWindow;
public:
	TBuilderTerrain_Ogre();
	~TBuilderTerrain_Ogre();

	void Show();

protected:
	void Init();

	void SetupShadow();

	void defineTerrain(long x, long y);
	void initBlendMaps(Ogre::Terrain* terrain);
	void configureTerrainDefaults();

	void AnalizHeightMap();
	void HeightMapTerrainGroup();

	bool mTerrainsImported;
	Ogre::TerrainGroup* mTerrainGroup;
	Ogre::TerrainGlobalOptions* mTerrainGlobals;
};

#endif
