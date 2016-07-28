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
protected:
  TGameObject* mGO;
public:
  TBehaviourPattern();
  virtual ~TBehaviourPattern();

  void SetGameObject(TGameObject* p);

  // Сериализация
  virtual bool SetInternalStateMap(TMapItem::TMapStrStr& m);
  virtual void GetInternalStateMap(TMapItem::TMapStrStr& m);

  virtual bool SetInternalStateC(TContainer c);
  virtual TContainer GetInternalStateC();

  // тип - подвижный, неподвижный - для оптимизации (в основном для моделей)
  // требуется ли каждый физ. кадр синхронизировать с графикой и звуком
  virtual bool GetNeedSynchro();

  // Модификация
  // Обновить от такого же Паттерна
  virtual bool SetModify(TContainer c);
  virtual TContainer GetModify();

  // mainly, for debug
  void SetPosition(nsMathTools::TVector3& v);
  void SetOrientation(nsMathTools::TVector3& v);

  // Обновить от FGIObject
  // ???
  //virtual bool SetDescFGIObject(TContainer c) = 0;
  //virtual TContainer GetDescFGIObject() = 0;

  virtual void Thread_Logic();
  virtual void Thread_Ogre();
  virtual void Thread_Bullet();
  virtual void Thread_OpenAL();
};

#endif
