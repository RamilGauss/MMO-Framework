/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef PatternModel_TerrainH
#define PatternModel_TerrainH

#include "TypeDef.h"
#include "BehaviourPatternModel.h"
#include "OgreVector3.h"
#include "BuilderTerrain_Ogre.h"
#include "BuilderTerrain_Bullet.h"

class DllExport TPatternModel_Terrain : public TBehaviourPatternModel
{
	bool flgIsLoad_Bullet;

	int mNeedLoadX_Bullet;
	int mNeedLoadY_Bullet;

	bool flgIsLoad_Ogre;

	int mNeedLoadX_Ogre;
	int mNeedLoadY_Ogre;

	TBuilderTerrain_Bullet mBuilderTerrain_Bullet;
	TBuilderTerrain_Ogre   mBuilderTerrain_Ogre;
public:
  TPatternModel_Terrain();
  virtual ~TPatternModel_Terrain();

  //virtual TBehaviourPatternContext* MakeNewConext();

	virtual bool LoadByModule_Graphic(bool fast = false);
  virtual bool LoadByModule_Physic(bool fast = false);

protected:
	void BeginLoad_Bullet();
	bool TryLoad_Bullet();

	void BeginLoad_Ogre();
	bool TryLoad_Ogre();
protected:
	void SetIsLoad_Bullet(bool v);
	bool IsLoad_Bullet();

	void SetLoad_X_Bullet(int v);
	int GetLoad_X_Bullet();

	void SetLoad_Y_Bullet(int v);
	int GetLoad_Y_Bullet();


	void SetIsLoad_Ogre(bool v);
	bool IsLoad_Ogre();

	void SetLoad_X_Ogre(int v);
	int GetLoad_X_Ogre();

	void SetLoad_Y_Ogre(int v);
	int GetLoad_Y_Ogre();

	std::string GetNameTerrainItem();
	Ogre::Vector3 GetOrigin();

	TBuilderTerrain_Bullet* GetBuilderTerrain_Bullet();
	TBuilderTerrain_Ogre* GetBuilderTerrain_Ogre();

};

#endif
