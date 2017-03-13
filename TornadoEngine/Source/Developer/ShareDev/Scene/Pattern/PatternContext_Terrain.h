/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternContext_TerrainH
#define PatternContext_TerrainH

#include "TypeDef.h"
#include "BehaviourPatternContext.h"
#include "OgreVector3.h"
#include "BuilderTerrain_Ogre.h"

class DllExport TPatternContext_Terrain : public TBehaviourPatternContext
{
	bool flgIsLoad_Ogre;

	int mNeedLoadX_Ogre;
	int mNeedLoadY_Ogre;

	TBuilderTerrain_Ogre mBuilderTerrain_Ogre;
public:
  TPatternContext_Terrain(TBehaviourPatternModel* pModel);
  virtual ~TPatternContext_Terrain();

	void SetIsLoad_Ogre(bool v);
	bool IsLoad_Ogre();

	void SetLoad_X_Ogre(int v);
	int GetLoad_X_Ogre();

	void SetLoad_Y_Ogre(int v);
	int GetLoad_Y_Ogre();

	std::string GetNameTerrainItem();
	Ogre::Vector3 GetOrigin();

	TBuilderTerrain_Ogre* GetBuilderTerrain_Ogre();
};

#endif
