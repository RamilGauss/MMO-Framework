/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information LICENSE.md.
*/

#ifndef BuilderTool_Terrain_OgreH
#define BuilderTool_Terrain_OgreH

#include "TypeDef.h"
#include <Ogre.h>
#include <OgreTerrain.h>
#include <OgreTerrainGroup.h>

struct TMapItem;
struct TTerrainItem;

// задача класса - загрузка графической составляющей TerrainItem

class DllExport TBuilderTool_Terrain_Ogre
{
  TTerrainItem* mTerrainItem;

  Ogre::Vector3 mTerrainOrigin;

  Ogre::SceneManager* mSceneMgr;
  Ogre::TerrainGroup* mTerrainGroup;
  Ogre::TerrainGlobalOptions* mTerrainGlobals;
public:
  TBuilderTool_Terrain_Ogre();
  ~TBuilderTool_Terrain_Ogre();

  void Begin(TTerrainItem* pTerrainItem, Ogre::Vector3& terrainOrigin);
  void Load( int x, int y );
  void End();

protected:
  void InitOgrePtr();

  void SetupShadow();

  void defineTerrain(long x, long y);
  void configureTerrainDefaults();
};

#endif
