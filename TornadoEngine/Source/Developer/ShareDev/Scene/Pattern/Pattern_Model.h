/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef Pattern_ModelH
#define Pattern_ModelH

#include "TypeDef.h"
#include "BehaviourPattern.h"
#include "PatternConfigItem.h"
#include "ModelItem.h"
#include "ModulePhysicEngine.h"

#include "ManagerNode_Model.h"
#include "HierarchyNode_Model.h"
#include "ManagerNodeLocation_Model.h"

#include "Builder_Model_Bullet.h"
#include "Builder_Model_Logic.h"
#include "Builder_Model_Ogre.h"

#include "Synchronizer_Model_Bullet.h"
#include "Synchronizer_Model_Logic.h"
#include "Synchronizer_Model_Ogre.h"

class TShapeNode_Model;

class DllExport TPattern_Model : public TBehaviourPattern
{
	bool mIsGameObject;
public:// for using by scenarios
	// набор узлов
	TManagerNode_Model mMngNode_Collection;
	// узлы из иерархии
	THierarchyNode_Model mHierarchy;
	// узлы из иерархии для расчета позиционирования узлов и крючков
	TManagerNodeLocation_Model mMngNodeLocation;

	TModelItem::eType mTypeContent;
protected:
	TBuilder_Model_Logic  mBuilderLogic;
	TBuilder_Model_Bullet mBuilderBullet;
	TBuilder_Model_Ogre   mBuilderOgre;

	//TDestructor_Model_Bullet 			mDestructorBullet;
	//TDestructor_Model_Ogre   			mDestructorOgre;

	//TModify_Model_Bullet  			  mModifyBullet;
	//TModify_Model_Ogre    			  mModifyOgre;

	//TUpdaterGameItem_Model_Bullet mUpdaterGIBullet;
	//TUpdaterGameItem_Model_Ogre   mUpdaterGIOgre;

	//TSaverGameItem_Model_Bullet   mSaverGameItem_Bullet;
	//TSaverGameItem_Model_Ogre     mSaverGameItem_Ogre;

	//TSaverOutData_Model_Bullet    mSaverOutData_Bullet;
	//TSaverOutData_Model_Ogre      mSaverOutData_Ogre;

	TSynchronizer_Model_Bullet mSynchronizerBullet;
	TSynchronizer_Model_Logic  mSynchronizerLogic;
	TSynchronizer_Model_Ogre   mSynchronizerOgre;
public:
  TPattern_Model();
  TPattern_Model(TPatternConfigItem::TMapStrStr* pDefaultParameterMap);
  virtual ~TPattern_Model();

  // от одного Паттерна другому, упаковано 
  virtual bool SetParameterFromPattern(TContainer c);// L
  virtual TContainer GetParameterToPattern();// B - Slave

	virtual TManagerNamePattern::eBaseType GetBaseType();

  // Выполнить задания в каждом из потоков
  virtual void BuildByModule_Logic();
  virtual bool BuildByModule_Graphic(bool fast = false);
  virtual bool BuildByModule_Physic(bool fast = false);
  virtual bool BuildByModule_Sound(bool fast = false);

  virtual void DestructByModule_Logic();
  virtual bool DestructByModule_Graphic(bool fast = false);
  virtual bool DestructByModule_Physic(bool fast = false);
  virtual bool DestructByModule_Sound(bool fast = false);

  virtual void SynchroByModule_Logic();  // внешняя синхронизация
  virtual void SynchroByModule_Graphic();// графика от физики
  virtual void SynchroByModule_Physic(); // внутренняя синхронизация
  virtual void SynchroByModule_Sound();  // звук от физики

	// model interface

	// активировать все физические тела
	// btRigidBody.h:
	// Bullet automatically deactivates dynamic rigid bodies, when the velocity is below a threshold for a given time.
	// Deactivated (sleeping) rigid bodies don't take any processing time, except a minor broadphase collision detection impact (to allow active objects to activate/wake up sleeping objects)
	virtual void ActivatePhysicBody(bool force = true);

public:// for using by scenarios
	// является ли объект самостоятельным игровым (или часть игрового или другого неигрового)
	virtual void SetIsGameObject(bool v);
	virtual bool IsGameObject();

	virtual void Event_AddModelNode(TModelNode_Model* p);

	TModelItem::eType GetTypeContent();
	void SetTypeContent(TModelItem::eType type);

	// игровой итэм для загрузки и управления частями
	void SetNameGameItem(std::string& name);
	std::string GetNameGameItem();
	// подвижность
	void SetMobility(bool v);
	bool GetMobility();

	// Logic feedback
	void CalcGlobalLocation_Parts();
	void RankGlobalLocationCorrection();

	// Physic feedback
	btRigidBody* GetRigidBody(std::string namePart);
	void AddRigidBody(btRigidBody*);
protected:
	void Init(TPatternConfigItem::TMapStrStr* pDefaultParameterMap);

};

#endif
