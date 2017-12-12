/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Modifier_Terrain_OgreH
#define Modifier_Terrain_OgreH

#include "TypeDef.h"

#include "Modifier_Terrain.h"
#include <Ogre.h>
#include <OgreTerrain.h>
#include <OgreTerrainGroup.h>

class DllExport TModifier_Terrain_Ogre : public TModifier_Terrain
{
  Ogre::SceneManager* mSceneMgr;
  Ogre::TerrainGroup* mTerrainGroup;
  Ogre::TerrainGlobalOptions* mTerrainGlobals;

  TTerrainItem* mTerrainItem;

  TDescTarget mDescTarget;
public:
  TModifier_Terrain_Ogre();

  virtual void SetFormat(TDescTarget& descTarget);
protected:
  void setupContent();
  void configureTerrainDefaults();
  void defineTerrain(long x, long y);
};

#endif
