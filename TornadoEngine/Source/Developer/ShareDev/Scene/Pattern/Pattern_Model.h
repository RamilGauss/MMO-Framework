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

class DllExport TPattern_Model : public TBehaviourPattern
{
	TModelItem::eType mTypeContent;

	struct TBaseDesc
	{
		TModelItem::eType type;
		std::string namePart;
		std::string nameVariant;
	};
	struct TModelDesc : public TBaseDesc
	{
		TPattern_Model* pModel;
		TModelDesc();
		~TModelDesc();
	};
	struct TShapeDesc : public TBaseDesc
	{
		std::string nameShapeItem;
		std::string nameMaterial; // реальный материал и переопределенный могут не совпадать
		// результат создания формы:
		Ogre::Entity* pEntity;
		btRigidBody* pRigidBody;
		TShapeDesc();
	};

	TBuilder_Model_Bullet mBuilderBullet;
	TBuilder_Model_Ogre   mBuilderOgre;

	//TDestructor_Shape_Bullet mDestructorBullet;
	//TDestructor_Shape_Ogre   mDestructorOgre;

	//TModify_Shape_Bullet mModifyBullet;
	//TModify_Shape_Ogre   mModifyOgre;

	//TUpdaterByResources_Shape_Bullet mUpdaterByResourcesBullet;
	//TUpdaterByResources_Shape_Ogre   mUpdaterByResourcesOgre;

	//TUpdaterResources_Shape_Bullet mUpdaterResourcesBullet;
	//TUpdaterResources_Shape_Ogre   mUpdaterResourcesOgre;

protected:
	typedef std::map<std::string,TBaseDesc*> TMapStrPtrDesc;
	typedef TMapStrPtrDesc::iterator         TMapStrPtrDescIt;
	typedef TMapStrPtrDesc::value_type       TMapStrPtrDescVT;

	typedef std::map<std::string,TMapStrPtrDesc> TMapStr_StrPtrDesc;
	typedef TMapStr_StrPtrDesc::iterator        TMapStr_StrPtrDescIt;
	typedef TMapStr_StrPtrDesc::value_type      TMapStr_StrPtrDescVT;

	// набор форм или моделей
	TMapStr_StrPtrDesc mMapNamePart_NameVariantDesc;

	TBaseDesc* mRoot;
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

	// всё относительно Root
	virtual void SetPosition(nsMathTools::TVector3& v);
	virtual bool GetPosition(nsMathTools::TVector3& v);
	virtual void SetOrientation(nsMathTools::TVector4& v);
	virtual bool GetOrientation(nsMathTools::TVector4& v);
protected:
	void Init(TPatternConfigItem::TMapStrStr* pDefaultParameterMap);

  void BuildModelsByModule_Logic(TModelItem::TMapStrPart& mapNamePart);
  void BuildShapesByModule_Logic(TModelItem::TMapStrPart& mapNamePart);

  void BuildShapeByModule_Graphic(TShapeDesc* pShapeDesc);
	void PostBuildByModule_Graphic();

	void BuildShapeByModule_Physic(TShapeDesc* pShapeDesc);
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

	void AddDesc(TBaseDesc* pDesc);
	TBaseDesc* GetDesc(std::string& namePart, std::string& nameVariant);

	int GetCountPart();
	std::string GetNamePart(int index);

	int GetCountVariant(std::string& namePart);
	std::string GetNameVariant(std::string& namePart, int index);

protected:
	TMapStrPtrDesc* FindMapByNamePart(std::string& namePart);
};

#endif
