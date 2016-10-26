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

class TGameObject;
class TFactoryGameItem;
class TFactoryBehaviourPatternModel;

class DllExport TBehaviourPatternContext
{
  std::string mNameModel;
protected:
  TGameObject*                   mGO;
  
  TMapItem::TMapStrStr mParameterMap;
  TMapItem::TMapStrStr mDefaultParameterMap;

  int mPhysicWorldID;
public:
  TBehaviourPatternContext(std::string nameModel);
  virtual ~TBehaviourPatternContext();

  void SetPhysicWorld(int id_physic_world);

  void SetName(std::string v);
  std::string GetName();

  void SetGameObject(TGameObject* p);
  //void SetFactory(TFactoryGameItem* pFGI, TFactoryBehaviourPatternModel* pFBP);

  // при загрузке карты/объекта
  virtual void SetParameterMap(TMapItem::TMapStrStr& m);// L
  // при сохранении карты/объекта,
  // что бы знать какие ключи вообще возможны, проектирование новых карт
  //virtual void GetDefualtParameterMap(TMapItem::TMapStrStr& m);// L
  // от одного Паттерна другому, упаковано 
  virtual bool SetParameterFromPattern(TContainer c);// L
  virtual TContainer GetParameterToPattern();// B - Slave

  // тип - подвижный, неподвижный - для оптимизации (в основном для моделей)
  // требуется ли каждый физ. кадр синхронизировать с графикой и звуком
  //virtual bool GetNeedSynchro();// B

  // меняет физику
  virtual void SetPosition(nsMathTools::TVector3& v);// L
  virtual bool GetPosition(nsMathTools::TVector3& v);// B, мгновенное значение
  virtual void SetOrientation(nsMathTools::TVector3& v);// L
  virtual bool GetOrientation(nsMathTools::TVector3& v);// B, мгновенное значение

  virtual bool UpdateFromGameItem(TBaseItem* pBI);// L

  const TMapItem::TMapStrStr* GetParameterMap();
protected:
  struct TParameterMap
  {
    bool flgMobility;
    std::string nameGameItem;
    std::string nameVariant;
    TParameterMap(){flgMobility=false;}
  };
  TParameterMap mStructParameterMap;

  virtual void ParseParameterMap(TMapItem::TMapStrStr& m);

};

#endif
