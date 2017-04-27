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
#include "StructPattern_Terrain.h"

#include "Builder_Terrain_Bullet.h"
#include "Builder_Terrain_Ogre.h"

#include "Modify_Terrain_Bullet.h"
#include "Modify_Terrain_Ogre.h"

#include <OgreVector3.h>
#include <OgreTerrainGroup.h>
#include <OgreTerrain.h>

class DllExport TPattern_Terrain : public TBehaviourPattern
{
	// temp data for Build
	struct TProgressBuild
	{
		bool flgIsBuild;
		int mNeedBuildX;
		int mNeedBuildY;
		TProgressBuild(){flgIsBuild=false;mNeedBuildX=0;mNeedBuildY=0;}
	};
	TProgressBuild mProgressBullet;
	TProgressBuild mProgressOgre;

	// in Resources
	Ogre::TerrainGroup*         mTerrainGroup;
	Ogre::TerrainGlobalOptions* mTerrainGlobalOptions;

	// out Resources
public:
	// физика
	typedef std::map<int,nsStructPattern_Terrain::TTerrainPart_Physic> TMapIntPartPhysic;
	typedef TMapIntPartPhysic::iterator   														 TMapIntPartPhysicIt;
	typedef TMapIntPartPhysic::value_type 														 TMapIntPartPhysicVT;

	typedef std::map<int,TMapIntPartPhysic>  TMapIntMapPartPhysic;
	typedef TMapIntMapPartPhysic::iterator   TMapIntMapPartPhysicIt;
	typedef TMapIntMapPartPhysic::value_type TMapIntMapPartPhysicVT;

	TMapIntMapPartPhysic mX_Y_PartPhysic;

protected:
	// helper operations
	// build
	//TBuilderTerrain_Bullet mBuilderTerrain_Bullet;//### убрать
	//TBuilderTerrain_Ogre   mBuilderTerrain_Ogre;  //### убрать
	
	TBuilder_Terrain_Bullet mBuilderBullet;
	TBuilder_Terrain_Ogre   mBuilderOgre;
	// modify
	TModify_Terrain_Bullet mModifyBullet;
	TModify_Terrain_Ogre   mModifyOgre;
	// update
	//###TUpdaterResources_Terrain_Bullet mUpdaterResourcesBullet;
	//###TUpdaterResources_Terrain_Ogre   mUpdaterResourcesOgre;
	// update by
	//###TUpdaterByResources_Terrain_Bullet mUpdaterByResourcesBullet;
	//###TUpdaterByResources_Terrain_Ogre   mUpdaterByResourcesOgre;
	// destruct
	//###TDestructor_Terrain_Bullet mDestructorBullet;
	//###TDestructor_Terrain_Ogre   mDestructorOgre;

public:
  TPattern_Terrain();
  virtual ~TPattern_Terrain();

	virtual bool BuildByModule_Graphic(bool fast = false);
  virtual bool BuildByModule_Physic(bool fast = false);

	virtual TManagerNamePattern::eBaseType GetBaseType();

public:
	// terrain interface
	TMapItem*     GetMapItem();
	TTerrainItem* GetTerrainItem();
	Ogre::Vector3 GetOrigin();

	// модификация
	void ModifyExtent();
	void ModifyBlend();
	void ModifyPaint();
protected:
	void BeginBuild_Bullet();
	bool TryBuild_Bullet();

	void BeginBuild_Ogre();
	bool TryBuild_Ogre();
protected:
	std::string GetNameTerrainItem();

};

#endif
