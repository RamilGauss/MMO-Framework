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

#include "Modifier_Terrain_Bullet.h"
#include "Modifier_Terrain_Ogre.h"

#include "Destructor_Terrain_Bullet.h"
#include "Destructor_Terrain_Ogre.h"

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

	// out Resources

	// in Resources
public:
	// создание, уничтожение и модификация - ответственность несут сценарии

	// физика
	// НЕ как указатель, потому что уничтожение данных НЕ должно производится в конструкторе
	typedef std::map<int,nsStructPattern_Terrain::TTerrainPart_Physic> TMapIntPartPhysic;
	typedef TMapIntPartPhysic::iterator   														 TMapIntPartPhysicIt;
	typedef TMapIntPartPhysic::value_type 														 TMapIntPartPhysicVT;

	typedef std::map<int,TMapIntPartPhysic>  TMapIntMapPartPhysic;
	typedef TMapIntMapPartPhysic::iterator   TMapIntMapPartPhysicIt;
	typedef TMapIntMapPartPhysic::value_type TMapIntMapPartPhysicVT;

	TMapIntMapPartPhysic mX_Y_PartPhysic;
	// доступ к графике:
	// pGE = TModuleLogic::Get()->GetC()->pGraphicEngine->GetGE()
	// Ogre::TerrainGroup* pTG = pGE->GetTerrainGroup();
	// Ogre::TerrainGlobalOptions* pTGO = pGE->GetTerrainGlobals();

protected:
	// helper operations
	// build
	TBuilder_Terrain_Bullet mBuilderBullet;
	TBuilder_Terrain_Ogre   mBuilderOgre;
	// modify
	TModifier_Terrain_Bullet mModifierBullet;
	TModifier_Terrain_Ogre   mModifierOgre;
	// update
	//###TUpdaterGameItem_Terrain_Bullet mUpdaterGameItemBullet;
	//###TUpdaterGameItem_Terrain_Ogre   mUpdaterGameItemOgre;
	// update by
	//###TUpdaterByGameItem_Terrain_Bullet mUpdaterByGameItemBullet;
	//###TUpdaterByGameItem_Terrain_Ogre   mUpdaterByGameItemOgre;
  // save game item
  //###TSaverGameItem_Terrain_Bullet mSaverGameItemBullet;
  //###TSaverGameItem_Terrain_Ogre   mSaverGameItemOgre;
  // save out data
  //###TSaverOutData_Terrain_Bullet mSaverOutDataBullet;
  //###TSaverOutData_Terrain_Ogre   mSaverOutDataOgre;
	// destruct
	TDestructor_Terrain_Bullet mDestructorBullet;
	TDestructor_Terrain_Ogre   mDestructorOgre;

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
