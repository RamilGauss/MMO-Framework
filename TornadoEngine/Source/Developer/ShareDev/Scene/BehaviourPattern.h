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

class DllExport TBehaviourPattern
{
  std::string mType;// для поиска деструктора
protected:
  TGameObject* mGO;
public:
  TBehaviourPattern();
  virtual ~TBehaviourPattern();

  void SetType(std::string v);
  std::string GetType();

  void SetGameObject(TGameObject* p);

  // Сериализация параметров
  // при загрузке карты/объекта, key - value
  virtual bool SetParameterMap(TMapItem::TMapStrStr& m);
  virtual void GetParameterMap(TMapItem::TMapStrStr& m);
  // от одного Паттерна другому, упаковано 
  virtual bool SetParameterFromPattern(TContainer c);
  virtual TContainer GetParameterToPattern();

  // тип - подвижный, неподвижный - для оптимизации (в основном для моделей)
  // требуется ли каждый физ. кадр синхронизировать с графикой и звуком
  virtual bool GetNeedSynchro();

  // mainly, for debug, меняет физику
  virtual void SetPosition(nsMathTools::TVector3& v);
  virtual void SetOrientation(nsMathTools::TVector3& v);

  // fast = false - если объект очень сложный, 
  // то может повысить fps (но только если выключена физика)
  // при этом нужно контролировать прогресс загрузки
  // Задания: загрузка, выгрузка, модификация
  virtual bool LoadFromGameItem(TBaseItem* pBI, 
    bool fast = true);// если вызывать без выгрузки, то Update
  virtual bool Unload(bool fast = true);

  // выгрузка считается законченной если возвращается 100
  virtual int GetProgressLoad();

  // Выполнить задания в каждом из потоков
  virtual void Thread_Logic();
  virtual void Thread_Ogre();
  virtual void Thread_Bullet();
  virtual void Thread_OpenAL();
};

#endif
