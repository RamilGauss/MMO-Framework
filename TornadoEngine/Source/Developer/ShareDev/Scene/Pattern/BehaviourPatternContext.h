/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BehaviourPatternContextH
#define BehaviourPatternContextH

/*
  Базовый тип поведения игрового объекта.
  Методов нет, есть только данные. Методы есть только
  для обмена данными между потоками (трубы).
  Интерфейс контекст подстраивается под нужды Модели и компонентов движков (Ogre,Bullet,OpenAL).
*/

#include "TypeDef.h"
#include "ContainerTypes.h"
#include "MathTools.h"
#include "MapItem.h"
#include "BL_Debug.h"
#include <boost/lexical_cast.hpp>

class TGameObject;
class TFactoryGameItem;
class TFactoryBehaviourPatternModel;
class TBehaviourPatternModel;

class TGameObjectComponent_Ogre;
class TGameObjectComponent_Bullet;
class TGameObjectComponent_OpenAL;

class DllExport TBehaviourPatternContext
{
  TBehaviourPatternModel* mModel;
protected:
  TGameObject*            mGO;
  
  TMapItem::TMapStrStr mParameterMap;
  TMapItem::TMapStrStr mDefaultParameterMap;

  int mPhysicWorldID;

  // данные
  boost::scoped_ptr<TGameObjectComponent_Ogre>   mPtrGraphic;
  boost::scoped_ptr<TGameObjectComponent_Bullet> mPtrPhysic;
  boost::scoped_ptr<TGameObjectComponent_OpenAL> mPtrSound;

	std::string mNameMap;

	nsMathTools::TVector3 mPosition;
public:
  TBehaviourPatternContext(TBehaviourPatternModel* pModel);
  virtual ~TBehaviourPatternContext();

  void SetPhysicWorld(int id_physic_world);
  int GetPhysicWorld();

  void SetModel(TBehaviourPatternModel* pModel);
  TBehaviourPatternModel* GetModel();

  void SetGameObject(TGameObject* p);

	void SetNameMap(std::string nameMap);
	std::string GetNameMap();

  // при загрузке карты/объекта
  virtual void SetParameterMap(TMapItem::TMapStrStr& m);// L
  // при сохранении карты/объекта,
  // что бы знать какие ключи вообще возможны, проектирование новых карт
  //virtual void GetDefaultParameterMap(TMapItem::TMapStrStr& m);// L

  // меняет физику
  virtual void SetPosition(nsMathTools::TVector3& v);// L
  virtual bool GetPosition(nsMathTools::TVector3& v);// B, мгновенное значение
  virtual void SetOrientation(nsMathTools::TVector3& v);// L
  virtual bool GetOrientation(nsMathTools::TVector3& v);// B, мгновенное значение

  virtual bool UpdateFromGameItem(TBaseItem* pBI);// L

  const TMapItem::TMapStrStr* GetParameterMap();

  TGameObjectComponent_Ogre* GetGraphic();
  TGameObjectComponent_Bullet*  GetPhysic();
  TGameObjectComponent_OpenAL*   GetSound();
protected:

	template<typename T>
	bool GetFromParameterMap(std::string name, T& result)
	{
		TMapItem::TMapStrStr* pMap = (TMapItem::TMapStrStr*)GetParameterMap();
		if( pMap==NULL )
		{
			BL_FIX_BUG();
			return false;
		}

		TMapItem::TMapStrStrIt fit = pMap->find(name);
		if( fit==pMap->end() )
		{
			BL_FIX_BUG();
			return false;
		}
		result = boost::lexical_cast<T>(fit->second);
		return true;
	}
};

#endif
