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

#include <OgreEntity.h>

#include "Builder_Model_Bullet.h"
#include "Builder_Model_Ogre.h"
#include "ManagerNode_Model.h"

class TShapeNode_Model;

class DllExport TPattern_Model : public TBehaviourPattern
{
	// набор узлов
	TManagerNode_Model mMngNode_Collection;

	// узлы из иерархии
	// THierarchyNode_Model mHierarchy;

	TModelItem::eType mTypeContent;

	TBaseNode_Model* mRootNode;

	//struct TBaseDesc
	//{
	//	TModelItem::eType type;
	//	std::string namePart;
	//	std::string nameVariant;
	//};
	//struct TModelDesc : public TBaseDesc
	//{
	//	TPattern_Model* pModel;
	//	TModelDesc();
	//	~TModelDesc();
	//};
	//struct TShapeDesc : public TBaseDesc
	//{
	//	std::string nameShapeItem;
	//	std::string nameMaterial; // реальный материал и переопределенный могут не совпадать
	//	// результат создания формы:
	//	Ogre::Entity* pEntity;
	//	btRigidBody* pRigidBody;
	//	TShapeDesc();
	//};

	TBuilder_Model_Bullet mBuilderBullet;
	TBuilder_Model_Ogre   mBuilderOgre;

	//TDestructor_Model_Bullet 			mDestructorBullet;
	//TDestructor_Model_Ogre   			mDestructorOgre;

	//TModify_Model_Bullet  			  mModifyBullet;
	//TModify_Model_Ogre    			  mModifyOgre;

	//TUpdaterGameItem_Model_Bullet mUpdaterGameItemBullet;
	//TUpdaterGameItem_Model_Ogre   mUpdaterGameItemOgre;

	//TSaverGameItem_Model_Bullet   mSaverGameItem_Bullet;
	//TSaverGameItem_Model_Ogre     mSaverGameItem_Ogre;

	//TSaverOutData_Model_Bullet    mSaverOutData_Bullet;
	//TSaverOutData_Model_Ogre      mSaverOutData_Ogre;

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
	virtual void ActivatePhysicBody();

	// всё относительно Root
	virtual void SetPosition(nsMathTools::TVector3& v);
	virtual bool GetPosition(nsMathTools::TVector3& v);
	virtual void SetOrientation(nsMathTools::TVector4& v);
	virtual bool GetOrientation(nsMathTools::TVector4& v);
protected:
	void Init(TPatternConfigItem::TMapStrStr* pDefaultParameterMap);

  void BuildModelsByModule_Logic(TModelItem::TMapStrPart& mapNamePart);
  void BuildShapesByModule_Logic(TModelItem::TMapStrPart& mapNamePart);

  void BuildShapeByModule_Graphic(TShapeNode_Model* pShapeNode);
	void PostBuildByModule_Graphic();

	void BuildShapeByModule_Physic(TShapeNode_Model* pShapeNode);
	void PostBuildByModule_Physic();

protected:
	TModelItem::eType GetTypeContent();
	void SetTypeContent(TModelItem::eType type);

	// игровой итэм для загрузки и управления частями
	void SetNameGameItem(std::string& name);
	std::string GetNameGameItem();
	// подвижность
	void SetMobility(bool v);
	bool GetMobility();

protected:
};

#endif
