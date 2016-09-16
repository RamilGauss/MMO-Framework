/*
Author: Gudakov Ramil Sergeevich a.k.a. Gauss 
Гудаков Рамиль Сергеевич 
Contacts: [ramil2085@mail.ru, ramil2085@gmail.com]
See for more information License.h.
*/

#ifndef BehaviourPatternH
#define BehaviourPatternH

/*
  Базовый тип поведения игрового объекта.
*/


#include "TypeDef.h"
#include "ContainerTypes.h"
#include "MathTools.h"
#include "MapItem.h"

class TGameObject;
class TFactoryGameItem;

class DllExport TBehaviourPattern
{
  std::string          mName;// Debug 
protected:
  TGameObject*         mGO;
  TFactoryGameItem*    mFGI;
  TMapItem::TMapStrStr mParameterMap;
  TMapItem::TMapStrStr mDefaultParameterMap;

  int mPhysicWorldID;
public:
  TBehaviourPattern();
  virtual ~TBehaviourPattern();

  void SetPhysicWorld(int id_physic_world);

  void SetName(std::string v);
  std::string GetName();

  void SetGameObject(TGameObject* p);
  void SetFGI(TFactoryGameItem* pFGI);

  // при загрузке карты/объекта
  virtual void SetParameterMap(TMapItem::TMapStrStr& m);// L
  // при сохранении карты/объекта,
  // что бы знать какие ключи вообще возможны, проектирование новых карт
  virtual void GetDefualtParameterMap(TMapItem::TMapStrStr& m);// L
  // от одного Паттерна другому, упаковано 
  virtual bool SetParameterFromPattern(TContainer c);// L
  virtual TContainer GetParameterToPattern();// B - Slave

  // тип - подвижный, неподвижный - для оптимизации (в основном для моделей)
  // требуется ли каждый физ. кадр синхронизировать с графикой и звуком
  virtual bool GetNeedSynchro();// B

  // меняет физику
  virtual void SetPosition(nsMathTools::TVector3& v);// L
  virtual bool GetPosition(nsMathTools::TVector3& v);// B, мгновенное значение
  virtual void SetOrientation(nsMathTools::TVector3& v);// L
  virtual bool GetOrientation(nsMathTools::TVector3& v);// B, мгновенное значение

  virtual bool LoadFromParameterMap();// L
  virtual bool UpdateFromGameItem(TBaseItem* pBI);// L
  virtual bool Unload();// L

  // считается законченной если возвращается 100
  //virtual int GetProgressLoad();// L
  //virtual int GetProgressUnload();// L

  // Выполнить задания в каждом из потоков
  virtual void LoadFromThread_Ogre(bool fast = true);
  virtual void LoadFromThread_Bullet(bool fast = true);
  virtual void LoadFromThread_OpenAL(bool fast = true);

  virtual void UnloadFromThread_Ogre(bool fast = true);
  virtual void UnloadFromThread_Bullet(bool fast = true);
  virtual void UnloadFromThread_OpenAL(bool fast = true);

  virtual void SynchroFromThread_Logic(); // внешняя синхронизация
  virtual void SynchroFromThread_Ogre();  // графика от физики
  virtual void SynchroFromThread_Bullet();// внутренняя синхронизация
  virtual void SynchroFromThread_OpenAL();// звук от физики
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
