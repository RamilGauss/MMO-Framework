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
#include "BL_Debug.h"
#include <boost/lexical_cast.hpp>
#include "PatternConfigItem.h"

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
  
  //TMapItem::TMapStrStr mDefaultParameterMap;
	const TPatternConfigItem::TMapStrStr* mDefaultParameterMap;// from MapItem

	TPatternConfigItem::TMapStrStr mParameterMap;// from MapItem

  int mPhysicWorldID;

  // данные
  boost::scoped_ptr<TGameObjectComponent_Ogre>   mPtrGraphic;
  boost::scoped_ptr<TGameObjectComponent_Bullet> mPtrPhysic;
  boost::scoped_ptr<TGameObjectComponent_OpenAL> mPtrSound;

	std::string mNameMapItem;

	nsMathTools::TVector3 mPosition;
	nsMathTools::TVector4 mOrientQuaternion;
public:
  TBehaviourPatternContext(TBehaviourPatternModel* pModel);
  virtual ~TBehaviourPatternContext();

  void SetPhysicWorld(int id_physic_world);
  int GetPhysicWorld();

  void SetModel(TBehaviourPatternModel* pModel);
  TBehaviourPatternModel* GetModel();

  void SetGameObject(TGameObject* p);

	void SetNameMapItem(std::string nameMap);
	std::string GetNameMapItem();

  // меняет физику
  virtual void SetPosition(nsMathTools::TVector3& v);
  virtual bool GetPosition(nsMathTools::TVector3& v);// мгновенное значение
  virtual void SetOrientation(nsMathTools::TVector4& v);
  virtual bool GetOrientation(nsMathTools::TVector4& v);// мгновенное значение

	// при загрузке карты/объекта
	void SetDefaultParameterMap(const TPatternConfigItem::TMapStrStr* pMap);

	virtual const TPatternConfigItem::TMapStrStr* GetParameterMap();
	virtual void SetParameterMap(TPatternConfigItem::TMapStrStr& m);

  TGameObjectComponent_Ogre*   GetGraphic();
  TGameObjectComponent_Bullet* GetPhysic();
  TGameObjectComponent_OpenAL* GetSound();
protected:

	template<typename T>
	bool GetFromParameterMap(std::string name, T& result)
	{
		TPatternConfigItem::TMapStrStrConstIt fit = mParameterMap.find(name);
		if( fit==mParameterMap.end() )
		{
			if( mDefaultParameterMap==NULL )
			{
				BL_FIX_BUG();
				return false;
			}
			fit = mDefaultParameterMap->find(name);
			if( fit==mDefaultParameterMap->end() )
			{
				BL_FIX_BUG();
				return false;
			}
		}
		result = boost::lexical_cast<T>(fit->second);
		return true;
	}
};

#endif
