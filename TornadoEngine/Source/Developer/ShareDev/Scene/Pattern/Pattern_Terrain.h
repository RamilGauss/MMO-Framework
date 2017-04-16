/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Pattern_TerrainH
#define Pattern_TerrainH

#include "TypeDef.h"
#include "BehaviourPattern.h"
#include <OgreVector3.h>
#include "BuilderTerrain_Ogre.h"
#include "BuilderTerrain_Bullet.h"

class DllExport TPattern_Terrain : public TBehaviourPattern
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
  TPattern_Terrain();
  virtual ~TPattern_Terrain();

	virtual bool BuildByModule_Graphic(bool fast = false);
  virtual bool BuildByModule_Physic(bool fast = false);

	// модификация
	void ModifyExtent();
	void ModifyBlend();
	void ModifyPaint();
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
